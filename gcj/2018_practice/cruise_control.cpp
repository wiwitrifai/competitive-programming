#include <bits/stdc++.h>

using namespace std;


int main() {
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; ++tc) {
    int n, d;
    scanf("%d %d", &d, &n);
    long double time = 0;
    for (int i = 0; i < n; ++i) {
      int k, s;
      scanf("%d %d", &k, &s);
      long double cur = (long double)(d - k) / s;
      if (i)
        time = max(time, cur);
      else
        time = cur;
    }
    printf("Case #%d: %.10lf\n", tc, (double)(d / time));
  }
  return 0;
}