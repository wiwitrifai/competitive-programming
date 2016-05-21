#include <bits/stdc++.h>

using namespace std;

const int N = 105, M = 1e4 + 5;
const int mod = 1e9 + 7;

vector<int> adj[N];
long long dp[N][M];
int n, m, k;
void dfs(int v, int p = -1) {
  for(int i = 1; i<=m; i++)
    dp[v][i] = 1;
  for(int u : adj[v]) if(u != p) {
    dfs(u, v);
    long long sum = 0;
    for(int i = k+1; i<= m; i++) {
      sum += dp[u][i];
      sum %= mod;
    }
    for(int i = 1; i<=m; i++) {
      dp[v][i] = (dp[v][i] * sum) % mod;
      sum -= dp[u][i+k];
      if(i-k+1 >= 1)
        sum += dp[u][i-k+1];
      sum %= mod;
      if(sum < 0)
        sum += mod;
    }
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i<=n; i++)
      adj[i].clear();
    for(int i = 1; i<n; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      u--; v--;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    dfs(0);
    long long ans = 0;
    for(int i = 1; i<=m; i++) {
      ans += dp[0][i];
      ans %= mod;
      if(ans < 0)
        ans += mod;
    }
    printf("%lld\n", ans);
  }
  return 0;
}