#include <bits/stdc++.h>

using namespace std;

const int N = 101;

char s[N][N];
int vis[N][N];

const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, -1, 0, 1};

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
      scanf("%s", s[i]);
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        vis[i][j] = 0;
        if (s[i][j] != 'B') continue;
        for (int k = 0; k < 4; ++k) {
          int r = i + dr[k], c = j + dc[k];
          if (r < 0 || r >= n || c < 0 || c >= m) continue;
          if (s[r][c] == '.')
            s[r][c] = '#';
        }
      }
    }
    queue<pair<int, int>> que;
    if (s[n-1][m-1] != '#') {
      que.emplace(n-1, m-1);
    }
    while (!que.empty()) {
      int r = que.front().first, c = que.front().second;
      que.pop();
      for (int k = 0; k < 4; ++k) {
        int x = r + dr[k], y = c + dc[k];
        if (x < 0 || x >= n || y < 0 || y >= m) continue;
        if (vis[x][y] || s[x][y] == '#') continue;
        vis[x][y] = 1;
        que.emplace(x, y);
      }
    }
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (s[i][j] == 'G')
          ok &= vis[i][j];
        else if (s[i][j] == 'B')
          ok &= !vis[i][j];
      }
    }
    puts(ok ? "Yes" : "No");
  }

  return 0;
}
