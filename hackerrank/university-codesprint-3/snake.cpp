#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int n, ans[N][N], d;

int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
char dir[] = "nswe";
bool isvalid(int x, int y) {
  if (x < 0 || x >= n || y < 0 ||  y >= n) return false;
  return !ans[x][y];
}

int main() {
  char dc;
  int x, y;
  scanf("%d %c %d %d", &n, &dc, &x, &y);
  d = 0;
  while (d < 4 && dir[d] != dc) d++;
  int now = 1;
  while (now <= n * n) {
    assert(isvalid(x, y));
    ans[x][y] = now++;
    int xx = x + dx[d], yy = y + dy[d];
    bool ok = 0;
    if (isvalid(xx, yy)) {
      x = xx, y = yy;
      ok = 1;
    }
    if (ok) continue;
    for (int j = 0; j < 4; j++) {
      if (j == d || j == (d^1)) continue;
      xx = x + dx[j], yy = y + dy[j];
      if (isvalid(xx, yy)) {
        x = xx, y = yy;
        ok = 1;
        break;
      }
    }
    if (ok) continue;
    x += dx[d^1];
    y += dy[d^1];
    ok |= isvalid(x, y);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d%c", ans[i][j], j == n-1 ? '\n' : ' ');
    }
  }
  return 0;
}