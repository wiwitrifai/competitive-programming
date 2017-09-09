/**
 *  ACM ICPC Regional Jakarta 2016 - G : National Disaster II
 *  Status : Still wrong answer :(
 */


#include <bits/stdc++.h>

using namespace std;

const long double eps = 1e-9;

struct point {
  long double x, y;
  point(long double x = 0, long double y = 0) : x(x), y(y) {}
  bool operator<(point& b) const {
    if (x != b.x) return x < b.x;
    return y < b.y;
  }
  bool operator==(point& b) {
    return fabs(x-b.x) < eps && fabs(y - b.y) < eps;
  }
};

long double dist2(point a, point b) {
  long double dx = a.x - b.x, dy = a.y - b.y;
  return dx * dx + dy * dy;
}

bool circle2PtsRad(point p1, point p2, long double r, point * c) {
  long double d2 = dist2(p1, p2);
  double det = r * r / d2 - 0.25;
  if (det < 0.0) return false;
  double h = sqrt(det);
  c->x = (p1.x + p2.x) * 0.5 + (p1.y-p2.y)*h;
  c->y = (p1.y + p2.y) * 0.5 + (p2.x-p1.x)*h;
  return true;
}

const int N = 1024;

point c[N], ul, dr;

bool inside(point b) {
  if (b.x < ul.x && fabs(b.x - ul.x) > eps) return false;
  if (b.x > dr.x && fabs(b.x - dr.x) > eps) return false;
  if (b.y < ul.y && fabs(b.y - ul.y) > eps) return false;
  if (b.y > dr.y && fabs(b.y - dr.y) > eps) return false;
  return true;
}

int main() {
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    int x, y;
    scanf("%d %d", &x, &y);
    ul = point(x, y);
    scanf("%d %d", &x, &y);
    dr = point(x, y);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d %d", &x, &y);
      c[i] = point(x, y);
    }
    sort(c, c+n);
    n = unique(c, c+n) - c;
    long long l = 0, r = 2e9;
    while (l < r) {
      long long mid = (l + r) / 2;
      long long mid2 = mid * mid;
      vector<point> ex;
      ex.push_back(ul);
      ex.push_back(dr);
      ex.push_back(point(ul.x, dr.y));
      ex.push_back(point(ul.y, dr.x));
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (i == j) continue;
          point b;
          if (circle2PtsRad(c[i], c[j], mid, &b) && inside(b)) {
            ex.push_back(b);
          }
        }
        long double dx = fabs(c[i].x - ul.x), dy = mid2 - dx * dx;
        if (dy >= 0) {
          dy = sqrt(dy);
          point b(ul.x, c[i].y+dy);
          if (inside(b))
            ex.push_back(b); 
          b = point(ul.x, c[i].y-dy);
          if (inside(b))
            ex.push_back(b);
        }
        dx = fabs(c[i].x - dr.x), dy = mid2 - dx * dx;
        if (dy >= 0) {
          dy = sqrt(dy);
          point b(dr.x, c[i].y+dy);
          if (inside(b))
            ex.push_back(b); 
          b = point(dr.x, c[i].y-dy);
          if (inside(b))
            ex.push_back(b);
        }
        dy = fabs(c[i].y - ul.y), dx = mid2 - dy * dy;
        if (dx >= 0) {
          dx = sqrt(dx);
          point b(c[i].y+dy, ul.y);
          if (inside(b))
            ex.push_back(b); 
          b = point(c[i].y-dy, ul.y);
          if (inside(b))
            ex.push_back(b);
        }
        dy = fabs(c[i].y - dr.y), dx = mid2 - dy * dy;
        if (dx >= 0) {
          dx = sqrt(dx);
          point b(c[i].y+dy, dr.y);
          if (inside(b))
            ex.push_back(b); 
          b = point(c[i].y-dy, dr.y);
          if (inside(b))
            ex.push_back(b);
        }
      }
      bool ok = 1;
      for (point & b : ex) {
        ok = 0;
        for (int i = 0; i < n; i++) {
          long double d2 = dist2(c[i], b);
          if (d2 < mid2 && fabs(d2- mid2) > eps) {
            ok = 1;
            break;
          }
        }
        if (!ok) break;
      }
      if (ok)
        r = mid;
      else
        l = mid + 1;
    }
    printf("Case #%d: %lld\n", tc, l);
  }
  return 0;
}