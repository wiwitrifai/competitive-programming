#include <bits/stdc++.h>

using namespace std;

int k, p, x;

double cost(int m) {
  return (double) k / m * p + 1LL * x * m;
}

int main() {
  scanf("%d %d %d", &k, &p, &x);
  int l = 1, r = 1e9;
  while (r - l > 3) {
    int lf = l + (r - l) / 3;
    int rf = r - (r - l) / 3;
    if (cost(lf) < cost(rf)) {
      r = rf;
    } else {
      l = lf;
    }
  }
  double ans = 1e100;
  for (int i = l; i <= r; i++) ans = min(ans, cost(i));
  printf("%.3f\n", ans);
  return 0;
}