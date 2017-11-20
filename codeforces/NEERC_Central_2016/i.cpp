#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
const int ITER = 2000;
const ld EPS = 1e-9;

struct point {
  ld x, y;
  point(ld x = 0, ld y = 0) : x(x), y(y) {}
    bool operator==(point p) const {
    return (fabs(x - p.x) < EPS) && (fabs(y - p.y) < EPS);
  }
  point operator+(point p) const { return point(x + p.x, y + p.y); }
  point operator-(point p) const { return point(x - p.x, y - p.y); }
  point operator*(ld scale) const { return point(x * scale, y * scale); }
  point operator/(ld scale) const { return point(x / scale, y / scale); }
  ld operator*(point p) const { return x * p.x + y * p.y; }
  ld operator%(point p) const { return x * p.y - y * p.x; }
};

ld dist(point a, point b) {
  point ab = b - a;
  return sqrt(ab * ab);
}

ld distToLineSegment(point p, point a, point b, point &c) {
  point ap = p-a, ab = b-a;
  if (a == b) {
    c = a;
    return dist(p, c);
  }
  ld u = ap * ab / (ab * ab);
  if (u < 0.0) c = a;
  else if (u > 1.0) c = b;
  else c = a + ab * u;
  return dist(p, c);
}

int main() {
#ifndef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, a, b;
  scanf("%d %d %d", &n, &a, &b);
  vector<point> vp;
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    vp.push_back(point(x, y));
  }
  bool ok = 0; 
  ld ans = -1;
  if (a > n + 1 || b > n + 1) {
    puts("-1");
    return 0;
  }
  if (a + b == n + 2) {
    for (int i = 0; i < n; i++) {
      int j = (i + a - 1) % n;
      ld cur = dist(vp[i], vp[j]);
      if (!ok)
        ans = cur, ok = 1;
      else
        ans = min(ans, cur);
    }
  }
  else if (a + b == n + 3) {
    for (int i = 0; i < n; i++) {
      int j = (i + a - 2) % n;
      point p;
      ld cur = distToLineSegment(vp[i], vp[j], vp[(j+1) % n], p);
      if (!ok)
        ans = cur, ok = 1;
      else
        ans = min(ans, cur);
      j = (i + b - 2) % n;
      cur = distToLineSegment(vp[i], vp[j], vp[(j+1) % n], p);
      if (!ok)
        ans = cur, ok = 1;
      else
        ans = min(ans, cur);
    }
  }
  else if (a + b == n + 4) {
    for (int i = 0; i < n; i++) {
      point p = vp[i], q = vp[(i+1) % n];
      int j = (i + a - 2) % n;
      point r = vp[j], s = vp[(j+1) % n];
      ld lo = 0, hi = 1;
      ld cur = dist(p, r);
      for (int it = 0; it < ITER; ++it) {
        ld c = (lo + lo + hi) / 3.0, d = (lo + hi + hi) / 3.0;
        point pc = p * c + q * (1.0-c), pd = p * d + q * (1.0 - d);
        point t; 
        ld vc = distToLineSegment(pc, r, s, t), vd = distToLineSegment(pd, r, s, t);
        cur = min(cur, min(vc, vd));
        if (vc < vd)
          hi = d;
        else
          lo = c;
      }
      if (!ok)
        ans = cur, ok = 1;
      else
        ans = min(cur, ans);
    }
  }
  if (!ok)
    puts("-1");
  else
    printf("%.3lf\n", (double) ans);
  return 0;
}