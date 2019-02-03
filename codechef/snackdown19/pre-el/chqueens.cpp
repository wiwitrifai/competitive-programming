#include <bits/stdc++.h>

using namespace std;

const int N = 105;
int n, m, p, q;
bool valid(int x, int y) {
  if (min(x, y) < 0 || x >= n | y >= m)
    return false;
  return true;
}

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int cnt[N][N][4];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d %d %d", &n, &m, &p, &q);
    --p, --q;
    long long ans = 0;
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        for (int k = 0; k < 4; ++k) {
          int x = i+dx[k], y = j+dy[k];
          if (!valid(x, y)) continue;
          cnt[i][j][k] = cnt[x][y][k] + 1;
          ans += cnt[i][j][k];
        }
      }
    }
    for (int k = 0; k < 4; ++k) {
      int a = 1, b = 1;
      int x = p+dx[k], y = q+dy[k];
      while (valid(x, y)) {
        ++a;
        x += dx[k];
        y += dy[k];
      }
      x = p-dx[k], y = q-dy[k];
      while (valid(x, y)) {
        ++b;
        x -= dx[k];
        y -= dy[k];
      }
      ans -= a * b-1;
    }
    ans *= 2;
    long long tot = n * m - 1;
    ans = tot * (tot-1) - ans;
    printf("%lld\n", ans);
  }
  return 0;
}