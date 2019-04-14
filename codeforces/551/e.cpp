#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int ask(int xa, int ya, int xb, int yb) {
  printf("? %d %d %d %d\n", xa, ya, xb, yb);
  fflush(stdout);
  int res;
  scanf("%d", &res);
  assert(res != -1);
  return res;
}

void answer(int xa, int ya, int xb, int yb) {
  printf("! %d %d %d %d\n", xa, ya, xb, yb);
  fflush(stdout);
  exit(0);
}

int r[N], c[N];

int main() {
  int n;
  scanf("%d", &n);
  int ra = n+1, rb = -1, ca = n+1, cb = -1;
  for (int i = 1; i < n; ++i) {
    r[i] = ask(1, 1, i, n) & 1;
    c[i] = ask(1, 1, n, i) & 1;
    if (r[i]) {
      ra = min(ra, i);
      rb = max(rb, i+1);
    }
    if (c[i]) {
      ca = min(ca, i);
      cb = max(cb, i+1);
    }
  }
  if (ra < rb && ca < cb) {
    int res = ask(1, 1, ra, ca);
    if ((res & 1) == 0)
      swap(ca, cb);
    answer(ra, ca, rb, cb);
  }
  else if (ra < rb) {
    int lo = 1, hi = n;
    while (lo < hi) {
      int mid = (lo + hi) >> 1;
      if (ask(1, 1, ra, mid) & 1)
        hi = mid;
      else
        lo = mid + 1;
    }
    answer(ra, lo, rb, lo);
  }
  else if (ca < cb) {
    int lo = 1, hi = n;
    while (lo < hi) {
      int mid = (lo + hi) >> 1;
      if (ask(1, 1, mid, ca) & 1)
        hi = mid;
      else
        lo = mid + 1;
    }
    answer(lo, ca, lo, cb);
  }
  else
    assert(false);
  return 0;
}
