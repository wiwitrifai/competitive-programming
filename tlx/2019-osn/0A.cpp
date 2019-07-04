#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int match[N][N];
bool vis[N][N];

int n, m;
char grid[N][N];
char ans[N][N];

const int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
const char direct[] = "v>^<";

bool dfs(int x, int y) {
  if (vis[x][y])
    return false;
  vis[x][y] = true;
  for (int i = 0; i < 4; ++i) {
    int xx = x + dx[i], yy = y + dy[i];
    if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
    if (match[xx][yy] == -1 || dfs(match[xx][yy]/m, match[xx][yy] % m)) {
      match[x][y] = xx * m + yy;
      match[xx][yy] = x * m + y;
      return true;
    }
  }
  return false;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%s", grid[i]);
    for (int j = 0; j <= m; ++j)
      ans[i][j] = grid[i][j];
  }
  memset(match, -1, sizeof match);
  while (1) {
    bool found = 0;
    memset(vis, 0, sizeof vis);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (((i+j) & 1) == 0) continue;
        if (grid[i][j] == '.') continue;
        if (match[i][j] != -1) continue;
        found |= dfs(i, j);
      }
    }
    if (!found)
      break;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == '.') continue;
      if (match[i][j] == -1) continue;
      for (int k = 0; k < 4; ++k) {
        int xx = i + dx[k], yy = j + dy[k];
        int now = xx * m + yy;
        if (now == match[i][j]) {
          ans[xx][yy] = direct[k];
        }
      }
    }
  }
  for (int i = 0; i < n; ++i)
    printf("%s\n", ans[i]);
  return 0;
}
