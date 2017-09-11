#include <bits/stdc++.h>

using namespace std;

const int N = 3e3 + 6, MAGIC = 1, SZ = N/MAGIC + 5;
const long long inf = 1e18;

vector<pair<int, long long>> g[N];
long long d[SZ][SZ], val2[SZ][SZ], val[SZ];
int tom[6][N], to[SZ][SZ], pv[N][6];
long long dist[N], pre[N], dd[N][6];

void dijkstra(int s, int low, int hi) {
  for (int i = low; i <= hi; i++)
    dist[i] = inf, pre[i] = -1;
  dist[s] = 0;
  set<pair<long long,int>> st;
  st.insert(make_pair(0, s));
  while (!st.empty()) {
    auto it = st.begin();
    int v = it->second;
    st.erase(it);
    for (auto e : g[v]) {
      int u = e.first;
      if (u < low || u > hi)
        continue;
      if (dist[u] <= dist[v] + e.second) continue;
      st.erase(make_pair(dist[u], u));
      dist[u] = dist[v] + e.second;
      pre[u] = v;
      st.insert(make_pair(dist[u], u));
    }
  }
}

int main() {
  int n, m, q;
  scanf("%d %d %d", &m, &n, &q);
  for (int i = 0; i < m-1; i++) {
    for (int j = 0; j < n; j++) {
      int u = j * m + i, v = u + 1;
      long long w;
      scanf("%lld", &w);
      g[u].emplace_back(v, w);
      g[v].emplace_back(u, w);
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n-1; j++) {
      int u = j * m + i, v = u + m;
      long long w;
      scanf("%lld", &w);
      g[u].emplace_back(v, w);
      g[v].emplace_back(u, w);
    }
  }
  while (q--) {
    int t, a, b, c, de;
    long long e;
    scanf("%d %d %d", &t, &a, &b);
    a--; b--;
    if (t == 1) {
      scanf("%d %d %lld", &c, &de, &e);
      c--; de--;
      int u = b * m + a, v = de * m + c;
      dijkstra(u, 0, n * m - 1);
      while (v >= 0) { 
        val[v] += e;
        v = pre[v];
      }
    }
    else {
      int u = b * m + a;
      long long ans = val[u];
      printf("%lld\n", ans);
    }
  }
  return 0;
}