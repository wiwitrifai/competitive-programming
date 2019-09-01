#include <bits/stdc++.h>

using namespace std;

typedef long double LD;
const LD EPS = 1e-9, PI = acos(-1);
inline bool eq(LD a, LD b) { return fabs(a-b) < EPS; }
inline bool lt(LD a, LD b) { return a + EPS < b; }
inline bool le(LD a, LD b) { return a < b + EPS; }
inline int sign(LD x) { return eq(x, 0) ? 0 : (x < 0 ? -1 : 1); }

struct point {
  LD x, y;
  int id;
  point(LD x = 0, LD y = 0, int id = -1) : x(x), y(y), id(id) {}
  point operator+(const point& p) const { return point(x+p.x, y+p.y); }
  point operator-(const point& p) const { return point(x-p.x, y-p.y); }
  point operator*(LD s) { return point(x*s, y*s); }
  point operator/(LD s) { return point(x/s, y/s); }
  LD operator*(const point& p) const { return x*p.x + y*p.y; } // dot
  LD operator%(const point& p) const { return x*p.y - y*p.x; } // cross
  LD norm_sq() { return *this * *this; }
  LD norm() { return sqrt(*this * *this); }
  point rotate(LD cs, LD sn) { return point(x*cs-y*sn, x*sn+y*cs); }
  point rotate(LD angle) { return rotate(cos(angle), sin(angle)); }
  bool operator==(const point& p) const { return eq(x, p.x) && eq(y, p.y); }
  bool operator<(const point& p) const { return eq(y, p.y) ? x < p.x : y < p.y; }
};
ostream& operator<<(ostream& os, point p) {
  return os << "(" << p.x << ", " << p.y << ")";
}
int ccw(point a, point b, point c) { return sign((b - a) % (c - b)); }
LD dist(point a, point b) { return (b-a).norm(); }
LD dist2(point a, point b) { return (b-a).norm_sq(); }


void ConvexHull(vector<point> & points) {
  if (points.size() < 3)
    return;
  int p0 = 0;
  for (int i = 1; i < (int)points.size(); ++i) {
    if (points[i] < points[p0])
      p0 = i;
  }
  swap(points[0], points[p0]);
  point pivot = points[0];
  sort(points.begin() + 1, points.end(), [pivot](point p, point q) {
    int dir = ccw(pivot, p, q);
    if (dir != 0)
      return dir > 0;
    return dist2(p, pivot) < dist2(q, pivot);
  });
  vector<point> ch;
  for (point p : points) {
    int sz;
    while ((sz = ch.size()) >= 2 && ccw(ch[sz-2], ch[sz-1], p) <= 0)
      ch.pop_back();
    ch.push_back(p);
  }
  points = ch;
}

const int ITER = 60;

LD farthest(const vector<point> & vp, point p) {
  LD ret = dist2(p, vp[0]);
  for (int i = 1; i < (int)vp.size(); ++i)
    ret = max(ret, dist2(p, vp[i]));
  return ret;
}

LD findCenterY(const vector<point>& vp, LD x) {
  LD lo = vp[0].y, hi = vp[0].y;
  for (const point & p : vp) {
    lo = min(lo, p.y);
    hi = max(hi, p.y);
  }
  for (int i = 0; i < ITER; ++i) {
    LD lef = (lo + lo + hi) / 3, rig = (lo + hi + hi) / 3;
    if (farthest(vp, point(x, lef)) < farthest(vp, point(x, rig)))
      hi = rig;
    else
      lo = lef;
  }
  return (lo + hi) * 0.5;
}

point findCenter(const vector<point>& vp) {
  LD lo = vp[0].x, hi = vp[0].x;
  for (const point & p : vp) {
    lo = min(lo, p.x);
    hi = max(hi, p.x);
  }
  for (int i = 0; i < ITER; ++i) {
    LD lef = (lo + lo + hi) / 3, rig = (lo + hi + hi) / 3;
    LD yl = findCenterY(vp, lef);
    LD yr = findCenterY(vp, rig);
    if (farthest(vp, point(lef, yl)) < farthest(vp, point(rig, yr)))
      hi = rig;
    else
      lo = lef;
  }
  LD x = (lo + hi) * 0.5;
  return point(x, findCenterY(vp, x));
}

vector<point> calcCenters(const vector<vector<point>> & groups) {
  vector<point> centers(groups.size());
  for (int i = 0; i < (int)groups.size(); ++i) {
    centers[i] = findCenter(groups[i]);
  }
  return centers;
}

void distribute(vector<point> & rest, const vector<point> & centers, vector<vector<point>> & groups, const vector<bool> & done) {
  for (point p : rest) {
    int sel = -1;
    LD best = 1e18;
    for (int i = 0; i < (int)groups.size(); ++i) {
      if (done[i]) continue;
      LD cur = dist2(p, centers[i]);
      if (sel == -1 || lt(cur, best)) {
        best = cur;
        sel = i;
      }
    }
    while (sel == -1);
    groups[sel].push_back(p);
  }
  rest.clear();
}

void kMean(vector<vector<point>> & groups, int g) {
  vector<point> points;
  for (auto & vp : groups) {
    for (point & p : vp)
      points.push_back(p);
  }
  vector<bool> done(groups.size(), false);
  while ((double)clock() / CLOCKS_PER_SEC < 3) {
    vector<point> centers = calcCenters(groups);
    for (auto & vp : groups)
      vp.clear();
    vector<point> rest = points;
    while (1) {
      distribute(rest, centers, groups, done);
      for (int i = 0; i < (int)groups.size(); ++i) {
        if (done[i]) continue;
        if ((int)groups[i].size() < g) continue;
        done[i] = 1;
        point pivot = centers[i];
        sort(groups[i].begin(), groups[i].end(), [pivot](point le, point ri) {
          return dist2(pivot, le) < dist2(pivot, ri);
        });
        while ((int)groups[i].size() > g) {
          rest.push_back(groups[i].back());
          groups[i].pop_back();
        }
      }
      bool ok = 1;
      for (bool b : done)
        ok &= b;
      if (ok)
        break;
    }
    fill(done.begin(), done.end(), false);
    distribute(rest, centers, groups, done);
  }
}

int main() {
  srand(time(0));
  int n, g;
  scanf("%d %d", &n, &g);
  vector<point> vp(n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    vp[i] = point(x, y, i+1);
  }
  sort(vp.begin(), vp.end());
  vector<vector<point>> groups;
  while ((int)vp.size() >= g) {
    vector<point> copy = vp;
    ConvexHull(copy);
    point s = copy[rand() % copy.size()];
    for (int i = 0; i < (int)vp.size(); ++i) {
      if (s == vp[i]) {
        swap(vp[i], vp.back());
      }
    }

    point pivot = vp.back();
    sort(vp.begin(), vp.end()-1, [pivot](point le, point ri) {
      return dist2(pivot, le) > dist2(pivot, ri);
    });
    groups.push_back({});
    for (int j = 0; j < g; ++j) {
      groups.back().push_back(vp[(int)vp.size()-1-j]);
    }
    vp.resize((int)vp.size() - g);
  }
  vector<point> centers = calcCenters(groups);
  for (auto it : vp) {
    LD best = dist2(it, centers[0]);
    int sel = 0;
    for (int i = 0; i < (int)groups.size(); ++i) {
      LD cur = dist2(it, centers[i]);
      if (lt(cur, best)) {
        sel = i;
        best = cur;
      }
    }
    groups[sel].push_back(it);
    centers[sel] = findCenter(groups[sel]);
  }
  // kMean(groups, g);
  printf("%d\n", (int)groups.size());
  for (auto & it : groups) {
    printf("%d\n", (int)it.size());
    for (int i = 0; i < (int)it.size(); ++i) {
      printf("%d%c", it[i].id, i+1 == (int)it.size() ? '\n' : ' ');
    }
  }
  return 0;
}
