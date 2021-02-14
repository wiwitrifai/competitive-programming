#include <bits/stdc++.h>

using namespace std;

const int N = 3e3 + 5, M = N * N;

int n, group[M], deg[M], match[M];
bool odd[M], vis[M];
vector<int> g[M];
inline int enc(int r, int c) {
  return r * n + c;
}

bool dfs(int v) {
  if (vis[v])
    return false;
  vis[v] = true;
  for (int u : g[v]) {
    if (group[u]) continue;
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
  }
  for (auto & e : edges) {
    int u = e.first, v = e.second;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
    ++deg[u];
    ++deg[v];
  }
  queue<int> que;
  int tot = n * n;
  for (int i = 0; i < tot; ++i) {
    if (deg[i] >= 2) continue;
    que.push(i);
  }
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    if (group[v] != 0) continue;
    group[v] = 1;
    for (int u : g[v]) {
      if (group[u]) continue;
      --deg[v];
      group[u] = -1;
      --deg[u];
      for (int z : g[u]) {
        if (group[z]) continue;
        --deg[z];
        if (deg[z] <= 1) {
          que.push(z);
        }
      }
    }
    assert(deg[v] == 0);
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      odd[enc(i, j)] = (i+j) & 1;
    }
  }
  int ans = 0;
  for (int i = 0; i < tot; ++i) {
    if (group[i] >= 0)
      ++ans;
  }
  bool ok = true;
  vector<int> rest;
  for (int i = 0; i < tot; ++i) {
    if (odd[i] && group[i] == 0)
      rest.emplace_back(i);
  }
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
