#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char buffer[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<string> grid;
  vector<vector<int>> dist(n, vector<int>(m, -1));
  queue<pair<int, int>> que;
  for (int i = 0; i < n; ++i) {
    scanf("%s", buffer);
    grid.push_back(buffer);
    for (int j = 0; j < m; ++j)
      if (buffer[j] == 'G') {
        que.emplace(i, j);
        dist[i][j] = 1;
      }
  }
  while (!que.empty()) {
    int c = que.front().first, a = que.front().second;
    que.pop();
    int b = a-1;
    if (b < 0) b += m;
    for (int nc = c-1; nc <= c+1; ++nc) {
      if (nc < 0 || nc >= n) continue;
      if (grid[nc][b] == 'M' || grid[nc][a] == 'M') continue;
      if (dist[nc][b] == -1) {
        dist[nc][b] = dist[c][a] + 1;
        que.emplace(nc, b);
      }
    }
    int d = b - 1;
    if (d < 0) d += m;
    if (grid[c][d] != 'M' && grid[c][b] != 'M' && dist[c][d] == -1) {
      dist[c][d] = dist[c][a] + 1;
      que.emplace(c, d);
    }
  }
  int ans = -1;
  for (int i = 0; i < m; ++i) {
    if (dist[n-1][i] == -1) continue;
    if (ans == -1 || ans > dist[n-1][i])
      ans = dist[n-1][i];
  }
  printf("%d\n", ans);
  return 0;
}
