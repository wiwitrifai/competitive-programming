#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5, M = 20;

struct node {
  int mask[M];
  node() {
    for (int i = 0; i < M; ++i)
      mask[i] = 1 << i;
  }
  node operator+(node & p) {
    node ret;
    for (int i = 0; i < M; ++i) {
      int now = mask[i], res = 0;
      for (int j = 0; j < M; ++j) {
        if (now & (1 << j))
          res |= p.mask[j];
      }
      ret.mask[i] = res;
    }
    return ret;
  }
  void combine(node p, node q) {
    for (int i = 0; i < M; ++i) {
      mask[i] = q.get(p.mask[i]);
    }
  }
  int get(int x) {
    int res = 0;
    for (int i = 0; i < M; ++i) {
      if (x & (1 << i))
        res |= mask[i];
    }
    return res;
  }
};

node seg[N << 2];

int a[N], n;

void build(int id = 1, int l = 0, int r = n) {
  if (r-l < 2) {
    int now = a[l];
    for (int i = 0; i < M; ++i) {
      if (now & (1 << i))
        seg[id].mask[i] = now;
    }
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
  seg[id].combine(seg[il], seg[ir]);
}

int get(int x, int y, int v, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return -1;
  if (x <= l && r <= y) {
    return seg[id].get(v);
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  int res = get(x, y, v, il, l, mid);
  if (res == -1)
    res = v; 
  int res2 = get(x, y, res, ir, mid, r);
  if (res2 != -1)
    res = res2;
  return res;
}

int main() {
  int q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  build();
  for (int i = 0; i < q; ++i) {
    int l, r;
    scanf("%d %d", &l, &r);
    --l, --r;
    int res = get(l, r, a[l]);
    puts((res & a[r]) > 0 ? "Shi" : "Fou");
  }
  return 0;
}
