#include <bits/stdc++.h>

using namespace std;

const int N = 305, mod = 1000000007;

long long dp[N + 5][3 * N + 5];
long long C[N][N];

int main() {
  dp[0][0] = 1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= 3 * N; j++) {
      if (dp[i][j] == 0) continue;
      for (int k = 1; k <= 3; k++) {
        long long & nw = dp[i+1][j+k];
        nw += dp[i][j];
        if (nw >= mod) nw -= mod;
      }
    }
  }
  for (int i = 0; i < N; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++)
      C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k, m;
    scanf("%d %d %d", &n, &k, &m);
    if (n > 3*k) {
      puts("0");
      continue;
    }
    long long ans = 0;
    for (int i = 0; i <= k; i++) {
      int now = 1LL * dp[k-i][n] * C[k][i] % mod;
      for (int j = 0; j <= min(i, m); j++) {
         ans = (ans + 1LL*now * C[i][j]) % mod;
      }
    }
    if (ans < 0) ans += mod;
    printf("%lld\n", ans);
  }
  return 0;
}