#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int r[N], c[N];
int ans[N][N];

int main() {
  int n, m, h;
  scanf("%d %d %d", &n, &m, &h);
  for (int i = 0; i < m; ++i)
    scanf("%d", c+i);
  for (int i = 0; i < n; ++i)
    scanf("%d", r+i);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int x;
      scanf("%d", &x);
      ans[i][j] = 0;
      if (x)
        ans[i][j] = min(c[j], r[i]);
      printf("%d%c", ans[i][j], j == m-1 ? '\n' : ' ');
    }
  }

  return 0;
}