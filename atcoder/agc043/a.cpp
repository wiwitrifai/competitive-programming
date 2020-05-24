#include <bits/stdc++.h>

using namespace std;

const int N = 105, inf = 1e9 + 7;

char grid[N][N];
int dp[N][N];

int main() {
  int n, m;
  scanf("%d %d" ,&n, &m);
  for (int i = 0; i < n; ++i)
    scanf("%s", grid[i]);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      dp[i][j] = inf;
    }
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (i+1 < n) {
        dp[i+1][j] = min(dp[i+1][j], dp[i][j] + (grid[i+1][j] != grid[i][j]));
      }
      if (j+1 < m) {
        dp[i][j+1] = min(dp[i][j+1], dp[i][j] + (grid[i][j+1] != grid[i][j]));
      }
    }
  }
  int ans = dp[n-1][m-1];
  if (grid[0][0] == '#')
    ++ans;
  if (grid[n-1][m-1] == '#')
    ++ans;
  printf("%d\n", ans / 2);
  return 0;
}
