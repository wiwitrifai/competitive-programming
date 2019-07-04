#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char buffer[N];
vector<vector<int>> presum;
vector<string> grid;

int main() {
  int r, c;
  scanf("%d %d", &r, &c);
  for (int i = 0; i < r; ++i) {
    scanf("%s", buffer);
    grid.push_back(buffer);
  }
  presum.resize(r+1, vector<int>(c+1, 0));
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      presum[i+1][j+1] = (grid[i][j] == '1') + presum[i+1][j] + presum[i][j+1] - presum[i][j];
    }
  }
  int tot = presum[r][c];
  int ans = tot+1;
  for (int v = 1; v <= tot; ++v) {
    if (tot % v) continue;
    int h = tot / v;
    if (v > r || h > c) continue;
    for (int i = v; i <= r; ++i) {
      for (int j = h; j <= c; ++j) {
        ans = min(ans, tot - presum[i][j] + presum[i-v][j] + presum[i][j-h] - presum[i-v][j-h]);
      }
    }
  }
  if (ans > tot)
    ans = -1;
  printf("%d\n", ans);
  return 0;
}
