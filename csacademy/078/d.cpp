#include <bits/stdc++.h>

using namespace std;

const int N = 5, inf = 1e9 + 7;

int n;

struct matrix {
  int a[N][N];
  matrix() {
    reset();
  }
  matrix operator+(matrix b) {
    matrix ret;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        ret.a[i][j] = -inf;
        for (int k = 0; k < n; ++k) {
          if (a[i][k] <= -inf) continue;
          for (int z = -1; z <= 1; ++z) {
            int w = k+z;
            if (w < 0 || w >= n) continue;
            if (b.a[w][j] <= -inf) continue;
            ret.a[i][j] = max(ret.a[i][j], a[i][k] + b.a[w][j]);
          }
        }
      }
    }
    return ret;
  }
  void reset() {
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        a[i][j] = -inf;
  }
};

const int M = 2e4 + 5;

matrix seg[M << 2];
int m;
int a[N][M];

void build(int id = 1, int l = 0, int r = m) {
  if (r-l < 2) {
    seg[id].reset();
    for (int i = 0; i < n; ++i)
      seg[id].a[i][i] = a[i][l];
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
  seg[id] = seg[il] + seg[ir];
}


void update(int x, int id = 1, int l = 0, int r = m) {
  if (r-l < 2) {
    seg[id].reset();
    for (int i = 0; i < n; ++i)
      seg[id].a[i][i] = a[i][x];
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  if (x < mid)
    update(x, il, l, mid);
  else
    update(x, ir, mid, r);
  seg[id] = seg[il] + seg[ir];
}

int main() {
  int q;
  scanf("%d %d %d", &n,&m, &q);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      scanf("%d", a[i]+j);
  build();
  for (int i = 0; i < q; ++i) {
    int r, c, t;
    scanf("%d %d %d", &r, &c, &t);
    --r, --c;
    a[r][c] = t;
    update(c);
    int ans = -inf;
    for (int j = 0; j < n; ++j) 
      for (int k = 0; k < n; ++k)
        ans = max(ans, seg[1].a[j][k]);
    printf("%d\n", ans);
  }

  return 0;
}