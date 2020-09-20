#include <bits/stdc++.h>

using namespace std;

long long x, y, d; // ax + by = d
void extendedEuclidean(long long a, long long b) {
  if(b == 0) { x = 1; y = 0; d = a; return; }
  extendedEuclidean(b, a % b);
  long long xx, yy;
  xx = y;
  yy = x - (a/b)*y;
  x = xx; y = yy;
}

int main() {
  long long n;
  scanf("%lld", &n);
  if (n == 1) {
    puts("1");
    return 0;
  }
  long long ans = 2 * n - 1;
  for (long long a = 1; a * a <= n; ++a) {
    if (n % a) continue;
    long long b = n / a;
    long long u = a, v = b;
    if (a & 1) {
      u = a, v = b * 2;
      extendedEuclidean(u, v);
      if (d == 1 && x && y) {
        ans = min(ans, min(abs(u * x), abs(v * y)));
      }
    }
    if (b & 1) {
      u = a * 2, v = b;
      extendedEuclidean(u, v);
      if (d == 1 && x && y) {
        ans = min(ans, min(abs(u * x), abs(v * y)));
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}
