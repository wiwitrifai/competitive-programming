/**
  IEEExtreme Programming Contest 10
  Problem : Ellipse Art
  Solver  : Wiwit Rifa'i
  Status  : Accepted
*/

#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-7;

int n;
int x[50][2], y[50][2], rr[50];
int tot = 0;

int solve(double l, double r, double w, double h, int depth = 0) {
  if (depth == 9) {
    bool ok = false;
    double c = (l+r)/2, d = (w + h)/2;
    for (int i = 0; i < n; i++) {
      double sum = 0;
      for (int j = 0; j < 2; j++) {
        double dx = c - x[i][j], dy = d - y[i][j];
        sum += sqrt(dx * dx + dy * dy);
      }
      if (sum + eps <= rr[i]) {
        ok = true;
        break;
      }
    }
    tot++;
    return ok;
  }
  else {
    double m1 = (l + r)/2.0, m2 = (h + w)/2;
    return solve(l, m1, w, m2, depth+1) + solve(l, m1, m2, h, depth+1) + solve(m1, r, m2, h, depth+1) + solve(m1, r, w, m2, depth+1);
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d %d %d %d %d", &x[i][0], &y[i][0], &x[i][1], &y[i][1], rr+i);
    }
    tot = 0;
    int res = solve(-50, 50, -50, 50);
    printf("%d%%\n", 100 - int(((double)res * 100)/tot + 0.5));
  }
  return 0;
}