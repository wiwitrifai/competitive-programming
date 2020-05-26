#include <bits/stdc++.h>

using namespace std;

const long double PI = acos(-1);
const int ITER = 100;

void solve() {
  int n;
  scanf("%d", &n);
  long double a = PI / n;
  // long double b = (PI - a) * 0.5;
  long double x = 1.0 / sin(a * 0.5);
  long double ka = (n / 2) * a;
  long double s = x * sin((PI * 0.5 + ka) * 0.5);
  printf("%.9lf\n", (double)s);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
