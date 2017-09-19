#include <bits/stdc++.h>

using namespace std;

const int N = 256;

long long val[N][N];
int d[N][N];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
int n, m, p, q;
char s[N][N];
bool isvalid(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < m && s[x][y] != '*';
}

int main() {
  scanf("%d %d %d %d", &n, &m, &q, &p);
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }
  memset(d, -1, sizeof d);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) if (s[i][j] >= 'A' && s[i][j] <= 'Z') {
      int v = q * (s[i][j] - 'A' + 1);
      queue<pair<int, int> > que;
      d[i][j] = 0;
      que.push(make_pair(i, j));
      while (!que.empty()) {
        int x = que.front().first, y = que.front().second;
        que.pop();
        val[x][y] += v >> d[x][y];
        if (v >> (d[x][y] + 1)) {
          for (int i = 0; i < 4; i++) {
            int xx = x + dx[i], yy = y + dy[i];
            if (!isvalid(xx, yy)) continue;
            if (d[xx][yy] != -1) continue;
            d[xx][yy] = d[x][y] + 1;
            que.push(make_pair(xx, yy));
          }
        }
      }

      // reset
      que.push(make_pair(i, j));
      d[i][j] = -1;
      while (!que.empty()) {
        int x = que.front().first, y = que.front().second;
        que.pop();
        for (int i = 0; i < 4; i++) {
          int xx = x + dx[i], yy = y + dy[i];
          if (!isvalid(xx, yy)) continue;
          if (d[xx][yy] == -1) continue;
          d[xx][yy] = -1;
          que.push(make_pair(xx, yy));
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      ans += val[i][j] > p;
    printf("%d\n", ans);
  return 0;
}