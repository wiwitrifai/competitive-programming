#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, mod = 1e9 + 21;

vector<int> g[N], dag[N], elem[N];
int num[N], low[N], cntr = 0, comp[N], ncomp;
int vis[N], b[N], din[N];
long long dp[N][201];

vector<int> S;

void dfs(int v) {
  num[v] = low[v] = ++cntr;
  vis[v] = 1;
  S.push_back(v);
  for (int u : g[v]) {
    if (num[u] == -1)
      dfs(u);
    if (vis[u])
      low[v] = min(low[v], low[u]);
  }
  if (low[v] == num[v]) {
    while (1) {
      int u = S.back(); S.pop_back();
      comp[u] = ncomp;
      vis[u] = 0;
      if (u == v)
        break;
    }
    ++ncomp;
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; ++i) {
      g[i].clear();
      scanf("%d", b+i);
    }
    for (int i = 0; i < m; ++i) {
      int u, v;
      scanf("%d %d", &u, &v);
      --u, --v;
      g[u].push_back(v);
    }
    fill(num, num+n, -1);
    fill(low, low+n, -1);
    fill(vis, vis+n, 0);
    cntr = 0;
    ncomp = 0;
    S.clear();
    for (int i = 0; i < n; ++i)
      if (num[i] == -1)
        dfs(i);
    for (int i = 0; i < ncomp; ++i) {
      dag[i].clear();
      elem[i].clear();
    }
    for (int i = 0; i < n; ++i) {
      elem[comp[i]].push_back(b[i]);
      for (int u : g[i])
        if (comp[i] != comp[u])
          dag[comp[i]].push_back(comp[u]);
    }
    for (int i = 0; i < ncomp; ++i) {
      sort(elem[i].begin(), elem[i].end());
      sort(dag[i].begin(), dag[i].end());
      dag[i].erase(unique(dag[i].begin(), dag[i].end()), dag[i].end());
    }
    stack<int> stak;
    fill(din, din+ncomp, 0);
    for (int i = 0; i < ncomp; ++i)
      for (int u : dag[i])
        ++din[u];
    for (int i = 0; i < ncomp; ++i) {
      if (din[i] == 0)
        stak.push(i);
    }
    vector<int> topo;
    while (!stak.empty()) {
      int v = stak.top(); stak.pop();
      topo.push_back(v);
      for (int u : dag[v]) {
        --din[u];
        if (din[u] == 0)
          stak.push(u);
      }
    }
    assert((int)topo.size() == ncomp);
    for (int i = 0; i < ncomp; ++i)
      for (int j = 0; j <= k; ++j)
        dp[i][j] = 0;
    for (int v : topo) {
      int sz = elem[v].size();
      int til = min(k, sz-1);
      for (int i = k; i >= 0; --i) {
        long long res = dp[v][i];
        for (int j = min(til, i); j >= 0; --j) {
          res = max(res, dp[v][i-j] + 1LL * (sz - j) * elem[v][j]);
        }
        dp[v][i] = res;
      }
      for (int u : dag[v])
        for (int i = 0; i <= k; ++i)
          dp[u][i] = max(dp[u][i], dp[v][i]);
    }
    long long ans = 0;
    for (int i = 0; i < ncomp; ++i)
      for (int j = 0; j <= k; ++j)
        ans = max(dp[i][j], ans);
    printf("%lld\n", ans % mod);
  }
  return 0;
}