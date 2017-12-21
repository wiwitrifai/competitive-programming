#include <bits/stdc++.h>

using namespace std;
const int N = 3e5 + 5, inf = 1e9 + 7;

pair<int, int> open[N], close[N];
vector<int> add[N], que[N];
vector<pair<int, int> > addr[N], remr[N];
int ans[N];

int main() {
  int n;
  scanf("%d", &n);
  vector<int> vr, vc;
  for (int i = 0; i < n; ++i) {
    int r, c;
    scanf("%d %d", &r, &c);
    open[i] = {r, c};
    vr.push_back(r);
    vc.push_back(c);
  }
  for (int i = 0; i < n; ++i) {
    int r, c;
    scanf("%d %d", &r, &c);
    close[i] = {r, c};
    vr.push_back(r);
    vc.push_back(c);
  }
  sort(vr.begin(), vr.end());
  sort(vc.begin(), vc.end());
  vr.erase(unique(vr.begin(), vr.end()), vr.end());
  vc.erase(unique(vc.begin(), vc.end()), vc.end());
  for (int i = 0; i < n; ++i) {
    open[i].first = lower_bound(vr.begin(), vr.end(), open[i].first) - vr.begin();
    open[i].second = lower_bound(vc.begin(), vc.end(), open[i].second) - vc.begin();
    close[i].first = lower_bound(vr.begin(), vr.end(), close[i].first) - vr.begin();
    close[i].second = lower_bound(vc.begin(), vc.end(), close[i].second) - vc.begin();
    add[open[i].second].push_back(i);
    que[close[i].second].push_back(i);
  }
  set<pair<int, int> > st;
  bool ok = 1;
  int now = 0; 
  for (int e = 0; ok && e < vc.size(); ++e) {
    for (int i : add[e]) {
      auto it = st.lower_bound(make_pair(open[i].first+1, -1));
      if (it != st.begin()) {
        it--;
        if (it->first == open[i].first)
          ok = 0;
      }
      st.insert(make_pair(open[i].first, i));
    }
    for (int i : que[e]) {
      auto it = st.lower_bound(make_pair(close[i].first+1, -1));
      if (it == st.begin()) {
        ok = 0;
      }
      else {
        it--;
        int rem = it->second;
        st.erase(it);
        ans[rem] = i;
      }
    }
  }
  if (ok) {
    for (int i = 0; i < vc.size(); ++i)
      add[i].clear(), que[i].clear();
    for (int i = 0; i < n; ++i) {
      pair<int, int> range = {open[i].first, close[ans[i]].first};
      addr[open[i].second].push_back(range);
      remr[close[ans[i]].second].push_back(range);
    }
    set<int> isi;
    for (int e = 0; ok && e < vc.size(); ++e) {
      sort(addr[e].begin(), addr[e].end());
      reverse(addr[e].begin(), addr[e].end());
      sort(remr[e].begin(), remr[e].end());
      for (auto r : addr[e]) {
        auto it = isi.lower_bound(r.first);
        ok &= (it == isi.end() || *it > r.second);
        isi.insert(r.first);
        isi.insert(r.second);
      }
      for (auto r : remr[e]) {
        auto it = isi.lower_bound(r.first);
        if (it == isi.end())
          ok = 0;
        else {
          it = isi.erase(it);
        }
        if (r.second == r.first) continue;
        if (it == isi.end())
          ok = 0;
        else if (*it != r.second)
          ok = 0;
        else
          isi.erase(it);
      }
    }
  }
  if (!ok)
    puts("syntax error");
  else {
    for (int i = 0; i < n; ++i)
      printf("%d\n", ans[i]+1);
  }

  return 0;
}