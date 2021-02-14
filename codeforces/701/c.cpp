#include <bits/stdc++.h>

using namespace std;

void solve() {
  int x, y;
  scanf("%d %d", &x, &y);
  long long ans = 0;
  for (int r = 1; 1LL * r * r <= x; ++r) {
    int c = min(x / (int)r, y+1);
    if (c > r+1) {
      ans += c - r-1;
    }
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
