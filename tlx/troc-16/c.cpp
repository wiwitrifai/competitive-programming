#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7, N = 1024;

long long dp[N][2][2];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  memset(dp[0], 0, sizeof dp[0]);
  dp[0][0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    memset(dp[i], 0, sizeof dp[i]);
    for (int j = 0; j < 2; ++j) {
      dp[i][j][0] = (dp[i][j][0] + 1LL * (dp[i-1][j][0] + dp[i-1][j][1]) * (m-1)) % mod;
      dp[i][1][1] = (dp[i][1][1] + dp[i-1][j][0]) % mod;
    }
  }
  long long ans = (dp[n][1][0] + dp[n][1][1]) % mod;
  if (ans < 0)
    ans += mod;
  printf("%lld\n", ans);
  return 0;
}
