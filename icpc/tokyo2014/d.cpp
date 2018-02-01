#include <bits/stdc++.h>

using namespace std;

const int N = 55;
const long double eps = 1e-9;

int p[N], h[N], d, n, b;

int main() {
  scanf("%d %d %d", &d, &n, &b);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", p+i, h+i);
  }
  long double ans = 0;
  bool sudah = 0;
  for (int bounce = 0; bounce <= b; ++bounce) {
    long double l = (long double) d / (bounce + 1);
    long double now = 0;
    long double v = sqrt(l * 0.5);
    bool ok = 1;
    for (int i = 0; i < n; ++i) {
      while (now + l  < p[i]) now += l;
      if (fabs(now - p[i]) < eps || fabs(now + l - p[i]) < eps) {
        ok = 0;
        break;
      }
      long double x = p[i] - now;
      long double vv = (long double)h[i] * l * l / (2.0 * x * (l-x));
      if (vv < 0) {
        ok = 0;
        break;
      }
      vv = sqrt(vv);
      v = max(vv, v);
    }
    if (!ok) continue;
    long double cur = l / (2 * v);
    //cerr << v * v << " " << l << endl;
    cur = sqrt(cur * cur + v * v);
    if (sudah)
      ans = min(ans, cur);
    else
      ans = cur, sudah = 1;
  }
  assert(sudah);
  printf("%.10lf\n", (double)ans);
  return 0;
}