#include <bits/stdc++.h>

using namespace std;

const int N = 2017;

int a[N][N], q, n;

int main() {
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      scanf("%d", a[i]+j);
  int cek = -1;
  while (q-- >= 0) {
    for (int i = 0; i < n; i++) {
      if (i == 0) {
        printf("%d ", 0);
      } else if (cek == -1) {
        printf("%d ", -a[0][i]);
        if (a[0][i] != 0)
          cek = i;
      } else {
        int now = -a[0][i];
        if (abs(now + a[0][cek]) != a[i][cek])
          now = -now;
        printf("%d ", now);
      }
    }
    printf("\n");
    if (q >= 0) {
      int p;
      scanf("%d", &p);
      p--;
      for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        a[i][p] = a[p][i] = x;
      }
    }
  }
  return 0;
}