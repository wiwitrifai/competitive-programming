#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

const int N = 1e6 + 6;

long long fac[N], inv[N], ifac[N];

long long C(int n, int k) {
  if (n < k || k < 0 || n < 0) return 0;
  return (fac[n] * ifac[k] % mod) * ifac[n-k] % mod;
}

long long cat(int n) {
  return C(2 * n, n) * inv[n+1] % mod;
}

int main() {
  fac[0] = ifac[0] = inv[0] = 1;
  for (int i = 1; i < N; ++i) {
    fac[i] = fac[i-1] * i % mod;
    inv[i] = powmod(i, mod - 2);
    ifac[i] = ifac[i-1] * inv[i] % mod;
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    n /= 2;
    long long sum = 0;
    for (int i = 0; i <= k; ++i) {
      long long sisa = n - 2 * i;
      if (sisa < 0) break;
      long long cur = C(n, i);
      long long oth = i > 0 ? C(n, i-1) : 0;
      cur = (cur + mod - oth) % mod;
      sum = (sum + cur * cur) % mod; 
    }
    long long ans = sum * powmod(cat(n), mod-2) % mod;
    ans %= mod;
    if (ans < 0) ans += mod;
    printf("%lld\n", ans);
  }
  return 0;
}