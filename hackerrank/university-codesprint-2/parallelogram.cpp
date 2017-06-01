#include <bits/stdc++.h>

using namespace std;

const int N = 806;

int vis[N][N];
char board[N][N];
int dx[] = {-1, -1, 0, 1, 1, 0}, dy[] = {0, 1, 1, 0, -1, -1};

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", board[i]);
  }
  int q;
  scanf("%d", &q);
  int cur = 1;
  for (int i = 0; i < q; i++) {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    a--; b--;
    int ans = 0;
    for (int x = a; x < c; x++) {
      for (int y = b; y < d; y++) if (vis[x][y] != cur) {
        ans++;
        queue< pair< int, int > > que;
        que.push(make_pair(x, y));
        vis[x][y] = cur;
        char col = board[x][y];
        while (!que.empty()) {
          pair< int, int > now = que.front(); que.pop();
          for (int j = 0; j < 6; j++) {
            int xx = now.first + dx[j], yy = now.second + dy[j];
            if (xx < a || xx >= c || yy < b || yy >= d) continue;
            if (vis[xx][yy] == cur || board[xx][yy] != col) continue; 
            vis[xx][yy] = cur;
            que.push(make_pair(xx, yy));
          }
        }
      }
    }
    printf("%d\n", ans);
    cur++;
  }
  return 0;
}