#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, mod = 1e9 + 7;

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}
long long fac[N], inv[N];

long long C(int n, int k) {
  if (n < 0 || k < 0 || n < k) return 0;
  return ((fac[n] * inv[k] % mod) * inv[n-k] % mod);
}

int main() {
  fac[0] = inv[0] = 1;
  for (int i = 1; i < N; ++i) {
    fac[i] = 1LL * fac[i-1] * i % mod;
    inv[i] = powmod(fac[i], mod - 2);
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    n -= k;
    n /= 2;
    long long ans = 0;
    for (int i = 0; i <= n; ++i) {
      ans = (ans + C(i+k-1, k-1)) % mod;
    }
    printf("%lld\n", ans);
  }
  return 0;
}