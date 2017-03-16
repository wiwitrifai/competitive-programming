#include <bits/stdc++.h>

using namespace std;

const int N = 22;
const double eps = 1e-7;

double x, y;

pair< int, int > l[N];

double dx[N], dy[N];

int main() {
  int n;
  scanf("%d", &n);
  int ma = 0, sum = 0;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    ma = max(ma, a);
    sum += a;
    l[i] =   make_pair(a, i);
  }
  scanf("%lf %lf", &x, &y);
  if (n == 1) {
    double d = hypot(x, y);
    if (d < eps)
      printf("%.7lf %.7lf\n", (double)l[0].first, 0.0);
    else {
      x = (double)l[0].first * x / d;
      y = (double)l[0].first * y / d;
      printf("%.7lf %.7lf\n", x, y);
    }
    return 0;
  }
  double dnow = hypot(x, y);
  if (dnow > eps) {
    if (sum < dnow) {
      double xn = 0, yn = 0;
      for (int i = 0; i < n; i++) {
        double mul = (double)l[i].first/dnow;
        xn += mul * x;
        yn += mul * y;
        printf("%.7lf %.7lf\n", xn, yn);
      }
      return 0;
    }
    else if (dnow < 2 * ma - sum) {
      double xn = 0, yn = 0;
      for (int i = 0; i < n; i++) {
        double mul = (double)l[i].first/dnow;
        if (l[i].first < ma) {
          mul *= -1;
        }
        xn += mul * x;
        yn += mul * y;
        printf("%.7lf %.7lf\n", xn, yn);
      }
      return 0;
    }
  }
  sort(l, l+n);
  for (int i = n-1; i > 0; i--) {
    double d = hypot(x, y);
    int id = l[i].second;
    sum -= l[i].first;
    double now = l[i].first;
    double r = min(d + now, (double)sum);
    double dd = min(d, r + now);
    if (dd < eps) {
      dx[id] = now;
      dy[id] = 0;
      x -= dx[id];
      y -= dy[id];
      continue;
    }
    // cerr << x << " " << y << " " << now << " " << r  <<" " << dd << endl;
    double alfa = acos((now * now + dd * dd - r * r) / (2 * now * dd));
    // cerr << alfa << " - " << now << endl;
    double xx = now * cos(alfa), yy = now * sin(alfa);
    double cs = x/d, sn = y/d;
    // cerr << xx << " " << yy << endl;
    double xn = cs * xx - sn * yy, yn = sn * xx + cs * yy;
    dx[id] = xn;
    dy[id] = yn;
    x -= xn;
    y -= yn;
  }
  double d = hypot(x, y);
  double last = l[0].first;
  int id = l[0].second;
  if (d < eps) {
    dx[id] = last;
    dy[id] = 0;
  }
  else {
    dx[id] = last/d * x;
    dy[id] = last/d * y;
  }
  x = 0;
  y = 0;
  for (int i = 0; i < n; i++) {
    // cerr << hypot(dx[i], dy[i]) << endl;
    x += dx[i]; 
    y += dy[i];
    printf("%.7lf %.7lf\n", x, y);
  }
  return 0;
}