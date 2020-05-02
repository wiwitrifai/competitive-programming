#include <bits/stdc++.h>

using namespace std;

typedef long double LD;

const LD eps = 1e-8;

inline bool eq(LD x, LD y) { return fabs(x - y) < eps; }
inline bool le(LD x, LD y) { return x < y + eps; }
inline bool lt(LD x, LD y) { return x + eps < y; }
inline int sign(LD x) { return eq(x, 0) ? 0 : x < 0 ? -1 : 1; }

struct point {
  point(LD x = 0, LD y = 0) : x(x), y(y) {}
  point operator+(point p) { return point(x + p.x, y + p.y); }
  point operator-(point p) { return point(x - p.x, y - p.y); }
  point operator*(LD s) { return point(x * s, y * s); }
  point operator/(LD s) { return point(x / s, y / s); }
  LD operator%(point p) { return x * p.y - y * p.x; }
  LD operator*(point p) { return x * p.x + y * p.y; }
  bool operator==(point p) { return eq(x, p.x) && eq(y, p.y); }
  bool operator<(point p) { return eq(y, p.y) ? lt(x, p.x) : lt(y, p.y); }
  LD x, y;
};

ostream& operator<<(ostream& os, point p) {
  return os << "(" << p.x << ", " << p.y << ")";
}

bool inLine(point p, point q, point c) {
  return eq((c - p) % (q - p), 0);
}

bool intersect(point a, point b, point p, point q, point & res) {
  point ab = b - a, pq = q - p;
  if (eq(ab % pq, 0))
    return false;
  LD t = ((p - a) % pq) / (ab % pq);
  res = a + ab * t;
  return true;
}

int main() {
  int n;
  scanf("%d", &n);
  vector<pair<point, point>> vp;
  for (int i = 0; i < n; ++i) {
    int xa, ya, xb, yb;
    scanf("%d %d %d %d", &xa, &ya, &xb, &yb);
    vp.emplace_back(point(xa, ya), point(xb, yb));
  }
  if (n == 1) {
    puts("1");
    return 0;
  }
  point c;
  if (!intersect(vp[0].first, vp[1].first, vp[0].second, vp[1].second, c)) {
    c = point(-1e18, -1e18);
  }
  vector<point> line1, line2;
  for (int i = 0; i < n; ++i) {
    line1.push_back(vp[i].first);
    line2.push_back(vp[i].second);
  }
  sort(line1.begin(), line1.end());
  sort(line2.begin(), line2.end());
  int mid1 = lower_bound(line1.begin(), line1.end(), c) - line1.begin();
  int mid2 = lower_bound(line2.begin(), line2.end(), c) - line2.begin();
  int ans = 0;
  vector<pair<int, int> > pairs[4];
  for (int i = 0; i < n; ++i) {
    if (vp[i].first == c || vp[i].second == c) {
      ++ans;
      continue;
    }
    int pos1 = lower_bound(line1.begin(), line1.end(), vp[i].first) - line1.begin();
    int pos2 = lower_bound(line2.begin(), line2.end(), vp[i].second) - line2.begin();
    int id = ((pos1 < mid1)) | ((pos2 < mid2) << 1);
    if (id == 1 || id == 2)
      pos1 = n - pos1;
    pairs[id].emplace_back(pos1, pos2);
  }
  for (auto & p : pairs) {
    sort(p.begin(), p.end());
    vector<int> incr;
    for (int i = 0; i < p.size(); ++i) {
      int pos = lower_bound(incr.begin(), incr.end(), p[i].second) - incr.begin();
      if (pos == incr.size())
        incr.push_back(p[i].second);
      incr[pos] = p[i].second;
    }
    ans += (int)incr.size();
  }
  printf("%d\n", ans);
  return 0;
}
