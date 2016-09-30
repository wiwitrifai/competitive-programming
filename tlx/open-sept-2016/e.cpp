#include <bits/stdc++.h>

using namespace std;

const int N = 404, M = 804;

bitset< M > vis[N][N];
int l[N][N], r[N][N];

int main() {
  int n, m, a, b, c, d;
  scanf("%d %d %d %d %d %d", &n, &m, &a, &b, &c, &d);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      scanf("%d", l[i]+j);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      scanf("%d", r[i]+j);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      vis[i][j].reset();
  queue< pair< pair<int, int>, pair<int, int> > > q;
  for (int i = l[a][b]; i <= r[a][b]; i++) {
    vis[a][b][i] = 1;
    q.push({{a, b}, {i, 0}});
  }
  int ans = -1;
  while (!q.empty()) {
    auto it = q.front();
    q.pop();
    int x = it.first.first, y = it.first.second, h = it.second.first, dd = it.second.second;
    // cerr << x << " " << y << " " << h << " " << dd << endl;
    if (x == c && y == d) {
      ans = dd;
      break;
    }
    static int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx >= 0 && xx < n && yy >= 0 && yy < m && h-1 <= r[xx][yy] && h-1 >= l[xx][yy] && !vis[xx][yy][h-1]) {
        vis[xx][yy][h-1] = 1;
        q.push({{xx, yy}, {h-1, dd+1}});
      }
    }
  }
  printf("%d\n", ans);

  return 0;
}