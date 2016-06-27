#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int inf = 1e9 + 9;
int n, a[N], q;

int m[N<<2], all[N<<2];

void build(int id = 1, int l = 0, int r = n) {
  if(r-l < 2) {
    m[id] = all[id] = a[l];
    return;
  }
  int mid = (l + r) >> 1, il = id<<1, ir = il|1;
  build(il, l, mid);
  build(ir, mid, r);
  m[id] = min(m[il], m[ir]);
  all[id] = all[il] | all[ir];
}

int get(int x, int y, int id = 1, int l = 0, int r = n) {
  if(x >= r || y <= l) return inf;
  if(x <= l && r <= y) return m[id];
  int mid = (l + r) >> 1, il = id << 1, ir = il|1;
  return min(get(x, y, il, l, mid), get(x, y, ir, mid, r));
}

void upd(int x, int y, int val, int id = 1, int l = 0, int r = n) {
  if(x >= r || y <= l) return;
  if(r-l < 2) {
    m[id] &= val;
    all[id] = m[id];
    return;
  }
  if(x <= l && r <= y && ((all[id] & val) == all[id]))
    return;
  int mid = (l + r) >> 1, il = id<<1, ir = il|1;
  upd(x, y, val, il, l, mid);
  upd(x, y, val, ir, mid, r);
  m[id] = min(m[il], m[ir]);
  all[id] = all[il] | all[ir];
}

int main() {
  scanf("%d%d", &n, &q);
  for(int i = 0; i<n; i++) {
    scanf("%d", a+i);
  }
  build();
  while(q--) {
    int t, l, r, val;
    scanf("%d%d%d", &t, &l, &r);
    l--;
    if(t == 0) {
      printf("%d\n", get(l, r));
    }
    else {
      scanf("%d", &val);
      upd(l, r, val);
    }
  }
  return 0;
}
