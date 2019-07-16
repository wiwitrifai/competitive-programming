#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int col[N << 2], n;
int cnt[N];

void build(int id = 1, int l = 0, int r = n) {
  col[id] = 1;
  if (r-l < 2)
    return;
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
  col[id] = col[il] == col[ir] ? col[il] : 0;
}

void add(int x, int v) {
  if (v == 0)
    return;
  cnt[x] += v;
}

void pushdown(int id, int il, int ir) {
  if (col[id] == 0) return;
  col[il] = col[id];
  col[ir] = col[id];
}

void update(int x, int y, int v, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y && col[id] > 0) {
    if (col[id] == v) return;
    add(col[id], -(r-l));
    col[id] = v;
    add(col[id], r-l);
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  pushdown(id, il, ir);
  update(x, y, v, il, l, mid);
  update(x, y, v, ir, mid, r);
  col[id] = col[il] == col[ir] ? col[il] : 0;  
}

int main() {
  int c, q;
  scanf("%d %d %d", &n, &c, &q);
  build();
  add(1, n);
  while (q--) {
    int p, x, a, b;
    scanf("%d %d %d %d", &p, &x, &a, &b);
    a %= n;
    b %= n;
    int s = cnt[p];
    // cerr << s << endl;
    int l = (a + 1LL * s * s) % n, r = (a + 1LL * (s + b) * (s + b)) % n;
    if (l > r) swap(l, r);
    // cerr << l << " change " << r << " " << x << endl;
    update(l, r+1, x);
  }
  int ans = 0;
  for (int i = 1; i <= c; ++i)
    ans = max(ans, cnt[i]);
  printf("%d\n", ans);
  return 0;
}