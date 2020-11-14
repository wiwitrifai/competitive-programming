#include <bits/stdc++.h>

using namespace std;

struct Dsu {
  vector<int> p;
  vector<int> val;

  Dsu(int _n, vector<int> _val) : p(_n, -1), val(_val) {}

  int find(int x) { return p[x] < 0 ? x : p[x] = find(p[x]); }

  long long merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return 0;
    if (-p[u] > -p[v])
      swap(u, v);
    p[v] += p[u];
    p[u] = v;
    long long ret = val[v] + val[u];
    val[v] = max(val[v], val[u]);
    return ret;
  }
};

vector<set<int>> g;

int main() {
  int n;
  scanf("%d", &n);
  g.resize(n);
  vector<pair<int, int>> vp(n);
  vector<int> val(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &val[i]);
    vp[i] = {val[i], i};
  }
  for (int i = 0; i < n-1; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].insert(v);
    g[v].insert(u);
  }
  vector<pair<int, int>> edges;
  sort(vp.begin(), vp.end());
  reverse(vp.begin(), vp.end());
  for (auto & pp : vp) {
    int v = pp.second;
    for (int u : g[v]) {
      g[u].erase(v);
      edges.emplace_back(u, v);
    }
    g[v].clear();
  }
  Dsu dsu(n, val);
  reverse(edges.begin(), edges.end());
  long long ans = 0;
  for (auto & e : edges) {
    ans += dsu.merge(e.first, e.second);
  }
  printf("%lld\n", ans);
  return 0;
}
