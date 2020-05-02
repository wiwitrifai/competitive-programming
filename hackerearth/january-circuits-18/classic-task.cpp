#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

int p[N];
int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}
bool merge(int u, int v) {
  if ((u = find(u)) == (v = find(v)))
    return false;
  if (p[u] > p[v]) swap(u, v);
  p[u] += p[v];
  p[v] = u;
  return true;
}

int main() {
  int n, m;
  int l, r;
  scanf("%d %d", &n, &m);
  memset(p, -1, sizeof p);
  int ans = n;
  while (m--) {
    scanf("%d %d", &l, &r);
    while (l < r) {
      ans -= merge(l, r);
      ++l, --r;
    }
  }
  printf("%d\n", ans);
  return 0;
}