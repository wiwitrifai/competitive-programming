#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

const ld EPS = 1e-9;

struct point {
  ld x, y;
  point(ld x = 0, ld y = 0) : x(x), y(y) {}
  point operator+(point p) { return point(x + p.x, y + p.y); }
  point operator-(point p) { return point(x - p.x, y - p.y); }
  point operator*(ld s) { return point(x * s, y * s); }
  point operator/(ld s) { return point(x / s, y / s); }
  ld operator*(point p) { return x * p.x + y * p.y; }
  ld operator%(point p) { return x * p.y - y * p.x; }
  ld norm() { return *this * *this; }
};

ld dist(point a, point b) {
  point ab = b - a;
  return sqrt(ab * ab);
}

// return 1 = ccw, 0 = colinear, -1 = cw
int ccw(point p, point q, point r) {
  point pq = q - p, pr = r-p;
  double crs = pq % pr;
  if (fabs(crs) < EPS) return 0;
  return crs > 0 ? 1 : -1;
}

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  vector<point> vp;
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    vp.push_back(point(x, y));
  }
  while (q--) {
    int p, k;
    scanf("%d %d", &p, &k);
    int l = 1, r = n-1;
    point a = vp[p % n], b = vp[(p + 1) % n];
    point c = a + (b - a) * ((ld)k / dist(a, b));
    while (l < r) {
      int mid = (l + r) >> 1;
      point e = vp[(p + mid) % n], f = vp[(p + mid + 1) % n];
      if (ccw(c, e, f) == 1)
        r = mid;
      else
        l = mid + 1;
    }
    printf("%d\n", (p + l) % n);
  }
  return 0;
}