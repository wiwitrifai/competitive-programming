#include <bits/stdc++.h>

using namespace std;

const int N = 202, mod = 1e9 + 7;

int g[N][N], c[N][N], d[N];
long long C[N][N];

int main() {
  for (int i = 0; i < N; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++)
      C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
  }
  memset(g, 0, sizeof g);
  memset(d, 0, sizeof d);
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    g[u][v] = g[v][u] = 1;
    d[u]++; d[v]++;
  }
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      int cnt = 0;
      for (int k = 0; k < n; k++) {
        cnt += g[i][k] & g[j][k];
      }
      c[i][j] = c[j][i] = cnt;
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      if (g[i][j] == 0) continue;
      int cc = c[i][j], a = d[i] - 1, b = d[j] - 1;
      // cerr << i << " " << j << " " << a << " " << b << " " << cc << endl;
      if (a >= 2)
        ans = (ans + C[cc][2] * C[a-2][3]) % mod;
      if (b >= cc) {
        if (a >= 1)
          ans = (ans + C[cc][1] * C[b-cc][1] * C[a-1][3]) % mod;
        ans = (ans + C[b-cc][2] * C[a][3]) % mod;
      }
    }
  }
  printf("%I64d\n", ans);
  return 0;
}