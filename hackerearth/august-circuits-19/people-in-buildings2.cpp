#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long double LD;
const LD EPS = 1e-8, PI = acos(-1);
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

LD farthest(const vector<point> & vp, point p) {
  LD ret = dist2(p, vp[0]);
  for (int i = 1; i < (int)vp.size(); ++i)
    ret = max(ret, dist2(p, vp[i]));
  return ret;
}

struct Circle {
  point c;
  LD r;
  Circle(point c_ = point(), LD r_ = 0) : c(c_), r(r_) {}
  bool inside(point p) {
    return le(dist2(p, c), r * r);
  }
};

Circle circumCircle(point &a, point &b, point &c) {
  if (a == b || a == c)
    return Circle((b + c) * 0.5, dist(b, c) * 0.5);
  if (b == c)
    return Circle((a + c) * 0.5, dist(a, c) * 0.5);
  point bb = b - a, cc = c - a;
  LD db = (bb).norm_sq(), dc = (cc).norm_sq(), d= 2*(bb % cc);
  Circle cir;
  cir.c = a-point(bb.y*dc-cc.y*db, cc.x*db-bb.x*dc) / d;
  cir.r = dist(cir.c, a);
  return cir;
}

Circle findCircleRec(vector<point>& vp, int fixed, int num) {
  if (fixed == 3)
    return circumCircle(vp[0], vp[1], vp[2]);
  Circle cir = circumCircle(vp[0], vp[0], vp[1]);
  for (int i = fixed; i < num; ++i) {
    if (cir.inside(vp[i])) continue;
    swap(vp[i], vp[fixed]);
    cir = findCircleRec(vp, fixed+1, i+1);
  }
  return cir;
}

Circle findCircle(vector<point>& vp) {
  shuffle(vp.begin(), vp.end(), rng);
  return findCircleRec(vp, 0, vp.size());
}

Circle findCircle2(vector<point>& vp) {
  Circle cir;
  for (point p : vp) {
    cir.c = cir.c + p;
  }
  cir.c = cir.c / vp.size();
  for (point p : vp) {
    cir.r = max(dist(cir.c, p), cir.r);
  }
  return cir;
}

vector<point> calcCenters(vector<vector<point>> & groups) {
  vector<point> centers(groups.size());
  for (int i = 0; i < (int)groups.size(); ++i) {
    centers[i] = findCircle(groups[i]).c;
  }
  return centers;
}

vector<point> calcCenters2(vector<vector<point>> & groups) {
  vector<point> centers(groups.size());
  for (int i = 0; i < (int)groups.size(); ++i) {
    centers[i] = findCircle2(groups[i]).c;
  }
  return centers;
}

LD calcScore(vector<vector<point>> & groups) {
  LD best = 0;
  for (int i = 0; i < (int)groups.size(); ++i) {
    best = max(best, findCircle(groups[i]).r);
  }
  return best;
}

void distribute(vector<point> & rest, vector<vector<point>> & groups) {
  vector<point> centers = calcCenters(groups);
  auto select = [&](point p) {
    int sel = -1;
    LD best = 1e18;
    for (int i = 0; i < (int)groups.size(); ++i) {
      LD cur = dist2(p, centers[i]);
      if (sel == -1 || lt(cur, best)) {
        best = cur;
        sel = i;
      }
    }
    return sel;
  };
  shuffle(rest.begin(), rest.end(), rng);
  for (point p : rest) {
    int sel = select(p);
    groups[sel].push_back(p);
    centers[sel] = findCircle(groups[sel]).c;
  }
}

void swapping(vector<vector<point>> & groups, int g) {
  int limit = min(g, 40);
  vector<point> centers = calcCenters(groups);
  auto sortPoints = [&](vector<point> & vp, point pivot) {
    sort(vp.begin(), vp.end(), [pivot](point le, point ri) {
      return dist2(pivot, le) > dist2(pivot, ri);
    });
  };
  for (int i = 0; i < (int)groups.size(); ++i) {
    sortPoints(groups[i], centers[i]);
  }
  while (true) {
    bool done = 1;
    for (int i = 0; i < (int)groups.size(); ++i) {
      for (int j = i+1; j < (int)groups.size(); ++j) {
        bool changed = 0;
        for (int a = 0; a < limit; ++a) {
          for (int b = 0; b < limit; ++b) {
            if (max(dist2(groups[i][a], centers[j]), dist2(groups[j][b], centers[i])) <
                max(dist2(groups[i][a], centers[i]), dist2(groups[j][b], centers[j]))) {
              swap(groups[i][a], groups[j][b]);
              changed = 1;
              done = 0;
            }
          }
        }
        if (changed) {
          centers[i] = findCircle(groups[i]).c;
          centers[j] = findCircle(groups[j]).c;
          sortPoints(groups[i], centers[i]);
          sortPoints(groups[j], centers[j]);
        }
      }
    }
    if (done)
      break;
  }
}

void refine(vector<vector<point>> & groups, int g) {
  LD best = calcScore(groups);
  vector<vector<point>> saved = groups;
  while ((double)clock() / CLOCKS_PER_SEC < 4.9) {
    vector<point> points;
    vector<point> centers = calcCenters(groups);
    for (int i = 0; i < (int)groups.size(); ++i) {
      point pivot = centers[i];
      sort(groups[i].begin(), groups[i].end(), [pivot](point le, point ri) {
        return dist2(pivot, le) < dist2(pivot, ri);
      });
      while ((int)groups[i].size() > g) {
        points.push_back(groups[i].back());
        groups[i].pop_back();
      }
    }

    swapping(groups, g);
    distribute(points, groups);
    swapping(groups, g);

    LD cur = calcScore(groups);
    if (cur < best) {
      best = cur;
      saved = groups;
    }
  }
  groups = saved;
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
    point cntr = findCircle2(vp).c;
    for (int i = 0; i + 1 < (int)vp.size(); ++i) {
      if (dist2(cntr, vp[i]) > dist2(cntr, vp.back())) {
        swap(vp[i], vp.back());
      }
    }

    point pivot = vp.back();
    sort(vp.begin(), vp.end(), [pivot](point le, point ri) {
      return dist2(pivot, le) > dist2(pivot, ri);
    });

    groups.push_back({});
    for (int j = 0; j < g; ++j) {
      groups.back().push_back(vp[(int)vp.size()-1-j]);
    }
    vp.resize((int)vp.size() - g);
  }
  swapping(groups, g);
  distribute(vp, groups);
  swapping(groups, g);

  refine(groups, g);
  printf("%d\n", (int)groups.size());
  for (auto & it : groups) {
    printf("%d\n", (int)it.size());
    for (int i = 0; i < (int)it.size(); ++i) {
      printf("%d%c", it[i].id, i+1 == (int)it.size() ? '\n' : ' ');
    }
  }
  return 0;
}
