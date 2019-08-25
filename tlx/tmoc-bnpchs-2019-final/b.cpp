#include <bits/stdc++.h>

using namespace std;

void solve() {
  int a, b;
  scanf("%d %d", &a, &b);
  double y = a + b, x = 2 * a;
  double ans = sqrt(y * y - (double)x * x / 3) + y;
  printf("%.6lf\n", ans);
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
