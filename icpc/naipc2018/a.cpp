#include <bits/stdc++.h>

using namespace std;

typedef long double LD;
const LD EPS = 1e-9, PI = acos(-1), inf = 1e18;
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
  bool areParallel(line l) {
    return eq(ab % l.ab, 0);
  }
  bool areSame(line l) {
    return areParallel(l) && onLine(l.a) && l.onLine(a);
  }
};
ostream& operator<<(ostream& o, point p) { return o << "(" << p.x << ", " << p.y << ")"; }
bool areIntersect(line l1, line l2, point & res) {
  if (l1.areParallel(l2)) return 0;
  LD ls = (l2.a  - l1.a) % l2.ab, rs = l1.ab % l2.ab;
  res = l1.a + l1.ab * ls/rs;
  return 1;
}

const int N = 402;

point ab[N][N], bb[N][N];
point bri[N], ble[N];
bool bab[N][N], bbb[N][N];
vector<point> a, b;

int na(int i) {
  while (i >= (int)a.size()) i -= (int)a.size();
  return i;
}
int nb(int i) {
  while (i >= (int)b.size()) i -= (int)b.size();
  return i;
}

LD dp[N][N];
bool vis[N][N];
LD solve(int l, int r) {
  if (l == r) return 0;
  if (l+1 == r) {
    return dist(b[nb(r)], b[nb(l)]);
  }
  LD & res = dp[l][r];
  if (vis[l][r])
    return res;
  vis[l][r] = 1;
  res = inf;
  for (int i = l; i < r; ++i) {
    LD cur = 0;
    point ri = bri[nb(i)], le = ble[nb(i)];
    point mid = (b[nb(i)] + b[nb(i+1)]) / 2.0;
    vector<point> proc;
    if (bbb[nb(i)][nb(l+b.size()-1)])
      proc.push_back(bb[nb(i)][nb(l+b.size()-1)]);
    if (bbb[nb(i)][nb(r)])
      proc.push_back(bb[nb(i)][nb(r)]);
    for (point p : proc) {
      if (mid < p) {
        if (p < ri)
          ri = p;
      }
      if (p < mid) {
        if (le < p)
          le = p;
      }
    }
    cur = dist(le, ri);
    if (l < i)
      cur += solve(l, i);
    if (i+1 < r)
      cur += solve(i+1, r);
    res = min(res, cur);
  }
  return res;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    a.push_back(point(x, y));
  }
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    b.push_back(point(x, y));
  }
  for (int i = 0; i < a.size(); ++i) {
    for (int j = 0; j < b.size(); ++j) {
      line l1(a[i], a[na(i+1)]), l2(b[j], b[nb(j+1)]);
      bab[i][j] = areIntersect(l1, l2, ab[i][j]);
    }
  }
  for (int i = 0; i < b.size(); ++i) {
    bool le = 0, ri = 0;
    point cur = (b[i] + b[nb(i+1)]) / 2;
    for (int j = 0; j < a.size(); ++j) {
      if (!bab[j][i]) continue;
      point p = ab[j][i];
      if (cur < p) {
        if (!ri || p < bri[i])
          bri[i] = p, ri = 1;
      }
      else {
        if (!le || ble[i] < p)
          ble[i] = p, le = 1;
      }
    }
    assert(le && ri);
  }
  for (int i = 0; i < b.size(); ++i) {
    for (int j = i+1; j < b.size(); ++j) {
      line l1(b[i], b[nb(i+1)]), l2(b[j], b[nb(j+1)]);
      bbb[i][j] = areIntersect(l1, l2, bb[i][j]);
      bbb[j][i] = bbb[i][j];
      bb[j][i] = bb[i][j];
    }
  }
  LD ans = inf;
  for (int i = 0; i < b.size(); ++i) {
    LD cur = dist(bri[i], ble[i]) + solve(i+1, i+n);
    ans = min(ans, cur);
  }
  printf("%.12lf\n", (double)ans);
  return 0;
}