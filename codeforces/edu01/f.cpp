#include <bits/stdc++.h>

using namespace std;

typedef long double LD;
const LD EPS = 1e-7;
inline bool eq(LD x, LD y) { return fabs(x-y) < EPS; }
inline bool le(LD x, LD y) { return x < y + EPS; }
inline bool lt(LD x, LD y) { return x + EPS < y; }
inline int sgn(LD x) { return eq(x, 0) ? 0 : x < 0 ? -1 : 1; }

struct point {
  LD x, y;
  point(LD x = 0, LD y = 0) : x(x), y(y) {}
  point operator+(const point& p) const { return point(x+p.x, y+p.y); }
  point operator-(const point& p) const { return point(x-p.x, y-p.y); }
  point operator*(LD s) const { return point(x * s, y * s); }
  point operator/(LD s) const { return point(x / s, y / s); }
  LD operator*(const point & p) const { return x * p.x + y * p.y; }
  LD operator%(const point & p) const { return x * p.y - y * p.x; }
  LD norm_sq() { return *this * *this; }
  LD norm() { return sqrt(*this * *this); }
  bool operator==(const point & p) const { return eq(x, p.x) && eq(y, p.y); }
  bool operator<(const point & p) const { return eq(y, p.y) ? lt(x, p.x) : lt(y, p.y); }
};
ostream &operator<<(ostream& o, const point& p) { return o <<  "(" << p.x << " " << p.y <<  ")"; }

int ccw(point a, point b, point c) {
  return sgn((b - a) % (c - b));
}
struct line {
  point a, ab;
  line(point a, point b) : a(a), ab(b-a) {}
  point b() { return a + ab; }
  bool areParallel(const line & l) const {
    return eq(ab % l.ab, 0);
  }
};

bool areIntersect(line l1, line l2, point & res) {
  if (l1.areParallel(l2)) return 0;
  LD ls = (l2.a  - l1.a) % l2.ab, rs = l1.ab % l2.ab;
  res = l1.a + l1.ab * ls/rs;
  return 1;
}

bool areInterLineSeg(line l, point a, point b, point & res) {
  if (!areIntersect(l, line(a, b), res)) return 0;
  if (le((a - res) * (b-res), 0))
    return 1;
  return 0;
}

int pointVsPolygon(point p, const vector< point >& vp) {
  int wn = 0, n = (int)vp.size() - 1;
  for(int i = 0; i < n; i++) {
    int cs = ccw(vp[i+1], vp[i], p);
    if(cs == 0 && (vp[i+1]-p) * (vp[i]-p) <= 0)
      return 0; // between(vp[i], p, vp[i+1])
    if(vp[i].y <= p.y) {
      if(vp[i+1].y > p.y && cs > 0)
        wn++;
    }
    else {
      if(vp[i+1].y <= p.y && cs < 0)
        wn--;
    }
  }
  return wn == 0 ? 1 : -1;
}


int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<point> poly;
  for (int i = 0; i < n; ++i) {
    double x, y;
    scanf("%lf %lf", &x, &y);
    poly.push_back(point(x, y));
  }
  poly.push_back(poly.front());
  for (int i = 0; i < m; ++i) {
    double xa, xb, ya, yb;
    scanf("%lf %lf %lf %lf", &xa, &ya, &xb, &yb);
    point a(xa, ya), b(xb, yb);
    line l(a, b);
    vector<pair<point, pair<int, int> > > ints;
    point p;
    for (int j = 0; j < n; ++j) {
      if (!areInterLineSeg(l, poly[j], poly[j+1], p)) continue;
      int pre = ccw(a, b, poly[j]), nxt = ccw(a, b, poly[j+1]);
      ints.push_back({p, {pre, nxt}});
    }
    sort(ints.begin(), ints.end());
    LD ans = 0;
    int inside = -1, prev = 0;
    point last;
    for (int j = 0; j < ints.size(); ++j) {
      point c = (ints[j].first + ints[j+1].first) / 2.0;
      if (inside >= 0)
        ans += (ints[j].first - last).norm();
      last = ints[j].first;
      if (inside == 0) {
        int cur = ((ints[j].second.first + ints[j].second.second));
        assert(ints[j].second.first == 0 || ints[j].second.second == 0);
        if (cur != 0) {
          if (cur == prev)
            inside = 1;
          else
            inside = -1;
        }
      }
      else if (ints[j].second.first * ints[j].second.second < 0) {
        if (inside >= 0) inside = -1;
        else inside = 1;
      }
      else {
        prev = (ints[j].second.first + ints[j].second.second) * inside;
        inside = 0;
      }
    }
    printf("%.20lf\n", (double)ans);
  }
  return 0;
}
