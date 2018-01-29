#include <bits/stdc++.h>

using namespace std;

const int N = 1 << 18;

int ma[N << 1], asg[N << 1], mask, n, a[N];
inline void build(int id = 1, int l = 0, int r = n) {
  asg[id] = -1;
  if (r-l < 2) {
    ma[id] = a[l];
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
  ma[id] = max(ma[il], ma[ir]);
}

inline void push(int id) {
  if (asg[id] != -1) {
    int il = id << 1, ir = il | 1;
    ma[il] = asg[il] = asg[id];
    ma[ir] = asg[ir] = asg[id];
    asg[id] = -1;
  }
}

inline void update(int x, int y, int v, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    asg[id] = v;
    ma[id] = v;
    return;
  }
  push(id);
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  int mul = (r-l) >> 1;
  if (mul & mask) swap(il, ir);
  update(x, y, v, il, l, mid);
  update(x, y, v, ir, mid, r);
  ma[id] = max(ma[il], ma[ir]);
}

inline int get(int x, int y, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return -1;
  if (x <= l && r <= y) {
    return ma[id];
  }
  push(id);
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  int mul = (r - l) >> 1;
  if (mul & mask) swap(il, ir);
  return max(get(x, y, il, l, mid), get(x, y, ir, mid, r));
}

int main() {
  int q;
  scanf("%d %d", &n, &q);
  n = 1 << n;
  mask = 0;
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  build();
  while (q--) {
    int t, x, y, z;
    scanf("%d %d", &t, &x);
    if (t == 1) {
      scanf("%d", &y);
      ++y;
      printf("%d\n", get(x, y));
    }
    else if (t == 2) {
      scanf("%d %d", &y, &z);
      ++y;
      update(x, y, z);
    }
    else {
      mask ^= x;
    }
  }
  return 0;
}