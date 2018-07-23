#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

int a[N], b[N], c[N];

int main() {
  int d, na, nb, nc;
  while (scanf("%d %d %d %d", &d, &na, &nb, &nc) == 4) {
    for (int i = 0; i < na; ++i)
      scanf("%d", a+i);
    for (int i = 0; i < nb; ++i)
      scanf("%d", b+i);
    for (int i = 0; i < nc; ++i)
      scanf("%d", c+i);
    long long ans = 0;
    for (int i = 0; i < na; ++i) {
      int bb = upper_bound(b, b+nb, a[i]) - lower_bound(b, b+nb, a[i]-d);
      int cc = upper_bound(c, c+nc, a[i]) - lower_bound(c, c+nc, a[i]-d);
      ans += 1LL * bb * cc;
    }
    for (int i = 0; i < nb; ++i) {
      int aa = lower_bound(a, a+na, b[i]) - lower_bound(a, a+na, b[i]-d);
      int cc = upper_bound(c, c+nc, b[i]) - lower_bound(c, c+nc, b[i]-d);
      ans += 1LL * aa * cc;
    }
    for (int i = 0; i < nc; ++i) {
      int aa = lower_bound(a, a+na, c[i]) - lower_bound(a, a+na, c[i]-d);
      int bb = lower_bound(b, b+nb, c[i]) - lower_bound(b, b+nb, c[i]-d);
      ans += 1LL * aa * bb;
    }
    printf("%lld\n", ans);
  }
  return 0;
}