#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, LG = 31;

int sum[LG][N], a[N];

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < LG; ++j)
      sum[j][i+1] = sum[j][i] + ((a[i] >> j) & 1);
  }
  while (q--) {
    int l, r;
    scanf("%d %d", &l, &r); --l;
    int x = 0;
    for (int i = 0; i < LG; ++i) {
      int v = sum[i][r] - sum[i][l];
      if (v + v < r-l)
        x |= (1 << i);
    }
    printf("%d\n", x);
  }
  return 0;
}