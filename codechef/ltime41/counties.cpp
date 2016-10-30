#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5, inf = 1e7;

vector< int > adj[N];
vector< pair<int, int > > que[N];
int sz[N], die[N], c[N], dv[N], dc[N], ans[N], to[N];
vector< int > node;
void getsz(int v, int p = -1) {
  sz[v] = 1;
  to[v] = -1;
  for (int u : adj[v]) if (u != p && !die[u]) {
    getsz(u, v);
    sz[v] += sz[u];
    if (to[v] == -1 || sz[u] > sz[to[v]])
      to[v] = u;
  }
}
void dfs(int v, int p = -1, int level = 0) {
  node.push_back(v);
  dv[v] = level;
  for (int u : adj[v]) if (u != p && !die[u]) {
    dfs(u, v, level + 1);
  }
}

void solve(int v) {
  node.clear();
  getsz(v);
  int tot = sz[v];
  while (to[v] != -1 && sz[to[v]] > tot/2)
    v = to[v];
  dfs(v);
  for (int u : node) {
    dc[c[u]] = inf;
  }
  for (int u : node) {
    dc[c[u]] = min(dc[c[u]], dv[u]);
  }
  for (int u : node) {
    for (auto e : que[u]) {
      ans[e.first] = min(ans[e.first], dv[u] + dc[e.second]);
    }
  }
  for (int u : node)
    dc[c[u]] = inf;
  die[v] = 1;
  for (int u : adj[v]) if (!die[u])
    solve(u);
}

int main() {
  int n,  m, q;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++)
    scanf("%d", c+i);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    que[a].push_back({i, b});
    ans[i] = inf;
  }
  solve(1);
  for (int i = 0; i < q; i++)
    printf("%d\n", ans[i]);
  return 0;
}