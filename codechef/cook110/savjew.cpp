#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, m;

int p[N];

struct SegTree {

  int maxi[N << 2];

  void build(int id = 1, int l = 0, int r = n) {
    if (r-l < 2) {
      maxi[id] = l;
      return;
    }
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    build(il, l, mid);
    build(ir, mid, r);
    maxi[id] = p[maxi[il]] < p[maxi[ir]] ? maxi[ir] : maxi[il];
  }

  void reset(int id = 1, int l = 0, int r = n) {
    if (r-l < 2) {
      maxi[id] = n;
      return;
    }
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    reset(il, l, mid);
    reset(ir, mid, r);
    maxi[id] = p[maxi[il]] < p[maxi[ir]] ? maxi[ir] : maxi[il];
  }

  int get(int x, int y, int id = 1, int l = 0, int r = n) {
    if (x >= r || l >= y) return n;
    if (x <= l && r <= y)
      return maxi[id];
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    int le = get(x, y, il, l, mid), ri = get(x, y, ir, mid, r);
    return p[le] < p[ri] ? ri : le;
  }

  void assign(int x, int v, int id = 1, int l = 0, int r = n) {
    if (r-l < 2) {
      maxi[id] = v;
      return;
    }
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    if (x < mid)
      assign(x, v, il, l, mid);
    else
      assign(x, v, ir, mid, r);
    maxi[id] = p[maxi[il]] < p[maxi[ir]] ? maxi[ir] : maxi[il];
  }
} awal, sisa;

int picked[N], dead[N];

void solve() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i)
    scanf("%d", p+i);
  p[n] = -1;
  awal.build();
  sisa.reset();
  fill(picked, picked+n, -1);
  fill(dead, dead+n, 0);
  for (int i = 0; i < m; ++i){
    int l, r;
    scanf("%d %d", &l, &r);
    --l;
    int v = awal.get(l, r);
    if (v < n) {
      assert(picked[v] == -1);
      picked[v] = i;
      awal.assign(v, n);
      sisa.assign(v, v);
    }
    while (1) {
      int u = sisa.get(l, r);
      if (p[u] <= p[v]) break;
      dead[u] = 1;
      sisa.assign(u, n);
    }
  }
  int pilih = 0;
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    if (picked[i] == -1) {
      ans += p[i];
      continue;
    }
    if (dead[i]) continue;
    pilih = max(pilih, p[i]);
  }
  ans += pilih;
  printf("%lld\n", ans);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
