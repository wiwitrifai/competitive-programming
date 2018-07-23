#include <bits/stdc++.h>

using namespace std;

const int N = 502, M = 250 * 499 + 2, mod = 1e9 + 7;

int dp[N][M];
int cnt[N][N];
int fac[N + 5];
int C[N+5][N+5];

void add(int & l, int r) {
  l += r;
  if (l >= mod) l -= mod;
}

int main() {
  fac[0] = 1;
  for (int i = 1; i < N+5; ++i) {
    fac[i] = 1LL * fac[i-1] * i % mod;
  }
  for (int i = 0; i < N + 5; ++i) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; ++j)
      C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
  }
  dp[1][0] = 1;
  dp[1][1] = mod-1;
  for (int i = 1; i+1 < N; ++i) {
    int now = 0, sum = 0;
    for (int j = 0; j < M; ++j) {
      add(now, dp[i][j]);
      add(sum, now);
      dp[i][j] = sum;
      add(dp[i+1][j], now);
      if (j+i+1 < M)
        add(dp[i+1][j+i+1], mod - now);
    }
  }
  for (int i = 1; i < N; ++i) {
    for (int j = 1; j <= i; ++j) {
      cnt[i][j] = fac[i-j+1] * 1LL * C[i][j] % mod;
    }
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int n, k;
    scanf("%d %d", &n, &k);
    int ans = 0;
    k = min(k, n * (n-1) / 2);
    for (int i = 1; i <= n; ++i) {
      ans = (ans + 1LL * cnt[n][i] * dp[i][k]) % mod;
    }
    printf("%d\n", ans);
  }
  return 0;
}
