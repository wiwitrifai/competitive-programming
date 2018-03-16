#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5, mod = 1e9 + 7;

struct node {
  long long sum, le, ri, mul;
  node() {
    sum = 0;
    le = ri = 0;
    mul = 1;
  }
  void assign(int a) {
    sum = mul = a;
    le = ri = a;
  }
  void combine(const node & il, const node & ir) {
    sum = (il.sum + ir.sum + il.ri * ir.le) % mod;
    le = (il.le + il.mul * ir.le) % mod;
    ri = (ir.ri + ir.mul * il.ri) % mod;
    mul = il.mul * ir.mul % mod;
  }
};
node seg[N << 2];
int a[N], n;

void build(int id = 1, int l = 0, int r = n) {
  if (r-l < 2) {
    seg[id].assign(a[l]);
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
  seg[id].combine(seg[il], seg[ir]);
}

void update(int x, int v, int id = 1, int l = 0, int r = n) {
  if (r-l < 2) {
    seg[id].assign(v);
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  if (x < mid)
    update(x, v, il, l, mid);
  else
    update(x, v, ir, mid, r);
  seg[id].combine(seg[il], seg[ir]);
}

node get(int x, int y, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return node();
  if (x <= l && r <= y) return seg[id];
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  node now;
  now.combine(get(x, y, il, l, mid), get(x, y, ir, mid, r));
  return now;
}
int l[N], r[N], p[N], ans[N];

int main() {
  int q, k;
  scanf("%d %d %d", &n, &q, &k);
  vector<pair<int, int> > va;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    va.emplace_back(a[i], i);
  }
  sort(va.begin(), va.end());
  build();
  vector<pair<int, int> > vq;
  for (int i = 0; i < q; ++i) {
    scanf("%d %d %d", l+i, r+i, p+i);
    vq.emplace_back(p[i], i);
  }
  sort(vq.begin(), vq.end());
  for (int i = 0, j = 0; i < q; ++i) {
    while (j < va.size() && va[j].first < vq[i].first) update(va[j].second, k), ++j;
    int id = vq[i].second;
    ans[id] = get(l[id]-1, r[id]).sum % mod;
    if (ans[id] < 0) ans[id] += mod;
  }
  for (int i = 0; i < q; ++i) {
    printf("%d\n", ans[i]);
  }
  return 0;
}