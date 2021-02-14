#include <bits/stdc++.h>

using namespace std;

const int N = 1024, mod = 1e9 + 7;

int dp[N][N], ways[N][N];
char s[N][N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%s", s[i]+1);
  memset(dp, -1, sizeof dp);
  dp[1][1] = s[1][1] == '1';
  ways[1][1] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (i == 1 && j == 1) continue;
      dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      if (dp[i][j] == dp[i-1][j])
        ways[i][j] = ways[i-1][j];
      if (dp[i][j] == dp[i][j-1])
        ways[i][j] += ways[i][j-1];
      ways[i][j] %= mod;
      dp[i][j] += s[i][j] == '1';
    }
  }
  printf("%d %d\n", dp[n][n], ways[n][n]);
  return 0;
}
