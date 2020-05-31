#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5, mod = 998244353;

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

long long fac[N], inv[N];

long long C(int n, int k) {
  if (n < 0 || k < 0 || n < k)
    return 0;
  return (fac[n] * inv[k] % mod) * inv[n-k] % mod;
}

int main() {
  fac[0] = inv[0] = 1;
  for (int i = 1; i < N; ++i) {
    fac[i] = fac[i-1] * i % mod;
    inv[i] = powmod(fac[i], mod - 2);
  }
  int n, k;
  scanf("%d %d", &n, &k);
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    int cnt = n / i;
    if (cnt < k) break;
    long long cur = C(cnt-1, k-1);
    ans = (ans + cur) % mod;
  }
  ans %= mod;
  if (ans < 0)
    ans += mod;
  printf("%lld\n", ans);
  return 0;
}
