#include <bits/stdc++.h>

using namespace std;

const int N = 505, Q = 1e5 + 5;

int p[N * N], dist[N * N];

int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}

bool merge(int u, int v) {
  u = find(u);
  v = find(v);
  if (u == v) return false;
  if (-p[u] > -p[v])
    swap(u, v);
  dist[v] = min(dist[v], dist[u]);
  p[v] += p[u];
  p[u] = v;
  return true;
}


int a[N][N], x[Q], y[Q], b[Q];

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int main() {
  memset(p, -1, sizeof p);
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  vector<pair<int, int>> grid;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", a[i]+j);
      int now = i * m + j;
      dist[now] = i + j;
      grid.emplace_back(a[i][j], now);
    }
  }
  vector<pair<int, int>> que;
  for (int i = 0; i < q; ++i) {
    scanf("%d %d %d", x+i, y+i, b+i);
    --x[i], --y[i];
    que.emplace_back(b[i], i);
  }
  sort(que.begin(), que.end());
  sort(grid.begin(), grid.end());
  int igrid = 0;
  vector<int> ans(q, -1);
  for (auto it : que) {
    int val = it.first, id = it.second;
    while (igrid < (int)grid.size() && grid[igrid].first <= val) {
      int now = grid[igrid].second;
      int r = now / m, c = now % m;
      for (int i = 0; i < 4; ++i) {
        int nr = r + dx[i], nc = c + dy[i];
        if (min(nr, nc) < 0 || nr >= n || nc >= m) continue;
        if (a[nr][nc] > val) continue;
        int nxt = nr * m + nc;
        merge(now, nxt);
      }
      ++igrid;
    }
    ans[id] = dist[find(x[id] * m + y[id])];
  }
  for (int val : ans)
    printf("%d\n", val);
  return 0;
}
