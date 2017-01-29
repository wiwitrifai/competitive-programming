#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, mod = 1e9 + 7;

vector< int > adj[N];
long long dp[N][2];

void dfs(int u = 0, int par = -1) {
  dp[u][0] = 1;
  dp[u][1] = 0;
  for (int v : adj[u]) if (v != par) {
    dfs(v, u);
    dp[u][1] = ((dp[u][0]+dp[u][1]) * (dp[v][0] + dp[v][1]) + dp[u][1] * dp[v][1]) % mod;
    dp[u][0] = (dp[u][0] * dp[v][1]) % mod;
  }
} 

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  } 
  dfs();
  printf("%lld\n", (2 * dp[0][1]) % mod);


  return 0;
}