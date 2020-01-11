#include <bits/stdc++.h>

using namespace std;

const int N = 1024, mod = 1e9 + 7, K = 22;

long long dp[K][N], C[N][N];
int a[N];

int main() {
  for (int i = 0; i < N; ++i) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
    }
  }
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < k; ++i) {
    scanf("%d", a+i);
  }
  dp[0][0] = 1;
  int tot = 0;
  for (int i = 0; i < k; ++i) {
    tot += a[i];
    tot = min(tot, n);
    for (int j = 0; j <= a[i]; ++j) {
      for (int cnt = 0; cnt + j <= tot; ++cnt) {
        int sisa = n - cnt;
        if (sisa < j) continue;
        long long cur = dp[i][cnt] * C[sisa][j] % mod;
        cur = cur * C[n - j][a[i] - j] % mod;
        dp[i+1][cnt+j] = (dp[i+1][cnt+j] + cur) % mod;
      }
    }
  }
  long long ans = dp[k][n] % mod;
  if (ans < 0)
    ans += mod;
  printf("%lld\n", ans);
  return 0;
}
