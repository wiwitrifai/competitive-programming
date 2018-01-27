
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
long long a[N], ma[N << 2], mi[N << 2], add[N << 2];
void build(int id = 1, int l = 0, int r = n) {
  add[id] = 0;
  if (r-l < 2) {
    ma[id] = mi[id] = a[l];
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
  ma[id] = max(ma[il], ma[ir]);
  mi[id] = min(mi[il], mi[ir]);
}
inline void upd1(int id, long long val) {
  add[id] += val;
  mi[id] += val;
  ma[id] += val;
}
inline void upd2(int id, long long val) {
  mi[id] = max(mi[id], val);
  ma[id] = max(ma[id], val);
}
inline void upd3(int id, long long val) {
  mi[id] = min(mi[id], val);
  ma[id] = min(ma[id], val);
}
void push(int id) {
  int il = id << 1, ir = il | 1;
  if (add[id]) {
    upd1(il, add[id]);    
    upd1(ir, add[id]);
    add[id] = 0;    
  }
  upd2(il, mi[id]);
  upd3(il, ma[id]);
  upd2(ir, mi[id]);
  upd3(ir, ma[id]);
}
void update(int x, int y, int t, int v, int id = 1, int l = 0,int r = n) {
  if (l >= y || x >= r) return;
  if (x <= l && r <= y) {
    if (t == 1)
      upd1(id, v);
    else if (t == 2)
      upd2(id, v);
    else
      upd3(id, v);
    return;
  }
  push(id);
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  update(x, y, t, v, il, l, mid);
  update(x, y, t, v, ir, mid, r);
  ma[id] = max(ma[il], ma[ir]);
  mi[id] = min(mi[il], mi[ir]);
}

void pushall(int id = 1, int l = 0, int r = n) {
  if (r-l < 2) {
    a[l] = mi[id];
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  push(id);
  pushall(il, l, mid);
  pushall(ir, mid, r);
  ma[id] = max(ma[il], ma[ir]);
  mi[id] = min(mi[il], mi[ir]);
}

int main() {
  int q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; ++i) {
    a[i] = 0;
  }
  build();
  for (int i = 0; i < q; ++i) {
    int t, x, y, z;
    scanf("%d %d %d %d", &t, &x, &y, &z);
    --x;
    update(x, y, t, z);
  }
  pushall();
  for (int i = 0; i < n; ++i) {
    printf("%lld%c", a[i], (i == n-1) ? '\n' : ' ');
  }
  return 0;
}