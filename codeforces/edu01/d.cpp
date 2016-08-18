#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

char s[N][N];
int b[N][N], ans[N * N], dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

int dfs(int x, int y, int v) {
  if (s[x][y] == '*')
    return 1;
  int ret = 0;
  b[x][y] = v;
  for (int i = 0; i < 4; i++) {
    int xx = x+dx[i], yy = y + dy[i];
    if (b[xx][yy] == 0)
      ret += dfs(xx, yy, v);
  }
  return ret;
}

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < n; i++)
    scanf("%s", s[i]);
  int now = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) if (b[i][j] == 0 && s[i][j] == '.') {
      ans[now] = dfs(i, j, now);
      now++;
    }
  }
  while (k--) {
    int x, y;
    scanf("%d %d", &x, &y);
    x--; y--;
    printf("%d\n", ans[b[x][y]]);
  }

  return 0;
}