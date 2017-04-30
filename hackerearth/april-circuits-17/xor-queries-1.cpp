#include <bits/stdc++.h>

using namespace std;

struct BIT {
  vector < int > a, sum, xr;
  void build() {
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    sum.resize(a.size() + 1);
    xr.resize(a.size() + 1);
  }
  void upd(int x, int v = 1) {
    x = getup(x);
    for (int ax = a[x-1]; x <= a.size(); x+=x&-x)
      sum[x] += v, xr[x] ^= ax;
  }
  int getsum(int x) {
    x = getup(x); int ret = 0;
    for (; x; x-=x&-x)
      ret += sum[x];
    return ret;
  }
  int getxr(int x) {
    x = getup(x); int ret = 0;
    for (; x; x-=x&-x)
      ret ^= xr[x];
    return ret;
  }
  int getup(int x) {
    return upper_bound(a.begin(), a.end(), x) - a.begin();
  }
};
const int N = 1e5 + 5;
BIT seg[N << 1];
vector< int > a[N];
int T[N], L[N], R[N], X[N], Y[N], n, q;
void build(int id = 1, int l = 0, int r = n) {
  if (r-l < 2) {
    seg[id].a = a[l];
    seg[id].build();
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
  seg[id].a = seg[il].a;
  seg[id].a.insert(seg[id].a.end(), seg[ir].a.begin(), seg[ir].a.end());
  seg[id].build();
}
void update(int x, int v, int z = 1, int id = 1, int l = 0, int r = n) {
  seg[id].upd(v, z);
  if (r-l < 2) {
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  if (x < mid)
    update(x, v, z, il, l, mid);
  else
    update(x, v, z, ir, mid, r);
}
int getsum(int x, int y, int v, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return 0;
  if (x <= l && r <= y) {
    return seg[id].getsum(v);
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  return getsum(x, y, v, il, l, mid) + getsum(x, y, v, ir, mid, r);
}
int getxr(int x, int y, int v, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return 0;
  if (x <= l && r <= y) return seg[id].getxr(v);
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  return getxr(x, y, v, il, l, mid) ^ getxr(x, y, v, ir, mid, r);
}

int solve(int l, int r, int x) {
  int lo = 0, hi = 1e5;
  while (lo < hi) {
    int mid = (lo + hi) >> 1;
    int sm = getsum(l, r, mid);
    if (sm < x)
      lo = mid + 1;
    else
      hi = mid;
  }
  int sm = getsum(l, r, hi), xr = getxr(l, r, hi);
  if ((sm-x) & 1)
    xr ^= hi;
  return xr;
}
int val[N];

int main() {
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    val[i] = x;
    a[i].push_back(x); 
  }
  for (int i = 0; i < q; i++) {
    scanf("%d %d %d", T+i, L+i, R+i);
    if (T[i] == 2)
      scanf("%d %d", X+i, Y+i);
    else
      a[--L[i]].push_back(R[i]);
  }
  build();
  for (int i = 0; i < n; i++)
    update(i, val[i]);
  int ans = 0;
  for (int i = 0; i < q; i++) {
    if (T[i] == 1)
      update(L[i], val[L[i]], -1), update(L[i], R[i]), val[L[i]] = R[i];
    else {
      int l = 1 + ((ans^L[i]) % n), r = 1 + ((ans^R[i]) % n);
      if (l > r) swap(l, r);
      l--;
      int x = 1 + ((ans^X[i]) % (r-l)), y = 1 + ((ans^Y[i]) % (r-l));
      if (x > y) swap(x, y);
      x--;
      ans = solve(l, r, x) ^ solve(l, r, y);
      printf("%d\n", ans);
    }
  }
  return 0;
}