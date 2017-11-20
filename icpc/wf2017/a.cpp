#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-10;

struct point {
  double x, y;
  point (double x = 0, double y = 0) : x(x), y(y) {
  }
  point operator*(double mul) {
    return point(x * mul, y * mul);
  }
  point operator/(double mul) {
    return point(x / mul, y / mul);
  }
  point operator+(point p) {
    return point(x + p.x, y + p.y);
  }
  point operator-(point p) {
    return point(x - p.x, y - p.y);
  }
};

double dist(point a, point b) {
  double dx = a.x - b.x, dy = a.y - b.y;
  return hypot(dx, dy);
}
double cross(point a, point b, point c) {
  return (a.x - b.x) * (c.y - b.y) - (a.y - b.y) * (c.x - b.x);  
}
bool equals(double x, double y) {
  return fabs(x-y) < eps;
}
bool intersect(point a, point b, point p, point q) {
  double c = cross(a, b, p), d = cross(a, b, q);
  if (equals(c, 0) || equals(d, 0) || c * d > 0) return false;
  c = cross(p, q, a), d = cross(p, q, b);
  if (equals(c, 0) || equals(d, 0) || c * d > 0) return false;
  return true;
}

bool between(point po, point a, point b, point c) {
  if (cross(a, po, c) > -eps) {
    return cross(a, po, b) > -eps && cross(b, po, c) > -eps;
  }
  else {
    return cross(a, po, b) > -eps || cross(b, po, c) > -eps;
  }
}

int n;
point p[222];
double longest = 0;
double calc(point po, point q) {
  double l = 0, r = longest;
  for (int k = 0; k < 100; k++) {
    double mid = (l + r)/2;
    point cur = po + q * mid;
    bool ok = 1;
    for (int z = 1; z <= n; z++) {
      if (intersect(po, cur, p[z], p[z+1])) {
        ok = 0;
        break;
      }
      if (equals(dist(po, p[z]), 0)) continue;
      double zcur = dist(p[z], cur);
      if (equals(dist(po, p[z]) + zcur, dist(po, cur)) && zcur > eps) {
        if (between(po, p[z-1], p[z], p[z+1])) {
          ok = 0;
          break;
        }
      }
    }
    if (ok)
      l = mid;
    else
      r = mid;
  }
  return l;
}


int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    p[i] = point(x, y);
  }
  p[n] = p[0];
  p[n+1] = p[1];
  double ans = 0;
  longest = 0;
  for (int i = 0; i < n; i++)
    for (int j = i+1; j < n; j++)
      longest = max(longest, dist(p[i], p[j]));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      double cur = 0;
      if (between(p[i], p[i+1], p[j], p[i-1]))
        cur += calc(p[i], (p[j]-p[i])/dist(p[i], p[j]));
      point tmp = (p[i] * 2 - p[j]);
      if (between(p[i], p[i+1], tmp, p[i-1]))
        cur += calc(p[i], (tmp-p[i])/dist(p[i], tmp));
      ans = max(ans, cur);
    }
  } 
  printf("%.10lf\n", ans);
  return 0;
}