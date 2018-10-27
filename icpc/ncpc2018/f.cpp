#include <bits/stdc++.h>

using namespace std;

typedef long double LD;
const LD EPS = 1e-7, PI = acos(-1);
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

int ccw(point a, point b, point c) { return sign((b - a) % (c - b)); }
LD dist(point a, point b) { return (b-a).norm(); }
LD dist2(point a, point b) { return (b-a).norm_sq(); }
LD angle(point a, point o, point b) {
  point oa = a-o, ob = b-o;
  return acos(oa*ob/(oa.norm()*ob.norm()));
}
point bisector(point a, point b) { return a * b.norm() + b * a.norm(); }

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
  point reflection(point p) {
    return projection(p) * 2.0 - p;
  }
  // Segment
  bool onSegment(point p) {
    if (ab == point()) return a == p;
    point pa = a-p, pb = b()-p;
    return eq(pa % pb, 0) && le(pa * pb, 0);
  }
  LD distSegment(point p) {
    if (le((p-a) * ab, 0)) return dist(a, p);
    if (le(0, (p-b()) * ab)) return dist(b(), p);
    return distLine(p);
  }
  point closestSegment(point p) {
    if (le((p-a) * ab, 0)) return a;
    if (le(0, (p-b()) * ab)) return b();
    return projection(p);
  }
  bool areParallel(line l) {
    return eq(ab % l.ab, 0);
  }
  bool areSame(line l) {
    return areParallel(l) && onLine(l.a) && l.onLine(a);
  }
};
bool areIntersect(line l1, line l2, point & res) {
  if (l1.areParallel(l2)) return 0;
  LD ls = (l2.a  - l1.a) % l2.ab, rs = l1.ab % l2.ab;
  res = l1.a + l1.ab * ls/rs;
  return 1;
}

const int N = 16;
vector<point> rec[N];
int cnt[N], lef[N], rig[N];
int n, l;

bool touch(int id) {
  if (cnt[id])
    return true;
  if (lef[id] > 0 && rig[id] > 0)
    return true;
  return false;
}

bool onAnyRec(point p) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 4; ++j) {
      line l(rec[i][j], rec[i][(j+1)&3]);
      if (l.onSegment(p))
        return true;
    }
  }
  return false;
}

int main() {
  scanf("%d %d", &n, &l);
  l *= l;
  vector<int> vx, vy;
  vector<point> all;
  for (int i = 0; i < n; ++i) {
    int xa, ya, xb, yb;
    scanf("%d %d %d %d", &xa, &ya, &xb, &yb);
    rec[i].push_back(point(xa, ya));
    rec[i].push_back(point(xb, ya));
    rec[i].push_back(point(xb, yb));
    rec[i].push_back(point(xa, yb));
    vx.push_back(xa);
    vx.push_back(xb);
    vy.push_back(ya);
    vy.push_back(yb);
  }
  sort(vx.begin(), vx.end());
  vx.erase(unique(vx.begin(), vx.end()), vx.end());
  sort(vy.begin(), vy.end());
  vy.erase(unique(vy.begin(), vy.end()), vy.end());
  vector<point> vp;
  for (int x : vx) {
    for (int y : vy) {
      vp.push_back(point(x, y));
    }
  }
  vector<line> vl;
  vector<point> add;
  for (point p : vp) {
    for (point q : vp) {
      if (p == q) continue;
      line l(p, q);
      vl.emplace_back(l);
      if (eq(p.x, q.x) || eq(p.y, q.y)) continue;
      if (le(dist2(p, q) * 4, l)) {
        point r = q;
        r.x = 2 * p.x - q.x;
        line l2(p, r);
        vl.emplace_back(l2);
      }
    }
  }
  int ans = 1;
  for (line l1 : vl) {
    vector<pair<point, int> > ev;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 4; ++j) {
        line l2(rec[i][j], rec[i][(j+1)&3]);
        point c;
        if (!areIntersect(l1, l2, c)) continue;
        if (!l2.onSegment(c)) continue;
        ev.emplace_back(c, i);
      }
    }
    sort(ev.begin(), ev.end());
    memset(cnt, 0, sizeof cnt);
    memset(lef, 0, sizeof lef);
    memset(rig, 0, sizeof rig);
    for (auto it : ev)
      ++rig[it.second];
    for (int i = 0, j = 0, now = 0; i < ev.size(); ++i) {
      while (j < ev.size() && le(dist2(ev[i].first, ev[j].first), l)) {
        int id = ev[j].second;
        bool pre = touch(id);
        ++cnt[id];
        --rig[id];
        if (touch(id) && !pre)
          ++now;
        ++j;
      }
      ans = max(ans, now);
      int id = ev[i].second;
      bool pre = touch(id);
      --cnt[id];
      ++lef[id];
      if (!touch(id) && pre)
        --now;
    }
  }
  printf("%d\n", ans);
  return 0;
}