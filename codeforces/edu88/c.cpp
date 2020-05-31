#include <bits/stdc++.h>

using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    long long h, c, t;
    scanf("%lld %lld %lld", &h, &c, &t);
    if (t == h) {
      puts("1");
      continue;
    } else if (2LL * t <= c + h) {
      puts("2");
      continue;
    }
    long long ans = 2;
    long long a = (c + h), b = 2;
    long long up = t - c, down = 2LL * t - (c + h);
    {
      long long k = max(up / down, 1LL);
      long long x = k * h + (k-1) * c;
      long long y = 2 * k - 1;
      long long difx = abs(x * b - t * b * y), difa = abs(a * y - t * b * y);
      if (difx == difa) {
        ans = min(ans, 2LL * k - 1);
      } else if (difx < difa) {
        ans = 2LL * k - 1;
        a = x;
        b = y;
      }
    }
    {
      long long k = max(up / down + 1, 1LL);
      long long x = k * h + (k-1) * c;
      long long y = 2 * k - 1;
      long long difx = abs(x * b - t * b * y), difa = abs(a * y - t * b * y);
      if (difx == difa) {
        ans = min(ans, 2LL * k - 1);
      } else if (difx < difa) {
        ans = 2LL * k - 1;
        a = x;
        b = y;
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
