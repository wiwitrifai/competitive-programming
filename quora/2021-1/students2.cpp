#include <bits/stdc++.h>

using namespace std;

const int N = 3e3 + 5, M = N * N;
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, -1, 0, 1};

int n;
int match[M];
bool vis[M];

int g[M];

inline int enc(int r, int c) {
  return r * n + c;
}

bool dfs(int v) {
  if (vis[v])
    return false;
  vis[v] = true;
  int r = v / n, c = v - r * n;
  for (int i = 0; i < 4; ++i) {
    int rr = r + dr[i], cc = c + dc[i];
    if (rr < 0 || rr >= n || cc < 0 || cc >= n || (g[v] & (1 << i)) == 0) continue;
    int u = enc(rr, cc);
    if (match[u] == -1 || dfs(match[u])) {
      match[u] = v;
      match[v] = u;
      return true;
    }
  }
  return false;
}

int main() {
  int m;
  scanf("%d %d", &n, &m);
  set<pair<int, int>> edges;
  for (int i = 0; i < m; ++i) {
    int ra, ca, rb, cb;
    scanf("%d %d %d %d", &ra, &ca, &rb, &cb);
    --ra, --ca, --rb, --cb;
    int u = enc(ra, ca);
    int v = enc(rb, cb);
    if (u > v)
      swap(u, v);
    edges.insert(make_pair(u, v));
    edges.insert(make_pair(v, u));
  }
  vector<int> rest;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (((i + j) & 1) == 0) continue;
      int v = enc(i, j);
      rest.push_back(v);
    }
  }
  int tot = n * n;
  for (int v = 0; v < tot; ++v) {
    int r = v / n, c = v - r * n;
    for (int i = 0; i < 4; ++i) {
      int rr = r + dr[i], cc = c + dc[i];
      if (rr < 0 || rr >= n || cc < 0 || cc >= n) continue;
      int u = enc(rr, cc);
      if (edges.count(make_pair(v, u)))
        g[v] |= 1 << i;
    }
  }
  int ans = tot;
  bool ok = true;
  memset(match, -1, sizeof match);
  while (ok) {
    memset(vis, false, sizeof vis);
    ok = false;
    for (int v : rest) {
      if (match[v] != -1) continue;
      if (dfs(v)) {
        ok = true;
        --ans;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
