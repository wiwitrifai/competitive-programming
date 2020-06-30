#include <bits/stdc++.h>

using namespace std;

void solve() {
  int a, b;
  scanf("%d %d", &a, &b);
  int ans = min(a, b);
  ans = min(ans, (a + b) / 3);
  printf("%d\n", ans);
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
