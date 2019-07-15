#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int col[N], row[N];
char buff[N];

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    int n, m;
    scanf("%d %d", &n, &m);
    fill(col, col+m, 0);
    fill(row, row+n, 0);
    vector<string> grid;
    for (int i = 0; i < n; ++i) {
      scanf("%s", buff);
      grid.push_back(buff);
      for (int j = 0; j < m; ++j) {
        if (buff[j] == '.') {
          ++row[i];
          ++col[j];
        }
      }
    }
    int ans = n + m + 1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int cur = row[i] + col[j];
        if (grid[i][j] == '.')
          --cur;
        ans = min(ans, cur);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
