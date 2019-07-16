#include <bits/stdc++.h>

using namespace std;

const long double eps = 1e-7;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long d, x, y, k, a;
    scanf("%lld %lld %lld %lld %lld", &d, &x, &y, &k, &a);
    if (a > k) {
      puts("YA");
      continue;
    }
    long long A = a * a - k * k;
    long long B = 2LL * k * x ;
    long long C = - (x * x + (y + d) * (y + d));
    long double low = (long double)(d + y) / a;
    if (a < k) {
      long double t = -(long double)(B / 2) / A;
      // if (t < low)
      //   t = low;
      long double res = t * t * A + t * B + C;
      if (res >= -eps)
        puts("YA");
      else
        puts("TIDAK");
      continue;
    }
    else {
      if (B > 0)
        puts("YA");
      else
        puts("TIDAK");
    }
  }
  return 0;
}