#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, LG = 200;
#define x first
#define y second

typedef pair< double, double > point;
point p[N];
double w[N], xmin, xmax, ymin, ymax;
int n;
double calc2(double x, double y) {
  double ret = 0;
  for (int i = 0; i < n; i++) {
    ret += (double)max(fabs(p[i].x-x), fabs(p[i].y-y)) * w[i];
  }
  // cerr << x << " " << y << " " << ret << endl;
  return ret;
}
double calc(double x) {
  double ret = calc2(x, ymin);
  double l = ymin, r = ymax;
  for (int it = 0; it < LG; it++) {
    double m1 = (l + l + r)/3, m2 = (l + r + r)/3;
    double res1 = calc2(x, m1), res2 = calc2(x, m2);
    if (res1 > res2)
      l = m1;
    else
      r = m2;
    ret = min(ret, min(res1, res2));
  }
  return ret;
}


int main() {
  time_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%lf %lf %lf", &p[i].x, &p[i].y, &w[i]);
    }
    xmin = xmax = p[0].x;
    ymin = ymax = p[0].y;
    for (int i = 1; i < n; i++) {
      xmin = min(xmin, p[i].x);
      xmax = max(xmax, p[i].x);
      ymin = min(ymin, p[i].y);
      ymax = max(ymax, p[i].y);
    }
    double l = xmin, r = xmax;
    double ans = calc2(xmin, ymin);
    for (int it = 0; it < LG; it++) {
      double m1 = (l + l + r)/3, m2 = (l + r + r)/3;
      double res1 = calc(m1), res2 = calc(m2);
      if (res1 > res2)
        l = m1;
      else
        r = m2;
      ans = min(ans, min(res1, res2));
    }
    printf("Case #%d: %.12lf\n", tc, ans);
    cerr << "~ #" << tc << " done! time : " << (double)(clock()-startt) * 1000/CLOCKS_PER_SEC << " ms" << endl;
  }
  return 0;
}