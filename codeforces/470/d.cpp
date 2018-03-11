#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N], t[N];
int sb[N], sa[N], tb[N], ta[N];

int main() {
  scanf("%s %s", s, t);
  int n = strlen(s), m = strlen(t);
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] != 'A') cnt = 0;
    else ++cnt;
    sa[i] = cnt;
    sb[i+1] = sb[i] + (s[i] != 'A');
  }
  cnt = 0;
  for (int i = 0; i < m; ++i) {
    if (t[i] != 'A') cnt = 0;
    else ++cnt;
    ta[i] = cnt;
    tb[i+1] = tb[i] + (t[i] != 'A');
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int x, y, l, r;
    scanf("%d %d %d %d", &x, &y, &l, &r); --x, --l;
    int bs = sb[y] - sb[x], bt = tb[r] - tb[l];
    int as = min(sa[y-1], y-x), at = min(ta[r-1], r-l);
    if (as < at) {
      printf("0");
      continue;
    }
    if ((as % 3) != (at % 3)) {
      bs += 2;
    }
    if (bs == 0 && bt > 0) {
      if (as > at) bs += 2;
    }
    if (bs == 0 && bt > 0) {
      printf("0");
      continue;
    }
    printf((bs <= bt && ((bt-bs) & 1) == 0) ? "1" : "0");
  }
  printf("\n");
  return 0;
}