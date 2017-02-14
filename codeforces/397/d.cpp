#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int f[N], n, m, g[N], h[N];
int used[N];

int main() {
  scanf("%d", &n);
  memset(used, 0, sizeof used);
  for (int i = 1; i <= n; i++)
    scanf("%d", f+i), used[f[i]] = 1;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (used[i] && f[i] != i) {
      puts("-1");
      return 0;
    }
    cnt += used[i];
  }
  m = 0;
  for (int i = 1; i <= n; i++) {
    if (used[i]) {
      g[i] = ++m;
      h[m] = i;
    }
  }
  for (int i = 1; i <= n; i++)
    g[i] = g[f[i]];
  printf("%d\n", m);
  for (int i = 1; i <= n; i++)
    printf("%d ", g[i]);
  printf("\n");
  for (int i = 1; i <= m; i++)
    printf("%d ", h[i]); 
  printf("\n");
  return 0;
}