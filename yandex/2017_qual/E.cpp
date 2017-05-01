#include <bits/stdc++.h>

using namespace std;

const int N = 1024, mod = 1e9 + 7;
long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1) r = r * b % mod;
  return r;
}
long long fac[N], inv[N];
long long C(int n, int k) {
  return (fac[n] * inv[k] % mod) * inv[n-k] % mod;
}
long long dp[N][4][4];

int main() {
  fac[0] = inv[0] = 1;
  for (int i = 1; i < N; i++) {
    fac[i] = fac[i-1] * i % mod;
    inv[i] = powmod(fac[i], mod-2);
  }
  dp[0][0][0] = 1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        if (j)
          (dp[i+j][j][0] += dp[i][j][k] * inv[k] % mod) %= mod;
        if (j+1 < 4 && k+1 < 4)
          (dp[i][j+1][k+1] += dp[i][j][k]) %= mod;
      }
    }
  }
  int n;
  cin >> n;
  long long ans = 0;
  for (int i = 0; i < 4; i++) {
    long long cur = dp[n-2][3][i];
    ans = (ans + cur * inv[i]) % mod;
  }
  cerr << ans << endl;
  ans = ans * fac[n-1] % mod;
  cerr << ans << endl;
  for (int i = 2; i <= n-i-1; i++) {
    long long cur = 1LL * fac[n] % mod;
    cur = cur * powmod(4, mod-2) % mod;
    if (i == n-i-1)
      cur = cur * ((mod+1)/2) % mod;
    ans = (ans + cur) % mod;
    cerr << cur << endl;
  }
  printf("%lld\n", ans);
  return 0;
}