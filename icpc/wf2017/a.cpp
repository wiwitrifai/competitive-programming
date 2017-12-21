#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

const ld eps = 1e-8;

struct point {
  ld x, y;
  point (ld x = 0, ld y = 0) : x(x), y(y) {}
  point operator+(point p) const { return point(x + p.x, y + p.y); }
  point operator-(point p) const { return point(x - p.x, y - p.y); }
  point operator*(ld s) const { return point(x * s, y * s); }
  point operator/(ld s) const { return point(x / s, y / s); }
  ld operator*(point p) const { return x * p.x + y * p.y; }
  ld operator%(point p) const { return x * p.y - y * p.x; }
  bool operator==(point p) const { return fabs(x - p.x) < eps && fabs(y - p.y) < eps; }
};

int ccw(point a, point b, point c) {
  ld crs = (b - a) % (c - b);
  if (fabs(crs) < eps) return 0;
  return crs < 0 ? -1 : 1;
}

ld dist(point a, point b) {
  point ab = b - a;
  return sqrt(ab * ab);
}

bool shootBetween(point po, point a, point b, point c) {
  if (ccw(po, a, c) >= 0) {
    return ccw(po, a, b) >= 0 && ccw(po, b, c) >= 0;
  }
  else {
    return ccw(po, a, b) >= 0 || ccw(po, b, c) >= 0;
  }
}

vector<point> vp;
int n;
ld longest;

point lineIntersectSeg(point p, point q, point A, point B) {
  double a = B.y - A.y;
  double b = A.x - B.x;
  double c = B.x * A.y - A.x * B.y;
  double u = fabs(a * p.x + b * p.y + c);
  double v = fabs(a * q.x + b * q.y + c);
  return point((p.x*v + q.x*u)/(u+v), (p.y*v + q.y*u)/(u+v));
}

ld calc(int id, point to) {
  ld ret = longest;
  ld dto = dist(vp[id], to);
  point arah = (to - vp[id]) / dto;
  vector<point> inter;
  for (int i = 0; i < n; ++i) {
    int cur = i % n, nx = (cur + 1) % n;
    if (ccw(vp[id], to, vp[cur]) * ccw(vp[id], to, vp[nx]) < 0) {
      point c = lineIntersectSeg(vp[cur], vp[nx], vp[id], to);
      ld d = dist(c, vp[id]);
      point z = vp[id] + arah * d;
      if ((to-vp[id]) * (c-vp[id]) > 0)
        ret = min(ret, d);
    }
    if (cur == id) continue;
    if (ccw(vp[id], to, vp[cur])) continue;
    if ((to - vp[id]) * (vp[cur] - vp[id]) < 0) continue;
    int bef = (cur + n-1) % n;
    point refl = vp[cur] * 2.0 - vp[id];
    if (shootBetween(vp[cur], vp[nx], vp[id], vp[bef]) && !shootBetween(vp[cur], vp[nx], refl, vp[bef])) {
      ret = min(ret, dist(vp[id], vp[cur]));
    }
  }
  return ret;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    vp.push_back(point(x, y));
  }
  vp.push_back(vp[0]);
  longest = 0;
  for (int i = 0; i < n; ++i)
    for (int j = i+1; j < n; ++j) {
      longest = max(longest, dist(vp[i], vp[j]));
    }
  ld ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      int nx = (i + 1) % n, bef = (i + n - 1) % n;
      ld cur = 0;
      if (shootBetween(vp[i], vp[nx], vp[j], vp[bef]))
        cur += calc(i, vp[j]);
      point refl = vp[i] * 2.0 - vp[j];
      if (shootBetween(vp[i], vp[nx], refl, vp[bef]))
        cur += calc(i, refl);
      ans = max(ans, cur);
    }
  }
  printf("%.10lf\n", (double)ans);
  return 0;
}