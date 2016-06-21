#include <bits/stdc++.h>

using namespace std;
const int N = 1004;
int n, m, k, dp[N][N][12][2];
char s[N], t[N];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  scanf("%s%s", s+1, t+1);
  for(int i = 1; i<=n; i++) {
    for(int j = 1; j<=m; j++) {
      for(int h = 1; h<=k; h++) {
        dp[i][j][h][0] = max(dp[i][j-1][h][0], dp[i-1][j][h][0]);
        if(s[i] == t[j])
          dp[i][j][h][1] = max(dp[i-1][j-1][h][1], dp[i-1][j-1][h-1][0]) + 1;
        dp[i][j][h][0] = max(dp[i][j][h][0], dp[i][j][h][1]);
      }
    }
  }
  printf("%d\n", dp[n][m][k][0]);
  return 0;
}