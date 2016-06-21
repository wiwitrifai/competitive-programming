#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
  return a ? gcd(b % a, a) : b;
}

long long lcm(long long a, long long b) {
  return (a / gcd(a, b)) * b;
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    long long a, b, c, d;
    scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
    long long g = gcd(a, b);
    a /= g; b /= g;
    g = gcd(c, d);
    c /= g; d /= g;
    long long n = gcd(a, c), m = lcm(b, d);
    g = gcd(n, m);
    n /= g; m /= g;
    long long x = lcm(a, c), y = gcd(b, d);
    g = gcd(x, y);
    x /= g; y /= g;
    printf("%lld/%lld %lld/%lld\n", n, m, x, y);
  }

  return 0;
}