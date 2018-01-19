#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    int ma = -1e9;
    for (int i = 0; i < n; ++i)
      scanf("%d", a+i), ma = max(ma, a[i]);
    if (ma <= 0) {
      printf("%d\n", ma);
      continue;
    }
    long long ans = ma;
    {
      long long now = 0;
      for (int i = 0; i < n * min(k, 2); ++i) {
        if (now < 0) now = 0;
        now += a[i % n];
        ans = max(ans, now);
      }
    }
    if (k > 2) {
      long long tot = 0;
      for (int i = 0; i < n; ++i)
        tot += a[i];
      if (tot < 0) tot = 0;
      long long fr = 0, bc = 0;
      long long now = 0;
      for (int i = 0; i < n; ++i) {
        now += a[i];
        if (fr < now) fr = now;
      }
      now = 0;
      for (int i = n-1; i >= 0; --i) {
        now += a[i];
        if (bc < now) bc = now;
      }
      ans = max(ans, fr + bc + tot * (k-2));
    }
    printf("%lld\n", ans);
  }
  return 0;
}