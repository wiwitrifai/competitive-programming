#include <bits/stdc++.h>

using namespace std;

struct point {
  int x, y;
  point(int x = 0, int y = 0) : x(x), y(y) {} 
  bool operator<(point b) {
    if (y == b.y)
      return x < b.x;
    return y < b.y;
  }
  bool operator==(point b) {
    return x == b.x && y == b.y;
  }
};

long long cross(point a, point b, point c) {
  return 1LL * (a.x - b.x) * (c.y - b.y) - 1LL * (a.y - b.y) * (c.x - b.x);
}
long long dist2(point a, point b) {
  long long dx = a.x - b.x, dy = a.y - b.y;
  return dx * dx + dy * dy;
}

point pivot;
bool cmp(point a, point b) {
  long long crs = cross(a, pivot, b);
  if (crs == 0)
    return dist2(pivot, a) < dist2(pivot, b);
  return crs > 0;
}

vector<point> convexHull(vector<point> vp) {
  int p0 = 0, n = vp.size();
  for (int i = 1; i < n; i++)
    if (vp[p0] < vp[i]) {
      p0 = i;
    }
  swap(vp[p0], vp[0]);
  pivot = vp[0];
  sort(++vp.begin(), vp.end(), cmp);
  if (vp.size() < 3) {
    vp.push_back(vp[0]);
    return vp;
  }
  if (cross(vp[0], vp[1], vp.back()) == 0) {
    vector<point> res;
    res.push_back(vp[0]);
    res.push_back(vp.back());
    res.push_back(vp[0]);
    return res;
  }
  vector<point> res;
  res.push_back(vp.back());
  res.push_back(vp[0]);
  for (int i = 0; i < vp.size();) {
    int s = res.size();
    long long crs = cross(res[s-2], res[s-1], vp[i]);
    if (crs >= 0)
      res.pop_back();
    else
      res.push_back(vp[i++]);
  }
  return res;
}
long long area(point a, point b, point c) {
  return llabs(cross(a, b, c));
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    vector<point> a, b;
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      a.push_back(point(x, y));
    }
    scanf("%d", &m);
    long long all = 0;
    for (int i = 1; i + 1 < a.size(); i++)
      all += area(a[0], a[i], a[i+1]);
    for (int i = 0; i < m; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      b.push_back(point(x, y));
    }
    b = convexHull(b);
    while (b.size() > 1 && b[0] == b.back())
      b.pop_back();
    m = b.size();
    if (m > 2) {
      for (int i = 0; i < m; i++) {
        assert(cross(b[i], b[(i+1) % m], b[(i+2) % m]) < 0);
      }
    }
    assert(m > 0);
    int j = 0;
    pivot = a[0];
    for (int i = 1; i < m; i++)
      if (cmp(b[i], b[j]))
        j = i;
    long long ans = 0, cur = 0;
    if (m == 0)
      ans = all;
    for (int i = 0, r = 0; i < n; i++) {
      if (cur <= 0)
        cur = 0, r = i;
      pivot = a[i];
      while (cross(b[(j+1) % m], a[i], b[j]) > 0) j = (j + 1) % m;
      while (cross(b[(j+m-1) % m], a[i], b[j]) > 0) j = (j + m - 1) % m;
      while (cross(a[(r+1) % n], a[i], b[j]) > 0) {
        int rr = (r + 1) % n;
        cur += area(a[i], a[r], a[rr]);
        r = rr; 
      }
      if (i != r)
        assert(cross(a[i], b[j], a[r]) > 0);
      else
        assert(cur == 0);
      ans = max(ans, cur);
      cur -= area(a[i], a[(i+1) % n], a[r]);
    }
    assert(ans < all);
    printf("%lld.%d0\n", ans/2, (ans&1) * 5);
  }
  return 0;
}