#include <bits/stdc++.h>

using namespace std;

typedef long long LD;

inline bool eq(LD x, LD y) { return x == y; }
inline bool le(LD x, LD y) { return x <= y; }
inline bool lt(LD x, LD y) { return x < y; }
inline int sgn(LD x) { return eq(x, 0) ? 0 : x < 0 ? -1 : 1; }

struct point {
  LD x, y;
  point (LD x = 0, LD y = 0) : x(x), y(y) {}
  point operator+(point p) { return point(x + p.x, y + p.y); }
  point operator-(point p) { return point(x - p.x, y - p.y); }
  point operator*(LD s) { return point(x * s, y * s); }
  point operator/(LD s) { return point(x / s, y / s); }
  LD operator*(point p) { return x * p.x + y * p.y; }
  LD operator%(point p) { return x * p.y - y * p.x; }
  bool operator==(point p) const { return eq(x, p.x) && eq(p.y, y); }
  bool operator<(point p) const { return eq(y, p.y) ? lt(x, p.x) : lt(y, p.y); }
};

LD dist2(point a, point b) {
  return (a - b) * (a - b);
}
int ccw(point a, point b, point c) {
  return sgn((b - a) % (c - b));
}

point pivot;
bool cmp_ang(point p, point q) {
  int ori = ccw(pivot, p, q);
  if (ori == 0)
    return lt(dist2(pivot, p), dist2(pivot, q));
  return ori > 0;
}

void convex_hull(vector<point> & vp) {
  if (vp.size() < 3) return;
  int n = vp.size();
  for (int i = 1; i < n; ++i) {
    if (vp[i] < vp[0])
      swap(vp[i], vp[0]);
  }
  pivot = vp[0];
  sort(vp.begin() + 1, vp.end(), cmp_ang);
  vector<point> ch;
  for (int i = 0; i < n; ++i) {
    int sz;
    while ((sz = ch.size()) > 1 && ccw(ch[sz-2], ch[sz-1], vp[i]) <= 0) ch.pop_back();
    ch.push_back(vp[i]);
  }
  vp.swap(ch);
}

int main() {
  int n, r;
  scanf("%d %d", &n, &r);
  vector<point> vp;
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    vp.push_back(point(x, y));
  }
  convex_hull(vp);
  n = vp.size();
  auto next = [n](int x) { return x == n-1 ? 0 : x+1; };
  long double ans = r * 2;
  for (int i = 0, j = next(0); i < n; ++i) {
    point nx = vp[next(i)];
    if (j == i) j = next(i);
    while (j != i && (nx - vp[i]) % (vp[next(j)] - vp[j]) > 0) j = next(j);
    ans = min(ans, fabs(((vp[j] - vp[i]) % (nx - vp[i]))/sqrtl(dist2(vp[i], nx))));
  }
  printf("%.20lf\n", (double) ans);
  return 0;
}
