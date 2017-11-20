#include <bits/stdc++.h>

using namespace std;

const int ITER = 1000;

struct point {
  double x, y;
  point(double x = 0, double y = 0) : x(x), y(y) {}
  point operator-(point p) { return point(x - p.x, y - p.y); }
  point operator+(point p) { return point(x + p.x, y + p.y); }
  point operator/(double s) { return point(x / s, y / s); }
  point operator*(double s) { return point(x * s, y * s); }
};

double dot(point a, point b) {
  return a.x * b.x + a.y * b.y;
}

double norm_sq(point p) {
  return dot(p, p);
}
double dist(point a, point b) {
  point ab = b - a;
  return sqrt(dot(ab, ab));
}

point a, b, c;
double calc(point p) {
  double ret = dist(p, a) + dist(p, b) + dist(p, c);
  return ret;
}

point calc1(double x) {
  point p = a * x + b * (1.0 - x);
  double lo = 0, hi = 1.0;
  point best = p;
  double dbest = calc(p);
  for (int it = 0; it < ITER; ++it) {
    double le = (lo + lo + hi) / 3.0, ri = (lo + hi + hi) / 3.0;
    point ple = p * le + (c * (1.0-le)), pri = p * ri + (c * (1.0-ri));
    double vle = calc(ple), vri = calc(pri);
    if (dbest > vle)
      dbest = vle, best = ple;
    if (dbest > vri)
      dbest = vri, best = pri;
    if (vle > vri)
      lo = le;
    else
      hi = ri;
  }
  point q = p * lo + c * (1 - lo);
  double dq = calc(q);
  if (dq < dbest)
    best = dq;
  return best;
}

int main() {
  cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
  point p = a;
  double cur = calc(p);
  double lo = 0, hi = 1;
  for (int it = 0; it < ITER; ++it) {
    double le = (lo + lo + hi) / 3.0, ri = (lo + hi + hi) / 3.0;
    point ple = calc1(le), pri = calc1(ri);
    double vle = calc(ple), vri = calc(pri);
    if (vri < cur)
      cur = vri, p = pri;
    if (vle < cur)
      cur = vle, p = ple;
    if (vle > vri) {
      lo = le;
    }
    else {
      hi = ri;
    }
  }
  cur = calc(p);
  point z = calc1(lo);
  double d = calc(z);
  if (d < cur)
    p = z;
  printf("%.9lf %.9lf\n", (double)p.x, (double)p.y);
  return 0;
}