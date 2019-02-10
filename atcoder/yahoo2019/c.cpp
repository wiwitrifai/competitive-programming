#include <bits/stdc++.h>

using namespace std;

int main() {
  int k, a, b;
  scanf("%d %d %d", &k, &a, &b);
  long long ans = k+1;
  if (b - a > 2 && k >= a-1) {
    k -= a - 1;
    long long cur = a;
    if (k & 1)
      ++cur;
    cur += 1LL * (k / 2) * (b - a);
    ans = max(ans, cur);
  }
  printf("%lld\n", ans);
  return 0;
}