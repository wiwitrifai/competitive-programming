#include <bits/stdc++.h>

using namespace std;

const int N = 52;

int g[N][N];
int from[N], to[N];
int pre[N][N];
int n, m;

inline bool valid(int x, int y) {
  return min(x, y) >= 0 && max(x, y) < n;
}

int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
pair<int, int> que[N * N];

void bfs(int id) {
  memset(pre, -1, sizeof pre);
  int x = from[id] / n, y = from[id] % n;
  pre[x][y] = x * n + y;
  int sz = 0, front = 0;
  que[sz++] = make_pair(x, y);
  while (front < sz) {
    x = que[front].first, y = que[front].second;
    ++front;
    for (int i = 0; i < 4; ++i) {
      int xx = x + dx[i], yy = y + dy[i];
      if (!valid(xx, yy)) continue;
      if (pre[xx][yy] != -1 || g[xx][yy] != -1) continue;
      pre[xx][yy] = x * n + y;
      que[sz++] = make_pair(xx, yy);
    }
  }
}

int used[N];

vector<pair<int, int> > ans;

void advance(int id, int dest) {
  if (from[id] == dest) return;
  int x = from[id] / n, y = from[id] % n;
  g[x][y] = -1;
  assert(pre[x][y] == from[id]);
  int now = dest;
  int sz = ans.size();
  while (now != from[id]) {
    int pp = pre[now / n][now % n];
    ans.emplace_back(pp, now);
    now = pp;
  }
  reverse(ans.begin() + sz, ans.end());
  from[id] = dest;
  x = from[id] / n, y = from[id] % n;
  g[x][y] = id;
}

int pos[N];

int main() {
  scanf("%d %d", &n, &m);
  memset(g, -1, sizeof g);
  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    --x; --y;
    from[i] = x * n + y;
    g[x][y] = i;
  }
  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    --x; --y;
    to[i] = x * n + y;
    ++used[x];
  }
  int row = 0;

  for (int i = 0; i < n; ++i) {
    if (used[row] > used[i]) {
      row = i;
    }
  }
  while (1) {
    bool ok = 1;
    for (int i = 0; i < m; ++i) {
      if (from[i]/n == row) continue;
      bfs(i);
      int dest = -1;
      for (int j = 0; j < n; ++j) {
        if (pre[row][j] != -1) {
          dest = row * n + j;
          break;
        }
      }
      ok = 0;
      if (dest != -1)
        advance(i, dest);
    }
    if (ok) break;
  }
  for (int i = 0; i < m; ++i)
    pos[i] = i;
  sort(pos, pos+m, [&](int x, int y){
    if (to[x] < row *n && to[y] < row * n) {
      return to[x] < to[y];    
    }
    return to[x] > to[y];
  });
  while (1) {
    bool ok = 1;
    for (int i = 0; i < m; ++i) {
      int id = pos[i];
      if (from[id] == to[id]) continue;
      ok = 0;
      bfs(id);
      if (pre[to[id]/n][to[id] %n] == -1) continue;
      advance(id, to[id]);
    }
    if (ok)
      break;
  }
  assert(ans.size() <= 10800);
  printf("%d\n", (int)ans.size());
  for (auto it : ans) {
    printf("%d %d %d %d\n", (it.first / n) + 1, (it.first % n) + 1, (it.second / n) + 1, (it.second % n) + 1);
  }
  return 0;
}