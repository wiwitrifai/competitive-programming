#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, MAGIC = 300;
int ans[MAGIC][N];

int a[N], n;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", a+i);
  for (int k = 1; k < MAGIC; k++) {
    for (int j = n; j > 0; j--) {
      if (j + a[j] + k > n)
        ans[k][j] = 1;
      else
        ans[k][j] = ans[k][j+a[j]+k] + 1;
    }
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int p, k;
    scanf("%d %d", &p, &k);
    if (k < MAGIC)
      printf("%d\n", ans[k][p]);
    else {
      int now = 0;
      while (p <= n) {
        now++;
        p += a[p] + k;
      }
      printf("%d\n", now);
    }
  }

  return 0;
}