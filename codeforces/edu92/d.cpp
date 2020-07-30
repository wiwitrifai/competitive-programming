#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, k;
  long long l, r, x, y;
  scanf("%d %d %lld %lld %lld %lld", &n, &k, &l, &r, &x, &y);
  long long low = min(l, x), hig = max(r, y);
  long long intl = max(l, x), intr = min(r, y);
  long long initial = intl > intr ? 0 : n * (intr - intl);
  long long waiting = 0, from = 0;
  if (intl <= intr) {
    from = intr - intl;
  } else {
    waiting = intl - intr;
  }
  if (initial >= k) {
    puts("0");
    return;
  }
  long long ans = -1;
  for (int i = 1; i <= n; ++i) {
    long long cur = waiting * i;
    long long need = k - initial;
    long long maxi = (hig - low) - from;
    if (maxi * i < need) {
      cur += maxi * i;
      need -= maxi * i;
      cur += need * 2;
    } else {
      cur += need;
    }
    if (ans < 0 || cur < ans)
      ans = cur;
  }
  printf("%lld\n", ans);
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
