#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

typedef long double LD;
const LD EPS = 1e-6, PI = acos(-1);
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
LD angle(point a, point o, point b) {
  point oa = a-o, ob = b-o;
  return acos(oa*ob/(oa.norm()*ob.norm()));
}

struct line {
  point a, ab; // p(t) = a + ab * t
  line(point ta, point tb) {
    if (tb < ta) swap(ta, tb);
    a = ta; ab = tb-ta;
  }
  point b() { return a + ab; }
  bool isLine() { return !(ab == point()); } // minor
  operator bool() { return !(ab == point()); } // minor
  // Line
  bool onLine(point p) {
    if (ab == point()) return a == p;
    return eq(ab % (p-a), 0);
  }
  LD distLine(point p) {
    if (ab == point()) return dist(a, p);
    return fabs((p-a) % ab)/ab.norm();
  }
  point projection(point p) {
    if (ab == point()) return a;
    return a + ab * ((p-a) * ab / ab.norm_sq());
  }
  bool areParallel(line l) {
    return eq(ab % l.ab, 0);
  }
  bool areSame(line l) {
    return areParallel(l) && onLine(l.a) && l.onLine(a);
  }
};

void solve() {
  int n, r;
  scanf("%d %d", &n, &r);
  LD r2 = (LD)r * r;
  vector<point> points(n), dir(n);
  for (int i = 0; i < n; ++i) {
    int x, y, dx, dy;
    scanf("%d %d %d %d", &x, &y, &dx, &dy);
    points[i] = point(x, y);
    dir[i] = point(dx, dy);
  }
  int offset = 0;
  vector<pair<LD, int>> events;
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      point d = dir[i] - dir[j];
      point a = points[i], b = points[j];
      if (d == point()) {
        if (le(dist2(a, b), r2))
          ++offset;
        continue;
      }
      line l(a, a+d);
      point nearest = l.projection(b);
      if (lt(r2, dist2(nearest, b))) continue;
      LD t = 0;
      if (lt(dist2(nearest, b), r2))
        t = sqrt(r2 - dist2(nearest, b));
      point lef = nearest - d * (t/d.norm()), rig = nearest + d * (t/d.norm());
      assert(eq(dist2(lef, b), r2) && eq(dist2(rig, b), r2));
      LD tl, tr;
      if (eq(d.x, 0))
        tl = (lef - a).y / d.y, tr = (rig - a).y / d.y;
      else
        tl = (lef - a).x / d.x, tr = (rig - a).x / d.x;
      if (tl > tr)
        swap(tl, tr);
      tl = max(tl, (LD)0);
      if (lt(tr, 0))
        continue;
      tr = max(tr, (LD)0);
      events.emplace_back(tl, +1);
      events.emplace_back(tr, -1);
    }
  }
  sort(events.begin(), events.end(), [](pair<LD, int> le, pair<LD, int> ri) {
    if (eq(le.first, ri.first))
      return le.second > ri.second;
    return le.first < ri.first;
  });
  int cur = offset, ans = offset;
  for (auto e : events) {
    cur += e.second;
    ans = max(ans, cur);
  }
  printf("%d\n", ans);
}

int main() {
  int tt = 1;
  for (int tc = 1; tc <= tt; ++tc) {
    // printf("Case #%d: ", tc);
    solve();
  }
  return 0;
}
