#include <bits/stdc++.h>

using namespace std;
const long double eps = 1e-7;
typedef long long LD;
inline bool eq(LD x, LD y) { return x == y; }
inline bool le(LD x, LD y) { return x <= y; }
inline bool lt(LD x, LD y) { return x < y; }
inline int sgn(LD x) { return eq(x, 0) ? 0 : x < 0 ? -1 : 1; }

struct point {
  LD x, y;
  point(LD x = 0, LD y = 0) : x(x), y(y) { }
  point operator+(const   point p) const { return point(x + p.x, y + p.y); }
  point operator-(point p) { return point(x - p.x, y - p.y); }
  point operator*(LD s) { return point(x * s, y * s); }
  point operator/(LD s) { return point(x / s, y / s); }
  LD operator*(point p) { return x * p.x + y * p.y; }
  LD operator%(point p) { return x * p.y - y * p.x; }
  bool operator==(const point & p) const { return eq(x, p.x) && eq(y, p.y); }
  bool operator<(const point & p) const { return eq(x, p.x) ? lt(y, p.y) : lt(x, p.x); }
};

ostream& operator<<(ostream & o, point p) { return o << "(" << p.x << ", " << p.y << ")"; }

int ccw(point a, point b, point c) {
  return sgn((b - a) % (c - b));
}
LD area2(vector<point> & vp) {
  int len = vp.size();
  if (len <= 2) return 0;
  LD ret = vp.back() % vp[0];
  for (int i = 0; i + 1 < len; ++i)
    ret += vp[i] % vp[i+1];
  return abs(ret);
}
// check if point p inside (CONVEX/CONCAVE) polygon vp
// 0 on boundary, -1 inside, 1 outside
int pointVsPolygon(point & p, vector< point >& vp) {
  int wn = 0, n = (int)vp.size();
  auto next = [n](int id) { return id == n-1 ? 0 : id+1; };
  for(int i = 0; i < n; i++) {
    int cs = ccw(vp[next(i)], vp[i], p);
    if(cs == 0 && (vp[next(i)]-p) * (vp[i]-p) <= 0)
      return 0; // between(vp[i], p, vp[i+1])
    if(vp[i].y <= p.y) {
      if(vp[next(i)].y > p.y && cs > 0)
        wn++;
    }
    else {
      if(vp[next(i)].y <= p.y && cs < 0)
        wn--;
    }
  }
  return wn == 0 ? 1 : -1;
}

const int N = 1e6 + 5;
vector<point> poly[N];
vector<int> child[N];
int bit[N], st[N], en[N], parent[N], id[N];
LD ar2[N];
const int LG = 21;
int lv[N], par[LG][N];
int n, q, nodes = 0;
int get(int x) {
  int r = 0;
  for (; x; x -= x & -x)
    r += bit[x];
  return r;
}
void upd(int x, int v) {
  for (; x <= n+2; x += x & -x)
    bit[x] += v;
}
void dfs(int v) {
  st[v] = nodes++;
  for (int u : child[v])
    dfs(u);
  en[v] = nodes;
}

int c[N], a[N], b[N];
struct Line {
  point a, ab;
  LD x;
  int id;
  Line() {}
  Line(point a, point b, LD x, int id) : x(x), id(id) {
    if (b < a) swap(a, b);
    this->a = a;
    this->ab = b - a;
  }
  point b() const { return a + ab; }
  long double getY(LD px) const {
    assert(ab.x > 0);
    return a.y + (long double)ab.y * (px - a.x) / (long double)ab.x;
  }
  bool operator<(const Line& rhs) const {
    assert(!(ab == point()));
    if (rhs.ab == point()) {
      return ccw(a, b(), rhs.a) > 0;
    }
    else {
      assert(x == rhs.x);
      return getY(x) < rhs.getY(x);
    }
  }
};
vector<LD> vx;
set<Line> seg[N << 2];
void build(int id = 1, int l = 0, int r = (int)vx.size()) {
  seg[id].clear();
  if (r - l < 2)
    return;
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
}

void add(int x, int y, Line ll, int id = 1, int l = 0, int r= (int)vx.size()) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    ll.x = vx[(l+r) >> 1];
    assert(ll.a.x <= vx[l] && vx[r-1] <= ll.b().x);
    seg[id].insert(ll);
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  add(x, y, ll, il, l, mid);
  add(x, y, ll, ir, mid, r);
}
pair<Line, Line> get(int x, Line ll, int id = 1, int l = 0, int r = (int)vx.size()) {
  Line lo(point(), point(1e9 + 9, 0), vx[x], 0), hi(point(0, 1e9 + 9), point(1e9 + 9, 1e9 + 9), vx[x], 0);
  lo.x = hi.x = vx[x];
  // cerr << ll.a << " " << " " << vx[x] << " " << vx[l] << " " << vx[r-1] << endl;
  auto it = seg[id].lower_bound(ll);
  if (it != seg[id].end()) {
    Line cur = *it; cur.x = vx[x];
    auto now = it; ++now;
    while (now != seg[id].end()) {
      Line cnow = *now;
      if (fabs(cnow.getY(vx[x]) - cur.getY(vx[x])) < eps) {
        if (lv[cnow.id] > lv[cur.id])
          cur = cnow;
      }
      else break;
      ++now;
    }
    if (cur < hi)
      hi = cur;
    if (ccw(cur.a, cur.b(), ll.a) == 0)
      lo = hi = cur;
  }
  if (it != seg[id].begin()) {
    --it;
    Line cur = *it; cur.x = vx[x];
    while (it != seg[id].begin()) {
      --it;
      Line cnow = *it;
      if (fabs(cnow.getY(vx[x]) - cur.getY(vx[x])) < eps) {
        if (lv[cnow.id] > lv[cur.id])
          cur = cnow;
      }
      else break;
    }
    if (lo < cur)
      lo = cur;
    if (ccw(cur.a, cur.b(), ll.a) == 0)
      lo = hi = cur;
  }
  if (r - l < 2) {
    return make_pair(lo, hi);
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  pair<Line, Line> res;
  if (x < mid)
    res = get(x, ll, il, l, mid);
  else
    res = get(x, ll, ir, mid, r);
  if (lo < res.first) lo = res.first;
  if (res.second < hi) hi = res.second;
  return make_pair(lo, hi);
}


int lca(int u, int v) {
  if (lv[u] > lv[v]) swap(u, v);
  int d = lv[v] - lv[u];
  for (int i = 0; i < LG; ++i) if (d & (1 << i))
    v = par[i][v];
  if (u == v) return v;
  for (int i = LG-1; i >= 0; --i)
    if (par[i][u] != par[i][v])
      u = par[i][u], v = par[i][v];
  return par[0][v];
}

int main() {
  poly[0].push_back(point(-1, -1));
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    fill(bit, bit+n+3, 0);
    vx.clear();
    for (int i = 1; i <= n; ++i) {
      int k;
      scanf("%d", &k);
      poly[i].clear();
      while (k--) {
        int x, y;
        scanf("%d %d", &x, &y);
        poly[i].push_back(point(x, y));
        vx.push_back(x);
      }
      child[i].clear();
      ar2[i] = area2(poly[i]);
      id[i] = i;
    }
    child[0].clear();
    lv[0] = 0;
    for (int i = 0; i < LG; ++i) par[i][0] = 0;
    sort(id+1, id+n+1, [](int le, int ri) { return ar2[le] > ar2[ri]; });
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
      scanf("%d %d", c+i, a+i);
      if (c[i] == 1)
        scanf("%d", b+i), vx.push_back(a[i]);
    }
    sort(vx.begin(), vx.end());
    vx.erase(unique(vx.begin(), vx.end()), vx.end());
    build();
    for (int i = 1; i <= n; ++i) {
      int u = id[i];
      int pos = lower_bound(vx.begin(), vx.end(), poly[u][0].x) - vx.begin();
      pair<Line, Line> res = get(pos, Line(poly[u][0], poly[u][0], poly[u][0].x, 0));
      int v = lca(res.first.id, res.second.id);
      par[0][u] = v;
      lv[u] = lv[v] + 1;
      // cerr << u << " " << v << " " << res.first.id << " " << res.second.id << " " << res.first.a << " " <<res.second.a << endl;
      child[v].push_back(u);
      for (int j = 0; j + 1 < LG; ++j)
        par[j+1][u] = par[j][par[j][u]];
      int len = poly[u].size();
      auto next = [len](int id) { return id == len-1 ? 0 : id+1; };
      for (int j = 0; j < len; ++j) {
        point p1 = poly[u][j], p2 = poly[u][next(j)];
        if (p1.x != p2.x) {
          Line ll(p1, p2, p1.x, u);
          int le = lower_bound(vx.begin(), vx.end(), p1.x) - vx.begin();
          int ri = lower_bound(vx.begin(), vx.end(), p2.x) - vx.begin();
          if (ri < le) swap(le, ri);
          add(le, ri+1, ll);
        }
        else {
          Line L1(p1, p1 + point(1, 0), p1.x, u);
          Line L2(p2, p2 + point(1, 0), p2.x, u);
          int le = lower_bound(vx.begin(), vx.end(), p1.x) - vx.begin();
          add(le, le+1, L1);
          add(le, le+1, L2);
        }
      }
    }
    nodes = 0;
    dfs(0);
    for (int qq = 0; qq < q; ++qq) {
      int x = a[qq], y = b[qq];
      if (c[qq] == 1) {
        point p(x, y);
        int pos = lower_bound(vx.begin(), vx.end(), x) - vx.begin();
        pair<Line, Line> res = get(pos, Line(p, p, x, 0));
        int u = lca(res.first.id, res.second.id);
        upd(st[u]+1, +1);
      }
      else
        printf("%d\n", get(en[x]) - get(st[x]));
    }
  }
  return 0;
}