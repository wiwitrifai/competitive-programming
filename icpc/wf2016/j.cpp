#include <bits/stdc++.h>

using namespace std;

typedef long long LD;
const LD EPS = 1e-9;
inline bool eq(LD x, LD y) { return x == y; }
inline bool lt(LD x, LD y) { return x < y; }
inline bool le(LD x, LD y) { return x <= y; }
inline int sgn(LD x) { return eq(x, 0) ? 0 : x < 0 ? -1 : 1; }

struct point {
  LD x, y;
  point(LD x = 0, LD y = 0) : x(x), y(y) {}
  point operator+(point p) { return point(x + p.x, y + p.y); }
  point operator-(point p) { return point(x - p.x, y - p.y); }
  point operator*(LD s) { return point(x * s, y * s); }
  point operator/(LD s) { return point(x / s, y / s); }
  LD operator *(point p) { return x * p.x + y * p.y; }
  LD operator %(point p) { return x * p.y - y * p.x; }
  LD norm_sq() { return *this * *this; }
  LD norm() { return sqrt(*this * *this); }
  bool operator==(point p) const { return eq(x, p.x) && eq(y, p.y); }
  bool operator<(point p) const { return eq(y, p.y) ? lt(x, p.x) : lt(y, p.y); }
};
ostream & operator<<(ostream & os, point p) { return os << "(" << p.x << "," << p.y << ")"; }

LD dist2(point a, point b) {
  return (b - a).norm_sq();
}

int ccw(point a, point b, point c) {
  return sgn((b - a) % (c - b));
}

point pivot;
bool cmp_angle(point a, point b) {
  int c = ccw(pivot, a, b);
  if (c == 0)
    return dist2(pivot, a) < dist2(pivot, b);
  return c > 0;
}

void convex_hull(vector<point>& vp) {
  if (vp.size() <= 2)
    return;
  int o = 0, n = vp.size();
  for (int i = 1; i < n; ++i)
    if (vp[i] < vp[o])
      o = i;
  swap(vp[o], vp[0]);
  pivot = vp[0];
  sort(vp.begin()+1, vp.end(), cmp_angle);
  vector<point> hull;
  hull.push_back(vp[0]);
  hull.push_back(vp[1]);
  for (int i = 2; i < n; ++i) {
    int s;
    while ((s = hull.size()) >= 2 && ccw(hull[s-2], hull[s-1], vp[i]) <= 0) hull.pop_back();
    hull.push_back(vp[i]);
  }
  vp = hull;
}

int pointVsPolygon(point p, vector<point> & vp) {
  int n = vp.size();
  if (n == 1)
    return p == vp[0] ? 0 : 1;
  if (n == 2)
    return (ccw(vp[0], vp[1], p) == 0 && (vp[0] - p) * (vp[1] - p) <= 0) ? 0 : 1;
  if (ccw(vp[0], vp[n-1], p) > 0) return 1;
  if (ccw(vp[0], vp[1], p) < 0) return 1;
  int l = 1, r = n-1;
  while (l + 1 < r) {
    int mid = (l + r) >> 1;
    if (ccw(vp[0], vp[mid], p) > 0)
      l = mid;
    else
      r = mid;
  }
  return ccw(vp[r], vp[l], p);
}

template<typename Lambda>
int extremeVertex(vector<point> & vp, Lambda cmp) { // assume p is outside polygon
  int n = vp.size();
  if (n <= 1) return 0;
  int step = 1;
  while (step < n) step <<= 1;
  int pos = 0;
  for (; step > 0; step >>= 1) {
    int best = pos;
    for (int d = -1; d < 2; d += 2) {
      int now = ((pos + step * d) % n + n) % n;
      if (cmp(vp[now], vp[best]) > 0)
        best = now;
    }
    pos = best;
  }
  assert(cmp(vp[pos], vp[(pos+n-1) % n]) >= 0 || cmp(vp[pos], vp[(pos+1) % n]) >= 0);
  return pos;
}

pair<int, int> tangentsConvex(point p, vector<point> & poly) {
  return {
    extremeVertex(poly, [&p](point a, point b) { return ccw(p, a, b); }),
    extremeVertex(poly, [&p](point a, point b) { return ccw(p, b, a); })};
}

bool cmp2(pair<point, int> le, pair<point, int> ri) {
  int c = ccw(point(), le.first, ri.first);
  if (c == 0)
    return le.second > ri.second;
  return c > 0;
}
void sort_angular(vector<pair<point, int> > & vp) {
  vector<pair<point, int> > up, down;
  for (pair<point, int> p : vp) {
    if (point() < p.first)
      up.push_back(p);
    else
      down.push_back(p);
  }
  sort(up.begin(), up.end(), cmp2);
  sort(down.begin(), down.end(), cmp2);
  vp = up;
  for (auto it : down)
    vp.push_back(it);
}

int main() {
  int n;
  scanf("%d", &n);
  vector<point> vote, novote;
  for (int i = 0; i < n; ++i) {
    int x, y, t;
    scanf("%d %d %d", &x, &y, &t);
    if (t)
      vote.push_back(point(x, y));
    else
      novote.push_back(point(x, y));
  }
  int ans = vote.size();
  convex_hull(vote);
  if (vote.size() == 1) {
    printf("%d\n", ans);
    return 0;
  }
  if (vote.size() == 2) {
    for (point p : novote)
      if (ccw(vote[0], vote[1], p) == 0 && (vote[0] - p) * (vote[1] - p) <= 0)
        ++ans;
    printf("%d\n", ans);
    return 0;
  }
  vector<pair<point, int> > event;
  int cnt = 0;
  for (point p : novote) {
    if (pointVsPolygon(p, vote) > 0) {
      pair<int, int> tangent = tangentsConvex(p, vote);
      point masuk = vote[tangent.first] - p, keluar = vote[tangent.second] - p;
      if (masuk < point() && point() < keluar) {
        ++cnt;
      }
      event.emplace_back(masuk, +1);
      event.emplace_back(keluar, -1);
      
      masuk = masuk * -1;
      keluar = keluar * -1;
      if (masuk < point() && point() < keluar) {
        ++cnt;
      }
      event.emplace_back(masuk, 1);
      event.emplace_back(keluar, -1);
    }
    else
      ++ans;
  }
  sort_angular(event);
  int off = ans;
  cnt += off;
  ans = cnt;
  for (auto it : event) {
    cnt += it.second;
    ans = min(ans, cnt);
  }
  printf("%d\n", ans);
  return 0;
}
