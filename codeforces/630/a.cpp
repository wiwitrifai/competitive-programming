#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int x, y, xa, ya, xb, yb;
    scanf("%d %d %d %d %d %d", &x, &y, &xa, &ya, &xb, &yb);
    int xx = x + b - a, yy = y + d - c;
    bool ok = 1;
    if (xx < xa || xx > xb)
      ok = 0;
    if (yy < ya || yy > yb)
      ok = 0;
    if (abs(a) + abs(b) > 0 && xa == xb)
      ok = 0;
    if (abs(c) + abs(d) > 0 && ya == yb)
      ok = 0;
    puts(ok ? "Yes" : "No");
  }
  return 0;
}
