#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int a[N], g[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int p,q ;
    scanf("%d %d", &p, &q);
    int n = p * q;
    for (int i = 0; i < n; i++) {
      scanf("%d", a+i);
    }
    int one = 0;
    int ans = 0;
    for (int i = 0; i < p; i++) {
      int o = 0, z = 0;
      g[i] = 0;
      for (int j = 0; j < q; j++)
        g[i] += a[i * q + j];
      one += (g[i] + g[i] > q);
    }
    if (one + one > p)
      ans = 1;
    for (int i = 0; i < q && !ans; i++) {
      for (int j = 0; j < p; j++) {
        int now = j * q + i;
        g[j] -= a[now];
        g[(j + p - 1) % p] += a[now];
      }
      one = 0;
      for (int j = 0; j < p; j++)
        one += (g[j] + g[j] > q);
      if (one + one > p)
        ans = 1;
    }
    printf("%d\n", ans);
  }
  return 0;
}