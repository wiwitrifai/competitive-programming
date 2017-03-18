#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int n, k;
long long dp[N][8], cnt[N][8];
vector< int > g[N];
long long ans;
void dfs(int v = 0, int par = -1) {
  dp[v][0] = 0;
  cnt[v][0] = 1;
  for (int u : g[v]) if (u != par) {
    dfs(u, v);
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < k; j++) {
        long long add = (i + j + k) / k;
        ans += add * cnt[v][i] * cnt[u][j];
        ans += cnt[v][i] * dp[u][j] + dp[v][i] * cnt[u][j];
      }
    }
    for (int i = 0; i + 1 < k; i++) {
      dp[v][(i+1) % k] += dp[u][i];
      cnt[v][(i+1) % k] += cnt[u][i];
    }
    dp[v][0] += dp[u][k-1] + cnt[u][k-1];
    cnt[v][0] += cnt[u][k-1];
  }
}

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  } 
  ans = 0;
  memset(dp, 0, sizeof dp);
  dfs();
  cout << ans << endl;
  return 0;
}