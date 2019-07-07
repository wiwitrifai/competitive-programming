#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, M = 1e6 + 6;;
tuple<int, int, int> edges[M];

int p[N];
int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}

void merge(int u, int v) {
  u = find(u);
  v = find(v);
  if (u == v)
    return;
  if (-p[u] < -p[v])
    swap(u, v);
  p[u] += p[v];
  p[v] = u;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int a, b, e;
  scanf("%d %d %d", &a, &b, &e);
  for (int i = 0; i < m-1; ++i) {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    edges[i] = make_tuple(z, x, y);
  }
  sort(edges, edges+m-1);
  int ans = 1e9;
  memset(p, -1, sizeof p);
  for (int i = 0; i < m-1; ++i) {
    int u, v, w;
    tie(w, u, v) = edges[i];
    merge(u, v);
    if (find(a) == find(b)) {
      ans = min(ans, w);
    }
  }
  printf("%d\n", ans);
  return 0;
}
