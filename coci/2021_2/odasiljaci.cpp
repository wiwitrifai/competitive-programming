#include <bits/stdc++.h>

using namespace std;

struct Dsu {
  vector<int> p;

  Dsu(int _n) : p(_n, -1) {}

  int find(int x) { return p[x] < 0 ? x : p[x] = find(p[x]); }

  bool merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return false;
    if (-p[u] > -p[v])
      swap(u, v);
    p[v] += p[u];
    p[u] = v;
    return true;
  }
};

int main() {
  int n;
  scanf("%d", &n);
  vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &x[i], &y[i]);
  }
  vector<tuple<long long, int, int>> edges;
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      long long dx = x[j] - x[i], dy = y[j] - y[i];
      edges.emplace_back(dx * dx + dy * dy, i, j);
    }
  }
  sort(edges.begin(), edges.end());
  long long ans = 0;
  Dsu dsu(n);
  for (auto & e : edges) {
    long long d;
    int u, v;
    tie(d, u, v) = e;
    if (dsu.merge(u, v)) {
      ans = d;
    }
  }
  printf("%.10lf\n", (double)sqrt(ans) * 0.5);
  return 0;
}
