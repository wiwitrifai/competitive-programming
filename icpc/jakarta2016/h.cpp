/**
 *  ACM ICPC Regional Jakarta 2016 - H : National Disaster II
 */


#include <bits/stdc++.h>

using namespace std;

const long double eps = 1e-12;

struct point {
  long double x, y;
  point(long double x = 0, long double y = 0) : x(x), y(y) {}
  bool operator<(point& b) const {
    if (x != b.x) return x < b.x;
    return y < b.y;
  }
};

long double dist2(point a, point b) {
  long double dx = a.x - b.x, dy = a.y - b.y;
  return dx * dx + dy * dy;
}

bool circle2PtsRad(point p1, point p2, long long r, point * c) {
  long double d2 = dist2(p1, p2);
  long double det = (long double)r * r / d2 - 0.25;
  if (det < 0.0) return false;
  long double h = sqrt(det);
  c->x = (p1.x + p2.x) * 0.5 + (p1.y-p2.y)*h;
  c->y = (p1.y + p2.y) * 0.5 + (p2.x-p1.x)*h;
  return true;
}

const int N = 1024;

int n;
point c[N], ul, dr;

bool inside(point b) {
  if (b.x < ul.x && fabs(b.x - ul.x) > eps) return false;
  if (b.x > dr.x && fabs(b.x - dr.x) > eps) return false;
  if (b.y < ul.y && fabs(b.y - ul.y) > eps) return false;
  if (b.y > dr.y && fabs(b.y - dr.y) > eps) return false;
  return true;
}

bool can(long long r) {
  long long r2 = r * r;
  vector<point> ex;
  ex.push_back(ul);
  ex.push_back(dr);
  ex.push_back(point(ul.x, dr.y));
  ex.push_back(point(dr.x, ul.y));
  for (point & b : ex) {
    bool ok = 0;
    for (int i = 0; i < n; i++) {
      long double d2 = dist2(c[i], b);
      if (d2 + eps < r2) {
        ok = 1;
        break;
      }
    }
    if (!ok) return false;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      point b;
      if (circle2PtsRad(c[i], c[j], r, &b) && inside(b)) {
        bool ok = 0;
        for (int k = 0; k < n; k++) {
          if (k == i || k == j) continue;
          long double d2 = dist2(c[k], b);
          if (d2 + eps < r2) {
            ok = 1;
            break;
          }
        }
        if (!ok) return false;
      }
    }
  }
  return true;
}

int main() {
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    int x, y;
    scanf("%d %d", &x, &y);
    ul = point(x, y);
    scanf("%d %d", &x, &y);
    dr = point(x, y);
    assert(ul.x < dr.x);
    assert(ul.y < dr.y);
    scanf("%d", &n);
    vector<pair<int, int > > pii;
    for (int i = 0; i < n; i++) {
      scanf("%d %d", &x, &y);
      pii.emplace_back(x, y);
    }
    sort(pii.begin(), pii.end());
    pii.erase(unique(pii.begin(), pii.end()), pii.end());
    n = pii.size();
    for (int i = 0; i < n; i++)
      c[i] = point(pii[i].first, pii[i].second);
    long long l = 0, r = 2e9;
    while (l < r) {
      long long mid = (l + r) / 2;
      if (can(mid))
        r = mid;
      else
        l = mid + 1;
    }
    printf("Case #%d: %lld\n", tc, l);
  }
  return 0;
}