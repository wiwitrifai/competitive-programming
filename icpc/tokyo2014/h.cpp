#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

const ld eps = 1e-7;
const ld PI = acos(-1);
const ld INF = 1e18;

struct point {
  ld x, y;
  point(ld x = 0, ld y = 0) : x(x), y(y) {}
  point operator+(point p) { return point(x+p.x, y+p.y); }
  point operator-(point p) { return point(x-p.x, y-p.y); }
  point operator*(ld s) { return point(x * s, y * s); }
  point operator/(ld s) { return point(x / s, y / s); }
  ld operator*(point p) { return x * p.x + y * p.y; } 
  ld operator%(point p) { return x * p.y - y * p.x; }
  bool operator==(point p) { return fabs(x - p.x) < eps && fabs(y - p.y) < eps; }
  bool operator<(point p) { return fabs(x - p.x) > eps ? x < p.x : y < p.y; }
};
ld norm_sq(point p) {
  return p * p;
}
ld dist(point a, point b) {
  point ab = b-a;
  return sqrt(ab * ab);
}
int ccw(point p, point q, point r) {
  point pq = q-p, qr = r-q;
  ld cross = pq % qr;
  if (fabs(cross) < eps) return 0;
  return cross > 0 ? 1 : -1;
}
point rotate(point p, ld angle) {
  ld cs = cos(angle), sn = sin(angle);
  return point(cs * p.x - sn * p.y, sn * p.x + cs * p.y);
}

struct circle {
  point o;
  ld r;
  circle(point o = point(), ld r = 0) : o(o), r(r) {}
  bool inside(point p) {
    ld d = norm_sq(p-o);
    return (d + eps < r * r);
  }
  bool onCircum(point p) {
    ld d = norm_sq(p-o);
    return fabs(r * r - d) < eps;
  }
  bool between(point p, point q, point r) {
    if (ccw(o, p, r) < 0) {
      return ccw(o, p, q) >= 0 || ccw(o, q, r) >= 0;
    }
    return ccw(o, p, q) >= 0 && ccw(o, q, r) >= 0;
  }
  ld circum() {
    return PI * 2 * r;
  }
  ld area() {
    return PI * r * r;
  }
  ld angleTali(ld tali) {
    assert(tali < 2 * r + eps);
    assert(tali >= 0);
    return acos(1 - (tali * tali)/(2 * r * r));
  }
};
vector<point> tangentPC(point p, circle c) {
  if (c.inside(p)) return {};
  if (c.onCircum(p)) return {p};
  ld d = dist(p, c.o);
  ld len = sqrt(d * d - c.r * c.r);
  ld cs = len/d, sn = c.r/d;
  point q = (c.o - p) * cs;
  point a(cs * q.x + sn * q.y, -sn * q.x + cs * q.y);
  point b(cs * q.x - sn * q.y, sn * q.x + cs * q.y);
  return {p+a, p+b};
}
vector<point> recFrom2Circle(point o1, point o2, ld r) {
  point d = o2-o1;
  point u = rotate(d, PI/2);
  ld len = sqrt(u * u);
  point v = u * r / len;
  vector<point> ret = {o1+v, o1-v, o2-v, o2+v};
  return ret;
}
bool insideRec(vector<point> rec, point p) {
  if (ccw(rec[0], rec[1], rec[2]) < 0)
    reverse(rec.begin(), rec.end());
  for (int i = 0; i < rec.size(); ++i)
    if (ccw(rec[i], rec[(i+1) % rec.size()], p) <= 0)
      return false;
  return true;
}

const int N = 333;

int n;
point fin;
point poles[N];
point pos[N];
int nempel[N], pre[N];
ld ans[N];

point readPoint() {
  int x, y;
  scanf("%d %d", &x, &y);
  return point(x, y);
}
vector<pair<int, ld> > g[N];
int m = 0;
const int R = 100;
void addPoint(point p, int i) {
  circle cnow(p, R);
  for (int k = 0; k < n; ++k) {
    if (k == i) continue;
    if (cnow.inside(poles[k]))
      return;
  }
  nempel[m] = i;
  pos[m++] = p;
}

int main() {
  scanf("%d", &n);
  fin = readPoint();
  for (int i = 0; i < n; ++i)
    poles[i] = readPoint();
  nempel[m] = -2;
  pos[m++] = point();
  nempel[m] = -1;
  pos[m++] = fin;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 2; ++j) {
      vector<point> t = tangentPC(pos[j], {poles[i], R});
      for (point p : t) {
        addPoint(p, i);
      }
    }
    for (int j = 0; j < n; ++j) {
      if (j == i) continue;
      vector<point> t = tangentPC(poles[j], {poles[i], 2 * R});
      for (point p : t) {
        p = (p + poles[i]) / 2.0;
        addPoint(p, i);
      }
    }
    for (int j = i+1; j < n; ++j) {
      vector<point> rec = recFrom2Circle(poles[i], poles[j], R);
      addPoint(rec[0], i);
      addPoint(rec[1], i);
      addPoint(rec[2], j);
      addPoint(rec[3], j);
    }
  }
  for (int i = 0; i < m; ++i) {
    for (int j = i+1; j < m; ++j) {
      if (nempel[i] == nempel[j]) {
        bool ok1 = 1, ok2 = 1;
        circle cnow(poles[nempel[i]], R * 2);
        for (int k = 0; k < n; ++k) {
          if (!cnow.inside(poles[k])) continue;
          if (k == nempel[i]) continue;
          ok1 &= !cnow.between(pos[i], poles[k], pos[j]);
          ok2 &= !cnow.between(pos[j], poles[k], pos[i]);
        }
        cnow.r = R;
        ld angle1 = cnow.angleTali(dist(pos[i], pos[j])), angle2 = 2 * PI - angle1;
        if (ccw(cnow.o, pos[i], pos[j]) < 0)
          swap(angle1, angle2);
        if (ok1) {
          ld dd = angle1 * R;
          g[i].emplace_back(j, dd);
          g[j].emplace_back(i, dd);
        }
        if (ok2) {
          ld dd = angle2 * R;
          g[i].emplace_back(j, dd);
          g[j].emplace_back(i, dd);
        }
      }
      else {
        vector<point> rec = recFrom2Circle(pos[i], pos[j], R);
        bool ok = 1;
        for (int k = 0; k < m && ok; ++k) {
          ok &= !insideRec(rec, poles[k]);
        }
        if (ok) {
          ld d = dist(pos[i], pos[j]);
          g[i].emplace_back(j, d);
          g[j].emplace_back(i, d);
        }
      }
    }
  }
  for (int i = 0; i < m; ++i)
    ans[i] = 2 * INF;
  ans[0] = 0;
  priority_queue<pair<ld, int> > pq;
  pq.emplace(ans[0], 0);
  while (!pq.empty()) {
    ld dnow;
    int v;
    tie(dnow, v) = pq.top(); pq.pop();
    dnow = -dnow;
    if (fabs(dnow - ans[v]) > eps) continue; 
    for (auto it : g[v]) {
      ld val = dnow + it.second;
      if (ans[it.first] > val) {
        pre[it.first] = v;
        ans[it.first] = val;
        pq.emplace(-val, it.first);
      }
    }
  }
  if (ans[1] > INF) {
    puts("0.0");
    return 0;
  }
  printf("%.9lf\n", (double)ans[1]);
  return 0;
}