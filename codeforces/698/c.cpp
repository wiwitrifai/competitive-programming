#include <bits/stdc++.h>

using namespace std;

typedef long long LD;
const LD EPS = 1e-9, PI = acos(-1);
inline bool eq(LD a, LD b) { return a == b; }
inline bool lt(LD a, LD b) { return a < b; }
inline bool le(LD a, LD b) { return a <= b; }
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
  bool operator<(const point& p) const { return eq(y, p.y) ? x < p.x : y < p.y; }
};
ostream& operator<<(ostream& os, point p) {
  return os << "(" << p.x << ", " << p.y << ")";
}
int ccw(point a, point b, point c) { return sign((b - a) % (c - b)); }

void solve() {
  int n;
  scanf("%d", &n);
  vector<point> vp(n);
  vector<int> ans;
  vector<bool> used(n, false);
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    vp[i] = {x, y};
  }
  int start = 0;
  for (int i = 0; i < n; ++i)
    if (vp[i] < vp[start])
      start = i;
  used[start] = true;
  ans.push_back(start);
  while ((int)ans.size() < n) {
    int selected = -1;
    LD farthest = -1;
    for (int i = 0; i < n; ++i) {
      if (used[i]) continue;
      int sz = ans.size();
      int last = ans[sz-1];
      if (sz > 1 && le((vp[ans[sz-2]] - vp[last]) * (vp[i] - vp[last]), 0)) {
        assert(false);
        continue;
      }
      long long cur = (vp[last] - vp[i]).norm_sq();
      if (cur > farthest) {
        selected = i;
        farthest = cur;
      }
    }
    ans.push_back(selected);
    used[selected] = true;
  }
  for (int i = 0; i < n; ++i)
    printf("%d%c", ans[i]+1, i+1 == n ? '\n' : ' ');
}

int main() {
  int tc = 1;
  // scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
