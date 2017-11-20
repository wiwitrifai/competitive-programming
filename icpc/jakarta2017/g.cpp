#include <bits/stdc++.h>

using namespace std;

typedef double ld;

const ld EPS = 1e-9;

struct point {
  ld x, y;
  point(ld x = 0, ld y = 0) : x(x), y(y) {}
  point operator+(point p) { return point(x + p.x, y + p.y); }
  point operator-(point p) { return point(x - p.x, y - p.y); }
  ld operator*(point p) { return x * p.x + y * p.y; }
  ld operator%(point p) { return x * p.y - y * p.x; }
  point operator*(ld s) { return point(x * s, y * s); }
  point operator/(ld s) { return point(x / s, y / s); }
  bool operator==(point p) { return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS; }
};

ld dist2(point a, point b) {
  point ab = b-a;
  return ab * ab;
}

struct circle {
  point p;
  ld r;
};

vector<point> interCircle(point o1, double r1, point o2, double r2) {
  ld d2 = dist2(o1, o2);
  ld d = sqrt(d2);
  if (d < abs(r1-r2)) return {};
  if (d > r1+r2) return {};
  point u = (o1+o2) * 0.5 + (o1-o2)*((r2*r2-r1*r1)/(2*d2));
  ld A = sqrt((r1+r2+d) * (r1-r2+d) * (r1+r2-d) * (-r1+r2+d));
  point v = point(o1.y-o2.y, -o1.x+o2.x) * (A / (2*d2));
  return {u+v, u-v};
}

bool intersect(point a, point b, circle c) {
  point ap = c.p-a, ab = b-a;
  if (a == b) {
    return dist2(c.p, a) + EPS < c.r * c.r;
  }
  ld dot = ap * ab;
  ld norm = (ab * ab);
  if (dot <= 0) return dist2(a, c.p) + EPS < c.r * c.r;
  else if (dot > norm) return dist2(b, c.p) + EPS < c.r * c.r;
  if (fabs(a.x - b.x) < EPS) {
    ld dx = a.x - c.p.x;
    return dx * dx + EPS < c.r * c.r;
  }
  else {
    assert(fabs(a.y - b.y) < EPS);
    ld dy = a.y - c.p.y;
    return dy * dy + EPS < c.r * c.r;
  }
}

bool inside(point a, point b, point p) {
  if (fabs(a.x-p.x) < EPS || fabs(b.x - p.x) < EPS || fabs(a.y - p.y) < EPS || fabs(b.y - p.y) < EPS) return false;
  return a.x < p.x && p.x < b.x && a.y < p.y && p.y < b.y;
}

const int N = 1025;

bool isa[N], isb[N], used[N], vis[N];
vector<int> g[N];
circle c[N];
point a, b;

int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> a.x >> a.y >> b.x >> b.y >> n;
  point d(a.x, b.y), e(b.x, a.y);
  for (int i = 0; i < n; i++) {
    cin >> c[i].p.x >> c[i].p.y >> c[i].r;
    g[i].clear();
    used[i] = 0;
    isa[i] = intersect(a, d, c[i]) || intersect(d, b, c[i]);
    isb[i] = intersect(a, e, c[i]) || intersect(e, b, c[i]);
    if (!isa[i] && !isb[i]) {
      if (!inside(a, b, c[i].p)) continue;
    }
    used[i] = 1;
    for (int j = 0; j < i; j++) {
      if (!used[j]) continue;
      vector<point> intersection = interCircle(c[i].p, c[i].r, c[j].p, c[j].r);
      if (intersection.size() < 2) continue;
      if (intersection[0] == intersection[1]) continue;
      if (inside(a, b, (intersection[0] + intersection[1])/2.0)) {
        g[i].push_back(j);
        g[j].push_back(i);
      }
    }
  }
  queue<int> que;
  for (int i = 0; i < n; i++) {
    if (isa[i]) {
      vis[i] = 1;
      que.push(i);
    }
    else
      vis[i] = 0;
  }
  while (!que.empty()) {
    int v = que.front(); que.pop();
    for (int u : g[v]) {
      if (vis[u]) continue;
      if (!used[u]) continue;
      vis[u] = 1;
      que.push(u);
    }
  }
  bool found = 0;
  for (int i = 0; i < n; i++)
    found |= vis[i] && isb[i];
  puts(!found ? "YES" : "NO");
  return 0;
}