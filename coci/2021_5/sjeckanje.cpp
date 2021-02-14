#include <bits/stdc++.h>

using namespace std;

void upd(long long & var, long long val) {
  if (var < val)
    var = val;
}

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  vector<long long> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &a[i]);
  }
  while (q--) {
    int l, r, x;
    scanf("%d %d %d", &l, &r, &x);
    vector<long long> up(n, 0), down(n, 0);
    for (int i = l-1; i < r; ++i)
      a[i] += x;
    for (int i = 1; i < n; ++i) {
      upd(up[i], up[i-1]);
      upd(up[i], down[i-1]);
      upd(down[i], up[i-1]);
      upd(down[i], down[i-1]);
      if (a[i] >= a[i-1]) {
        upd(up[i], up[i-1] + a[i] - a[i-1]);
      }
      if (a[i] <= a[i-1]) {
        upd(down[i], down[i-1] + a[i-1] - a[i]);
      }
    }
    printf("%lld\n", max(up[n-1], down[n-1]));
  }
  return 0;
}
