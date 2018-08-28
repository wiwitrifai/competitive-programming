#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

struct rect {
  int xa, xb, ya, yb;

  bool ok() {
    return xa <= xb && ya <= yb;
  }
};

rect intersect(rect r, rect s) {
  r.xa = max(r.xa, s.xa);
  r.ya = max(r.ya, s.ya);
  r.xb = min(r.xb, s.xb);
  r.yb = min(r.yb, s.yb);
  return r;
}

rect r[N];
rect le[N], ri[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d %d %d", &r[i].xa, &r[i].ya, &r[i].xb, &r[i].yb);
  }
  le[0] = r[0];
  for (int i = 1; i < n; ++i) {
    le[i] = intersect(le[i-1], r[i]);
  }
  if (le[n-2].ok()) {
    printf("%d %d\n", le[n-2].xa, le[n-2].ya);
    return 0;
  }
  ri[n-1] = r[n-1];
  for (int i = n-2; i >= 0; --i) {
    ri[i] = intersect(ri[i+1], r[i]);
  }
  if (ri[1].ok()) {
    printf("%d %d\n", ri[1].xa, ri[1].ya);
    return 0;
  }
  for (int i = 1; i + 1 < n; ++i) {
    rect res = intersect(le[i-1], ri[i+1]);
    if (res.ok()) {
      printf("%d %d\n", res.xa, res.ya);
      return 0;
    }
  }
  assert(false);
  return 0;
}