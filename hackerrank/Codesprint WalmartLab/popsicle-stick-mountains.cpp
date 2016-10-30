#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 6, mod = 1e9 + 7;

long long powmod(long long b, long long p) {
  long long r = 1;
  while (p) {
    if (p & 1)
      r = (r * b) % mod;
    b = (b * b) % mod;
    p >>= 1;
  }
  return r;
}

long long fac[N], inv[N];
long long C(int n, int k) {
  return (((fac[n] * inv[k]) % mod) * inv[n-k]) % mod;
}

int main() {
  fac[0] = inv[0] = 1;
  for (int i = 1; i < N; i++) {
    fac[i] = (fac[i-1] * i) % mod;
    inv[i] = powmod(fac[i], mod-2);
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    n >>= 1;
    long long ans = 0;
    for (int i = 1; i <= n; i++)
      ans = (ans + C(2 * i, i) * powmod(i+1, mod-2)) % mod;
    printf("%lld\n", ans);
  }
  return 0;
}