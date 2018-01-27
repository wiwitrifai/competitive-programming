#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, mod = 1e9 + 7;

vector<int> g[N];
bool mark[N];
long long dp[N][2];

void dfs(int v, int par = -1) {
  dp[v][0] = dp[v][1] = 0;
  dp[v][mark[v]] = 1;
  for (int u : g[v]) if (u != par) {
    dfs(u, v);
    dp[v][1] = ((1LL * dp[v][1] * (dp[u][0] + 1) % mod) + (1LL * dp[u][1] * (dp[v][0] + dp[v][1]) % mod)) % mod;
    dp[v][0] = 1LL * dp[v][0] * (dp[u][0] + 1) % mod;
  }
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 0; i < k; ++i) {
    int v;
    scanf("%d", &v);
    --v;
    mark[v] = 1;
  }
  dfs(0);
  long long ans = 0;
  for (int i = 0; i < n; ++i)
    ans = (ans + dp[i][1]) % mod;
  if (ans < 0) ans += mod;
  cout << ans << endl;
  return 0;
}