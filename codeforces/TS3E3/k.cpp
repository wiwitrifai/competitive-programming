#include <bits/stdc++.h>

using namespace std;

const int N = 105;

char s[N][N];
int r, c, dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1}, dist[N * N][16];

int upd(char ch) {
  int mask = 0;
  if (ch == 'b')
    mask = 1;
  else if (ch == 'y')
    mask = 2;
  else if (ch == 'r')
    mask = 4;
  else if (ch == 'g')
    mask = 8;
  return mask;
}
int get(char ch) {
  int mask = 0;
  if (ch == 'B')
    mask = 1;
  else if (ch == 'Y')
    mask = 2;
  else if (ch == 'R')
    mask = 4;
  else if (ch == 'G')
    mask = 8;
  return mask;
}


int main() {
  scanf("%d %d", &r, &c);
  while (r && c) {
    for (int i = 0; i < r; i++)
      scanf("%s", s[i]);
    int rc = r * c;
    queue< pair< int, int > > q;
    memset(dist, -1, sizeof dist);
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++)
        if (s[i][j] == '*') {
          q.push({i * c + j, 0});
          dist[i * c + j][0] = 0;
        }
    }
    while (!q.empty()) {
      int now = q.front().first, i = now / c, j = now % c;
      int mask = q.front().second;
      q.pop();
      for (int z = 0; z < 4; z++) {
        int x = i + dx[z], y = j + dy[z];
        if (x >= 0 && x < r && y >= 0 && y < c && s[x][y] != '#') {
          int must = get(s[x][y]), ne = mask | upd(s[x][y]);
          int to = x * c + y;
          if ((must & ne) == must && dist[to][ne] == -1) {
            dist[to][ne] = dist[now][mask] + 1;
            q.push({to, ne});
          }
        }
      }
    }
    int ans = -1;
    for (int i = 0; i < r; i++)
      for (int j = 0; j < c; j++) if (s[i][j] == 'X') {
        for (int k = 0; k < 16; k++) if (dist[i * c + j][k] != -1) {
          if (ans == -1 || ans > dist[i * c + j][k])
            ans = dist[i * c + j][k];
        }
      }
    if (ans < 0)
      puts("The poor student is trapped!");
    else
      printf("Escape possible in %d steps.\n", ans);
    scanf("%d %d", &r, &c);
  }

  return 0;
}