#include <bits/stdc++.h>

using namespace std;

const int N = 1000 + 5, mod = 1e9 + 7;

typedef long double LD;
const LD EPS = 1e-9, PI = acos(-1);
inline bool eq(LD a, LD b) { return fabs(a-b) < EPS; }
inline bool lt(LD a, LD b) { return a + EPS < b; }
inline bool le(LD a, LD b) { return a < b + EPS; }
inline int sign(LD x) { return eq(x, 0) ? 0 : (x < 0 ? -1 : 1); }

struct point {
  LD x, y;
  int id;
  point(LD x = 0, LD y = 0, int id = -1) : x(x), y(y), id(id) {}
  point operator+(const point& p) const { return point(x+p.x, y+p.y); }
  point operator-(const point& p) const { return point(x-p.x, y-p.y); }
  point operator*(LD s) { return point(x*s, y*s); }
  point operator/(LD s) { return point(x/s, y/s); }
  LD operator*(const point& p) const { return x*p.x + y*p.y; } // dot
  LD operator%(const point& p) const { return x*p.y - y*p.x; } // cross
  LD norm_sq() { return *this * *this; }
  LD norm() { return sqrt(*this * *this); }
  bool operator==(const point& p) const { return eq(x, p.x) && eq(y, p.y); }
  bool operator<(const point& p) const { return eq(y, p.y) ? x < p.x : y < p.y; }
};
int ccw(point a, point b, point c) { return sign((b - a) % (c - b)); }
LD dist2(point a, point b) { return (b-a).norm_sq(); }
LD dist(point a, point b) { return (b-a).norm(); }


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

ostream& operator<<(ostream& os, point p) {
  os << "(" << p.x << "," << p.y << "," << p.id << ") ";
  return os;
}

int n;
vector<point> all;

int ans[N];
bool used[N];
int h[N];

bool inside(point p, point a, point b, point c) {
  line ap(a, p), bc(b, c);
  point d;
  if (!areIntersect(ap, bc, d)) {
    LD hnow = (h[c.id] - h[b.id]) * dist(a, p) / dist(b, c) * sign((c-b) * (p - a));
    return lt(h[p.id], hnow);
  }
  LD hd = h[b.id] + (h[c.id] - h[b.id]) * dist(d, b) / dist(b, c) * sign((c-b) * (d-b));
  LD hnow = h[a.id] + (hd - h[a.id]) * dist(p, a) / dist(a, d) * sign((p-a) * (d-a));
  return lt(h[p.id], hnow);
}

bool cek(point a, point b, point c) {
  for (int i = 0; i < n; ++i) {
    if (used[i]) continue;
    if (i == a.id || i == b.id || i == c.id) continue;
    if (!inside(all[i], a, b, c)) return false;
  }
  return true;
}

int find(int a, int b) {
  int x = -1;
  for (int i = 0; i < n; ++i) {
    if (used[i]) continue;
    if (ccw(all[a], all[b], all[i]) <= 0) continue;
    if (x == -1 || !inside(all[i], all[a], all[b], all[x]))
      x = i;
  }
  if (x == -1) {
    for (int i = 0; i < n; ++i) {
      if (used[i]) continue;
      if (ccw(all[a], all[b], all[i]) > 0) continue;
      if (x == -1 || !inside(all[i], all[a], all[b], all[x]))
        x = i;
    }
  }
  return x;
}

void rec(int a, int b, int id) {
  ans[id] = b;
  if (id + 1 == n) return;
  int x = find(a, b);
  used[x] = 1;
  bool res = cek(all[a], all[b], all[x]);
  rec(b, x, id+1);
}

void solve() {
  scanf("%d", &n);
  all.resize(n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d %d", &x, &y, h+i);
    all[i] = (point(x, y, i));
  }
  int a = 0, b = -1;
  for (int i = 0; i < n; ++i)
    if (h[i] >= h[a]) a = i;
  ans[0] = a;
  memset(used, 0, sizeof used);
  used[a] = 1;
  for (int i = 0; i < n; ++i) {
    if (i == a) continue;
    b = i;
    used[b] = 1;
    int x = find(a, b);
    used[x] = 1;
    if (x != -1 && cek(all[a], all[b], all[x])) {
      used[x] = 0;
      break;
    }
    used[x] = 0;
    used[b] = 0;
    b = -1;
  }
  ans[1] = b;
  used[b] = 1;
  rec(a, b, 1);
  reverse(ans, ans+n);
  for (int i = 0; i < n; ++i) {
    printf("%d%c", ans[i]+1, i+1 == n ? '\n' : ' ');
  }
}

int main() {
  time_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    printf("Case #%d: ", tc);
    solve();
    cerr << "~ #" << tc << " done! time : " << (double)(clock()-startt) * 1000/CLOCKS_PER_SEC << " ms" << endl;
  }
  return 0;
} 