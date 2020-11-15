#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

vector<pair<int, int>> g[N];

long long dp[N][2], up[N][2];

void dfs(int v, int par = -1) {
  dp[v][0] = 0;
  dp[v][1] = 0;
  for (auto & e : g[v]) {
    int u = e.first;
    if (u == par) continue;
    dfs(u, v);
    dp[v][1] = max(dp[v][1], dp[u][1]);
    dp[v][1] = max(dp[v][1], dp[v][0] + dp[u][0] + e.second);
    dp[v][0] = max(dp[v][0], dp[u][0] + e.second);
  }
}

long long ans;

void dfs2(int v, int par = -1, int w = 0) {
  if (par != -1) {
    ans = min(ans, abs(up[v][1] - dp[v][1]));
  }
  long long single = up[v][0] + w, duo = max(up[v][1], single);
  for (auto & e : g[v]) {
    int u = e.first;
    if (u == par) continue;
    up[u][0] = single;
    up[u][1] = duo;
    duo = max(duo, dp[u][1]);
    duo = max(duo, dp[u][0] + e.second + single);
    single = max(single, dp[u][0] + e.second);
  }
  reverse(g[v].begin(), g[v].end());
  // single = up[v][0] + w;
  // duo = max(up[v][1], single);
  single = duo = 0;
  for (auto & e : g[v]) {
    int u = e.first;
    if (u == par) continue;
    up[u][1] = max(up[u][1], duo);
    up[u][1] = max(up[u][1], up[u][0] + single);
    up[u][0] = max(single, up[u][0]);

    duo = max(duo, dp[u][1]);
    duo = max(duo, dp[u][0] + single + e.second);
    single = max(single, dp[u][0] + e.second);
  }
  for (auto & e : g[v]) {
    int u = e.first;
    if (u == par) continue;
    dfs2(u, v, e.second);
  }
}

void solve() {
  int n;
  scanf("%d", &n);
  if (n == 0) {
    exit(0);
  }
  for (int i = 0; i < n; ++i)
    g[i].clear();
  for (int i = 1; i < n; ++i) {
    int u, w;
    scanf("%d %d", &u, &w);
    --u;
    g[u].emplace_back(i, w);
    g[i].emplace_back(u, w);
  }
  ans = 1e18;
  dfs(0);
  dfs2(0);
  printf("%lld\n", ans);
}

int main() {
  while (true) {
    solve();
  }
  return 0;
}
