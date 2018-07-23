#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int a[N][N], ans[N][N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        scanf("%d", a[i]+j), ans[i][j] = a[i][j];
        if (ans[i][j] == -1)
          ans[i][j] = 1;
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (a[i][j] != -1) continue;
        if (i > 0)
          ans[i][j] = max(ans[i][j], ans[i-1][j]);
        if (j > 0)
          ans[i][j] = max(ans[i][j], ans[i][j-1]);
      }
    }
    bool cek = 1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (i > 0)
          cek &= ans[i][j] >= ans[i-1][j];
        if (j > 0)
          cek &= ans[i][j] >= ans[i][j-1];
      }
    }
    if (cek) {
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
          printf("%d%c", ans[i][j], j == m-1 ? '\n' : ' ');
    }
    else
      puts("-1");
  }
  return 0;
}