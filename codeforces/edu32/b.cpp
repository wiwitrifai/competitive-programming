#include <bits/stdc++.h>

using namespace std;
const int N = 105;

int d[N][N + N][N + N];

int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
char s[] = "LURD", cmd[N];
int main() {
  int n;
  scanf("%d %s", &n, cmd);
  memset(d, -1, sizeof d);
  d[0][N][N] = 0; 
  queue<tuple<int, int, int> > que;
  que.push(make_tuple(0, N, N));
  while (!que.empty()) {
    int x, y, t;
    tie(t, x, y) = que.front();
    que.pop();
    if (t == n) continue;
    for (int i = 0; i < 4; i++) {
      if (s[i] != cmd[t]) continue;
      if (d[t+1][x + dx[i]][y + dy[i]] >= d[t][x][y] + 1) continue; 
      d[t+1][x + dx[i]][y + dy[i]] = max(d[t+1][x + dx[i]][y + dy[i]], d[t][x][y] + 1);
      que.emplace(t+1, x + dx[i], y + dy[i]);
    }
    if (d[t+1][x][y] <= d[t][x][y]) {
      d[t+1][x][y] = max(d[t+1][x][y], d[t][x][y]);
      que.emplace(t+1, x, y);
    }
  }
  printf("%d\n", d[n][N][N]);
  return 0;
}