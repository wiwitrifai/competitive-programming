#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod) {
    if (p & 1)
      r = r * b % mod;
  }
  return r;
}

int main() {
  int n, m, k, r, c;
  scanf("%d %d %d %d %d", &n, &m, &k, &r, &c);
  int ax, ay, bx, by;
  scanf("%d %d %d %d", &ax, &ay, &bx, &by);
  printf("%lld\n", powmod(k, 1LL * n * m - 1LL * r * c * (ax != bx || ay != by)));
  return 0;
}
