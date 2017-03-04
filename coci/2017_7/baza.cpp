#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int a[N][N], b[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      scanf("%d", a[i]+j);
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    for (int i = 0; i < m; i++)
      scanf("%d", b+i);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      bool ok = 1;
      for (int j = 0; j < m && ok; j++) {
        if (b[j] == -1) continue;
        if (a[i][j] != b[j])
          ok = 0;
      }
      ans += ok;
    }
    printf("%d\n", ans);
  }
  return 0;
}