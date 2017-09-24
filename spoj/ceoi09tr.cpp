#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-9;

struct point {
  double x, y;
  point(double x = 0, double y = 0) : x(x), y(y) {}
  point operator-(const point& b) const {
    return point(x - b.x, y - b.y);
  }
  double operator*(const point& b) const {
    return x * b.y - y * b.x;
  }
  bool operator<(const point& b) const {
    double crs = b * *this;
    if (fabs(crs) > eps)
      return crs > 0;
    return dist() < b.dist();
  }
  double dist() const {
    return sqrt(x * x + y * y);
  }
};

struct line { double a, b, c; };
void pointToLine(point p1, point p2, line * l) {
  if (fabs(p1.x - p2.x) < eps)
    l->a = 1.0, l->b = 0.0, l->c = -p1.x;
  else {
    l->a = - (double)(p1.y-p2.y)/(p1.x - p2.x);
    l->b = 1.0;
    l->c = - (l->a * p1.x) - (l->b * p1.y);
  }
}

const int N = 1e5 + 5;

int n, m;
point p[N];
vector<point> lh[N << 2];
void build(int id = 1, int l = 0, int r = n) {
  if (r-l < 2) {
    lh[id].push_back(p[l]);
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
  lh[id] = lh[il];
  int i = 0;
  while (i < lh[ir].size()) {
    int s = lh[id].size();
    double crs;
    if (s >= 2 && (lh[id][s-2]-lh[id][s-1]) * (lh[ir][i]-lh[id][s-1]) > -eps)
      lh[id].pop_back();
    else
      lh[id].push_back(lh[ir][i++]);
  }
}

int le, ri;
point a, b;
line lab;
double get(point p) {;
  return lab.a * p.x + lab.b * p.y + lab.c;
}

bool get(int id = 1, int l = 0, int r = n) {
  if (l >= ri || le >= r) return false;
  if (le <= l && r <= ri) {
    int lo = 0, hi = (int)lh[id].size()-1;
    while (lo < hi) {
      int mid = (lo + hi) >> 1;
      double cur = get(lh[id][mid]), nxt = get(lh[id][mid+1]);
      if (min(cur, nxt) < 0)
        return true;
      if (cur < nxt || fabs(cur - nxt) < eps)
        hi = mid;
      else
        lo = mid + 1;
    }
    return get(lh[id][lo]) < 0;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  if (get(il, l, mid))
    return true;
  return get(ir, mid, r);
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    p[i] = point(x, y);
  }
  sort(p, p+n);
  build();
  while (m--) {
    int x, y;
    scanf("%d %d", &x, &y);
    a = point(x, y);
    scanf("%d %d", &x, &y);
    b = point(x, y);
    if (b < a)
      swap(a, b);
    le = lower_bound(p, p+n, a) - p;
    ri = lower_bound(p, p+n, b) - p;
    pointToLine(a, b, &lab);
    if (lab.c > eps)
      lab.a *= -1, lab.b *= -1, lab.c *= -1;
    puts(get() ? "Y" : "N");
  }
  return 0;
}