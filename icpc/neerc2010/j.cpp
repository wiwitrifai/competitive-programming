#include <bits/stdc++.h>

using namespace std;

const string NAME = "jungle";

typedef long double LD;

const LD eps = 1e-9;

inline bool eq(LD x, LD y) { return fabs(x - y) < eps; }
inline bool le(LD x, LD y) { return x < y + eps; }
inline bool lt(LD x, LD y) { return x + eps < y; }
inline int sgn(LD x) { return eq(x, 0) ? 0 : x < 0 ? -1 : 1; }

struct point {
  LD x, y;
  point(LD x = 0, LD y = 0) : x(x), y(y) {}
  point operator+(point p) { return point(x + p.x, y + p.y); }
  point operator-(point p) { return point(x - p.x, y - p.y); }
  point operator*(LD s) { return point(x * s, y * s); }
  point operator/(LD s) { return point(x / s, y / s); }
  LD operator*(point p) { return x * p.x + y * p.y; }
  LD operator%(point p) { return x * p.y - y * p.x; }
  bool operator<(point p) const { return eq(y, p.y) ? lt(x, p.x) : lt(y, p.y); }
  bool operator==(point p) const { return eq(y, p.y) && eq(x, p.x); }
};

ostream& operator<<(ostream& os, point p) {
  return os << "(" << p.x << ", "<< p.y << ")";
}

int ccw(point a, point b, point c) {
  return sgn((b - a) % (c - b));
}

struct line {
  point a, ab;
  line(point a, point b) : a(a), ab(b-a) {
  }
  point b() { return a + ab; }
  bool onSegment(point p) {
    if (ab == point()) return a == p;
    point pa = a-p, pb = b()-p;
    return eq(pa % pb, 0) && le(pa * pb, 0);
  }
  bool areParallel(line l) {
    return eq(ab % l.ab, 0);
  }
  bool onLine(point p) {
    if (ab == point()) return a == p;
    return eq(ab % (p-a), 0);
  }
};

bool areIntersect(line l1, line l2, point & res) {
  if (l1.areParallel(l2)) return 0;
  LD ls = (l2.a  - l1.a) % l2.ab, rs = l1.ab % l2.ab;
  res = l1.a + l1.ab * ls/rs;
  return 1;
}


vector<point> vp;

bool can(int c) {
  if (c >= vp.size()) return false;
  point a = vp[0], b = vp[c];
  int n = vp.size();
  if (b < a) swap(a, b);
  vector<pair<point, int> > inter;
  line l(a, b);
  for (int i = 1; i < n; ++i) {
    point p = vp[i], q = vp[(i+c) % n];
    line t(p,q);
    point r;
    bool res = areIntersect(l, t, r);
    if (!res || !l.onSegment(r)) continue; 
    assert(l.onLine(r) && t.onLine(r));
    int sign = 1;
    cerr << l.a << " " << l.b() << " " << t.a << " " << t.b() << endl;  
    cerr << p << " " << q << " " << a << " " << b << " " << r << " " << res << endl;
    if (ccw(p, q, a) < 0 || ccw(p, q, b) > 0)
      sign = -1;
    inter.emplace_back(r, sign);
  }
  sort(inter.begin(), inter.end());
  int last = -1;
  //~ cerr << c << endl;
  bool ok = 1;
  for (int i = 0; i < inter.size(); ++i) {
    if (last > 0 && inter[i].second < 0)
      ok = 0;
    //~ cerr << inter[i].first << " " << inter[i].second << " ";
    last = inter[i].second;
  }
  //~ cerr << ok << endl;
  return ok;
}

int main() {
#ifndef LOCAL
  freopen((NAME + ".in").c_str(), "r", stdin);
  freopen((NAME + ".out").c_str(), "w", stdout);
#endif
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    vp.push_back(point(x, y));
  }
  reverse(vp.begin(), vp.end()); // reverse to ccw
  for (point p : vp)
    cerr << p << endl;
  int l = 1, r = n/2 + 1;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (can(mid+1))
      l = mid + 1;
    else
      r = mid;
  } 
  printf("%d\n", l);
#ifndef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}