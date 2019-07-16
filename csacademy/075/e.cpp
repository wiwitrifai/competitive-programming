#include <bits/stdc++.h>

#pragma GCC optimize("O2")

using namespace std;

const int N = 4e4 + 4, S = 202, LG = 16;

int il[N * 55], ir[N * 55], sum[N * 55];
int root[N], node = 0, a[N];

int build(int l, int r) {
  int id = ++node;
  sum[id] = 0;
  if (r-l < 2) {
    return id;
  }
  int mid = (l + r) >> 1;
  il[id] = build(l, mid);
  ir[id] = build(mid, r);
  return id;
}
int upd(int x, int v, int id, int l, int r) {
  int ID = ++node;
  sum[ID] = sum[id] + v;
  il[ID] = il[id];
  ir[ID] = ir[id];
  if (r-l < 2) {
    return ID;
  }
  int mid = (l + r) >> 1;
  if (x < mid)
    il[ID] = upd(x, v, il[id], l, mid);
  else
    ir[ID] = upd(x, v, ir[id], mid, r);
  return ID;
}

int get(int x, int y, int id, int l, int r) {
  if (x >= r || l >= y) return 0;
  if (x <= l && r <= y) return sum[id];
  int mid = (l + r) >> 1;
  return get(x, y, il[id], l, mid) + get(x, y, ir[id], mid, r);
}

int rmq[S][LG][N];

int get_rmq(int s, int l, int r) {
  int len = r-l;
  int lg = 31 - __builtin_clz(len);
  return max(rmq[s][lg][l], rmq[s][lg][r-(1 << lg)]);
}

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  root[0] = build(0, N);
  for (int i = 0; i < n; ++i)
    root[i+1] = upd(a[i], +1, root[i], 0, N);
  for (int i = 1; i < S; ++i) {
    for (int j = 0; j < n; ++j)
      rmq[i][0][j] = a[j] % i;
    for (int j = 0; j + 1 < LG; ++j) {
      for (int k = 0; k + (1 << (j+1)) <= n; ++k)
        rmq[i][j+1][k] = max(rmq[i][j][k], rmq[i][j][k+(1 << j)]);
    }
  }
  while (q--) {
    int l, r, k;
    scanf("%d %d %d", &l, &r, &k);
    if (k < S) {
      printf("%d\n", get_rmq(k, l-1, r));
    }
    else {
      int le = 0, ri = k-1;
      while (le < ri) {
        int mid = (le + ri + 1) >> 1;
        bool ok = 0;
        for (int i = 0; i < N; i += k) {
          int le = i + mid, ri = min(i+k, N);
          if (le >= ri) break;
          int cnt = get(le, ri, root[r], 0, N) - get(le, ri, root[l-1], 0, N);
          if (cnt > 0) {
            ok = 1;
            break;
          }
        }
        if (ok)
          le = mid;
        else
          ri = mid-1;
      }
      printf("%d\n", le);
    }
  }
  return 0;
}