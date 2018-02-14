#include <bits/stdc++.h>

using namespace std;


typedef long double LD;
const LD EPS = 1e-9, PI = acos(-1);
inline bool equal(LD a, LD b) { return fabs(a-b) < EPS; }
inline bool less(LD a, LD b) { return a + EPS < b; }
inline bool eqless(LD a, LD b) { return a < b + EPS; }
inline int sign(LD x) { return equal(x, 0) ? 0 : (x < 0 ? -1 : 1); }

struct point {
  LD x, y;
  point(LD x = 0, LD y = 0) : x(x), y(y) {}
  point operator+(point p) { return point(x+p.x, y+p.y); }
  point operator-(point p) { return point(x-p.x, y-p.y); }
  point operator*(LD s) { return point(x*s, y*s); }
  point operator/(LD s) { return point(x/s, y/s); }
  LD operator*(point p) { return x*p.x + y*p.y; } // dot
  LD operator%(point p) { return x*p.y - y*p.x; } // cross
  LD norm_sq() { return *this * *this; }
  LD norm() { return sqrt(*this * *this); }
  point rotate(LD cs, LD sn) { return point(x*cs-y*sn, x*sn+y*cs); }
  point rotate(LD angle) { return rotate(cos(angle), sin(angle)); }
  bool operator==(point p) { return equal(x, p.x) && equal(y, p.y); }
  bool operator<(point p) const { return equal(y, p.y) ? x < p.x : y < p.y; }
};
int ccw(point a, point b, point c) { return sign((b - a) % (c - b)); }
LD dist(point a, point b) { return (b-a).norm(); }
LD dist2(point a, point b) { return (b-a).norm_sq(); }
LD angle(point a, point o, point b) {
  point oa = a-o, ob = b-o;
  return acos(oa*ob/(oa.norm()*ob.norm()));
}

vector<point> interCircle(point o1, LD r1, point o2, LD r2) {
  LD d2 = (o1 - o2).norm_sq();
  LD d = sqrt(d2);
  if (d < fabs(r1-r2)) return {};
  if (d > r1+r2) return {};
  point u = (o1+o2) * 0.5 + (o1-o2)*((r2*r2-r1*r1)/(2*d2));
  LD A = sqrt((r1+r2+d) * (r1-r2+d) * (r1+r2-d) * (-r1+r2+d));
  point v = point(o1.y-o2.y, -o1.x+o2.x) * (A / (2*d2));
  return {u+v, u-v};
}

int main() {
  int n;
  scanf("%d", &n);
  vector<pair<int, point> > circles;
  for (int i = 0; i < n; ++i) {
    int x, y, r;
    scanf("%d %d %d", &x, &y, &r);
    pair<int, point> circle = make_pair(r, point(x, y));
    bool ok = 1;
    for (auto it : circles) {
      if (it.first == circle.first && it.second == circle.second)
        ok = 0;
    }
    if (ok)
      circles.push_back(circle);
  }
  sort(circles.begin(), circles.end());
  int ans = 1;
  bool gabung = 1;
  for (int i = 0; i < circles.size(); ++i) {
    vector<point> intersections;
    int nyambung = 1;
    for (int j = 0; j < i; ++j) {
      vector<point> res = interCircle(circles[i].second, circles[i].first, circles[j].second, circles[j].first);
      if (res.size() == 2)
        if (res[0] == res[1])
          res.pop_back();
      if (res.size() == 0 && i == 1 && j == 0)
        gabung = 0;
      // cerr << i << " " << j << " cek " << res.size() << endl;
      if (res.size() == 0)
        nyambung = 0;
      for (point p : res) {
        bool ok = 1;
        for (point q : intersections) if (q == p) {
          ok = 0;
          break;
        }
        if (ok)
          intersections.push_back(p);
      }
    }
    int cur = max((int)intersections.size(), 1);
    // cerr << i << " " << gabung << " " << nyambung << " " << cur << endl;
    if (i == 2 && !gabung && nyambung)
      cur = max(cur-1, 1);
    // cerr << cur << endl;
    ans += cur;
  }
  printf("%d\n", ans);
  return 0;
}