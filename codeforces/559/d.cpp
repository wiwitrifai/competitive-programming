#include <bits/stdc++.h>
using namespace std;

typedef long long LD;

inline bool eq(LD x, LD y) { return x == y; }
inline bool le(LD x, LD y) { return x <= y; }
inline bool lt(LD x, LD y) { return x < y; }
inline int sign(LD x) { return eq(x, 0) ? 0 : (x < 0 ? -1 : 1); }

struct point {
  LD x, y;
  point(LD x = 0, LD y = 0) : x(x), y(y) {}
  point operator+(point p) { return point(x+p.x, y+p.y); }
  point operator-(point p) { return point(x-p.x, y-p.y); }
  point operator*(LD s) { return point(x * s, y * s); }
  // point operator/(LD s) { return point(x / s, y / s); }
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


bool cmp_ccw(point a, point b) {
  int sg = sign(a % b);
  return sg == 0 ? a.norm2() < b.norm2() : sg > 0;
}

const int N = 2020;
int n;
point p[N];
char s[N];
bool used[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    p[i] = point(x, y);
  }
  scanf("%s", s);
  int p0 = 0;
  for (int i = 0; i < n; ++i)
    if (p[i] < p[p0])
      p0 = i;
  vector<int> ans;
  ans.push_back(p0);
  used[p0] = 1;
  for (int i = 0; i < n-2; ++i) {
    int now = -1;
    for (int j = 0; j < n; ++j) {
      if (used[j]) continue;
      if (now == -1) {
        now = j;
        continue;
      }
      if (s[i] == 'L') {
        if (ccw(p[ans.back()], p[now], p[j]) < 0)
          now = j;
      }
      else {
        if (ccw(p[ans.back()], p[now], p[j]) > 0)
          now = j;
      }
    }
    used[now] = 1;
    ans.push_back(now);
  }
  for (int i = 0; i < n; ++i)
    if (!used[i])
      ans.push_back(i);
  for (int i = 0; i < n; ++i) {
    printf("%d%c", ans[i]+1, i == n-1 ? '\n' : ' ');
  }
  return 0;
}
