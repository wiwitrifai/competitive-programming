/**
  IEEExtreme Programming Contest 10
  Problem : Painter's Dilemma
  Solver  : Luqman Arifin
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 505;
const int M = 25;
const int inf = 1e9;

int a[N], dp[N][M][M];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        for (int k = 0; k < M; k++) {
          dp[i][j][k] = inf;
        }
      }
    }
    
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    dp[0][0][0] = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= 20; j++) {
        for (int k = 0; k <= 20; k++) {
          if (j == a[i]) dp[i + 1][a[i]][k] = min(dp[i + 1][a[i]][k], dp[i][j][k]);
          if (k == a[i]) dp[i + 1][j][a[i]] = min(dp[i + 1][j][a[i]], dp[i][j][k]);
          dp[i + 1][a[i]][k] = min(dp[i + 1][a[i]][k], dp[i][j][k] + 1);
          dp[i + 1][j][a[i]] = min(dp[i + 1][j][a[i]], dp[i][j][k] + 1); 
        }
      }
    }
    int ans = inf;
    for (int i = 0; i <= 20; i++) {
      for (int j = 0; j <= 20; j++) {
        ans = min(ans, dp[n][i][j]);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
