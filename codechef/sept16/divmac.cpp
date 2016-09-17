#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int seg[N << 2][20], lazy[N << 2], n, a[N], p[N], to[N];

void build(int id = 1, int l = 0, int r = n) {
  lazy[id] = 0;
  if (r-l < 2) {
    int now = a[l];
    for (int i = 0; i < 20; i++) {
      seg[id][i] = p[now];
      now = to[now];
    }
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
  for (int i = 0; i < 20; i++)
    seg[id][i] = max(seg[il][i], seg[ir][i]);
}

void shift(int id) {
  if (lazy[id]) {
    int il = id << 1, ir = il | 1;
    for (int i = 0; i + lazy[id] < 20; i++) {
      if (seg[il][i] == 1 && seg[ir][i] == 1)
        break;
      seg[il][i] = seg[il][i + lazy[id]];
      seg[ir][i] = seg[ir][i + lazy[id]];
    }
    for (int i = max(0, 20-lazy[id]); i < 20; i++) {
      if (seg[il][i] == 1 && seg[ir][i] == 1)
        break;
      seg[il][i] = 1;
      seg[ir][i] = 1;
    }
    lazy[il] += lazy[id];
    lazy[ir] += lazy[id];
    lazy[id] = 0;
  }
}

void upd(int x, int y, int id = 1, int l = 0, int r = n) {
  if (x >= r || y <= l) return;
  if (x <= l && r <= y) {
    for (int i = 0; i < 19; i++) {
      seg[id][i] = seg[id][i+1];
      if (seg[id][i] == 1)
        break;
    }
    seg[id][19] = 1;
    lazy[id]++;
    return;
  }
  shift(id);
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  upd(x, y, il, l, mid);
  upd(x, y, ir, mid, r);
  for (int i = 0; i < 20; i++) {
    if (seg[id][i] == 1)
      break;
    seg[id][i] = max(seg[il][i], seg[ir][i]);
  }
}

int get(int x, int y, int id = 1, int l = 0, int r = n) {
  if (x >= r || y <= l) return 1;
  if (x <= l && r <= y)
    return seg[id][0];
  shift(id);
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  return max(get(x, y, il, l, mid), get(x, y, ir, mid, r));
}

int main() {
  p[1] = 1;
  for (int i = 2; i < N; i++) if (p[i] == 0) {
    p[i] = i;
    for (long long j = 1LL * i * i; j < N; j += i)
      if (p[j] == 0)
        p[j] = i;
  }
  for (int i = 1; i < N; i++)
    to[i] = i / p[i];
  int t;
  scanf("%d", &t);
  while (t--) {
    int m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
      scanf("%d", a+i);
    build();
    while (m--) {
      int y, l, r;
      scanf("%d %d %d", &y, &l, &r);
      l--;
      if (y)
        printf("%d ", get(l, r));
      else
        upd(l, r);
    }
    printf("\n");
  }

  return 0;
}