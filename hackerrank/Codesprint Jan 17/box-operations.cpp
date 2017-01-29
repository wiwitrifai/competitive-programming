#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, M = 504;

int a[N], n;
int mi[N << 2], p[N << 2], ladd[N << 2][M];
long long add[N << 2][M], s[N << 2];
int lz[N << 2];
  
void build(int id = 1, int l = 0, int r = n) {
  // for (int i = 0; i < M; i++)
  //   add[id][i] = ladd[id][i] = 0;
  p[id] = 1;
  if (r-l < 2) {
    s[id] = mi[id] = a[l];
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
  s[id] = s[il] + s[ir];
  mi[id] = min(mi[il], mi[ir]);
}
void upd(int id, int l, int r, int nadd[M], int pt) {
  mi[id] += nadd[0];
  int now = pt;
  int last = add[now];
  now += pt;
  for (int i = 0; i < M; i++) {
    ladd[id][i] = nadd[i];
    add[i] = last + 1LL * (r-l) * nadd[i];
    if (now < M) { 
      last = add[now];
      now += pt;
    }
    else
      last = add[M-1];
  }
  p[id] = 1;
  lz[id] = pt;
}
void shift(int id, int l, int r) {
  if (!lz[id])
    continue;
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  upd(il, l, mid, ladd[id], p[id]);
  upd(ir, mid, r, ladd[id], p[id]);
  lz[id] = 0;
}
void update1(int x, int val, int id = 1, int l = 0, int r = n) {
  if (r-l < 2) {
    s[id] = mi[id] = add[p[id]] + val;
    a[l] = val;
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  shift(id, l, r);
  if (x < mid)
    update1(x, val, il, l, mid);
  else
    update1(x, val, ir, mid, r);
  s[id] = s[il] + s[ir];
  mi[id] = min(mi[il], mi[ir]);
}
void update2(int x, int y, int nadd[M], int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    upd(id, l, r, nadd, p[id]);
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  shift(id, l, r);
  update2(x, y, nadd, il, l, mid);
  update2(x, y, nadd, ir, mid, r);
  mi[id] = min(mi[il], mi[ir]);
}
void update3(int x, int y, int d, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    int np = p[id];
    if (1LL * np * d >= M)
      np = M-1;
    else
      np = p[id] * d;
    p[id] = lz[id] = 0;
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  shift(id, l, r);
  update2(x, y, nadd, il, l, mid);
  update2(x, y, nadd, ir, mid, r);
  mi[id] = min(mi[il], mi[ir]);

}
int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  while (q--) {
    int ty, l, r, x;
    scanf("%d %d %d", &ty, &l, &r);
    if (ty == 1) {
      scanf("%d", &x);
      for (int i = l; i <= r; i++)
        a[i] += x;
    }
    else if (ty == 2) {
      scanf("%d", &x);
      for (int i = l; i <= r; i++)
        a[i] = a[i] < 0 ? (a[i]-x+1)/x  : a[i]/x;
    }
    else if (ty == 3) {
      int mi = a[l];
      for (int i = l+1; i <= r; i++)
        if (mi > a[i])
          mi = a[i];
      printf("%d\n", mi);
    }
    else {
      long long sum = 0;
      for (int i = l; i <= r; i++)
        sum += a[i];
      printf("%lld\n", sum);
    }
  }
  return 0;
}