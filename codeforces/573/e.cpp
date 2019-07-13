#include <bits/stdc++.h>

using namespace std;

typedef long double LD;

const int inf = 1e9 + 7;
const int N = 2e5 + 5, LG = 20;
const LD eps = 1e-7;

inline bool eq(LD x, LD y) { return fabs(x-y) < eps; }
inline bool le(LD x, LD y) { return x < y + eps; }
inline bool lt(LD x, LD y) { return x + eps < y; }
inline int sign(LD x) { return eq(x, 0) ? 0 : (x < 0 ? -1 : 1); }

struct point {
  LD x, y;
  point(LD x = 0, LD y = 0) : x(x), y(y) {}
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


bool cmp_ccw(point a, point b) {
  int sg = sign(a % b);
  return sg == 0 ? a.norm2() < b.norm2() : sg > 0;
}

void sort_ccw(vector<point> & vp) {
  vector<point> upper, lower;
  point origin;
  for (point p : vp) {
    if (origin < p)
      upper.push_back(p);
    else
      lower.push_back(p);
  }
  sort(upper.begin(), upper.end(), cmp_ccw);
  sort(lower.begin(), lower.end(), cmp_ccw);
  for (int i = 0; i < (int)upper.size(); ++i)
    vp[i] = upper[i];
  for (int i = 0; i < (int)lower.size(); ++i)
    vp[upper.size() + i] = lower[i];
}

// check line AB intersect Circle(center=p, radius=r) on 2 points
bool intersect_line_circle(point a, point b, point p, LD r) {
  point ap = p-a, ab = b-a;
  return lt(fabs(ap % ab), sqrt(ab * ab) * r);
}

// check if angle AOB < 90 or angle BOA < 90
bool acute(point a, point o, point b) {
  return sign((a-o) * (b-o)) > 0;
}

double r;

// check if point A can be replaced by point B
bool replaceable(point a, point b) {
  if (!intersect_line_circle(a, b, point(0, 0), r))
    return false;
  if (lt(a * a, b * b))
    return false;
  if (acute(point(0, 0), b, a))
    return false;
  return true;
}

// check if we can visit point B from point A
bool visit(point a, point b) {
  if (!cmp_ccw(a, b))
    return false;
  if (!intersect_line_circle(a, b, point(0, 0), r))
    return true;
  if (lt(a * a, b * b))
    swap(a, b);
  if (acute(point(0, 0), b, a))
    return false;
  return true;
}

bool bad[N];
long long step[LG][N];
vector<point> vp;

int calc(int n, LD R) {
  ::r = R;
  fill(bad, bad + n, false);
  vector<int> good;
  for (int i = 0; i < 2 * n; ++i) {
    int now = i;
    if (now >= n)
      now -= n;
    if (!good.empty() && replaceable(vp[now], vp[good.back()])) {
      bad[now] = true;
      continue;
    }
    while (!good.empty() && replaceable(vp[good.back()], vp[now])) {
      bad[good.back()] = true;
      good.pop_back();
    }
    good.push_back(now);
  }
  vector<point> s;
  for (int i = 0; i < n; ++i) {
    if (bad[i]) continue;
    s.push_back(vp[i]);
  }
  n = s.size();
  for (int i = 0, cnt = 1; i < n; ++i) {
    cnt = max(cnt-1, 1);
    while (cnt < n && visit(s[i], s[(i+cnt) % n])) ++cnt;
    step[0][i] = cnt;
  }
  for (int i = 0; i+1 < LG; ++i) {
    for (int j = 0; j < n; ++j) {
      int nxt = (step[i][j] + j) % n;
      step[i+1][j] = step[i][j] + step[i][nxt];
    }
  }
  int ans = inf;
  for (int i = 0; i < n; ++i) {
    int cnt = 0;
    int cur = 0;
    for (int j = LG-1; j >= 0; --j) {
      int now = (i + cur) % n;
      if (cur + step[j][now] < n) {
        cur += step[j][now];
        cnt += 1 << j;
      }
    }
    ans = min(ans, cnt+1);
  }
  return ans;
}

const int ITER = 100;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  LD low = 0, high = 0;
  vector<pair<int, int>> pairs;
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    pairs.emplace_back(x, y);
  }
  sort(pairs.begin(), pairs.end());
  pairs.erase(unique(pairs.begin(), pairs.end()), pairs.end());
  n = pairs.size();
  for (int i = 0; i < n; ++i) {
    vp.push_back(point(pairs[i].first, pairs[i].second));
    LD cur = sqrt(vp.back().norm2());
    if (i == 0)
      high = cur;
    else
      high = min(high, cur);
  }
  sort_ccw(vp);
  for (int i = 0; i < ITER; ++i) {
    LD mid = (low + high) * 0.5;
    if (calc(n, mid) > m)
      high = mid;
    else
      low = mid;
  }
  printf("%.12lf\n", (double)(low + high) * 0.5);
  return 0;
}
