#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

const int N = 1e6 + 6;

long long fac[N], inv[N];

long long P(int n, int k) {
  return fac[n] * inv[k] % mod;
}

int main() {
  fac[0] = 1;
  for (int i = 1; i < N; ++i)
    fac[i] = fac[i-1] * i % mod;
  inv[N-1] = powmod(fac[N-1], mod-2);
  for (int i = N-2; i >= 0; --i)
    inv[i] = inv[i+1] * (i+1) % mod;
  int n;
  scanf("%d", &n);
  // if (n == 1) {
  //   puts("1");
  //   return 0;
  // }
  long long ans = 1;
  for (int i = 0; i < n; ++i) {
    long long cnt = P(n, i) - P(n, i+1);
    cnt %= mod;
    if (cnt < 0) cnt += mod;
    ans = (ans + cnt * (n-i)) % mod;
  }
  if (ans < 0) ans += mod;
  printf("%lld\n", ans);
  return 0;
}