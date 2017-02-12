#include <bits/stdc++.h>

using namespace std;

long long ext_euclid(long long a, long long b, long long &x, long long &y) {
  if (a == 0) {
    x = 0, y = 1;
    return b;
  }
  long long d = ext_euclid(b % a, a, x, y);
  // b = a p + q
  // q x + a y = d
  // (a p + q) x + a * (y-px) = d
  long long nx = y - (b/a) * x, ny = x;
  x = nx, y = ny;
  return d;
}

int main() {
  long long a, b, d, x, y;
  cin >> a >> b >> d;
  long long g = ext_euclid(a, b, x, y);
  if (d % g)
    puts("-1");
  else {
    d /= g;
    x *= d;
    y *= d;
    a /= g;
    b /= g;
    // ax + by = g
    // a(x + b/g*k) + b(y - a/g*k)
    bool ok = 1;
    long long ans = abs(x) + abs(y);
    long long k = x/b;
    x -= b * k, y += a * k;
    ans = min(ans, abs(x) + abs(y));
    while (x < 0) {
      ans = min(ans, abs(x) + abs(y));
      x += b;
      y -= a;
    }
    ans = min(ans, abs(x) + abs(y));
    while (x > 0) {
      ans = min(ans, abs(x) + abs(y));
      x -= b;
      y += a;
    }
    ans = min(ans, abs(x) + abs(y));


    k = y/a;
    x += b * k, y -= a * k;
    ans = min(ans, abs(x) + abs(y));
    while (y > 0) {
      ans = min(ans, abs(x) + abs(y));
      x += b;
      y -= a;
    }
    ans = min(ans, abs(x) + abs(y));
    while (y < 0) {
      ans = min(ans, abs(x) + abs(y));
      x -= b;
      y += a;
    }
    ans = min(ans, abs(x) + abs(y));
    printf("%lld\n", ans);
  }
  return 0;
}