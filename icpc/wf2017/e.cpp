#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
const long long inf = 1e18;

int d[N], s[N], n, t;

double solve(double c) {
  double sum = 0;
  for (int i = 0; i < n; i++) {
    sum += (double) d[i] / (s[i] + c);
  }
  return sum;
}

int main() {
  scanf("%d %d", &n, &t);
  double l = -inf;
  for (int i = 0; i < n; i++) {
    scanf("%d %d", d + i, s + i);
    l = max(l, (double) -s[i]);
  }
  double r = 1e12;
  double sum = 0;
  //cout << l << endl;
  for (int it = 0; it < 200; it++) {
    double mid = (l + r) / 2;
    if (solve(mid) < t) {
      r = mid;
    } else {
      l = mid;
    }
  }
  printf("%.15f\n", r);
  //cout << solve(3) << endl;
  return 0;
}