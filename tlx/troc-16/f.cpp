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

const int inf = int(2e9) + 7;

// 1 : ccw, -1 : cw, 0 : colinear
int ccw(point a, point b, point c) {
  return sign((b-a) % (c-b));
}

int main() {
  int n, m;
  long long r;
  scanf("%d %d %lld", &n, &m, &r);
  vector<point> vp(n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    vp[i] = point(x, y);
  }
  vector<point> cir(m);
  vector<int> cost(m);
  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d %d %d", &x, &y, &cost[i]);
    cir[i] = point(x, y);
  }
  r *= r;
  int nmask = 1 << m;
  vector<int> dp(nmask, 0);
  for (int i = 0; i < n; ++i) {
    int mask = 0;
    for (int j = 0; j < m; ++j) {
      long long d = (vp[i] - cir[j]).norm2();
      if (d <= r) {
        mask |= 1 << j;
      }
    }
    ++dp[mask];
  }
  for (int i = 0; i < m; ++i) {
    int cur = 1 << i;
    for (int mask = 0; mask < nmask; ++mask) {
      if (mask & cur) continue;
      dp[mask | cur] += dp[mask];
    }
  }
  vector<int> ans(n+1, inf);
  for (int mask = 0; mask < nmask; ++mask) {
    int cur = 0;
    for (int i = 0; i < m; ++i) {
      if (mask & (1 << i)) continue;
      cur += cost[i];
    }
    int cnt = n - dp[mask];
    ans[cnt] = min(ans[cnt], cur);
  }
  for (int i = n; i > 0; --i)
    ans[i-1] = min(ans[i-1], ans[i]);
  for (int i = 1; i <= n; ++i) {
    int cur = ans[i];
    if (cur >= inf)
      cur = -1;
    printf("%d\n", cur);
  }
  return 0;
}
