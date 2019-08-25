#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector<int> g[N];
int d[N], up[N];
bool mark[N];

void dfs(int v, int par = -1) {
  if (mark[v])
    d[v] = up[v] = 0;
  for (int u : g[v]) {
    if (u == par) continue;
    dfs(u, v);
    if (d[u] >= 0)
      d[v] = max(d[v], d[u]+1);
  }
}

void dfs2(int v, int par = -1) {
  int cur = up[v];
  for (int u : g[v]) {
    if (u == par) continue;
    if (cur >= 0)
      up[u] = max(up[u], cur + 1);
    if (d[u] >= 0)
      cur = max(cur, d[u]+1);
  }
  reverse(g[v].begin(), g[v].end());
  cur = up[v];
  for (int u : g[v]) {
    if (u == par) continue;
    if (cur >= 0)
      up[u] = max(up[u], cur + 1);
    if (d[u] >= 0)
      cur = max(cur, d[u]+1);
  }
  for (int u : g[v]) {
    if (u == par) continue;
    dfs2(u, v);
  }
}

void solve() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    g[i].clear();
    d[i] = up[i] = -1;
  }
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  fill(mark, mark+n, 0);
  for (int i = 0; i < m; ++i) {
    int v;
    scanf("%d", &v);
    --v;
    mark[v] = 1;
  }
  dfs(0);
  dfs2(0);
  int ans = 0;

  for (int i = 0; i < n; ++i) {
    d[i] = max(d[i], up[i]);
    if (d[ans] > d[i])
      ans = i;
  }
  printf("%d %d\n", ans+1, d[ans]);
}

int main() {
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; ++tc) {
    printf("Case #%d: ", tc);
    solve();
  }
  return 0;
}
