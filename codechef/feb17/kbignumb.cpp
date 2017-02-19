#include <bits/stdc++.h>

using namespace std;


long long powmod(long long b, long long p, long long m) {
  long long ret = 1;
  while (p) {
    if (p & 1)
      ret = (ret * b) % m;
    b = (b * b) % m;
    p >>= 1;
  }
  return ret;
}

long long solve(long long x, long long b, long long n, long long m) {
  if (n == 1)
    return x % m;
  long long n2 = n/2;
  long long half = solve(x, b, n2, m);
  long long ret = (half * (powmod(b, n2, m) + 1)) % m;
  if (n & 1)
    ret = (ret + x * powmod(b, n2 * 2, m)) % m;
  if (ret < 0)
    ret += m;
  return ret;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long a, b, n, m;
    scanf("%lld %lld %lld", &a, &n, &m);
    b = 1;
    while (b <= a) b *= 10;
    printf("%lld\n", solve(a, b, n, m));
  }
  return 0;
}