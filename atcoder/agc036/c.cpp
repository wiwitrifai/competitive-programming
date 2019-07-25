#include <bits/stdc++.h>

using namespace std;

const int N = 3e6 + 6, mod = 998244353;

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

int fact[N], inv[N];

long long C(int n, int k) {
  if (n < 0 || k < 0 || n < k)
    return 0;
  return (1LL * fact[n] * inv[k] % mod) * inv[n-k] % mod;
}

int main() {
  fact[0] = inv[0] = 1;
  for (int i = 1; i < N; ++i) {
    fact[i] = 1LL * i * fact[i-1] % mod;
  }
  inv[N-1] = powmod(fact[N-1], mod-2);
  for (int i = N-2; i > 0; --i) {
    inv[i] = 1LL * (i+1) * inv[i+1] % mod;
  }
  int n, m;
  scanf("%d %d", &n, &m);
  long long ans = C(m * 3 + n-1, n-1);
  for (int i = 2 * m + 1; i <= 3 * m; ++i) {
    int sisa = 3 * m - i;
    long long cur = 1LL * C(sisa + n-2, n-2) * n % mod;
    ans = (ans - cur) % mod;
  }
  for (int i = m+1; i <= n; ++i) {
    int sisa = 3 * m - i;
    if (sisa & 1) continue;
    sisa /= 2;
    long long cur = 1LL * C(n, i) * C(sisa + n-1, n-1) % mod;
    ans = (ans - cur) % mod;
  }
  if (ans < 0)
    ans += mod;
  printf("%lld\n", ans);
  return 0;
}
