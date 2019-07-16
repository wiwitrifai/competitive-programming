#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 4;

int sum[N];
int qi[N], qj[N], qk[N];
int n, q, a[N];
int id_q[N], id_a[N];
int ans[N];

int get(int x, int y, int id = 1, int l = 0, int r = n) {
  if (l >= y || r <= x) return 0;
  if (x <= l && r <= y) return sum[id];
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  return get(x, y, il, l, mid) + get(x, y, ir, mid, r);
}

void update(int x, int v, int id = 1, int l = 0, int r = n) {
  if (r-l < 2) {
    sum[id] = v;
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  if (x < mid)
    update(x, v, il, l, mid);
  else
    update(x, v, ir, mid, r);
  sum[id] = sum[il] + sum[ir];
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d", a+i), id_a[i] = i;
  scanf("%d", &q);
  for (int i = 1; i <= q; ++i) {
    id_q[i] = i;
    scanf("%d %d %d", qi+i, qj+i, qk+i);
  }
  sort(id_a+1, id_a+n+1, [&](int l, int r) {
    return a[l] > a[r];
  });
  sort(id_q+1, id_q+q+1, [&](int l, int r) {
    return qk[l] > qk[r];
  });
  for (int i = 1, j = 1; i <= q; ++i) {
    int id = id_q[i];
    while (j <= n && a[id_a[j]] > qk[id]) {
      update(id_a[j]-1, +1);
      ++j;
    }
    ans[id] = get(qi[id]-1, qj[id]);
  }
  for (int i = 1; i <= q; ++i)
    printf("%d\n", ans[i]);
  return 0;
}