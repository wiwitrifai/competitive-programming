#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
  return a ? gcd(b % a, a) : b;
}

int main() {
  long long a, b, c, d;
  scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
  long long ans = 0;
  for (int p = 1; p < 1000; ++p) {
    for (int q = 1; p + q < 1000; ++q) {
      int g = gcd(p, q);
      if (g > 1) continue;
      long long lo = max((a + p - 1) / p, (c + q - 1) / q);
      long long hi = min(b / p, d / q);
      if (lo <= hi)
        ans += hi - lo + 1;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
