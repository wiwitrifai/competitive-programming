
#include <bits/stdc++.h>

using namespace std;

const int N = 212;

int d[N][N];

int dx[] = {-1, 1, 2, 1,-1,-2};
int dy[] = {-2,-2, 0, 2, 2, 0};
char arah[][5] = {"UL", "UR", "R", "LR", "LL", "L"};

int main() {
  memset(d, -1, sizeof d);
  int n;
  int sx, sy, ex, ey;
  scanf("%d %d %d %d %d", &n, &sy, &sx, &ey, &ex);
  queue<pair<int, int> > q;
  d[ey][ex] = 0;
  q.push(make_pair(ey, ex));
  while (!q.empty()) {
    int y = q.front().first, x = q.front().second;
    q.pop();
    for (int i = 0; i < 6; ++i) {
      int yy = y + dy[i], xx = x + dx[i];
      if (xx < 0 || xx >= n || yy < 0 || yy >= n) continue;
      if (d[yy][xx] != -1) continue;
      d[yy][xx] = d[y][x] + 1;
      q.push(make_pair(yy, xx));
    }
  }
  if (d[sy][sx] == -1) {
    puts("Impossible");
  }
  else {
    int cur = d[sy][sx];
    printf("%d\n", cur);
    while (cur--) {
      for (int i = 0; i < 6; ++i) {
        int xx = sx + dx[i], yy = sy + dy[i];
        if (xx < 0 || xx >= n || yy < 0 || yy >= n) continue;
        if (d[yy][xx] != cur) continue;
        printf("%s%c", arah[i], " \n"[cur == 0]);
        sx = xx;
        sy = yy;
        break;
      }
    }
  }
  return 0;
}