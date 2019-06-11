#include <bits/stdc++.h>

using namespace std;

const int N = 1024, B = 129, mod = 1e9 + 9;

long long dp[B][N];

void add(long long & var, long long val) {
  var += val;
  if (var >= mod)
    var -= mod;
}

int main() {
  int k, b;
  scanf("%d %d", &k, &b);
  dp[0][0] = 1;
  for (int i = 0; i+1 < B; ++i) {
    for (int j = 0; j < k; ++j) {
      if (dp[i][j] == 0) continue;
      long long & now = dp[i][j];
      add(dp[i+1][(j * 2) % k], now);
      add(dp[i+1][(j * 2 + 1) % k], now);
    }
  }
  int pw = 1;
  long long ans = 0;
  for (int i = 0; i < b; ++i) {
    int sisa = b-i-1;
    for (int j = 0; j < k; ++j) {
      int now = 1LL * (2 * j + 1) * pw % k;
      now = k - now;
      if (now >= k)
        now -= k;
      add(ans, 1LL * dp[i][now] * dp[sisa][j] % mod);
    }
    pw = pw * 2 % k;
  }
  ans %= mod;
  if (ans < 0) ans += mod;
  printf("%lld\n", ans);
  return 0;
}
