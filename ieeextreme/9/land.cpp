#include <bits/stdc++.h>

using namespace std;

typedef pair<long long, long long> point;

#define x first
#define y second

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

vector<point> convexHull(vector<point>& vp) {
  if (vp.size() < 3) {
    return vp;
  }
  int p0 = 0, n = vp.size();
  for (int i = 1; i < n; i++)
    if (vp[p0] < vp[i]) {
      p0 = i;
    }
  swap(vp[p0], vp[0]);
  pivot = vp[0];
  sort(vp.begin()+1, vp.end(), cmp);
  if (cross(vp[0], vp[1], vp.back()) == 0) {
    vector<point> res;
    res.push_back(vp[0]);
    res.push_back(vp.back());
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
  res.pop_back();
  return res;
}
long long area(point a, point b, point c) {
  return llabs(cross(a, b, c));
}
vector<point> a, b;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    a.clear();
    b.clear();
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      long long x, y;
      cin >> x >> y;
      a.push_back(make_pair(x, y));
    }
    scanf("%d", &m);
    assert(m > 0);
    long long all = 0;
    for (int i = 1; i + 1 < a.size(); i++)
      all += area(a[0], a[i], a[i+1]);
    for (int i = 0; i < m; i++) {
      long long x, y;
      cin >> x >> y;
      b.push_back(make_pair(x, y));
    }
    b = convexHull(b);
    m = b.size();
    if (m > 2) {
      for (int i = 0; i < m; i++) {
        assert(cross(b[i], b[(i+1) % m], b[(i+2) % m]) < 0);
      }
    }
    int j = 0;
    for (int i = 1; i < m; i++)
      if (cross(b[i], a[0], a[j]) > 0)
        j = i;
    long long ans = 0, cur = 0;
    if (m == 0)
      ans = all;
    for (int i = 0, r = 0; i < n; i++) {
      if (cur <= 0)
        cur = 0, r = i;
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