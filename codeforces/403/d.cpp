#include <bits/stdc++.h>

using namespace std;

const int N = 505;
bitset< N > g[66][2][N], rev[66][2][N];
int n, m;
long long dp[2][N][2];

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v, t;
    scanf("%d %d %d", &u, &v, &t);
    u--; v--;
    g[0][t][u][v] = 1;
    rev[0][t][v][u] = 1;
  }
  int ma = 0;
  for (int lg = 0; lg < 64; lg++) {
    if ((lg & 1)) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if ((g[lg][0][i] & rev[lg][0][j]).count()) {
            g[lg+1][0][i][j] = 1, ma = lg+1;
            rev[lg+1][0][j][i] = 1;
          }
          if ((g[lg][1][i] & rev[lg][1][j]).count()) {
            g[lg+1][1][i][j] = 1;
            rev[lg+1][1][j][i] = 1;
          }
        }
      }
    }
    else {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if ((g[lg][0][i] & rev[lg][1][j]).count()) {
            g[lg+1][0][i][j] = 1, ma = lg+1;
            rev[lg+1][1][j][i] = 1;
          }
          if ((g[lg][1][i] & rev[lg][0][j]).count()) {
            g[lg+1][1][i][j] = 1;
            rev[lg+1][0][j][i] = 1;
          }
        }
      }
    }
  }
  if (ma >= 63) {
    puts("-1");
    return 0;
  }
  memset(dp, 0, sizeof dp);
  int c = 0, b = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      if (g[ma][0][i][j])
        dp[c][j][0] = 1LL << ma;
  }
  for (int lg = ma-1; lg >= 0; lg--) {
    swap(c, b);
    for (int i = 0; i < n; i++) {
      dp[c][i][0] = dp[b][i][0];
      dp[c][i][1] = dp[b][i][1];
    }
    for (int i = 0; i < n; i++) if (dp[b][i][0] > 0) {
      for (int j = 0; j < n; j++) {
        if (g[lg][1][i][j])
          dp[c][j][1] = max(dp[c][j][1], dp[b][i][0] + (1LL << lg));
      }
    }

    for (int i = 0; i < n; i++) if (dp[b][i][1] > 0) {
      for (int j = 0; j < n; j++) {
        if (g[lg][0][i][j])
          dp[c][j][0] = max(dp[c][j][0], dp[b][i][1] + (1LL << lg));
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < 2; k++)
      ans = max(ans, dp[c][i][k]);
  }
  if (ans > 1e18)
    puts("-1");
  else
    cout << ans << endl;
  return 0;
}