#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9, N = 1e5 + 5, M = 43;
int fac[M];
set<int> id[M];
int n, m;
int sum[N << 2][M], sf[N << 2];
int lz[N << 2];
int a[N];

inline void add(int & le, int ri) {
  le += ri;
  if (le >= mod)
    le -= mod;
}

inline void combine(int id, int il, int ir) {
  sf[id] = 0;
  for (int i = 0; i < M; ++i) {
    sum[id][i] = sum[il][i] + sum[ir][i];
    add(sf[id], 1LL * sum[id][i] * fac[i] % mod);
  }
}

inline void build(int id = 1, int l = 0, int r = n) {
  if (r-l < 2) {
    if (a[l] < M)
      sum[id][a[l]]++, sf[id] = fac[a[l]];
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
  combine(id, il, ir);
}

inline void incr(int id, int v) {
  sf[id] = 0;
  lz[id] += v;
  for (int i = M-1; i >= 0; --i) {
    int nx = i + v;
    if (nx < M) {
      sum[id][nx] = sum[id][i];
      add(sf[id], 1LL * sum[id][nx] * fac[nx] % mod);
    }
    sum[id][i] = 0;
  }
}

inline void push(int id) {
  if (lz[id] == 0) return;
  int il = id << 1, ir = il | 1;
  incr(il, lz[id]);
  incr(ir, lz[id]);
  lz[id] = 0;
}

inline void add1(int x, int y, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    incr(id, 1);
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  push(id);
  add1(x, y, il, l, mid);
  add1(x, y, ir, mid, r);
  combine(id, il, ir);
}

inline void upd1(int x, int v, int id = 1, int l = 0, int r = n) {
  if (r-l < 2) {
    for (int i = 0; i < M; ++i)
      sum[id][i] = 0;
    if (v < M) {
      sf[id] = fac[v];
      sum[id][v] = 1;
    }
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  push(id);
  if (x < mid)
    upd1(x, v, il, l, mid);
  else
    upd1(x, v, ir, mid, r);
  combine(id, il, ir);
}

inline int get(int x, int y, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return 0;
  if (x <= l && r <= y)
    return sf[id];
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  push(id);
  int ret = 0;
  add(ret, get(x, y, il, l, mid));
  add(ret, get(x, y, ir, mid, r));
  return ret;
}

int main() {
  fac[0] = 1;
  for (int i = 1; i < M; ++i) {
    fac[i] = (1LL * fac[i-1] * i) % mod;
  }
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  build();
  while (m--) {
    int t, l, r;
    scanf("%d %d %d", &t, &l, &r);
    l--;
    if (t == 1)
      add1(l, r);
    else if (t == 2)
      printf("%d\n", get(l, r));
    else
      upd1(l, r);
  }
  return 0;
}