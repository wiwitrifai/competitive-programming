#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, q, a[N], t[N], l[N], r[N], m;

int main() {
  scanf("%d %d %d", &n, &q, &m);
  for (int i = 1; i <= n; i++)
    scanf("%d", a+i);
  for (int i = 1; i <= q; i++) {
    scanf("%d %d %d", t+i, l+i, r+i);
  }
  while (m--) {
    int b;
    scanf("%d", &b);
    for (int i = q; i >= 1; i--) {
      if (b < l[i] || b > r[i]) continue;
      if (t[i] == 1) {
        if (b == l[i])
          b = r[i];
        else
          b--;
      }
      else {
        b = l[i] + r[i] - b;
      }
    }
    printf("%d", a[b]);
    if (m)
      printf(" ");
  }
  printf("\n");
  return 0;
}