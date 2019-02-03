#include <bits/stdc++.h>

using namespace std;

long long mulmod(long long a, long long b, long long mod) {
  a %= mod;
  if (a < 0) a += mod;
  b %= mod;
  if (b < 0) b += mod;
  long long r = 0;
  for (; b; b >>= 1, a = (a + a)) {
    if (a >= mod)
      a -= mod;
    if (b & 1) {
      r = (r + a);
      if (r >= mod)
        r -= mod;
    }
  }
  return r;
}

long long powmod(long long b, long long p, long long mod) {
  long long r = 1;
  for (; p; p >>= 1, b = mulmod(b, b, mod))
    if (p & 1)
      r = mulmod(r, b, mod);
  return r;
}

const int mod = 1e9 + 7;

long long gcd(long long a, long long b) {
  return a ? gcd(b % a, a) : b;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long a, b, n;
    scanf("%lld %lld %lld", &a, &b, &n);
    long long m = abs(a-b);
    long long ans = 0;
    if (m == 0)
      ans = (powmod(a, n, mod) + powmod(b, n, mod)) % mod;
    else {
      long long r = powmod(a, n, m) + powmod(b, n, m);
      ans = gcd(r, m) % mod;
    }
    printf("%lld\n", ans);
  }
  return 0;
}