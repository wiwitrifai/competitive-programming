#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector< int > g[N], tree[N];
int a[N], n, m, num[N], low[N], ncur, ncom = 0, com[N];
long long tot[N];

vector<int> ve;
void dfs(int v, int par = -1) {
  num[v] = low[v] = ncur++;
  ve.push_back(v);
  for (int u : g[v]) {
    if (u == par) continue;
    if (num[u] == -1) {
      dfs(u, v);
      low[v] = min(low[v], low[u]);
    }
    else
      low[v] = min(low[v], low[u]);
  }
  if (low[v] == num[v]) {
    tot[ncom] = 0;
    // cerr << " com " << ncom << " : ";
    while (1) {
      int u = ve.back(); ve.pop_back();
      // cerr << u << " ";
      com[u] = ncom;
      tot[ncom] += a[u];
      if (u == v) break;
    }
    // cerr << tot[ncom] << endl;
    ncom++;
  }
}

long long ans = 0, dp[N];
bool vis[N];

void dfs2(int v, int par = -1) {
  vis[v] = 1;
  dp[v] = 0;
  for (int u : tree[v]) if (u != par) {
    dfs2(u, v);
    ans = max(ans, dp[v] + dp[u] + tot[v]);
    dp[v] = max(dp[v], dp[u]);
  }
  dp[v] += tot[v];
  ans = max(dp[v], ans);
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  memset(num, -1, sizeof num);
  ncur = 0;
  ncom = 0;
  for (int i = 0; i < n; i++) if ( num[i] == -1) {
    dfs(i);
  }
  for (int v = 0; v < n; v++) {
    for (int u : g[v]) if (com[u] != com[v]) {
      tree[com[v]].push_back(com[u]);
    }
  }
  memset(vis, 0, sizeof vis);
  ans = 0;
  for (int i = 0; i < ncom; i++) if (!vis[i]) {
    dfs2(i);
  }
  printf("%lld\n", ans);

  return 0;
}