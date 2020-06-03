#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

struct point {
  double x, y;
  int id;
  point(double x = 0, double y = 0, int id = -1) : x(x), y(y), id(id) {}
  point operator-(point b) const { return point(x - b.x, y - b.y); }
  point operator+(point b) const { return point(x + b.x, y + b.y); }
  bool operator<(point b) const {
    if (fabs(x - b.x) > EPS)
      return x < b.x;
    return y < b.y;
  }
  point operator*(double s) const { return point(x * s, y * s); }
};
double cross(point a, point b) {
  return a.x * b.y - a.y * b.x;
}
// return 1 = ccw, 0 = colinear, -1 = cw
int ccw(point p, point q, point r) {
  point pq = q - p, pr = r-p;
  double crs = cross(pq, pr);
  if (fabs(crs) < EPS) return 0;
  return crs > 0 ? 1 : -1;
}

struct line { double a, b, c; };
void pointToLine(point p1, point p2, line& l) {
  if(fabs(p1.x - p2.x) < EPS) {
    l.a = 1.0; l.b = 0.0; l.c = -p1.x;
  }
  else {
    l.a = -(double)(p1.y - p2.y)/(p1.x - p2.x);
    l.b = 1.0;
    l.c = -(double)(l.a * p1.x) - (l.b * p1.y);
  }
}
// convert point and gradient/slope to line
void pointSlopeToLine(point p, double m, line& l) {
  l.a = -m;
  l.b = 1;
  l.c = -((l.a * p.x) + (l.b * p.y));
}
const int N = 1e5 + 5;
double ans[N];

double batas(point a, point b) {
  if (fabs(b.y - a.y) < EPS)
    return (a.x + b.x) * 0.5;
  line l1, l2;
  pointToLine(a, b, l1);
  pointSlopeToLine((a + b) * 0.5, 1/l1.a, l2);
  return -l2.c / l2.a;
}

bool bad(point a, point b, point c) {
  return batas(a, b) > batas(b, c);
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  vector<point> vp;
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    vp.push_back(point(x, y, i));
    ans[i] = 0;
  }
  sort(vp.begin(), vp.end());
  vp.erase(unique(vp.begin(), vp.end(), [](point le, point ri) { return fabs(le.x - ri.x) < EPS; }), vp.end());
  vector<point> hull;
  for (int i = 0; i < vp.size(); i++) {
    int z = (int)hull.size()-2;
    while (z >= 0 && bad(hull[z], hull[z+1], vp[i])) hull.pop_back(), z--;
    hull.push_back(vp[i]);
  }
  double now = 0;
  for (int i = 0; i + 1 < hull.size(); i++) {
    double cur = min(batas(hull[i], hull[i+1]), (double)k);
    if (now < cur) {
      ans[hull[i].id] += cur - now;
      now = cur;
    }
  }
  if (now < k)
    ans[hull.back().id] += (double)k - now;
  for (int i = 0; i < n; i++)
    printf("%.9lf\n", ans[i]);
  return 0;
}