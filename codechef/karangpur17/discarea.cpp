#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
const ld EPS = 1e-7, PI = acos(-1);

struct point {
  ld x, y;
  point(ld x = 0, ld y = 0) : x(x), y(y) {}
  bool operator==(const point p) const {
    return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
  }
  bool operator<(const point p) const {
    if (fabs(x - p.x) > EPS)
      return x < p.x;
    return y < p.y;
  }
  point operator+(point p) { return point(x + p.x, y + p.y); }
  point operator-(point p) { return point(x - p.x, y - p.y); }
  point operator*(ld s) { return point(x * s, y * s); }
  point operator/(ld s) { return point(x / s, y / s); }
  ld operator*(point p) { return x * p.x + y * p.y; }
  ld operator%(point p) { return x * p.y - y * p.x; }
};

ld norm_sq(point a) {
  return a * a;
}

ld dist(point a, point b) {
  point ab = b - a;
  return sqrt(ab * ab);
}
// return 1 = ccw, 0 = colinear, -1 = cw
int ccw(point p, point q, point r) {
  point pq = q - p, pr = r-p;
  ld crs = pq % pr;
  if (fabs(crs) < EPS) return 0;
  return crs > 0 ? 1 : -1;
}
bool between(point p, point q, point r) {
  return ccw(p, q, r) == 0 && (p.x-q.x) * (r.x-q.x) < EPS && (p.y-q.y) * (r.y-q.y) < EPS;
}
// calculate angle between OA and OB
ld angle(point a, point o, point b) {
  point oa = a-o, ob = b-o;
  return acos(oa * ob / sqrt((oa * oa) * (ob * ob)));
}

vector<point> interCircle(point o1, ld r1, point o2, ld r2) {
  ld d2 = norm_sq(o1 - o2);
  ld d = sqrt(d2);
  if (d < abs(r1-r2)) return {};
  if (d > r1+r2) return {};
  point u = (o1+o2) * 0.5 + (o1-o2)*((r2*r2-r1*r1)/(2*d2));
  ld A = sqrt((r1+r2+d) * (r1-r2+d) * (r1+r2-d) * (-r1+r2+d));
  point v = point(o1.y-o2.y, -o1.x+o2.x) * (A / (2*d2));
  return {u+v, u-v};
}

ld tembereng(ld r, ld talibusur) {
  ld ang = acos(1 - talibusur * talibusur/(2 * r * r));
  return (ang - sin(ang)) * 0.5 * r * r;
}

ld irisan2(point o1, ld r1, point o2, ld r2) {
  vector<point> vp = interCircle(o1, r1, o2, r2);
  if (vp.empty()) return 0;
  ld d = dist(vp[0], vp.back());
  ld ans = 0;
  if (ccw(vp[0], vp[1], o1) >= 0)
    ans += PI * r1 * r1 - tembereng(r1, d);
  else
    ans += tembereng(r1, d);
  if (ccw(vp[0], vp[1], o2) <= 0)
    ans += PI * r2 * r2 - tembereng(r2, d);
  else
    ans += tembereng(r2, d);
  return ans;
}

bool inside(point o, ld r, point p) {
  return norm_sq(p - o) < r * r + EPS;
}

// kalo ketiganya beririsan asumsi ada 3 titik potong (secara umum bisa salah)
ld irisan3(point o1, ld r1, point o2, ld r2, point o3, ld r3) {
  if (ccw(o1, o2, o3) < 0) {
    swap(o2, o3);
    swap(r2, r3);
  }
  vector<point> res = interCircle(o2, r2, o3, r3);
  if (res.empty()) return 0;
  if (inside(o1, r1, res[0]) && inside(o1, r1, res[1]))
    return irisan2(o2, r2, o3, r3);
  point p1 = res[0];
  res = interCircle(o3, r3, o1, r1);
  if (res.empty()) return 0;
  if (inside(o2, r2, res[0]) && inside(o2, r2, res[1]))
    return irisan2(o3, r3, o1, r1);
  point p2 = res[0];
  res = interCircle(o1, r1, o2, r2);
  if (res.empty()) return 0;
  if (inside(o3, r3, res[0]) && inside(o3, r3, res[1]))
    return irisan2(o1, r1, o2, r2);
  point p3 = res[0];
  return fabs((p1-p2) % (p3-p2)) * 0.5 + tembereng(r1, dist(p2, p3)) + tembereng(r2, dist(p1, p3)) + tembereng(r3, dist(p1, p2));
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, q;
    scanf("%d %d", &n, &q);
    vector<pair<point, int> > circ;
    for (int i = 0; i < n; ++i) {
      int x, r;
      scanf("%d %d", &x, &r);
      circ.push_back({point(x, 0), r});
    }
    sort(circ.begin(), circ.end());
    vector<pair<point, int> > upper;
    for (auto it : circ) {
      if (upper.size() > 0 && upper.back().first.x + upper.back().second + EPS > it.first.x + it.second)
        continue;
      while (upper.size() > 0) {
        int sz = upper.size();
        if (upper[sz-1].first.x - upper[sz-1].second + EPS > it.first.x - it.second) {
          upper.pop_back();
          continue;
        }
        if (sz <= 1) break;
        vector<point> res1 = interCircle(upper[sz-2].first, upper[sz-2].second,upper[sz-1].first, upper[sz-1].second);
        vector<point> res2 = interCircle(upper[sz-2].first, upper[sz-2].second,it.first, it.second);
        if (res1.empty() || res2.empty()) break;
        if (res1[0].x + EPS > res2[0].x) upper.pop_back();
        else break;
      }
      upper.push_back(it);
    }
    for (int i = 0; i < q; ++i) {
      int x, y, r;
      scanf("%d %d %d", &x, &y, &r);
      point p(x, y);
      ld ans = 0;
      bool fullInside = 0;
      for (int j = 0; j < upper.size(); ++j) {
        if (dist(p, upper[j].first) + r < upper[j].second + EPS) {
          fullInside = 1;
          break;
        }
      }
      if (fullInside) {
        printf("%.20lf\n", (double) PI * r * r);
        continue;
      }
      for (int j = 0; j < upper.size(); ++j) {
        ans += irisan2(p, r, upper[j].first, upper[j].second);
        if (j) {
          ans -= irisan3(p, r, upper[j-1].first, upper[j-1].second, upper[j].first, upper[j].second);
        }
      }
     printf("%.20lf\n", (double)ans);
    }
  }
  return 0;
}