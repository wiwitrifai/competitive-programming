#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e18 + 1e9;

void solve() {
  int n, k;
  scanf("%d %d", &n, &k);
  ++k;
  long long ans = inf;
  for (int d = 0; d < 10; ++d) {
    int cur = 0;
    int lef = 0, rig = 0;
    bool carry = false;
    for (int i = 0; i < k; ++i) {
      if (carry)
        ++rig;
      else
        ++lef;
      int dig = (d + i) % 10;
      if (dig == 9)
        carry = true;
      cur += dig;
    }
    if (n < cur) continue;
    for (int nine = 0; cur + rig <= n; ++nine) {
      int sisa = n - cur - rig;
      if ((sisa % k) == 0) {
        sisa /= k;
        long long now = min(sisa, 8);
        sisa -= now;
        long long ten = 10;
        while (sisa) {
          int rem = min(sisa, 9);
          now += ten * rem;
          ten *= 10;
          sisa -= rem;
        }
        for (int i = 0; i < nine; ++i) {
          now = now * 10 + 9;
        }
        now = now * 10 + d;
        ans = min(ans, now);
      }
      cur += 9 * lef;
    }
  }
  if (ans >= inf)
    ans = -1;
  printf("%lld\n", ans);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
