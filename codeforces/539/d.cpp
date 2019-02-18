#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6, mod = 1e9 + 7;

long long powmod(long long b, long long p) {
  long long r= 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

long long fac[N], inv[N];
long long C(int n, int k) {
  if (n < 0 || k < 0 || n-k < 0)
    return 0;
  return (fac[n] * inv[k] % mod) * inv[n-k] % mod;
}

long long F(int n, int r) {
  if (n == 0)
    return 1;
  return 1LL * r * powmod(n+r, n-1) % mod;
}

int main() {
  fac[0] = inv[0] = 1;
  for (int i = 1; i < N; ++i) {
    fac[i] = fac[i-1] * i % mod;
    inv[i] = powmod(fac[i], mod - 2);
  }
  int n, m;
  scanf("%d %d %*d %*d", &n, &m);
  long long ans = 0;
  for (int e = 1; e <= n-1; ++e) {
    long long cur = C(m-1, e-1) * powmod(m, n-1-e) % mod;
    cur = (cur * fac[e-1]) % mod;
    cur = (cur * C(n-2, e-1)) % mod;
    cur = (cur * F(n-e-1, e+1)) % mod;
    ans = (ans + cur) % mod;
    // cerr << e << " " << cur << endl;
  }
  ans %= mod;
  if (ans < 0)
    ans += mod;
  printf("%lld\n", ans);
  return 0;
}