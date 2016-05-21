#include <bits/stdc++.h>
using namespace std;

const int inf = 1e8;

int n, m;
char a[555][555];
int dist[555][555], dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

int main() {
  scanf("%d%d", &n, &m);
  for(int i = 0; i<n; i++) {
    scanf("%s", a[i]);
  }
  queue< pair<int, int> > q;
  for(int i = 0; i<n; i++)
    for(int j = 0; j<m; j++)
      dist[i][j] = inf;
  q.push({0, 0});
  dist[0][0] = 0;
  while(!q.empty()) {
    int x = q.front().first, y = q.front().second;
    int dd = a[x][y] - '0';
    q.pop();
    for(int i = 0; i<4; i++) {
      int xx = x + dx[i] * dd, yy = y + dy[i] * dd;
      if(xx < n && xx >= 0 && yy < m && yy >= 0 && dist[xx][yy] == inf) {
        dist[xx][yy] = dist[x][y] + 1;
        q.push({xx, yy});
      }
    }
  }
  if(dist[n-1][m-1])
    puts("IMPOSSIBLE");
  else
    printf("%d\n", dist[n-1][m-1]);
  return 0;
}