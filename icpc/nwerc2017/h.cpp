#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    long long a[3], d;
    scanf("%lld %lld %lld %lld", a, a+1, a+2, &d);
    sort(a, a+3);
    long long ans = 0;
    for (long long i = a[0], j = 0; i <= a[0]+d && j < 1000; ++i, ++j) {
      long long aa[3];
      long long need = 0;
      for (int k = 0; k < 3; ++k) {
        aa[k] = max(a[k], i);
        need += aa[k] - a[k];
      }
      if (need > d) break;
      aa[2] += d-need;
      long long cur = 7LL * i;
      for (int k = 0; k < 3; ++k) {
        cur += aa[k] * aa[k];
      }
      ans = max(ans, cur);
    }
    printf("%lld\n", ans);
  }
  return 0;
}