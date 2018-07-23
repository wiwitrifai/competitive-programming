#include <bits/stdc++.h>

using namespace std;

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    long long a, b;
    scanf("%lld %lld", &a, &b);
    long long mul = 1LL * a * b - 1;
    if (a > b) swap(a, b);
    long long ans = a-1;
    long long le = a-1, ri = b-1;
    while (le < ri) {
      long long mid = (le + ri + 1) >> 1;
      long long k = (mid + a + 1) / 2;
      long long c = min(max(k - a, 1LL), mid);
      bool ok = 1;
      for (int i = -2; i <= 2; ++i) {
        long long d = c + i;
        if (d <= 0 || d > mid) continue;
        long long x = a + d, y = mid + 1 - d;
        if (x * y > mul) {
          ok = 0;
          break;
        }
      }
      if (ok)
        le = mid;
      else
        ri = mid-1;
    }
    ans += ri;
    printf("%lld\n", ans);
  }
  return 0;
}