#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

int p[N];

int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}

void merge(int u, int v) {
  if ((u = find(u)) == (v = find(v)))
    return;
  if (-p[u] < -p[v])
    swap(u, v);
  p[u] += p[v];
  p[v] = u;
}

int main() {
  int n, m;
  memset(p, -1, sizeof p);
  scanf("%d %d", &n, &m);
  while (m--) {
    int k;
    scanf("%d", &k);
    int last = -1;
    while (k--) {
      int x;
      scanf("%d", &x);
      if (last != -1)
        merge(last, x);
      last = x;
    }
  }
  for (int i = 1; i <= n; ++i) {
    printf("%d%c", -p[find(i)], i == n ? '\n' : ' ');
  }
  return 0;
}
