#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, mod = 1e9 + 7;
const long long inf = 1e18;

int a[N], n;

int main() {
  scanf("%d", &n);
  long long p, q, s = 0, ans = -inf;
  p = q = inf;
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
    s += a[i];
    if (i & 1) {
      ans = max(ans, s - p);
      p = min(p, s);
    }
    else {
      if (i > 0)
        ans = max(ans, s - q);
      q = min(q, s);
    }
  }
  printf("%lld\n", ans);

  return 0;
}