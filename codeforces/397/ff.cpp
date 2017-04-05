#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 6, inf = 1e9 + 7;

int le[N], ri[N], a[N], ans[N], sz;
int n, m;
vector< int > que[N];
int seg[N], val[N];
void build(int id = 1, int l = 0, int r = sz) {
  seg[id] = n+1;
  if (r-l < 2) return;
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
}
void upd(int v, int last, int id = 1, int l = 0, int r = sz) {
  seg[id] = min(seg[id], last);
  if (r-l < 2) return;
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  if (val[mid] > v)
    upd(v, last, il, l, mid);
  else
    upd(v, last, ir, mid, r);
}
int get(int x, int y, int id = 1, int l = 0, int r = sz) {
  if (x > val[r-1] || val[l] > y) return inf;
  if (x <= val[l] && val[r-1] <= y) return seg[id];
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  return min(get(x, y, il, l, mid), get(x, y, ir, mid, r));
}

int bit[N];
void upd_bit(int x, int val) {
  for (; x <= n+1; x += x&-x)
    bit[x] = min(bit[x], val);
}
int get_bit(int x) {
  int ret = inf;
  for (; x; x -= x&-x)
    ret = min(ret, bit[x]);
  return ret;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", a+i), val[i-1] = a[i];
  sort(val, val+n);
  sz = unique(val, val+n) - val;
  build();
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", le+i, ri+i);
    que[le[i]].push_back(i);
  }
  fill(bit, bit+n+2, inf);
  for (int i = n; i >= 1; i--) {
    int up = inf;
    while (up >= a[i]) {
      int id = get(a[i], up);
      upd_bit(id, a[id]-a[i]);
      if (up == a[i]) break;
      up = (a[i] + up)/2;
    }
    int down = 0;
    while (down <= a[i]) {
      int id = get(down, a[i]);
      upd_bit(id, a[i]-a[id]);
      if (down == a[i]) break;
      down = (a[i] + down + 1)/2;
    }
    upd(a[i], i);
    for (int id : que[i]) {
      ans[id] = get_bit(ri[id]);
    }
  }
  for (int i = 1; i <= m; i++)
    printf("%d\n", ans[i]);
  return 0;
}