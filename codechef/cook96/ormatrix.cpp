#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

char a[N][N];
int row[N], col[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i)
      scanf("%s", a[i]);
    memset(row, 0, sizeof row);
    memset(col, 0, sizeof col);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        a[i][j] -= '0';
        if (a[i][j])
          ++row[i], ++col[j], ++cnt;
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (j)
          printf(" ");
        int ans = a[i][j] ? 0 : ((row[i] + col[j]) > 0 ? 1 : (cnt ? 2 : -1));
        printf("%d", ans);
      }
      printf("\n");
    }
  }
  return 0;
}