#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
const ld EPS = 1e-12, PI = acos(-1);
const int STEP = 200, ITER = 100;

struct point {
  ld x, y;
  bool segi;
  point(ld x = 0, ld y = 0, bool segi = 0) : x(x), y(y), segi(segi) {
  }
  bool operator==(point p) const {
    return (fabs(x - p.x) < EPS) && (fabs(y - p.y) < EPS);
  }
  point operator+(point p) const { return point(x+p.x, y+p.y); }
  point operator-(point p) const { return point(x-p.x, y-p.y); }
  ld operator*(point p) const { return x * p.x + y * p.y; }
  point operator*(ld s) const { return point(x * s, y * s); }
  point operator/(ld s) const { return point(x / s, y / s); }
  ld operator%(point p) const { return x * p.y - y * p.x; } 
};

bool cmp(point a, point b) {
  ld ret = a % b;
  return ret > 0;
}
bool is_up(point & p) {
  if (fabs(p.y) < 0)
    return p.x > 0;
  return p.y > 0;
}

void sort_cycle(vector<point> & vp) {
  vector<point> up, down;
  for (point & p : vp) {
    if (is_up(p))
      up.push_back(p);
    else
      down.push_back(p);
  }
  sort(up.begin(), up.end(), cmp);
  sort(down.begin(), down.end(), cmp);
  vp = up;
  for (point & p : down)
    vp.push_back(p);
}

struct line {
  ld a, b, c;
};

void pointToLine(point p1, point p2, line & l) {
  if (fabs(p1.x -p2.x) < EPS) {
    l.a = 1.0, l.b = 0.0, l.c = -p1.x;
  }
  else {
    l.a = - (ld)(p1.y - p2.y) / (p1.x - p2.x);
    l.b = 1.0;
    l.c = - (ld)(l.a * p1.x) - (ld)(l.b * p1.y);
  }
}

ld distToLine(point p, line l) {
  ld up = p.x * l.a + p.y * l.b;
  return fabs(up) / sqrt(l.a * l.a + l.b * l.b);
}

int n, m;
vector<point> vp;

ld calc(ld offset) {
  vector<point> cur = vp;
  for (int i = 0; i < m; i++) {
    cur.push_back(point(cos(i * 2.0 * PI/m + offset), sin(i * 2.0 * PI/m + offset), true));
  }
  sort_cycle(cur);
  ld ans = 1e18;
  bool ok = 0;
  int l = (int)cur.size() - 1, r = 0;
  while (!cur[l].segi) l--;
  while (!cur[r].segi) r++;
  line ln;
  pointToLine(cur[l], cur[r], ln);
  ln.c = 0;
  for (int i = 0; i < cur.size(); i++) {
    if (i == r) {
      l = i;
      r = i+1;
      while (!cur[r].segi) {
        r++;
        if (r >= cur.size())
          r -= (int)cur.size();
      }
      pointToLine(cur[l], cur[r], ln);
      ln.c = 0;      
      continue;
    }
    if (ok)
      ans = min(ans, distToLine(cur[i], ln));
    else
      ans = distToLine(cur[i], ln), ok = 1;
  }
  return ans;
}

ld calc2(ld lo, ld hi) {
  ld ans = 0;
  for (int iter = 0; iter < ITER; iter++) {
    ld le = (lo + lo + hi) / 3.0, ri = (lo + hi + hi) / 3.0;
    ld vle = calc(le), vri = calc(ri);
    ans = max(ans, max(vle, vri));
    if (vle < vri)
      lo = le;
    else
      hi = ri;
  }
  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &m);
    vp.clear();
    for (int i = 0; i < n; i++) {
      double x, y;
      scanf("%lf %lf", &x, &y);
      vp.push_back(point(x, y));
    }
    ld lo = 0, hi = 2.0 * PI/m;
    ld ans = calc(lo);
    ld maju = hi/STEP;
    for (int step = 0; step < STEP; step++) {
      ld cur = hi * step/STEP;
      ld res = calc2(cur, cur + maju);
      if (ans < res)
        ans = res, lo = cur;
    }
    ld res = ans / cos(PI/m);
    printf("%.20lf\n", (double) res);
  }
  return 0;
}