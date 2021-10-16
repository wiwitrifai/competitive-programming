#include <bits/stdc++.h>

using namespace std;

struct Dsu {
  vector<int> p;
  Dsu(int _n) : p(_n, -1) {
  }

  int find(int x) {
    return p[x] < 0 ? x : p[x] = find(p[x]);
  }

  int merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
      return -1;
    if (-p[u] > -p[v])
      swap(u, v);
    p[v] += p[u];
    p[u] = v;
    return v;
  }

};


int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> c(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &c[i]);
  vector<tuple<int, int, int>> edges, mst;
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    --u, --v;
    edges.emplace_back(w, u, v);
  }
  sort(edges.begin(), edges.end());
  reverse(edges.begin(), edges.end());
  Dsu dsu(n);
  for (auto & e : edges) {
    int u, v, w;
    tie(w, u, v) = e;
    if (dsu.merge(u, v) != -1)
      mst.push_back(e);
  }
  const long long inf = 1e18 + 7;
  vector<long long> ans(n, inf);
  vector<long long> sum(n, 0);
  for (int i = 0; i < n; ++i)
    sum[i] = c[i];
  Dsu comp(n);
  for (auto & e : mst) {
    int u, v, w;
    tie(w, u, v) = e;
    u = comp.find(u);
    v = comp.find(v);
    long long tot = sum[u] + sum[v];
    long long z = -1;
    if (sum[u] <= w) {
      z = max(z, min(w - sum[u], min(ans[u], ans[v] - sum[u])));
    }
    if (sum[v] <= w) {
      z = max(z, min(w - sum[v], min(ans[v], ans[u] - sum[v])));
    }
    int r = comp.merge(u, v);
    sum[r] = tot;
    ans[r] = z;
    if (z <= 0) {
      puts("-1");
      return 0;
    }
  }
  printf("%lld\n", ans[comp.find(0)]);
  return 0;
}
