#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

char buffer[N];

vector<pair<int, int>> g[N];

void solve() {
  int r, c;
  scanf("%d %d", &r, &c);
  if (r == 0 || c == 0)
    exit(0);
  vector<string> grid(r);
  for (int i = 0; i < r; ++i) {
    scanf("%s", buffer);
    grid[i] = buffer;
    reverse(grid[i].begin(), grid[i].end());
  }
  auto enc = [&](int x, int y) { return x * c + y; };
  int s = r * c + 1, t = s + 1;
  for (int i = 0; i <= t; ++i)
    g[i].clear();
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (grid[i][j] == '@') continue;
      int now = enc(i, j);
      if (i == 0 || j == 0) {
        g[s].emplace_back(now, grid[i][j] == '.');
      }
      if (i+1 == r || j+1 == c) {
        g[now].emplace_back(t, 0);
      }
      if (i + 1 < r && grid[i+1][j] != '@') {
        int nxt = enc(i+1, j);
        g[now].emplace_back(nxt, grid[i+1][j] == '.');
        g[nxt].emplace_back(now, grid[i][j] == '.');
      }
      if (j + 1 < c && grid[i][j+1] != '@') {
        int nxt = enc(i, j+1);
        g[now].emplace_back(nxt, grid[i][j+1] == '.');
        g[nxt].emplace_back(now, grid[i][j] == '.');
      }
      if (i + 1 < r && j + 1 < c && grid[i+1][j+1] != '@') {
        int nxt = enc(i+1, j+1);
        g[now].emplace_back(nxt, grid[i+1][j+1] == '.');
        g[nxt].emplace_back(now, grid[i][j] == '.');
      }
      if (i - 1 >= 0 && j + 1 < c && grid[i-1][j+1] != '@') {
        int nxt = enc(i-1, j+1);
        g[now].emplace_back(nxt, grid[i-1][j+1] == '.');
        g[nxt].emplace_back(now, grid[i][j] == '.');
      }
    }
  }
  const int inf = 1e9 + 7;
  vector<int> dist(t+1, inf);
  dist[s] = 0;
  priority_queue<pair<int, int>> pq;
  pq.emplace(0, s);
  while (!pq.empty()) {
    int w, v;
    tie(w, v) = pq.top();
    pq.pop();
    w = -w;
    if (dist[v] != w) continue;
    for (auto & e : g[v]) {
      int u = e.first;
      if (dist[u] <= w + e.second) continue;
      dist[u] = w + e.second;
      pq.emplace(-dist[u], u);
    }
  }
  int ans = dist[t];
  if (ans >= inf)
    ans = -1;
  printf("%d\n", ans);
}

int main() {
  while (true) {
    solve();
  }
  return 0;
}
