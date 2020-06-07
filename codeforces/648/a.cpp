#include <bits/stdc++.h>

using namespace std;

const int N = 101;

int a[N][N], row[N], col[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    fill(row, row+n, 0);
    fill(col, col+m, 0);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) {
        scanf("%d", &a[i][j]);
        row[i] += a[i][j];
        col[j] += a[i][j];
      }
    int mr = 0, mc = 0;
    for (int i= 0; i < n; ++i)
      mr += row[i] == 0;
    for (int i= 0; i < m; ++i)
      mc += col[i] == 0;
    int ans = min(mc, mr);
    puts((ans & 1) ? "Ashish" : "Vivek");
  }

  return 0;
}
