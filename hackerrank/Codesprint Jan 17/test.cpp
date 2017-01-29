#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long inf = 2e9 + 9;
#define floor(x, d) ((x)<0?((x)-(d)+1)/(d):(x)/(d))

int n, a[N];
long long mi[N << 2], add[N << 2], dd[N << 2];
long long sum[N << 2];
bool calc[N << 2];

void build(int id = 1, int l = 0 , int r = n) {
  add[id] = 0;
  dd[id] = 1;
  calc[id] = 1;
  if (r-l < 2) {
    sum[id] = mi[id] = a[l];
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
  mi[id] = min(mi[il], mi[ir]);
  sum[id] = sum[il] + sum[ir];
}
void shift(int id, int l, int r);
void upd(int id, int l, int r, long long ad, long long d) {
  if (d > 1 && r-l >= 2) {
    shift(id, l, r);
    add[id] += ad;
    dd[id] = d;
  }
  else
    add[id] += ad * dd[id];
  if (d > 1)
    calc[id] = 0;
  if (calc[id])
    sum[id] += ad * (r-l);
  mi[id] = floor(mi[id] + ad, d);
}
void shift(int id, int l, int r) {
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  if (dd[id] > 1 || add[id]) {
    upd(il, l, mid, add[id], dd[id]);
    upd(ir, mid, r, add[id], dd[id]);
    add[id] = 0;
    dd[id] = 1;
  }
}
void update(int x, int y, long long ad, long long d, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    upd(id, l, r, ad, d);
    return;
  }
  shift(id, l, r);
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  update(x, y, ad, d, il, l, mid);
  update(x, y, ad, d, ir, mid, r);
  mi[id] = min(mi[il], mi[ir]);
  if (calc[id])
    sum[id] = sum[il] + sum[ir];
}

long long getmin(int x, int y, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return inf;
  if (x <= l && r <= y)
    return mi[id];
  shift(id, l, r);
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  return min(getmin(x, y, il, l, mid), getmin(x, y, ir, mid, r));
}
void calcsum(int id, int l, int r) {
  // cerr << l << "-" << r << endl;
  if (calc[id]) return;
  calc[id] = 1;
  if (r-l < 2) {
    sum[id] = mi[id];
    return;
  }
  shift(id, l, r);
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  calcsum(il, l, mid);
  calcsum(ir, mid, r);
  sum[id] = sum[il] + sum[ir];
}
long long getsum(int x, int y, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return 0;
  if (x <= l && r <= y) {
    // cerr << l << " " << r << endl;
    calcsum(id, l, r);
    return sum[id];
  }
  shift(id, l, r);
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  return getsum(x, y, il, l, mid) + getsum(x, y, ir, mid, r);
}

int main() {
  int q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  build();
  while (q--) {
    int ty, l, r, x;
    scanf("%d %d %d", &ty, &l, &r);
    r++;
    if (ty == 1) {
      scanf("%d", &x);
      update(l, r, x, 1);
    }
    else if (ty == 2) {
      scanf("%d", &x);
      update(l, r, 0, x);
    }
    else if (ty == 3)
      printf("%lld\n", getmin(l, r));
    else
      printf("%lld\n", getsum(l, r));
  }
  return 0;
}