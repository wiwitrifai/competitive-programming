#include <bits/stdc++.h>

using namespace std;

const int N = 30030, ITER = 300;
int c[N];
double p[N], h[N];

double calc(double pa, double ha, double pb, double hb) {
  double ret = 0, best = pb * hb;
  if (pa * ha > best) {
    ret = 1;
    best = pa * ha;
  }
  double low = 0, hi = 1;
  auto calc = [&](double x) {
    double cp = pa * x + pb * (1 - x);
    double ch = ha * x + hb * (1 - x);
    return cp * ch;
  };
  for (int i = 0; i < ITER; ++i) {
    double le = (low + low + hi) / 3.0, ri = (low + hi + hi) / 3.0;
    double resl = calc(le), resr = calc(ri);
    if (best < resl) {
      best = resl;
      ret = le;
    }
    if (best < resr) {
      best = resr;
      ret = ri;
    }
    if (resl > resr)
      hi = ri;
    else
      low = le;
  }
  return best;
}

typedef long double LD;
const LD EPS = 1e-9, PI = acos(-1);
inline bool eq(LD a, LD b) { return fabs(a-b) < EPS; }
inline bool lt(LD a, LD b) { return a + EPS < b; }
inline bool le(LD a, LD b) { return a < b + EPS; }
inline int sign(LD x) { return eq(x, 0) ? 0 : (x < 0 ? -1 : 1); }

struct point {
  LD x, y;
  point(LD x = 0, LD y = 0) : x(x), y(y) {}
  point operator+(const point& p) const { return point(x+p.x, y+p.y); }
  point operator-(const point& p) const { return point(x-p.x, y-p.y); }
  point operator*(LD s) { return point(x*s, y*s); }
  point operator/(LD s) { return point(x/s, y/s); }
  LD operator*(const point& p) const { return x*p.x + y*p.y; } // dot
  LD operator%(const point& p) const { return x*p.y - y*p.x; } // cross
  LD norm_sq() { return *this * *this; }
  LD norm() { return sqrt(*this * *this); }
  point rotate(LD cs, LD sn) { return point(x*cs-y*sn, x*sn+y*cs); }
  point rotate(LD angle) { return rotate(cos(angle), sin(angle)); }
  bool operator==(const point& p) const { return eq(x, p.x) && eq(y, p.y); }
  bool operator<(const point& p) const { return eq(y, p.y) ? x < p.x : y < p.y; }
};
ostream& operator<<(ostream& os, point p) {
  return os << "(" << p.x << ", " << p.y << ")";
}
int ccw(point a, point b, point c) { return sign((b - a) % (c - b)); }
LD dist(point a, point b) { return (b-a).norm(); }
LD dist2(point a, point b) { return (b-a).norm_sq(); }


void convexHull(vector<point> & vp) {
  if (vp.size() < 3)
    return;
  int n = vp.size();
  for (int i = 1; i < n; ++i) {
    if (vp[i] < vp[0])
      swap(vp[i], vp[0]);
  }
  point pivot;
  sort(vp.begin()+1, vp.end(), [&pivot](point a, point b) {
    int vccw = ccw(pivot, a, b);
    if (vccw == 0)
      return dist2(pivot, a) < dist2(pivot, b);
    return vccw > 0;
  });
  vector<point> result;
  for (point p : vp) {
    int sz;
    while ((sz = result.size()) >= 2 && ccw(result[sz-2], result[sz-1], p) < 0)
      result.pop_back();
    result.push_back(p);
  }
  vp = result;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  double ans = 0;
  vector<point> vp;
  for (int i = 0; i < n; ++i) {
    scanf("%d %lf %lf", c+i, h+i, p+i);
    h[i] = h[i] * m / c[i];
    p[i] = p[i] * m / c[i];
    ans = max(ans, h[i] * p[i]);
    vp.push_back(point(h[i], p[i]));
  }
  convexHull(vp);
  for (int i = 0; i < vp.size(); ++i) {
    int nxt = i+1;
    if (nxt == vp.size()) nxt = 0;
    double res = calc(vp[i].x, vp[i].y, vp[nxt].x, vp[nxt].y);
    ans = max(ans, res);
  }
  printf("%.2lf\n", ans);
  return 0;
}
