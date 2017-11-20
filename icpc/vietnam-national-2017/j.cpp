#include <bits/stdc++.h>

using namespace std;

const int ITER = 500;

double calc(double h, int x, int y) {
  if (2 * h > x || 2 * h > y) return 0;
  return h * (x - 2 * h) * (y - 2 * h);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int x, y;
    scanf("%d %d", &x, &y);
    double lo = 0, hi = min(x, y)/2.0, ans = 0;
    for (int it = 0; it < ITER; it++) {
      double le = (lo + lo + hi) / 3.0, ri = (lo + hi + hi) / 3.0;
      double vle = calc(le, x, y), vri = calc(ri, x, y);
      ans = max(ans, max(vle, vri));
      if (vle < vri)
        lo = le;
      else
        hi = ri;
    }
    printf("%.12lf\n", ans);
  }
  return 0;
}