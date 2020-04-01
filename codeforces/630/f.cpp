#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353, N = 3e5 + 5;

vector<int> g[N];

long long dp[N][3], tmp[3];

void dfs(int v, int par = -1) {
  dp[v][0] = 1;
  dp[v][1] = 1;
  dp[v][2] = 0;
  for (int u : g[v]) {
    if (u == par) continue;
    dfs(u, v);
    tmp[0] = (dp[v][0] * ((dp[u][0] * 2 + dp[u][1] + dp[u][2] * 2) % mod)) % mod;
    tmp[1] = (dp[v][1] * (dp[u][0] + dp[u][2]))  % mod;
    tmp[2] = (dp[v][1] * dp[u][0] + dp[v][2] * (dp[u][0] * 2 + dp[u][2])) % mod;
    for (int i = 0; i < 3; ++i)
      dp[v][i] = tmp[i];
  }
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
  dfs(0);
  long long ans = (dp[0][0] + dp[0][2] - 1) % mod;
  if (ans < 0)
    ans += mod;
  printf("%lld\n", ans);
  return 0;
}
