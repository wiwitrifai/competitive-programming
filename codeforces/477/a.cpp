#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, inf = 2e9 + 7;

int l[N], e[N];

int main() {
  int n, m, cl, ce, v;
  scanf("%d %d %d %d %d", &n, &m, &cl, &ce, &v);
  for (int i = 0; i < cl; ++i) {
    scanf("%d", l+i);
  }
  for (int i = 0; i < ce; ++i) {
    scanf("%d", e+i);
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int ans = inf;
    int xa, xb, ya, yb;
    scanf("%d %d %d %d", &ya, &xa, &yb, &xb);
    int dy = abs(ya - yb);
    if (xa > xb) swap(xa, xb);
    if (dy == 0)
      ans = min(ans, xb - xa);
    // elevator
    int id = lower_bound(e, e+ce, xa) - e;
    if (id < ce) {
      ans = min(ans, (dy + v - 1) / v + xb - xa + max(0, e[id] - xb) * 2);
    }
    if (id > 0) {
      --id;
      ans = min(ans, (dy + v - 1) / v + xb - xa + max(0, xa - e[id]) * 2);
    }
    // stairs
    id = lower_bound(l, l+cl, xa) - l;
    if (id < cl) {
      ans = min(ans, dy + xb - xa + max(0, l[id] - xb) * 2);
    }
    if (id > 0) {
      --id;
      ans = min(ans, dy + xb - xa + max(0, xa - l[id]) * 2);
    }
    printf("%d\n", ans);
  }
  return 0;
}