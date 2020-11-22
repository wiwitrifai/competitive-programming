#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  scanf("%d", &n);
  int ans = n-1;
  if ((n & 1)) {
    ans = min(ans, 3);
  } else {
    ans = min(ans, 2);
  }
  printf("%d\n", ans);
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
