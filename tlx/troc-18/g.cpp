#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353, N = 1024;

long long dp[N][2][2];

void upd(long long & var, long long val) {
  var += val;
  if (var >= mod)
    var -= mod;
}

int main() {
  int n;
  long long x;
  scanf("%d %lld", &n, &x);
  vector<long long> a(n);
  long long all = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &a[i]);
    all ^= a[i];
  }
  long long ans = 0;
  for (int bit = 29; bit >= 0; --bit) {
    long long mask = (1LL << (bit+1)) - 1, imask = (mask >> 1);
    for (int i = 0; i < n; ++i)
      a[i] &= mask;
    memset(dp, 0, sizeof dp);
    dp[0][0][0] = 1;
    for (int i = 0; i < n; ++i) {
      int cur = (a[i] >> bit) & 1;
      long long inside = imask & a[i], full = (a[i] + 1) % mod;
      inside = (inside + 1) % mod;
      long long pw2 = (1LL << bit) % mod;
      for (int j = 0; j < 2; ++j) {
        if (cur) {
          upd(dp[i+1][j^1][0], dp[i][j][0] * inside % mod);
          upd(dp[i+1][j][1], dp[i][j][0] % mod);

          upd(dp[i+1][j][1], dp[i][j][1] * pw2 % mod);
          upd(dp[i+1][j^1][1], dp[i][j][1] * inside % mod);
        } else {
          upd(dp[i+1][j][0], dp[i][j][0] * full % mod);
          upd(dp[i+1][j][1], dp[i][j][1] * full % mod);
        }
      }
    }
    int cur = (x >> bit) & 1;
    upd(ans, dp[n][cur][1]);
    if ((all^x) & (1LL << bit))
      break;
  }
  if (all == x)
    upd(ans, 1);
  printf("%lld\n", ans);
  return 0;
}
