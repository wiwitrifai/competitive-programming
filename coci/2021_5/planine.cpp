#include <bits/stdc++.h>

using namespace std;

typedef long long LD;

struct point {
  LD x, y;
  point(LD _x = 0, LD _y = 0) : x(_x), y(_y) {}
  point operator+(point p) { return point(x + p.x, y + p.y); }
  point operator-(point p) { return point(x - p.x, y - p.y); }
  LD operator*(point p) { return x * p.x + y * p.y; }
  LD operator%(point p) { return x * p.y - y * p.x; }
};

int ccw(point a, point b, point c) {
  LD res = (b - a) % (c - a);
  return (res < LD(0)) ? -1 : (LD(0) < res) ? +1 : 0;
}

ostream& operator<<(ostream& os, point f) {
  return os << "(" << f.x << "," << f.y << ")";
}

const long double eps = 1e-7;

int main() {
  int n;
  long long h;
  scanf("%d %lld", &n, &h);
  vector<int> x(n), y(n);
  vector<point> vp(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &x[i], &y[i]);
    vp[i] = point(x[i], y[i]);
  }
  LD fh(h);
  vector<pair<LD, LD>> segments(n/2 - 1);
  vector<point> hull;
  for (int i = 0; i < n; ++i) {
    int sz;
    point & now = vp[i];;
    while ((sz = hull.size()) >= 2 && ccw(hull[sz-2], hull[sz-1], now) >= 0)
      hull.pop_back();
    if ((i & 1) == 0) {
      int id = i/2 - 1;
      if (id >= 0 && id < (int)segments.size()) {
        assert(hull.back().y > y[i]);
        segments[id].first = LD(x[i]) - (LD(x[i]) - LD(hull.back().x)) * (fh - y[i]) / (LD(hull.back().y) - LD(y[i]));
      }
    }
    hull.push_back(now);
  }
  hull.clear();
  for (int i = n-1; i >= 0; --i) {
    int sz;
    point & now = vp[i];;
    while ((sz = hull.size()) >= 2 && ccw(hull[sz-2], hull[sz-1], now) <= 0)
      hull.pop_back();
    if ((i & 1) == 0) {
      int id = i/2 - 1;
      if (id >= 0 && id < (int)segments.size()) {
        assert(hull.back().y > y[i]);
        segments[id].second = LD(x[i]) + (LD(hull.back().x) - LD(x[i])) * (fh - y[i]) / (LD(hull.back().y) - LD(y[i]));
      }
    }
    hull.push_back(now);
  }
  sort(segments.begin(), segments.end());
  int ans = 1;
  LD last = segments[0].second;
  for (int i = 1; i < (int)segments.size(); ++i) {
    if (!(last + eps < segments[i].first)) {
      last = min(segments[i].second, last);
      continue;
    }
    ++ans;
    last = segments[i].second;
  }
  printf("%d\n", ans);
  return 0;
}
