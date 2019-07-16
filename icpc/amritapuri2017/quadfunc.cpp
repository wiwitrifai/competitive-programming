#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long a, b, c, d, e, f, l, r;
    scanf("%lld %lld %lld", &a, &b, &c);
    scanf("%lld %lld %lld", &d, &e, &f);
    scanf("%lld %lld", &l, &r);
    a -= d, b -= e, c -= f;
    long long up = abs(a * 2 * (r * r * r - l * l * l) + b * 3 * (r * r - l * l) + c * 6 * (r - l));
    long long down = 6;
    if ((up % 2) == 0)
      up /= 2, down /= 2;
    if ((up % 3) == 0)
      up /= 3, down /= 3;
    printf("%lld/%lld\n", up, down);
  }
  return 0;
}