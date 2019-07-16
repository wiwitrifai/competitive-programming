#include <bits/stdc++.h>

using namespace std;

const int N = 101;

int grid[N][N];

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      scanf("%d", grid[i]+j);
  vector<tuple<int, int, int, int>> ans;
  for (int i = n; i >= 1; i -= 2) {
    for (int j = 1; j <= m; ++j) {
      if (grid[i][j] == 0) continue;
      if (grid[i-1][j] == 0) {
        int c = 1;
        while (1) {
          bool ok = 1;
          if (grid[i][j] == c)
            ok = 0;
          if (c == grid[i-1][j-1])
            ok = 0;
          if (ok)
            break;
          ++c;
        }
        ans.emplace_back(1, j, c, grid[i][j]);
        ans.emplace_back(1, j, c, c);
        ans.emplace_back(1, j, c, c);
      }
      else {
        ans.emplace_back(1, j, grid[i-1][j], grid[i][j]);
      }
    }
  }
  printf("%d\n", (int)ans.size());
  for (auto it : ans) {
    int v, c, a, b;
    tie(v, c, a, b) = it;
    printf("%d %d %d %d\n", v, c, a, b);
  }
  return 0;
}
