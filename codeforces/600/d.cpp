#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int p[N], big[N];

int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}

void merge(int u, int v) {
  if ((u = find(u)) == (v = find(v)))
    return;
  p[u] = v;
  big[v] = max(big[v], big[u]);
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  iota(big, big+n, 0);
  fill(p, p+n, -1);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    merge(u, v);
  }
  int ans = 0;
  for (int i = 0; i + 1 < n; ++i) {
    if (big[find(i)] > i && find(i) != find(i+1)) {
      merge(i, i+1);
      ++ans;
    }
  }
  printf("%d\n", ans);

  return 0;
}
