#include <bits/stdc++.h>

using namespace std;

const int N = 1 << 22;

int a[N];
bool match[N], b[N], c[N];

int p[N];
int find(int x) { return p[x] < 0 ? x : p[x] = find(p[x]); }
void merge(int u, int v) {
  if ((u = find(u)) == (v = find(v))) return;
  if (-p[u] < -p[v]) swap(u, v);
  p[u] += p[v];
  p[v] = u;
}

int main() {
  memset(p, -1, sizeof p);
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d", a+i);
    b[a[i]] = 1;
  }
  int nn = 1 << n;
  for (int i = 0; i < n; ++i) {
    int now = 1 << i;
    for (int mask = 0; mask < nn; ++mask) {
      b[mask | now] |= b[mask];
    }
  }
  for (int i = 0; i < nn; ++i) {
    int u = (nn-1)^i;
    if (b[i] && b[u]) {
      match[i] = 1;
      match[u] = 1;
      merge(i, u);
    }
  }
  for (int i = 0; i < n; ++i) {
    int now = 1 << i;
    for (int mask = 0; mask < nn; ++mask) {
      if (now & mask) continue;
      if (b[mask] && b[mask^now] && match[mask^now]) {
        merge(mask, mask^now);
        match[mask] = 1;
      }
    }
  }
  for (int i = 0; i < m; ++i)
    c[find(a[i])] = 1;
  int ans = 0;
  for (int i = 0; i < nn; ++i)
    ans += c[i];
  printf("%d\n", ans);
  return 0;
}