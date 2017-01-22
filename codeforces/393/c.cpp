#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, inf = 1e8;

int h[N << 2], lz[N << 2], n;

void build(int id = 1, int l = 0, int r = n) {
  h[id] = lz[id] = 0;
  if (r-l < 2)
    return;
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
}

void shift(int id) {
  if (!lz[id]) return;
  int il = id << 1, ir = il | 1;
  h[il] += lz[id];
  lz[il] += lz[id];
  h[ir] += lz[id];
  lz[ir] += lz[id];
  lz[id] = 0;
}

void update(int x, int y, int v, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    lz[id] += v;
    h[id] += v;
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  shift(id);
  update(x, y, v, il, l, mid);
  update(x, y, v, ir, mid, r);
  h[id] = max(h[il], h[ir]);
}

int get(int id = 1, int l = 0, int r = n) {
  if (r-l < 2) {
    if (h[id] > 0)
      return l;
    return -1;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  shift(id);
  if (h[ir] > 0)
    return get(ir, mid, r);
  else
    return get(il, l, mid); 
}

int val[N];


int main() {
  scanf("%d", &n);
  build();
  for (int i = 0; i < n; i++) {
    int p, t, x;
    scanf("%d %d", &p, &t);
    if (t == 0)
      update(0, p, -1);
    else {
      scanf("%d", &x);
      update(0, p, +1);
      val[p-1] = x;
    }
    int ans = get();
    if (ans >= 0)
      ans = val[ans];
    printf("%d\n", ans);
  }
  return 0;
}