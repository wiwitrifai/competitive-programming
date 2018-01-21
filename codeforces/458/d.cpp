#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

int gcd(int a, int b) {
  return a ? gcd(b % a, a) : b;
}
int a[N], seg[N << 2], n;

void build(int id = 1, int l = 0, int r = n) {
  if (r-l < 2) {
    seg[id] = a[l];
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
  seg[id] = gcd(seg[il], seg[ir]);
}

void update(int x, int v, int id = 1, int l = 0, int r = n) {
  if (r-l < 2) {
    seg[id] = v;
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  if (x < mid)
    update(x, v, il, l, mid);
  else
    update(x, v, ir, mid, r);
  seg[id] = gcd(seg[il], seg[ir]);
}

int getr(int x, int v,  int id = 1, int l = 0, int r = n) {
  if (r <= x) return n;
  if ((seg[id] % v) == 0) return n;
  if (r-l < 2) return l;
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  int res;
  if ((res = getr(x, v, il, l, mid)) >= mid)
    res = getr(x, v, ir, mid, r);
  return res;
}

int getl(int x, int v,  int id = 1, int l = 0, int r = n) {
  if (x < l) return -1;
  if ((seg[id] % v) == 0) return -1;
  if (r-l < 2) return l;
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  int res;
  if ((res = getl(x, v, ir, mid, r)) < mid)
    res = getl(x, v, il, l, mid);
  // cerr << l << " " << r << " " << res << endl;
  return res;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  build();
  int q;
  scanf("%d", &q);
  while (q--) {
    int t, x, y, z;
    scanf("%d %d %d", &t, &x, &y);
    if (t == 1) {
      scanf("%d", &z);
      --x, --y;
      int ri = getr(x, z), le = getl(y, z);
      // cerr << ri << " " << le << endl;;
      puts(ri >= le ? "YES" : "NO");
    }
    else
      update(x-1, y);
  }
  return 0;
}