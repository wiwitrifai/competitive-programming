#include <bits/stdc++.h>

using namespace std;

void solve() {
  int a, b, c, d;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  if (a <= b) {
    printf("%d\n", b);
    return;
  };
  a -= b;
  if (d >= c) {
    puts("-1");
    return;
  }
  int x = c - d;
  int need = (a + x - 1) / x;
  long long ans = b + 1LL * need * c;
  printf("%lld\n", ans);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
