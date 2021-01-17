#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  scanf("%d", &n);
  long long tot = 2 * n;
  tot *= tot;
  tot /= 2;
  int ans = 0;
  for (int i = 0; i <= tot/3; ++i) {
    int x = i, y  = min(tot - x * 3, (tot - x) / 3);
    ans = max(ans, x + y);
  }
  printf("%d\n", ans);
}

int main() {
  int tc = 1;
  // scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
