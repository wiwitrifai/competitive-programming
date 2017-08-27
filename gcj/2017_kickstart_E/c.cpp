#include <bits/stdc++.h>

using namespace std;

const int N = 4, LOOP = 500;
const long double inf = 1e6, eps = 1e-12;
int x[N], y[N], z[N];

long double dist(long double xx, long double yy, long double zz, int j) {
  xx -= x[j];
  yy -= y[j];
  zz -= z[j];
  return sqrt(xx * xx + yy * yy + zz * zz);
}
long double get(long double m, long double r, bool pr = false) {
  long double xx = x[1] * m + x[2] * (1-m), 
  yy = y[1] * m + y[2] * (1-m),
  zz = z[1] * m + z[2] * (1-m);
  long double dd = sqrt(xx * xx + yy * yy + zz * zz);
  if (dd > r) {
    xx = xx*r/dd;
    yy = yy*r/dd;
    zz = zz*r/dd;
  }
  // if (pr) {
  //   cerr << xx << " " << yy << " " << zz << endl;
  //   cerr << x[1] << " " << y[1] << " " << z[1] << endl;
  //   cerr << x[2] << " " << y[2] << " " << z[2] << endl;
  // }
  long double res = (max(dist(xx, yy, zz, 1), dist(xx, yy, zz, 2))-r)/2.0;
  if (res < 0)
    res = 0;
  return res;
}

long double get2(long double m, long double r, bool pr = false) {
  long double xx = x[1] * m + x[2] * (1-m), 
  yy = y[1] * m + y[2] * (1-m),
  zz = z[1] * m + z[2] * (1-m);
  long double dd = sqrt(xx * xx + yy * yy + zz * zz);
  if (dd > 5 * r) {
    xx = xx*5*r/dd;
    yy = yy*5*r/dd;
    zz = zz*5*r/dd;
  }
  // if (pr) {
  //   cerr << xx << " " << yy << " " << zz << endl;
  //   cerr << x[1] << " " << y[1] << " " << z[1] << endl;
  //   cerr << x[2] << " " << y[2] << " " << z[2] << endl;
  // }
  long double res = max(dist(xx, yy, zz, 1), dist(xx, yy, zz, 2));
  if (res < 0)
    res = 0;
  return res;
}

int main() {
  time_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    for (int i = 0; i < 3; i++)
      scanf("%d %d %d", x+i, y+i, z+i);
    long double ans = inf;
    for (int i = 0; i < 3; i++) {
      swap(x[i], x[0]);
      swap(y[i], y[0]);
      swap(z[i], z[0]);
      int xx = x[0], yy = y[0], zz = z[0];
      for (int j = 0; j < 3; j++) {
        x[j] -= xx;
        y[j] -= yy;
        z[j] -= zz;
      }
      // each cycle contains a point
      long double low = 0, hi = inf;
      for (int iter = 0; iter < LOOP; iter++) {
        long double r = (low + hi) / 2.0;
        long double le = 0, ri = 1;
        for (int it2 = 0; it2 < LOOP; it2++) {
          long double m1 = (le + le + ri)/3.0, m2 = (le + ri + ri) / 3.0;
          if (get(m1, r) < get(m2, r))
            ri = m2;
          else
            le = m1;
        }
        // cerr << low << " " << hi << " " << r << " " << le << " " << ri << endl;
        // cerr << get(le, r, true) << endl;
        if (min(get(le, r), get(ri, r)) <= r)
          hi = r;
        else
          low = r;
      }
      ans = min(ans, hi);

      // two points in one circle
      low = 0, hi = inf;
      for (int iter = 0; iter < LOOP; iter++) {
        long double r = (low + hi) / 2.0;
        long double le = 0, ri = 1;
        for (int it2 = 0; it2 < LOOP; it2++) {
          long double m1 = (le + le + ri)/3.0, m2 = (le + ri + ri) / 3.0;
          if (get2(m1, r) < get2(m2, r))
            ri = m2;
          else
            le = m1;
        }
        // cerr << low << " " << hi << " " << r << " " << le << " " << ri << endl;
        // cerr << get(le, r, true) << endl;
        if (min(get2(le, r), get2(ri, r)) <= r)
          hi = r;
        else
          low = r;
      }
      ans = min(ans, hi);
    }
    printf("Case #%d: %.20lf\n", tc, (double)ans);
    cerr << "~ #" << tc << " done! time : " << (long double)(clock()-startt) * 1000/CLOCKS_PER_SEC << " ms" << endl;
  }
  return 0;
}