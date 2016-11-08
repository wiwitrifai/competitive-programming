#include <bits/stdc++.h>

using namespace std;

const int N = 1003, mod = 1e9 + 7;

long long dp[N][N];

int main() {
  freopen("galactic.in", "r", stdin);
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    if (k > n) {
      puts("0");
      continue;
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= k; j++) {
        dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] * j) % mod;
      }
    }
    long long ans = dp[n][k];
    for (int i = 1; i <= k; i++)
      ans = (ans * i) % mod;
    printf("%lld\n", ans);
  }
  return 0;
}