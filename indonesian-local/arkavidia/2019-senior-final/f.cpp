#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long powmod(long long b, long long p, long long m) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % m)
    if (p & 1)
      r = r * b % m;
  return r;
}

long long get_n_digit(long long n, long long a, long long b) {
  long long r = powmod(10, n, b) * a % b;
  return ((a * powmod(10, n, mod) - r) % mod) * powmod(b, mod-2, mod) % mod;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, a, b, q;
    scanf("%d %d %d %d", &n, &a, &b, &q);
    while (q--) {
      int l, r;
      scanf("%d %d", &l, &r);
      long long ans = (get_n_digit(r, a, b) - get_n_digit(l-1, a, b) * powmod(10, r-l+1, mod)) % mod;
      if (ans < 0) ans += mod;
      printf("%lld\n", ans);
    }
  }
  return 0;
}