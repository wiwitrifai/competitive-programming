#include <bits/stdc++.h>

using namespace std;

void solve() {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  int ans1 = (a < c) ? 1 : -1;
  int ans2 = 1LL * a * b > c ? b : -1;
  printf("%d %d\n", ans1, ans2);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
