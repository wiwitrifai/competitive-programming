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
  return os << "(" << (long double)p.x << ", " << (long double)p.y << ")";
}

// 1 : ccw, -1 : cw, 0 : colinear
int ccw(point a, point b, point c) {
  return sign((b-a) % (c-b));
}

bool intersect(point a, point b, point p, point q) {
  return ccw(a, b, p) * ccw(a, b, q) < 0 && ccw(p, q, a) * ccw(p, q, b) < 0;
}

int main() {
  int n;
  scanf("%d", &n);
  vector<point> vp(n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    vp[i] = point(x, y);
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      bool ok = true;
      for (int k = 0; k < n && ok; ++k) {
        if (k == i || k == j) continue;
        for (int l = k+1; l < n && ok; ++l) {
          if (l == i || l == j) continue;
          ok &= !intersect(vp[i], vp[j], vp[k], vp[l]);
        }
      }
      ans += ok;
    }
  }
  printf("%d\n", ans);
  return 0;
}
