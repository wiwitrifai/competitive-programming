#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5, M = 55;
const long long inf = 1e18;

long long dp[N][M];

vector<pair<int, int> > g[N];
int n, m;

void dfs(int v, int par = -1) {
  dp[v][0] = 0;
  for (auto it : g[v]) {
    int u = it.first, w = it.second;
    if (u == par) continue;
    dfs(u, v);
    for (int j = m; j >= 0; --j) {
      for (int k = 0; k <= j; ++k) {
        dp[v][j] = min(dp[v][j], dp[u][k] + dp[v][j-k] + (k ? 1LL * w * (k-2) : 0));
      }
    }
  }
}

int main() {
  scanf("%d %d", &n, &m);
  long long sum = 0;
  for (int i = 1; i < n; ++i) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    --u, --v;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
    sum += w;
  }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j <= m; ++j)
      dp[i][j] = 0;
  dfs(0);
  long long ans = sum * 2;
  for (int i = 1; i <= m; ++i)
    ans = min(ans, sum * 2 + dp[0][i]);
  printf("%lld\n", ans);
  return 0;
}