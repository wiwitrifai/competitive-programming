#include <bits/stdc++.h>

using namespace std;

const int N = 5e6 + 5, mod = 998244353;

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

int fact[N], inv[N];

long long C(int n, int k) {
  if (k < 0 || n < k)
    return 0;
  return 1LL * (1LL * fact[n] * inv[k] % mod) * inv[n-k] % mod;
}

int main() {
  fact[0] = inv[0] = 1;
  for (int i = 1; i < N; ++i) {
    fact[i] = 1LL * i * fact[i-1] % mod;
  }
  inv[N-1] = powmod(fact[N-1], mod-2);
  for (int i = N-2; i > 0; --i) {
    inv[i] = inv[i+1] * 1LL * (i + 1) % mod;
  }
  int n;
  scanf("%d", &n);
  n /= 2;
  long long ans = powmod(3, 2 * n);
  long long sum = 0, pw2 = 2, pw = powmod(2, n), inv2 = inv[2];
  for (int a = 1; a <= n; ++a) {
    pw = (pw * inv2) % mod;
    sum = (sum + 1LL * C(n, n+1-a) * pw2) % mod;
    ans = (ans - sum * (C(n, a) * pw % mod)) % mod;
    pw2 = (pw2 * 2) % mod;
  }
  if (ans < 0)
    ans += mod;
  printf("%lld\n", ans);
  return 0;
}
