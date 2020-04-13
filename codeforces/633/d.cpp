#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> g[N];

int dp[N][2];

int dfs(int v, int par = -1) {
  int child = (int)g[v].size() - (par != -1);
  dp[v][0] = 0;
  dp[v][1] = 1;
  int ret = max(dp[v][1], dp[v][0]);
  for (int u : g[v]) {
    if (u == par) continue;
    ret = max(ret, dfs(u, v));
    ret = max(ret, dp[v][1] + dp[u][0]);
    ret = max(ret, dp[v][0] + max(dp[u][0], dp[u][1]) + (g[v].size() >= 2 ? (int)g[v].size()-2 : 0));
    dp[v][0] = max(dp[v][0], max(dp[u][0], dp[u][1]));
    dp[v][1] = max(dp[v][1], dp[u][0]+1);
  }
  if (child > 0)
    dp[v][0] += child-1;
  dp[v][0] = max(dp[v][0], child);
  ret = max(ret, max(dp[v][0], dp[v][1]));
  return ret;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int ans = dfs(0);
  printf("%d\n", ans);
  return 0;
}
