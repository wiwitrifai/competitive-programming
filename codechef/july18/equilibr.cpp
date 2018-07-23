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

int main() {
  int n;
  scanf("%d %*d", &n);
  long long q = powmod(2, n-1), p = (q - n) % mod;
  p = p * powmod(q, mod-2) % mod;
  if (p < 0) p += mod;
  printf("%lld\n", p);
  return 0;
}