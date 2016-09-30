#include <bits/stdc++.h>

using namespace std;

// a-b = i
// a = i+b;
const int mod = 1e9;

int main() {
  int a, b, c, d;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  long long ans = 0;
  for (int i = -1e6; i <= 1e6; i++) {
    int l1 = max(1, 1+i), r1 = min(a, b+i), l2 = max(1, 1+i), r2 = min(c, d+i);
    ans += 1LL * max(r1-l1 + 1, 0) * max(r2-l2+1, 0);
  }
  ans *= 4;
  ans %= mod;
  if ((ans % 4) == 0)
    ans /= 4;
  else
    ans -= ans % 4;
  printf("%lld\n", ans);
  return 0;
}