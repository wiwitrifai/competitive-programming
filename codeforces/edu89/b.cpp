#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, x, m;
  scanf("%d %d %d", &n, &x, &m);
  int xl = x, xr = x;
  for (int i = 0; i < m; ++i) {
    int l, r;
    scanf("%d %d", &l, &r);
    if (xl <= r && l <= xr) {
      xl = min(xl, l);
      xr = max(xr, r);
    }
  }
  printf("%d\n", xr-xl+1);
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
