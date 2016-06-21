#include <bits/stdc++.h>

using namespace std;
const int N = 55;
const int mod = 1e9 + 7;
long long dp[N][N];
vector< int > adj[N];
int n, k;

void dfs(int v, int p = -1) {
  long long cur[N];
  dp[v][1] = 1;
  for(int u : adj[v]) if(u != p) {
    dfs(u, v);
    for(int i = k; i>= 0; i--) {
      long long cur = 0;
      for(int j = 0; j<=i; j++) {
        cur = (cur + dp[u][j] * dp[v][i-j]) % mod;
        cur = (cur + dp[u][j+1] * dp[v][i-j]) % mod;
      }
      dp[v][i] = cur;
    }
  }
}
int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%d%d", &n, &k);
    for(int i = 0; i<n; i++)
      adj[i].clear();
    for(int i = 1; i<n; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      u--; v--;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    memset(dp, 0, sizeof dp);
    dfs(0);
    long long ans = 0;
    long long mul = k;
    for(int i = 1; i<=k; i++) {
      ans = (ans + dp[0][i] * mul) % mod;
      mul = (mul * (k-i)) % mod;
    }
    if(ans < 0)
      ans += mod;
    printf("%lld\n", ans);
  }
  return 0;
}