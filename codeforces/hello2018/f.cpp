#include <bits/stdc++.h>

using namespace std;

const int N = 2018, mod = 998244353;

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}
long long dp[N], mf[N], mg[N][N];
long long p, q, pp[N], qq[N];
long long g(int n, int k) {
  if (n < k) return 0;
  if (k == 0) return 1;
  if (mg[n][k] != -1) return mg[n][k];
  long long & ret = mg[n][k];
  ret = pp[k] * g(n-1, k) % mod;
  if (k)
    ret = (ret + g(n-1, k-1) * qq[n-k]) % mod;
  if (ret < 0) ret += mod;
  return ret;
}
long long f(int k) {
  if (mf[k] != -1) return mf[k];
  long long & ret = mf[k];
  ret = 1;
  for (int i = 1; i < k; ++i) {
    ret = (ret - f(i) * g(k, i)) % mod;
  }
  ret %= mod;
  if (ret < 0) ret += mod;
  return ret;
}
long long solve(int n) {
  if (dp[n] != -1) return dp[n];
  long long & ret = dp[n];
  ret = 0;
  long long sum = 0;
  for (int k = 1; k < n; ++k) {
    long long cur = (1LL * k * (k-1) /2 + solve(k) + solve(n-k)) % mod;
    cur = cur * f(k) % mod;
    sum = (sum + cur * g(n, k)) % mod;;
  }
  long long cur = f(n) * g(n, n) % mod;
  long long w = (1LL * n * (n-1) / 2) % mod;
  sum = (sum + w * cur) % mod;
  long long bagi = (1 - cur) % mod;
  if (bagi < 0) bagi += mod;
  ret = sum * powmod(bagi, mod - 2) % mod;
  if (ret < 0) ret += mod;
  return ret;
}

int main() {
  memset(dp, -1, sizeof dp);
  memset(mf, -1, sizeof mf);
  memset(mg, -1, sizeof mg);
  int n, a, b;
  scanf("%d %d %d", &n, &a, &b);
  p = 1LL * a * powmod(b, mod - 2) % mod;
  q = (mod + 1 - p) % mod;
  pp[0] = 1, qq[0] = 1;
  for (int i = 1; i < N; ++i) {
    pp[i] = pp[i-1] * p % mod;
    qq[i] = qq[i-1] * q % mod;
  }
  long long ans = solve(n) + 1LL * n * (n-1) / 2;
  ans %= mod;
  if (ans < 0) ans += mod;
  cout << ans << endl;
  return 0;
}