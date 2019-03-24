#include <bits/stdc++.h>

using namespace std;

const int N = 512, inf = 1e9;

int n, m;
char s[N][N];
int d[N][N];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void bfs() {
  memset(d, -1, sizeof d);
  queue<pair<int, int>> que;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (s[i][j]) {
        d[i][j] = 0;
        que.emplace(i, j);
      }
    }
  }
  while (!que.empty()) {
    int x, y;
    tie(x,y) = que.front();
    que.pop();
    for (int i = 0; i < 4; ++i) {
      int xx = x + dx[i], yy = y + dy[i];
      if (min(xx, yy) <= 0 || xx > n || yy > m) continue;
      if (d[xx][yy] != -1) continue;
      d[xx][yy] = d[x][y] + 1;
      que.emplace(xx, yy);
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (d[i][j] == -1)
        d[i][j] = inf;
    }
  }
}

bool can(int x) {
  int plus_max = inf, plus_min = -inf, minus_max = inf, minus_min = -inf;
  bool ok = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (d[i][j] <= x) continue;
      plus_max = min(plus_max, i+j+x);
      plus_min = max(plus_min, i+j-x);
      minus_max = min(minus_max, i-j+x);
      minus_min = max(minus_min, i-j-x);
      ok = 0;
    }
  }
  if (ok)
    return true;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int plus = i + j, minus = i - j;
      if (plus_min <= plus && plus <= plus_max && minus_min <= minus && minus <= minus_max)
        return true;
    }
  }
  return false;
}

void solve(int tc) {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", s[i]+1);
    for (int j = 1; j <= m; ++j)
      s[i][j] -= '0';
  }
  bfs();
  int lo = 0, hi = inf;
  while (lo < hi) {
    int mid = (lo + hi) >> 1;
    if (can(mid))
      hi = mid;
    else
      lo = mid + 1;
  }
  printf("Case #%d: %d\n", tc, hi);
}

int main() {
  time_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    solve(tc);
    cerr << "~ #" << tc << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << " s" << endl;
  }
  return 0;
}
