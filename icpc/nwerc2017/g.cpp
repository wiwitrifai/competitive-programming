#include <bits/stdc++.h>

using namespace std;

typedef long double LD;
const LD eps = 1e-8;
const LD PI = acos(-1);
const int ITER = 300;
inline bool eq(LD x, LD y) { return fabs(x - y) < eps; }
inline bool le(LD x, LD y) { return x < y + eps; }
inline bool lt(LD x, LD y) { return x + eps < y; }
inline int sign(LD x) { return eq(x, 0) ? 0 : x < 0 ? -1 : 1; }

struct point {
  LD x, y;
  point(LD x = 0, LD y = 0) : x(x), y(y) {}
  point operator+(point p) { return point(x+p.x, y+p.y); }
  point operator-(point p) { return point(x-p.x, y-p.y); }
  LD operator%(point p) { return x * p.y - y * p.x; }
  LD operator*(point p) { return x * p.x + y * p.y; }
  point operator*(LD s) { return point(x*s, y*s); }
  point operator/(LD s) { return point(x/s, y/s); }
  bool operator==(point p) { return eq(x, p.x) && eq(y, p.y); }
  bool operator<(point p) { return eq(p.x, x) ? y < p.y : x < p.x; }
  point rotate(LD cs, LD sn) { return point(x*cs-y*sn, x*sn+y*cs); }
  point rotate(LD angle) { return rotate(cos(angle), sin(angle)); }
};

int ccw(point a, point b, point c) { return sign((b - a) % (c - b)); }

ostream& operator<<(ostream & os, point p) {
  return os << "(" << p.x << ", " << p.y << ")";
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
  LD val = 0;
  int ans = -1;
  for (int k = 3; k <= 8; ++k) {
    LD l = 0, r = 1e8;
    vector<point> conv(k);
    for (int it = 0; it < ITER; ++it) {
      LD mid = (l + r) / 2;
      bool ok = 1;
      point now(mid, 0);
      for (int i = 0; i < k; ++i) {
        LD angle = i * PI * 2 / k;
        conv[i] = now.rotate(angle);
      }
      for (int i = 0; i < k && ok; ++i) {
        point a = conv[i];
        point b = conv[(i+1) % k];
        assert(sign(a % b) > 0);
        for (point p : vp) {
          if (sign(a % p) >= 0 && sign(p % b) >= 0 && ccw(a, b, p) > 0) {
            ok = 0;
            break;
          }
        }
      }
      if (ok)
        l = mid;
      else
        r = mid;
    }
    LD lo = l;
    l = 0, r = 1e8;
    for (int it = 0; it < ITER; ++it) {
      LD mid = (l + r) / 2;
      bool ok = 1;
      point now(mid, 0);
      for (int i = 0; i < k; ++i) {
        LD angle = i * PI * 2 / k;
        conv[i] = now.rotate(angle);
      }
      for (int i = 0; i < k && ok; ++i) {
        point a = conv[i];
        point b = conv[(i+1) % k];
        assert(sign(a % b) > 0);
        for (point p : vp) {
          if (ccw(a, b, p) < 0) {
            ok = 0;
            break;
          }
        }
      }
      if (ok)
        r = mid;
      else
        l = mid;
    }
    LD cur = (lo / r) * (lo / r);
    if (cur > val) {
      val = cur;
      ans = k;
    }
  }
  printf("%d %.10lf\n", ans, (double)val);
  return 0;
}