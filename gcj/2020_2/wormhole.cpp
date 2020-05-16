#include <bits/stdc++.h>

using namespace std;


typedef long long LD;
inline bool eq(LD a, LD b) { return a == b; }
inline bool lt(LD a, LD b) { return a < b; }
inline bool le(LD a, LD b) { return a <= b; }
inline int sign(LD x) { return eq(x, 0) ? 0 : (x < 0 ? -1 : 1); }

struct point {
  LD x, y;
  point(LD _x = 0, LD _y = 0) : x(_x), y(_y) {}
  point operator+(const point& p) const { return point(x+p.x, y+p.y); }
  point operator-(const point& p) const { return point(x-p.x, y-p.y); }
  point operator*(LD s) { return point(x*s, y*s); }
  point operator/(LD s) { return point(x/s, y/s); }
  LD operator*(const point& p) const { return x*p.x + y*p.y; } // dot
  LD operator%(const point& p) const { return x*p.y - y*p.x; } // cross
  LD norm_sq() { return *this * *this; }
  bool operator==(const point& p) const { return eq(x, p.x) && eq(y, p.y); }
  bool operator<(const point& p) const { return eq(y, p.y) ? x < p.x : y < p.y; }
};
ostream& operator<<(ostream& os, point p) {
  return os << "(" << p.x << ", " << p.y << ")";
}
// -1 : clockwise, 0 = collinear, 1 : counter-clockwise
int ccw(point a, point b, point c) { return sign((b - a) % (c - b)); }

LD dist(point a, point b) { return (b-a).norm_sq(); }


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
    return (p-a) % ab;
  }
  // Segment
  bool onSegment(point p) {
    if (ab == point()) return a == p;
    point pa = a-p, pb = b()-p;
    return eq(pa % pb, 0) && le(pa * pb, 0);
  }
  bool areParallel(line l) {
    return eq(ab % l.ab, 0);
  }
  bool areSame(line l) {
    return areParallel(l) && onLine(l.a) && l.onLine(a);
  }
};


void solve() {
  int n;
  scanf("%d", &n);
  vector<point> vp(n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    vp[i] = point(x, y);
  }
  vector<point> points = vp;
  int ans = 0;
  if (n <= 2) {
    printf("%d\n", n);
    return;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      line ln(vp[i], vp[j]);
      sort(points.begin(), points.end(), [&](point l, point r) {
        return ln.distLine(l) < ln.distLine(r);
      });
      int odd = 0, cur = 0, one = 0;
      for (int k = 0; k < n;) {
        int len = 1;
        while (k + len < n && ln.distLine(points[k]) == ln.distLine(points[k+len])) {
          ++len;
        }
        if (len == 1)
          ++one;
        else
          odd += (len&1) == 1;
        k += len;
      }
      one -= 2;
      if (odd & 1)
        ++one;
      cur = n - max(one, 0);
      ans = max(ans, cur);
    }
  }
  printf("%d\n", ans);
}

int main() {
#ifdef LOCAL
  time_t starttime = clock();
#endif
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    printf("Case #%d: ", tc);
    solve();
#ifdef LOCAL
    cerr << "~ TC#" << tc << " done! execution time: " <<
      (double)(clock()-starttime) / CLOCKS_PER_SEC << " s" << endl;
#endif
  }
  return 0;
}
