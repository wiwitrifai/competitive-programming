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
  bool operator<(const point& p) const { return eq(x, p.x) ? y > p.y : x < p.x; }
};

struct parabola {
  LD b, c;
  parabola() {}
  parabola(point p, point q) {
    b = (p.y - p.x * p.x - q. y + q.x * q.x) / (p.x - q.x);
    c = p.y - p.x * (p.x + b);
  }
  LD calc(LD x) {
    return x * (x + b) + c;
  }
  bool inside(point p) {
    return le(calc(p.x), p.y);
  }
};

bool check(point a, point b, point c) {
  parabola par(a, b);
  return par.inside(c);
}


int main() {
  int n;
  scanf("%d", &n);
  vector<point>vp;
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    vp.push_back(point(x, y));
  }
  sort(vp.begin(), vp.end());
  vector<point> ans;
  ans.push_back(vp[0]);
  for (int i = 1; i < n; ++i) {
    if (eq(ans.back().x, vp[i].x)) continue;
    int sz;
    while ((sz = (int)ans.size()) >= 2 && check(ans[sz-2], ans[sz-1], vp[i]))
      ans.pop_back();
    ans.push_back(vp[i]);
  }
  int res = (int)ans.size() - 1;
  printf("%d\n", res);
  return 0;
}
