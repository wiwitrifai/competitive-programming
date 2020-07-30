#include <bits/stdc++.h>

using namespace std;

void solve() {
  int l, r;
  scanf("%d %d", &l, &r);
  int x = r / 2, y = x * 2;
  if (min(x, y) < l || max(x, y) > r) {
    puts("-1 -1");
    return;
  }
  printf("%d %d\n", x, y);
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
