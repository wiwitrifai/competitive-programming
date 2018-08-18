#include <bits/stdc++.h>

using namespace std;

typedef long long LD;
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
  bool operator==(const point& p) const { return eq(x, p.x) && eq(y, p.y); }
  bool operator<(const point& p) const { return eq(y, p.y) ? x < p.x : y < p.y; }
};

int ccw(point a, point b, point c) { return sign((b - a) % (c - b)); }
LD dist2(point a, point b) { return (b-a).norm_sq(); }

point pivot;
bool angle_cmp(point a, point b) {
  if(ccw(pivot, a, b) == 0)
    return dist2(a, pivot) < dist2(b, pivot);
  return ccw(pivot, a, b) > 0;
}

// hasil convexHull tidak siklik
void convexHull(vector<point> & P) {
  int i, j, n = (int) P.size();
  if(n < 3) {
    return;
  }
  int PO = 0;
  for(i = 1; i < n; i++) {
    if(P[i] < P[PO]) {
      PO = i;
    }
  }
  swap(P[0], P[PO]);
  pivot = P[0];
  sort(++P.begin(), P.end(), angle_cmp);
  vector<point> S;
  S.push_back(P[0]);
  S.push_back(P[1]);
  i = 2;
  while(i < n) {
    j = (int) S.size() - 1;
    // if point on boundary is included then ccw >= 0
    if(j < 1 || ccw(S[j-1], S[j], P[i]) > 0) S.push_back(P[i++]);
    else S.pop_back();
  }
  P = S;
}

const int N = 1e6 + 6;

int to[N];

bool same(vector<point> a, vector<point> b) {
  if (a.size() != b.size())
    return false;
  int n = a.size();
  if (n == 1)
    return true;
  if (n == 2)
    return dist2(a[0], a[1]) == dist2(b[0], b[1]);
  auto nxt = [n](int i) {
    if (i == n-1)
      return 0;
    return i+1;
  };
  auto pre = [n](int i) {
    if (i == 0)
      return n-1;
    return i-1;
  };
  vector<tuple<LD, LD, LD> > va, vb;
  for (int i = 0; i < n; ++i) {
    point p = a[pre(i)], q  = a[i], r = a[nxt(i)];
    va.emplace_back((p-q) % (r-q), (p-q) * (r-q), dist2(p, q));
  }
  for (int i = 0; i < n; ++i) {
    point p = b[pre(i)], q  = b[i], r = b[nxt(i)];
    vb.emplace_back((p-q) % (r-q), (p-q) * (r-q), dist2(p, q));
  }
  for (int i = 0; i < n; ++i)
    va.push_back(va[i]);
  to[0] = 0;

  for(int i = 1; i < n; i++) {
    int j = to[i - 1];
    while(j > 0 && vb[i] != vb[j]) j = to[j - 1];
    if(vb[i] == vb[j]) to[i] = j + 1;
  }

  int j = 0;
  for(int i = 0; i < va.size();) {
    if(vb[j] == va[i]) {
      i++; j++;
    } else if(j > 0) {
      j = to[j - 1];
    } else {
      i++;
    }
    if(j == vb.size()) {
      return true;
    }
  }
  return false;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<point> va, vb;
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    va.push_back(point(x, y));
  }
  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    vb.push_back(point(x, y));
  }
  convexHull(va);
  convexHull(vb);
  puts(same(va, vb) ? "YES" : "NO");
  return 0;
}