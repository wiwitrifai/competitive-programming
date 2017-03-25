#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long ext_euclid(long long a, long long b, long long &x, long long &y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  long long d = ext_euclid(b % a, a, x, y);
  long long yy = x, xx = y-(b/a) * yy;
  x = xx, y = yy;
  return d;
}
long long x[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    map< long long, int > mp;
    for (int i = 0; i < n; i++) {
      scanf("%lld", &x[i]);
    }
    long long a, b, y, z;
    scanf("%lld %lld %lld %lld", &a, &b, &z, &y);
    long long p, q, d = ext_euclid(a, b, p, q), ab = a+b, pq = p-q;
    pq %= ab;
    if (pq < 0) pq += ab;
    bool ok = 0;
    for (int i = 0; i < n; i++) {
      long long diff = z-x[i];
      diff = (diff * pq) % ab;
      if (diff < 0) diff += ab;
      int cnt = ++mp[diff];
      if (cnt >= y) {
        ok = 1;
        break;
      }
    }
    puts(ok ? "YES" : "NO");
  }
  return 0;
}