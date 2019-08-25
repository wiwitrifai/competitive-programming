#include <bits/stdc++.h>

using namespace std;

void solve() {
  long long n;
  scanf("%lld", &n);
  long long x = n, y = n+1;
  if (x & 1)
    y /= 2;
  else
    x /= 2;
  long long ans = x * y;
  printf("%lld\n", ans);
}

int main() {
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; ++tc) {
    printf("Case #%d: ", tc);
    solve();
  }
  return 0;
}
