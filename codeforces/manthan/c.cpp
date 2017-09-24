#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, mod = 1e9 + 7;
vector<int> g[N];
int n, m, k, x;
long long dp[N][11][3];

void upd(long long &le, long long ri) {
  le += ri;
  if (le >= mod)
    le -= mod;
}

long long tmp[11][3];

void dfs(int v, int par = -1) {  
  for (int i = 0; i <= x; i++)
    for (int j = 0; j <= 2; j++)
      dp[v][i][j] = 0;
  dp[v][0][0] = m-k;
  dp[v][1][1] = 1;
  dp[v][0][2] = k-1;
  for (int u : g[v]) if (u != par) {
    dfs(u, v);
    memset(tmp, 0, sizeof tmp);
    for (int i = 0; i <= x; i++) {
      for (int j = 0; j <= i; j++) {
        int z = i-j;
        upd(tmp[i][0], (dp[u][j][0] + dp[u][j][2]) * dp[v][z][0] % mod);
        upd(tmp[i][1], dp[u][j][2] * dp[v][z][1] % mod);
        upd(tmp[i][2], (dp[u][j][0] + dp[u][j][1] + dp[u][j][2]) * dp[v][z][2] % mod);
      }
    }
    for (int i = 0; i <= x; i++)
      for (int j = 0; j <= 2; j++)
        dp[v][i][j] = tmp[i][j];
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  scanf("%d %d", &k, &x);
  dfs(0);
  long long ans = 0;
  for (int i = 0; i <= x; i++) {
    ans = (ans + dp[0][i][0] + dp[0][i][1] + dp[0][i][2]) % mod;
  }
  if (ans < 0) ans += mod;
  cout << ans << endl;
  return 0;
}