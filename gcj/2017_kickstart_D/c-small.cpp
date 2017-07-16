#include <bits/stdc++.h>

using namespace std;

const int N = 11;
double x[N], y[N];
int n;
double p, h;

double dist(double a, double b, double c, double d) {
  double x = a - c, y = b - d;
  return sqrt(x * x + y * y);
}

bool can(double r) { 
  double a = (h-r) * 4 / p / p;
  double le = 0, ri = p;
  if (x[0] < p/2)
    ri = p/2;
  else
    le = p/2;
  for (int it = 0; it < 200; it++) {
    double d = (le + le + ri)/3, e = (le + ri + ri) / 3;
    double yd = a * d * (p - d), ye = a * e * (p-e);
    if ((dist(d, yd, x[0], y[0]) < dist(e, ye, x[0], y[0])))
      ri = e;
    else
      le = d;
  }
  double yd = a * le * (p - le), ye = a * ri * (p-ri);
  return min(dist(le, yd, x[0], y[0]), dist(ri, ye, x[0], y[0])) >= r;
}

int main() {
  time_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    cin >> n >> p >> h;
    for (int i = 0; i < n; i++) {
      cin >> x[i] >> y[i];
    }
    double le = 0, ri = h;
    for (int it = 0; it < 200; it++) {
      double mid = (le + ri)/2;
      if (can(mid))
        le = mid;
      else
        ri = mid;
    }
    double ans = max((double)y[0], le);
    printf("Case #%d: %.20lf\n", tc, ans);
    cerr << "~ #" << tc << " done! time : " << (double)(clock()-startt) * 1000/CLOCKS_PER_SEC << " ms" << endl;
  }
  return 0;
}