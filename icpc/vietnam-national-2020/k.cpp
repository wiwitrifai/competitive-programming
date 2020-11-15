#include <bits/stdc++.h>

using namespace std;


typedef long long LD;

inline bool eq(LD x, LD y) { return x == y; }
inline bool le(LD x, LD y) { return x <= y; }
inline bool lt(LD x, LD y) { return x < y; }
inline int sign(LD x) { return eq(x, 0) ? 0 : (x < 0 ? -1 : 1); }

struct point {
  LD x, y;
  point(LD _x = 0, LD _y = 0) : x(_x), y(_y) {}
  point operator+(point p) { return point(x+p.x, y+p.y); }
  point operator-(point p) { return point(x-p.x, y-p.y); }
  point operator*(LD s) { return point(x * s, y * s); }
  point operator/(LD s) { return point(x / s, y / s); }
  LD operator*(point p) { return x * p.x + y * p.y; }
  LD operator%(point p) { return x * p.y - y * p.x; }
  LD norm2() { return *this * *this; }
  bool operator<(point p) const { return eq(y, p.y) ? x < p.x : y < p.y; }
  bool operator==(point p) { return eq(x, p.x) && eq(y, p.y); }
};

ostream& operator<<(ostream & os, point p) {
  return os << "(" << p.x << ", " << p.y << ")";
}

// 1 : ccw, -1 : cw, 0 : colinear
int ccw(point a, point b, point c) {
  return sign((b-a) % (c-b));
}

vector<point> vp(4), points, pp;

inline int rec(int id, int i) {
  if (id == 4) {
    pp = vp;
    sort(pp.begin(), pp.end());
    sort(pp.begin()+1, pp.end(), [&](point & le, point & ri) {
      return ccw(pp[0], le, ri) > 0;
    });
    for (int j = 0; j < 2; ++j)
      pp.push_back(pp[j]);
    for (int j = 0; j < 4; ++j) {
      if (ccw(pp[j], pp[j+1], pp[j+2]) <= 0)
        return 0;
    }
    return 1;
  }
  int ret = 0;
  while (i < (int)points.size()) {
    vp[id] = points[i];
    ret += rec(id+1, i+1);
    ++i;
  }
  return ret;
}

void solve() {
  int n;
  scanf("%d", &n);
  if (n == 0)
    exit(0);
  points.resize(n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    points[i] = point(x, y);
  }
  int ans = rec(0, 0);
  printf("%d\n", ans);
}

int main() {
  int tc = 1;
  // scanf("%d", &tc);
  while (true) {
    solve();
  }
  return 0;
}
