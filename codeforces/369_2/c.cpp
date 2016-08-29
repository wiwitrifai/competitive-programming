#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const long long inf = 1e15;

long long p[N][N];
long long dp[N][N][N];
long long up[N], down[N];

int n, m, k, c[N];
int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", c+i);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= m; j++)
      scanf("%d", p[i]+j);
  }
  for (int i = 0; i <= k; i++)
    for (int j = 0; j <= m; j++)
      dp[0][i][j] = inf;
  dp[0][0][0] = 0;
  for (int i = 0; i < n; i++) {
    if (c[i] == 0) {
      for (int j = 0; j <= k; j++) {
        dp[i+1][j][0] = inf;
        for (int h = 1; h <= m; h++) {
          long long & now = dp[i+1][j][h];
          now = inf;
          if (j > 0) {
            for (int g = 0; g <= m; g++) if (g != h)
              now = min(now, dp[i][j-1][g]);
          }
          now = min(now, dp[i][j][h]);
          now += p[i][h];
        }
      }
    }
    else {
      int col = c[i];
      for (int j = 0; j <= k; j++) {
        for (int h = 0; h <= m; h++)
          dp[i+1][j][h] = inf;
        long long & now = dp[i+1][j][col];
        now = dp[i][j][col];
        if (j > 0) {
          for (int h = 0; h <= m; h++) if (h != col) {
            now = min(now, dp[i][j-1][h]);
          }
        }
      }
    }
  }
  long long ans = inf;
  for (int i = 1; i <= m; i++)
    ans = min(dp[n][k][i], ans);
  if (ans >= inf)
    puts("-1");
  else
    cout << ans << endl;
  return 0;
}