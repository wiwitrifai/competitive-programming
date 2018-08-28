#include <bits/stdc++.h>

using namespace std;

const int N = 222;

char s[N][N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i)
    scanf("%s", s[i]);
  int l = m, r = 0, lo = n, hi = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j)
      if (s[i][j] == 'B') {
        l = min(l, j);
        r = max(r, j);
        lo = min(lo, i);
        hi = max(hi, i);
      }
  }
  printf("%d %d\n", (lo+hi)/2+1, (l+r)/2+1);
  return 0;
}