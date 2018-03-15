#include <bits/stdc++.h>

using namespace std;

typedef long double LD;

const LD EPS = 1e-9;

inline bool eq(LD x, LD y) { return fabs(x - y) < EPS; }
inline bool le(LD x, LD y) { return x + EPS < y; }
inline bool lt(LD x, LD y) { return x < y + EPS; }
inline int sgn(LD x) { return eq(x, 0) ? 0 : x < 0 ? -1 : 1; }

struct point {
  LD x, y;
  point(LD x = 0, LD y = 0) : x(x), y(y) {}
  point operator+(const point & p) const { return point(x + p.x, y + p.y); }
  point operator-(const point & p) const { return point(x - p.x, y - p.y); }
  point operator*(LD s) { return point(x * s, y * s); }
  point operator/(LD s) { return point(x / s, y / s); }
  LD operator*(const point & p) const { return x * p.x + y * p.y; }
  LD operator%(const point & p) const { return x * p.y - y * p.x; }
  bool operator==(const point & p) const { return eq(x, p.x) && eq(y, p.y); }
  bool operator<(const point & p) const { return eq(y, p.y) ? lt(x, p.x) : lt(y, p.y); }
};
int ccw(point a, point b, point c) {
  return sgn((b - a) % (c - b));
}

struct line {
  point a, ab;
  line(point a, point b) {
    if (b < a) swap(a, b);
    a = a;
    ab = b - a;
  }
  bool isParallel(const line & l) const { return eq(ab % l.ab, 0); }
  bool operator<(const line & l) const {
    return sgn(ab % l.ab) > 0; 
  }
  bool onLine(const point & p) const {
    return eq((p-a) % ab, 0);
  }
  bool operator==(const line & l) const {
    return isParallel(l);
  }
};

point perp(point p) {
  return point(-p.y, p.x);
}

const int N = 2048;
point p[N];
bool die[N];
int n;
point mid;

bool process(line l) {
  vector<LD> projection;
  point ab = perp(l.ab);
  LD offset = ab * mid;
  for (int i = 0; i < n; ++i) {
    LD val = p[i] * ab;
    projection.push_back(val - offset);
  }
  sort(projection.begin(), projection.end());
  for (int i = 0, j = (int)projection.size()-1; i < j; ++i, --j) {
    if (!eq(-projection[i], projection[j]))
      return false;
  }
  return true;
}

int main() {
  scanf("%d", &n);
  mid = point(0, 0);
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    p[i] = point(x, y);
    mid = mid + p[i];
  }
  mid = mid / n;
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (die[i]) continue;
    for (int j = i+1; j < n; ++j) {
      if (die[j]) continue;
      if ((p[i] - mid) == (mid - p[j])) {
        die[i] = 1;
        die[j] = 1;
        break;
      }
    }
    cnt += !die[i];
  }
  if (cnt <= 1) {
    puts("-1");
    return 0;
  }
  for (int i = 0, j = 0; i < cnt; ++i, ++j) {
    while (die[j]) ++j;
    p[i] = p[j];
  }
  n = cnt;
  vector<line> vl;
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      point c = (p[i] + p[j]) / 2.0;
      vl.push_back(line(c, mid));
    }
  }
  sort(vl.begin(), vl.end());
  line cur = vl[0];
  cnt = 0;
  int ans = 0;
  for (int i = 0; i < vl.size(); ++i) {
    if (vl[i] == cur)
      ++cnt;
    else {
      if (cnt * 2 + 1 >= n) {
        ans += process(cur);
      }
      cnt = 1;
      cur = vl[i];
    }
  }
  if (cnt * 2 + 1 >= n) {
    ans += process(cur);
  }
  printf("%d\n", ans);
  return 0;
}