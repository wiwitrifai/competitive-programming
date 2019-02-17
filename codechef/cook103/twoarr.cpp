#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, M = N * 50;

int a[N], b[N], n;
struct PST {
  int L[M], R[M];
  int root[N], nodes = 0, last= 0;
  long long sum[M];
  PST() : nodes(0), last(0) {
  }
  int build(int l, int r, int * b) {
    int id = nodes++;
    if (r-l < 2) {
      sum[id] = b[l];
      return id;
    }
    int mid = (l + r) >> 1;
    L[id] = build(l, mid, b);
    R[id] = build(mid, r, b);
    sum[id] = sum[L[id]] + sum[R[id]];
    return id;
  }
  int update(int x, int y, int old_id, int l, int r) {
    int id = nodes++;
    if (r-l < 2) {
      sum[id] = y;
      return id;
    }
    int mid = (l + r) >> 1;
    L[id] = L[old_id], R[id] = R[old_id];
    if (x < mid)
      L[id] = update(x, y, L[old_id], l, mid);
    else
      R[id] = update(x, y, R[old_id], mid, r);
    sum[id] = sum[L[id]] + sum[R[id]];
    return id;
  }
  long long get(int x, int y, int id, int l, int r) {
    if (l >= y || x >= r) return 0;
    if (x <= l && r <= y) return sum[id];
    int mid = (l + r) >> 1;
    return get(x, y, L[id], l, mid) + get(x, y, R[id], mid, r);
  }
} pers;

long long sum[N << 2];
pair<int, int> lazy[N << 2];
void build(int id = 1, int l = 0, int r = n) {
  lazy[id] = {-1, -1};
  if (r-l < 2) {
    sum[id] = a[l];
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
  sum[id] = sum[il] + sum[ir];
}

inline void upd(int id, int l, int r, pair<int, int> v) {
  if (v.first == -1) return;
  sum[id] = pers.get(v.second, v.second + r - l, v.first, 0, n);
  lazy[id] = v;
}

inline void push(int id, int l, int r) {
  if (lazy[id].first == -1) return;
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  upd(il, l, mid, lazy[id]);
  upd(ir, mid, r, {lazy[id].first, lazy[id].second + mid - l});
  lazy[id] = {-1, -1};
}

void update(int x, int y, pair<int, int> v, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    upd(id, l, r, {v.first, v.second + l-x});
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  push(id, l, r);
  update(x, y, v, il, l, mid);
  update(x, y, v, ir, mid, r);
  sum[id] = sum[il] + sum[ir];
}

long long get(int x, int y, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return 0;
  if (x <= l && r <= y) {
    return sum[id];
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  push(id, l, r);
  return get(x, y, il, l, mid) + get(x, y, ir, mid, r);
}

int main() {
  int q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", b+i);
  }
  pers.root[0] = pers.build(0, n, b);
  pers.last = 0;
  build();
  for (int i = 0; i < q; ++i) {
    int t, l, r, x;
    scanf("%d %d %d", &t, &l, &r);
    if (t == 1) {
      --l;
      pers.root[pers.last+1] = pers.update(l, r, pers.root[pers.last], 0, n);
      ++pers.last;
    }
    else if (t == 2) {
      int x;
      scanf("%d", &x);
      --l; --x;
      update(l, r, make_pair(pers.root[pers.last], x));
    }
    else {
      --l;
      printf("%lld\n", get(l, r));
    }
  }
  return 0;
}