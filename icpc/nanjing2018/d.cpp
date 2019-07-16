#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const int ITER = 33;

double x[N][3];
double xl[3], xh[3];
double lo[3], hi[3];
double cur[3];

double dist(double a[3], double b[3]) {
  double ret = 0;
  for (int i = 0; i < 3; ++i) {
    double dx = a[i] - b[i];
    ret += dx * dx;
  }
  return ret;
}

int n;
double solve(int c) {
  if (c == 3) {
    double ret = dist(cur, x[0]);
    for (int i = 1; i < n; ++i) {
      ret = max(ret, dist(cur, x[i]));
    }
    return ret;
  }
  lo[c] = xl[c], hi[c] = xh[c];
  double ans = 1e18;
  for (int i = 0; i < ITER; ++i) {
    double mid1 = (lo[c] + lo[c] + hi[c]) / 3;
    double mid2 = (lo[c] + hi[c] + hi[c]) / 3;
    cur[c] = mid1;
    double val1 = solve(c+1);
    cur[c] = mid2;
    double val2 = solve(c+1);
    ans = min(ans, min(val1, val2));
    if (val1 < val2)
      hi[c] = mid2;
    else
      lo[c] = mid1;
  }
  return ans;
}

int main() {
  for (int i = 0; i < 3; ++i) {
    xl[i] = 1e6;
    xh[i] = -1e6;
  }
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 3; ++j) {
      int z;
      scanf("%d", &z);
      x[i][j] = z;
      xl[j] = min(xl[j], (double)x[i][j]);
      xh[j] = max(xh[j], (double)x[i][j]);
    }
  }
  printf("%.20lf\n", sqrt(solve(0)));

  return 0;
}