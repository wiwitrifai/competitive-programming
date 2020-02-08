#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

const int N = 355;

long long dp[N][N], C[N][N];

int main() {
  for (int i = 0; i < N; ++i) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
    }
  }
  int n;
  scanf("%d", &n);
  memset(dp, 0, sizeof dp);
  dp[0][0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= n; ++j) {
      if (dp[i][j] == 0) continue;
      for (int k = j; k <= n; ++k) {
        if (k-j == i+1) continue;
        dp[i+1][k] = (dp[i+1][k] + dp[i][j] * C[n-j][n-k]) % mod;
      }
    }
  }
  long long ans = 1;
  for (int i = 0; i < n; ++i)
    ans = ans * n % mod;
  ans = (ans - dp[n][n]) % mod;
  if (ans < 0)
    ans += mod;
  printf("%lld\n", ans);
  return 0;
}
