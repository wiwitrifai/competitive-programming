#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353, N = 3030;

int dp[N][N + N], C[N][N];

void add(int & var, int val) {
  var += val;
  if (var >= mod)
    var -= mod;
}

int main() {
  for (int i = 0; i < N; ++i) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; ++j)
      C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
  }
  int n, x;
  scanf("%d %d", &n, &x);
  if (x == 1) {
    int ans = 1;
    for (int i = 0; i < n; ++i)
      ans = (ans * 2) % mod;
    printf("%d\n", ans);
    return 0;
  }
  if (x == 2) {
    printf("%d\n", n + 1);
    return 0;
  }
  dp[0][0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < x; ++j) {
      for (int k = 0; k <= 2; ++k) {
        if (j + k >= x) continue;
        add(dp[i+1][j+k], dp[i][j]);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < x; ++i)
    add(ans, dp[n][i]);
  for (int len = 3; len <= n; ++len) {
    for (int i = 1; i * 2 < len; ++i) {
      int tengah = len - 2 * i;
      int sisa = x-1 - 2 * i;
      if (sisa < tengah || sisa > 2 * tengah) continue;
      ans = (ans + 1LL * C[tengah][sisa-tengah] * C[n][len]) % mod;
    }
  }
  if (x & 1) {
    for (int len = (x - 1); len <= n; ++len) {
      ans = (ans + C[n][len]) % mod;
    }
  }
  ans %= mod;
  if (ans < 0) ans += mod;
  printf("%d\n", ans);
  return 0;
}
