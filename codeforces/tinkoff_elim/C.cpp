#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6;
const double eps = 1e-7;

int x[N], y[N], vx[N], vy[N];
int xl, yl, xr, yr;

int main() {
  int n;
  scanf("%d", &n);
  scanf("%d %d %d %d", &xl, &yl, &xr, &yr);
  int ma = max(xl, xr), mi = min(xl, xr);
  xl = mi; xr = ma;
  ma = max(yl, yr), mi = min(yl, yr);
  yl = mi; yr = ma;
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d %d", x+i, y+i, vx+i, vy+i);
  }
  bool ok = 1;
  vector< double > tmin, tmax;
  for (int i = 0; i < n; i++) {
    bool cek = 0;
    double low, up;
    if (vx[i] == 0 && vy[i] == 0) {
      if (!(x[i] < xr && x[i] > xl && y[i] > yl && y[i] < yr)) {
        ok = 0;
        break;
      }
      continue;
    }
    if ((x[i] <= xr && x[i] >= xl && y[i] >= yl && y[i] <= yr)) {
      cek = 1;
      low = up = 0;
    }
    if (vx[i] != 0) {
      double t = (double)(xl-x[i])/vx[i];
      double yy = y[i] + t * vy[i];
      if (t + eps >= 0 && yy > yl && yr > yy) {
        if (!cek)
          cek = 1, low = up = t;
        else
          low = min(low, t), up = max(up, t);
      }
      t = (double)(xr-x[i])/vx[i];
      yy = y[i] + t * vy[i];
      if (t + eps >= 0 && yy > yl && yr > yy) {
        if (!cek)
          cek = 1, low = up = t;
        else
          low = min(low, t), up = max(up, t);
      }
    }
    if (vy[i] != 0) {
      double t = (double)(yl-y[i])/vy[i];
      double xx = x[i] + t * vx[i];
      if (t + eps >= 0 && xx> xl && xr > xx) {
        if (!cek)
          cek = 1, low = up = t;
        else
          low = min(low, t), up = max(up, t);
      }
      t = (double)(yr-y[i])/vy[i];
      xx = x[i] + t * vx[i];
      if (t + eps >= 0 && xx > xl && xr > xx) {
        if (!cek)
          cek = 1, low = up = t;
        else
          low = min(low, t), up = max(up, t);
      }
    }
    if (!cek) {
      ok = 0;
      break;
    }
    if (up - low < eps) {
      ok = 0;
      break;
    }
    tmin.push_back(low);
    tmax.push_back(up);
  }
  if (!ok) {
    puts("-1");
    return 0;
  }
  double low = 0;
  for (auto it : tmin)
    low = max(it, low);
  for (auto it : tmax)
    if (low > it + eps) {
      puts("-1");
      return 0;
    }
  printf("%.20lf\n", low);
  return 0;
}