#include <bits/stdc++.h>

using namespace std;

double dist(int x, int y, int p, int q) {
  int dx = x - p, dy = y - q;
  return sqrt((double)dx * dx + (double)dy * dy);
}

int main() {
  int x, y, a, b, c, d;
  scanf("%d %d %d %d %d %d", &x, &y, &a, &b, &c, &d);
  double ans = dist(x, y, a, b);
  ans = min(ans, dist(x, y, a, d));
  ans = min(ans, dist(x, y, c, b));
  ans = min(ans, dist(x, y, c, d));
  if (a <= x && x <= c) {
    ans = min(ans, (double)min(abs(y-b), abs(y-d)));
  }
  if (b <= y && y <= d) {
    ans = min(ans, (double)min(abs(x-a), abs(x-c)));
  }
  printf("%.3lf\n", ans);
  return 0;
}
