#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

char ss[N][N];
int d[N][N], dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++)
    scanf("%s", ss[i]);
  pair< int, int > s, f;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (ss[i][j] == 'F')
        f = {i, j};
      else if (ss[i][j] == 'S')
        s = {i, j};
    }
  }
  queue< pair< int, int > > que;
  memset(d, -1, sizeof d);
  d[s.first][s.second] = 0;
  que.push(s);
  while (!que.empty()) {
    int x = que.front().first, y = que.front().second;
    que.pop();
    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx < 0 || xx >= n || yy < 0 || y >= m)
        continue;
      if (d[xx][yy] != -1 || ss[xx][yy] == '*')
        continue;
      d[xx][yy] = d[x][y] + 1;
      que.push(make_pair(xx, yy)); 
    }
  }
  printf("%d\n", d[f.first][f.second]);
  return 0;
}