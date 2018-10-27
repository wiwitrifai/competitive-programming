#include <bits/stdc++.h>

using namespace std;

const int N = 2505, mod = 1e9 + 7;

long long dp[N][N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  dp[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) {
      dp[i][j] = (1LL * dp[i-1][j] * (j-1) + dp[i-1][j-1]) % mod;
    }
  }
  long long ans = dp[n][k];
  for (int i = 1; i <= k; ++i)
    ans = (ans * i) % mod;
  printf("%lld\n", ans);

  return 0;
}