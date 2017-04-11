#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int dp[2][N][2][55];
int a[2][N];
int aa[2][N], n, p, k;

int main() {
  scanf("%d %d %d", &n, &p, &k);
  for (int j = 0; j < 2; j++) {
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
      int x;
      scanf("%d", &x);
      a[j][x] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 2; j++)
      aa[j][i] = aa[j][i-1] + (a[j][i] && !a[j^1][i]);
    for (int j = 0; j < 2; j++)
      a[j][i] += a[j][i-1];
  }
  int ans = 0;
  int cur = 0, nxt = 1;
  for (int i = 0; i <= p; i++) {
    for (int j = 0; j <= n; j++) {
      for (int c = 0; c < 2; c++) {
        for (int z = k; z >= 0; z--) {
          ans = max(ans, dp[cur][j][c][z]);
          int up = j, down = max(j-z, 0);
          int ndown = min(down + k, n);
          dp[nxt][ndown][c^1][ndown-up] = max(dp[nxt][ndown][c^1][ndown-up], dp[cur][j][c][z] + a[c^1][ndown]-a[c^1][up]+aa[c^1][up]-aa[c^1][down]);
          if (z)
            dp[cur][j][c][z-1] = max(dp[cur][j][c][z-1], dp[cur][j][c][z]);
          dp[cur][j+1][c][z+1] = max(dp[cur][j+1][c][z+1], dp[cur][j][c][z]);
        }
      }
      int now = max(dp[cur][j][0][0], dp[cur][j][1][0]); 
      int up = j, down = j, z = 0;
      int ndown = min(down + k, n);
      for (int c = 0; c < 2; c++) {
        dp[nxt][ndown][c^1][ndown-up] = max(dp[nxt][ndown][c^1][ndown-up], now + a[c^1][ndown]-a[c^1][up]);
        dp[cur][j+1][c][z+1] = max(dp[cur][j+1][c][z+1], now);
        dp[cur][j+1][c][z] = max(dp[cur][j+1][c][z], now);
      }
    }
    swap(cur, nxt);
  }
  printf("%d\n", ans);
  return 0;
}