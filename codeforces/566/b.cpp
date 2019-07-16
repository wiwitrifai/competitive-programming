#include <bits/stdc++.h>

using namespace std;

const int N = 505;

char s[N][N];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i)
    scanf("%s", s[i]);
  int sx = -1, sy = -1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i][j] != '*') continue;
      int cnt = 0;
      for (int k = 0; k < 4; ++k) {
        int x = i + dx[k], y = j + dy[k];
        if (x < 0 || x >= n || y < 0 || y >= m) continue;
        cnt += s[x][y] == '*';
      }
      if (cnt == 4) {
        if (sx != -1) {
          puts("NO");
          return 0;
        }
        sx = i;
        sy = j;
      }
    }
  }
  if (sx == -1) {
    puts("NO");
    return 0;
  }
  s[sx][sy] = '.';
  for (int k = 0; k < 4; ++k) {
    int x = sx, y = sy;
    while (1) {
      x += dx[k];
      y += dy[k];
      if (x < 0 || x >= n || y < 0 || y >= m) break;
      if (s[x][y] != '*') break;
      s[x][y] = '.';
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == '*') {
        puts("NO");
        return 0;
      }
    }
  }
  puts("YES");
  return 0;
}
