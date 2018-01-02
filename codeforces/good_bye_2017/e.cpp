#include <bits/stdc++.h>

using namespace std;

const int M = 1024, mod = 1e9 + 7;

long long dp[M][M];
long long fac[M], inv[M];

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

long long C(int n, int k) {
  if (k < 0 || n < k) return 0;
  return (fac[n] * inv[k] % mod) * inv[n-k] % mod;
}

long long solve(int n, int k) {
  if (n == 0) return 1;
  if (k <= 0) return 0;
  long long & ret = dp[n][k];
  if (ret != -1) return ret;
  ret = 0;
  long long mul = 1;
  for (int i = 0; i * k <= n; ++i) {
    long long cur = solve(n - i * k, k-1) * inv[i] % mod;
    ret = (ret + cur * mul) % mod;
    if (ret < 0) ret += mod;
    mul = mul * C(n - i * k, k) % mod;
  }
  return ret;
}

long long val[M];
char s[M];

int main() {
  fac[0] = inv[0] = 1;
  for (int i = 1; i < M; ++i) {
    fac[i] = fac[i-1] * i % mod;
    inv[i] = powmod(fac[i], mod - 2);
  }
  memset(dp, -1, sizeof dp);
  int n, m;
  scanf("%d %d", &m, &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s);
    for (int j = 0; j < m; ++j) if (s[j] == '1')
      val[j] |= 1LL << i;
  }
  sort(val, val+m);
  int cnt = 0;
  long long cur = val[0];
  long long ans = 1;
  for (int i = 0; i < m; ++i) {
    if (cur != val[i]) {
      ans = ans * solve(cnt, cnt) % mod;
      cnt = 0;
      cur = val[i];
    }
    ++cnt;
  }
  if (cnt) {
    ans = ans * solve(cnt, cnt) % mod;
  }
  cout << ans << endl;
  return 0;
}