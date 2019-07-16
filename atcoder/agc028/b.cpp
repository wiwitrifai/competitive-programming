#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, mod = 1e9 + 7;

int a[N];
long long fac[N], inv[N];
long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

long long C(int n, int k) {
  if (k < 0 || n < k || n < 0)
    return 0;
  return (fac[n] * inv[k] % mod) * inv[n-k] % mod;
}
long long s[N];

int main() {
  fac[0] = 1;
  for (int i = 1; i < N; ++i)
    fac[i] = 1LL * fac[i-1] * i % mod;
  inv[N-1] = powmod(fac[N-1], mod-2);
  for (int i = N-2; i >= 0; --i)
    inv[i] = inv[i+1] * (i+1) % mod;
  int n;
  scanf("%d", &n);
  s[0] = 0;
  for (int i = 1; i < n; ++i) {
    long long now = (fac[i] * fac[n-i-1] % mod) * C(n, i+1) % mod;
    s[i] = (s[i-1] + now) % mod;
  }
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    long long cnt = (fac[n] + s[i] + s[n-1-i]) % mod;
    scanf("%d", a+i);
    ans = (ans + cnt * a[i]) % mod;
  }
  ans %= mod;
  if (ans < 0) ans += mod;
  printf("%lld\n", ans);
  return 0;
}