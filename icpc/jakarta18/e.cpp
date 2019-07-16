#include <bits/stdc++.h>

using namespace std;

typedef long long LD;
// const LD EPS = 1e-8, PI = acos(-1);
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
  LD norm() { return sqrt(*this * *this); }
  bool operator==(const point& p) const { return eq(x, p.x) && eq(y, p.y); }
  bool operator<(const point& p) const { return eq(y, p.y) ? x < p.x : y < p.y; }
};
int ccw(point a, point b, point c) { return sign((b - a) % (c - b)); }

struct line {
  point a, b;
  line(point ta = point(), point tb = point()) {
    a = ta; b = tb;
  }
};

const int N = 8e4 + 4;

point p[N];
line w[6];
point que[N];
int ans[N];

struct mbuh {
  point p;
  int id;
  int type;
  mbuh(point p, int type, int id) : p(p), id(id), type(type) {}
};

int bit[N];

int get(int x) {
  int ret = 0;
  for (++x; x; x -= x&-x)
    ret += bit[x];
  return ret;
}

void upd(int x, int v) {
  for (++x; x < N; x += x&-x)
    bit[x] += v;
}
int pos[N];

int main() {
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  assert(n+q < N);
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    p[i] = point(x, y);
  }
  for (int i = 0; i < m; ++i) {
    int xa, xb, y;
    scanf("%d %d %d", &xa, &xb, &y);
    w[i] = line(point(xa, y), point(xb, y));
  }
  for (int i = 0; i < q; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    que[i] = point(x, y);
    ans[i] = n;
  }
  for (int mask = 1; mask < (1 << m); ++mask) {
    vector<line> wall;
    for (int i = 0; i < m; ++i) {
      if (mask & (1 << i)) {
        wall.push_back(w[i]);
      }
    }
    sort(wall.begin(), wall.end(), [](line a, line b) {
      return a.a.y < b.a.y;
    });
    vector<mbuh> ev, ev2;
    for (int i = 0; i < n; ++i) {
      if (le(p[i].y, wall.back().a.y))
        continue;
      point pil = wall[0].a;
      for (int j = 1; j < wall.size(); ++j) {
        if (ccw(p[i], pil, wall[j].a) > 0)
          pil = wall[j].a;
      }
      ev.push_back(mbuh(p[i] - pil, 0, i));
      pil = wall[0].b;
      for (int j = 1; j < wall.size(); ++j) {
        if (ccw(p[i], pil, wall[j].b) < 0)
          pil = wall[j].b;
      }
      ev2.push_back(mbuh(p[i] - pil, 0, i));
    }
    for (int i = 0; i < q; ++i) {
      point pil = wall[0].a;
      for (int j = 1; j < wall.size(); ++j) {
        if (ccw(que[i], pil, wall[j].a) < 0)
          pil = wall[j].a;
      }
      ev.push_back(mbuh(pil - que[i], 1, i));
      pil = wall[0].b;
      for (int j = 1; j < wall.size(); ++j) {
        if (ccw(que[i], pil, wall[j].b) > 0)
          pil = wall[j].b;
      }
      ev2.push_back(mbuh(pil - que[i], 1, i));
    }

    sort(ev.begin(), ev.end(), [](mbuh a, mbuh b) {
      if (sign(a.p % b.p) == 0)
        return a.type < b.type;
      return sign(a.p % b.p) > 0;
    });
    sort(ev2.begin(), ev2.end(), [](mbuh a, mbuh b) {
      if (sign(a.p % b.p) == 0)
        return a.type < b.type;
      return sign(a.p % b.p) < 0;
    });
    memset(bit, 0, sizeof bit);
    for (int i = 0; i < ev2.size(); ++i) {
      pos[ev2[i].id + ev2[i].type * n] = i;
    }
    int sg = (__builtin_popcount(mask) & 1) ? -1 : 1;
    for (int i = 0; i < ev.size(); ++i) {
      int pp = pos[ev[i].id + ev[i].type * n];
      if (ev[i].type) {
        ans[ev[i].id] += sg * get(pp);
      }
      else
        upd(pp, 1);
    }
  }
  for (int i = 0; i < q; ++i) {
    printf("%d\n", ans[i]);
  }
  return 0;
}