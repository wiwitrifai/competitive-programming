#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int xa, xb, ya, yb;
    scanf("%d %d %d %d", &xa, &ya, &xb, &yb);
    int dx = abs(xb - xa), dy = abs(yb - ya);
    printf("%lld\n", 1LL * dx * dy + 1);
  }
  return 0;
}
