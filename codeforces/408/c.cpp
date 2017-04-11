#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 6, inf = 1e9 + 7;

vector< int > g[N];
int a[N], s[N], up[N];
int ans;

void pre(int v = 0, int par = -1) {
  s[v] = -inf;
  for (int u : g[v]) if (u != par) {
    pre(u, v);
    s[v] = max(s[v], s[u]);
    s[v] = max(s[v], a[u]);
  }
}

int dfs(int v = 0, int par = -1, int ma = -inf) {
  int now = max(ma+2, a[v]);
  if (par != -1) {
    now = max(now, a[par]+1);
    ma = max(ma, a[par]);
  }
  for (int u : g[v]) if (u != par) {
    up[u] = ma;
    ma = max(ma, max(a[u], s[u]));
    now = max(now, a[u]+1);
    now = max(now, s[u]+2);
  }
  ans = min(ans, now);
  ma = -inf;
  for (int i = (int)g[v].size()-1; i >= 0; i--) {
    int u = g[v][i];
    if (u == par) continue;
    up[u] = max(ma, up[u]);
    ma = max(ma, max(a[u], s[u]));
    dfs(u, v, up[u]);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  ans = -inf;
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
    ans = max(ans, a[i] + 2);
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  pre();
  dfs();
  printf("%d\n", ans);
  return 0;
}