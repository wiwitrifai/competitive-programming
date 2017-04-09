#include <bits/stdc++.h>

using namespace std;

const int N = 2017;
int n;
long long x[N], y[N], z[N], r[N];
bool used[N];
bool can2(long long len) {
  long long xo, yo, zo;
  xo = yo = zo = 1e9;
  for (int i = 0; i < n; i++) {
    if (used[i]) continue;
    xo = min(xo, x[i]-r[i]);
    yo = min(yo, y[i]-r[i]);
    zo = min(zo, z[i]-r[i]);
  }
  for (int i = 0; i < n; i++) {
    if (used[i]) continue;
    if (x[i] - r[i] < xo || x[i] + r[i] > xo+len) return 0;
    if (y[i] - r[i] < yo || y[i] + r[i] > yo+len) return 0;
    if (z[i] - r[i] < zo || z[i] + r[i] > zo+len) return 0;
  }
  return 1;
}
bool mark(long long xo, long long yo, long long zo, long long len) {
  memset(used, 0, sizeof used);
  for (int i = 0; i < n; i++) {
    if (x[i] - r[i] < xo || x[i] + r[i] > xo+len) continue;
    if (y[i] - r[i] < yo || y[i] + r[i] > yo+len) continue;
    if (z[i] - r[i] < zo || z[i] + r[i] > zo+len) continue;
    used[i] = 1;
  }
  return can2(len);
}
bool can(long long s) {
  long long xl, xh, yl, yh, zl, zh;
  xl = yl = zl = 1e9;
  xh = yh = zh = -1e9;
  for (int i = 0; i < n; i++) {
    xl = min(xl, x[i]-r[i]);
    yl = min(yl, y[i]-r[i]);
    zl = min(zl, z[i]-r[i]);
    xh = max(xh, x[i]+r[i]);
    yh = max(yh, y[i]+r[i]);
    zh = max(zh, z[i]+r[i]);
  }
  if (mark(xl, yl, zl, s)) return 1;
  if (mark(xl, yl, zh-s, s)) return 1;
  if (mark(xl, yh-s, zl, s)) return 1;
  if (mark(xl, yh-s, zh-s, s)) return 1;
  if (mark(xh-s, yl, zl, s)) return 1;
  if (mark(xh-s, yl, zh-s, s)) return 1;
  if (mark(xh-s, yh-s, zl, s)) return 1;
  if (mark(xh-s, yh-s, zh-s, s)) return 1;
  return 0;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%lld %lld %lld %lld", x+i, y+i, z+i, r+i); 
    }
    long long l = 1, r = 1e9;
    while (l < r) {
      long long mid = (l + r)/2;
      if (can(mid))
        r = mid;
      else
        l = mid + 1;
    }
    printf("Case #%d: %lld\n", tc, l);
  }
  return 0;
}