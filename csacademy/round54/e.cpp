#include <bits/stdc++.h>

using namespace std;

const int N = 5050 * 2, inf = 1e9 + N;

int d[N];
vector<pair<int, int > > g[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    u--; v--;
    u <<= 1;
    v <<= 1;
    g[u].emplace_back(v | 1, w);
    g[u | 1].emplace_back(v, w);
    g[v].emplace_back(u | 1, w);
    g[v | 1].emplace_back(u, w);
  }
  fill(d, d+2 * n, inf);
  d[0] = 0;
  set<pair<int, int> > st;
  st.insert(make_pair(0, 0));
  while (!st.empty()) {
    auto it = st.begin();
    int v = it->second;
    st.erase(it);
    for (auto e : g[v]) {
      int u = e.first;
      int nd = max(d[v], e.second) + 1;
      if ((nd & 1) !=  (u & 1))
        nd++;
      if (d[u] > nd) {
        st.erase(make_pair(d[u], u));
        d[u] = nd;
        st.insert(make_pair(d[u], u));
      }
    }
  }
  int ans = min(d[2 * n-1], d[2 * n-2]);
  if (ans >= inf)
    ans = -1;
  printf("%d\n", ans);
  return 0;
}