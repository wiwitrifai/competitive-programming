#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

char s[N][N];
int d[N][N];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int main() {
  memset(d, -1, sizeof d);
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i)
    scanf("%s", s[i]);
  queue<pair<int, int>> que;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i][j] != '#') continue;
      d[i][j] = 0;
      que.emplace(i, j);
    }
  }
  while (!que.empty()) {
    int x, y;
    tie(x, y) = que.front();
    que.pop();
    for (int i = 0; i < 4; ++i) {
      int xx = x + dx[i], yy = y + dy[i];
      if (min(xx, yy) < 0 || xx >= n || yy >= m) continue;
      if (d[xx][yy] != -1) continue;
      d[xx][yy] = d[x][y] + 1;
      que.emplace(xx, yy);
    }
  }
  int ans = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      ans = max(ans, d[i][j]);
  printf("%d\n", ans);
  return 0;
}
