#include <bits/stdc++.h>

using namespace std;

const long double PI = acos(-1);

void solve() {
  int a, b, r, d;
  scanf("%d %d %d %d", &a, &b, &r, &d);
  double x = atan2(b, a + r);
  double rad = d * PI / 180;
  double ans = 0;
  if (x <= rad) {
    ans = sqrt(b * b + (a + r) * (a + r)) - r;
  }
  else {
    double c = sqrt(b * b + (a + r) * (a + r));
    ans = cos(x-rad) * c - r;
  }
  printf("%.12lf\n", ans);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
