#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, S = 256;

vector<pair<int, int> > range[N];
int ans[N];
bitset<S> bs[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<pair<int, int> > edge;
    for (int i = 0; i < m; ++i) {
      int u, v;
      scanf("%d %d", &u, &v);
      --u, --v;
      if (u > v) swap(u, v);
      edge.emplace_back(u, v);
    }
    sort(edge.begin(), edge.end());
    edge.erase(unique(edge.begin(), edge.end()), edge.end());
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
      range[i].clear();
      int k;
      scanf("%d", &k);
      for (int j = 0; j < k; ++j) {
        int l, r;
        scanf("%d %d", &l, &r);
        --l;
        range[i].emplace_back(l, r);
      }
      sort(range[i].begin(), range[i].end());
      ans[i] = 1;
    }
    for (int i = 0; i < q; i += S) {
      int til = min(q, i+S);
      vector<pair<int, int> > events;
      for (int j = i; j < til; ++j) {
        for (auto r : range[j]) {
          events.emplace_back(r.first, j);
          events.emplace_back(r.second, ~j);
        }
      }
      sort(events.begin(), events.end());
      bitset<S> now;
      now.reset();
      for (int j = 0, k = 0; j < n; ++j) {
        while (k < events.size() && events[k].first <= j) {
          int v = events[k].second;
          if (v >= 0)
            now[v-i] = 1;
          else
            now[~v-i] = 0;
          ++k;
        }
        bs[j] = now;
      }
      now.reset();
      for (int k = 0; k < til-i; ++k)
        now[k] = 1;
      for (auto e : edge) {
        bitset<S> res = bs[e.first] & bs[e.second] & now;
        if (!res.count())
          continue;
        for (int j = 0; j < til-i; ++j) {
          if (res[j]) {
            now[j] = 0;
            ans[j+i] = 0;
          }
        }
      }
    }
    for (int i = 0; i < q; ++i) {
      puts(ans[i] ? "YES" : "NO");
    }
  }
  return 0;
}