/**
 *  ACM ICPC Regional Jakarta 2016 - D : Pay Day
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5, mod = 1e9 + 7;

long long fac[N], inv[N];

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1) r = r * b % mod;
  return r;
}

long long C(int n, int k) {
  if (n < k || k < 0) return 0;
  return (fac[n] * inv[k] % mod) * inv[n-k] % mod;
}

int main() {
  fac[0] = inv[0] = 1;
  for (int i = 1; i < N; i++) {
    fac[i] = fac[i-1] * i % mod;
    inv[i] = powmod(fac[i], mod - 2);
  }
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
      int c;
      scanf("%d", &c);
      while (c--)
        scanf("%*d");
    }
    printf("Case #%d: %lld\n",tc, C(m-1, n-1));
  }
  return 0;
}