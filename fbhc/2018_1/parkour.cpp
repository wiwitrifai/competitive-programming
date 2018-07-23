#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, inf = 1e9 + 7;

int up[N << 2];
int down[N << 2];
int n, m, h[N];

void build(int id = 1, int l = 0, int r = n) {
  up[id] = down[id] = inf;
  if (r-l < 2) return;
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
}

void update(int x, int y, int u, int d, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    up[id] = min(up[id], u);
    down[id] = min(down[id], d);
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  update(x, y, u, d, il, l, mid);
  update(x, y, u, d, ir, mid, r);
}

int upper[N], lower[N];

void dfs(int u = inf, int d = inf, int id = 1, int l = 0, int r = n) {
  u = min(u, up[id]);
  d = min(d, down[id]);
  if (r-l < 2) {
    upper[l] = u;
    lower[l] = d;
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  dfs(u, d, il, l, mid);
  dfs(u, d, ir, mid, r);
}

int main() {
  clock_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; ++tc) {
    scanf("%d %d", &n, &m);
    int h1, h2, w, x, y, z;
    scanf("%d %d %d %d %d %d", &h1, &h2, &w, &x, &y, &z);
    h[0] = h1;
    h[1] = h2;
    for (int i = 2; i < n; ++i) {
      h[i] = (1LL * w * h[i-2] + 1LL * x * h[i-1] + y) % z; 
    }
    build();
    for (int i = 0; i < m; ++i) {
      int a, b, u, d;
      scanf("%d %d %d %d", &a, &b, &u, &d);
      if (a > b)
        swap(a, b), swap(u, d);
      update(a, b, u, d);
    }
    dfs();
    double lo = 0, hi = 0;
    for (int i = 0; i < n; ++i)
      hi = max(hi, (double)h[i]);
    for (int it = 0; it < 100; ++it) {
      double mid = (lo + hi) / 2;
      double le = max(h[0] - mid, (double)0.0), ri = h[0] + mid;
      bool ok = 1;
      for (int i = 1; i < n; ++i) {
        le -= lower[i];
        ri += upper[i];
        double cle = max(h[i] - mid, (double)0.0), cri = h[i] + mid;
        le = max(le, cle);
        ri = min(ri, cri);
        if (le > ri) {
          ok = 0;
          break;
        }
      }
      if (ok)
        hi = mid;
      else
        lo = mid;
    }
    printf("Case #%d: %.6lf\n", tc, hi);
    cerr << " TC# " << tc << " done ! time : " << (double)(clock() - startt) * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
  }
  return 0;
}