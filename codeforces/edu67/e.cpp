#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 +5 ;

vector<int> g[N];
int sz[N];
long long dp[N];
int n;
void get_sz(int v, int par = -1) {
  sz[v] = 1;
  dp[v] = 0;
  for (int u : g[v]) {
    if (u == par) continue;
    get_sz(u, v);
    sz[v] += sz[u];
    dp[v] += dp[u];
  }
  dp[v] += sz[v];
}

void dfs(int v, int par = -1) {
  for (int u : g[v]) {
    if (u == par) continue;
    dp[u] = dp[v] - 2LL * sz[u] + n;
    dfs(u, v);
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  get_sz(0);
  dfs(0);
  long long ans = 0;
  for (int i = 0; i < n; ++i)
    ans = max(ans, dp[i]);
  printf("%lld\n", ans);
  return 0;
}
