#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, mod = 1e9 + 7;

int x[N], y[N], f[N];
int dp[N][4];

void add(int & var, int val) {
  var += val;
  if (var >= mod)
    var -= mod;
}

void dfs(int v) {
  if (v == 0) return;
  dfs(x[v]);
  dfs(y[v]);
  int a = x[v], b = y[v];
  if (f[v] == -1) {
    for (int i = 0; i < 4; ++i)
      for (int j = 0; j < 4; ++j) {
        add(dp[v][3^(i&j)], 1LL * dp[a][i] * dp[b][j] % mod);
      }
  }
  else if (f[v] == 0) {
    for (int i = 0; i < 4; ++i)
      for (int j = 0; j < 4; ++j) {
        add(dp[v][(3^(i&j))&2], 1LL * dp[a][i] * dp[b][j] % mod);
      }
  }
  else {
    for (int i = 0; i < 4; ++i)
      for (int j = 0; j < 4; ++j) {
        add(dp[v][(3^(i&j))|1], 1LL * dp[a][i] * dp[b][j] % mod);
      }
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d %d", x+i, y+i, f+i);
  }
  dp[0][0] = 1;
  dp[0][3] = 1;
  dfs(1);
  int ans = (dp[1][1] + dp[1][2]) % mod;
  if (ans < 0) ans += mod;
  printf("%d\n", ans);
  return 0;
}