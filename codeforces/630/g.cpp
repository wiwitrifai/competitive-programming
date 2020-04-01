#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int up[N], down[N];
int rup[N], rdown[N];
int a[N];

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  stack<int> st_up, st_down;
  vector<pair<int, int>> events;
  for (int i = 0; i < n; ++i) {
    while (!st_up.empty() && a[st_up.top()] <= a[i]) st_up.pop();
    while (!st_down.empty() && a[st_down.top()] >= a[i]) st_down.pop();
    rup[i] = st_up.empty() ? -1 : st_up.top();
    rdown[i] = st_down.empty() ? -1 : st_down.top();
    st_up.push(i);
    st_down.push(i);
    int lef = min(rup[i], rdown[i]);
    if (lef >= 0)
      events.emplace_back(lef, i);
  }
  while (!st_up.empty()) st_up.pop();
  while (!st_down.empty()) st_down.pop();

  sort(events.begin(), events.end());
  reverse(events.begin(), events.end());
  set<int> st;
  vector<pair<int, int>> full;
  for (int i = n-1, j = 0; i >= 0; --i) {
    while (!st_up.empty() && a[st_up.top()] <= a[i]) st_up.pop();
    while (!st_down.empty() && a[st_down.top()] >= a[i]) st_down.pop();
    up[i] = st_up.empty() ? n : st_up.top();
    down[i] = st_down.empty() ? n : st_down.top();
    st_up.push(i);
    st_down.push(i);
    int rig = max(up[i], down[i]);
    while (j < (int)events.size()) {
      if (events[j].first > i) {
        st.insert(events[j].second);
        ++j;
      }
      else
        break;
    }
    auto it = st.upper_bound(rig);
    if (it == st.end()) continue;
    full.emplace_back(i, *it);
  }
  sort(full.begin(), full.end());
  vector<pair<int, int>> optimals;
  for (auto it : full) {
    while (!optimals.empty() && optimals.back().second >= it.second)
      optimals.pop_back();
    optimals.push_back(it);
  }
  vector<tuple<int, int, int>> triple;
  for (int i = 0; i < n; ++i) {
    triple.emplace_back(rup[i], i, up[i]);
    triple.emplace_back(rdown[i], ~i, down[i]);
  }
  sort(triple.begin(), triple.end());
  vector<tuple<int, int, int>> optriple;
  for (auto it : triple) {
    while (!optriple.empty() && get<2>(optriple.back()) >= get<2>(it))
      optriple.pop_back();
    if (optriple.empty() || get<0>(optriple.back()) < get<0>(it))
      optriple.push_back(it);
  }
  while (q--) {
    int l, r;
    scanf("%d %d", &l, &r);
    --l;
    int p = lower_bound(optimals.begin(), optimals.end(), make_pair(l, -1)) - optimals.begin();
    if (p < (int)optimals.size() && optimals[p].second < r) {
      int x = optimals[p].first, y = optimals[p].second;
      int u = a[up[x]] > a[rup[y]] ? up[x] : rup[y];
      int d = a[down[x]] < a[rdown[y]] ? down[x] : rdown[y];
      if (u > d)
        swap(u, d);
      printf("4\n%d %d %d %d\n", x+1, u+1, d+1, y+1);
      continue;
    }
    p = lower_bound(optriple.begin(), optriple.end(), make_tuple(l, -n-1, -1)) - optriple.begin();
    if (p < (int)optriple.size() && get<2>(optriple[p]) < r) {
      int mid = get<1>(optriple[p]);
      int lef, rig;
      if (mid >= 0)
        lef = rup[mid], rig = up[mid];
      else
        mid = ~mid, lef = rdown[mid], rig = down[mid];
      printf("3\n%d %d %d\n", lef+1, mid+1, rig+1);
      continue;
    }
    puts("0");
  }
  return 0;
}
