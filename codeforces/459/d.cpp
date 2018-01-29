#include <bits/stdc++.h>

using namespace std;

const int N = 102, mod = 1e9 + 7;

long long dp[N][N][N], tmp[N][N];
long long calc[N], C[N][N];
int sz[N];
vector<int> g[N];

void dfs(int v, int par = -1) {
  dp[v][1][1] = 1;
  sz[v] = 1;
  for (int u : g[v]) if (u != par) {
    dfs(u, v);
    for (int i = 0; i <= sz[u] + sz[v]; ++i)
      for (int j = 0; j <= sz[u] + sz[v]; ++j)
        tmp[i][j] = 0;
    for (int j = 1; j <= sz[u]; ++j) {
      for (int i = 1; i <= sz[v]; ++i) {
        for (int k = 1; k <= sz[u]; ++k) {
          for (int l = 1; l <= sz[v]; ++l) {
            tmp[i+j-1][l+k] = (tmp[i+j-1][l+k] + dp[v][i][l] * dp[u][j][k]) % mod;
            tmp[i+j][l] = (tmp[i+j][l] + dp[v][i][l] * (dp[u][j][k] * 1LL * k % mod)) % mod;
          }
        }
      }
    }
    sz[v] += sz[u];
    for (int i = 0; i <= sz[v]; ++i)
      for (int j = 0; j <= sz[v]; ++j)
        dp[v][i][j] = tmp[i][j];
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
  for (int i = 0; i < N; ++i) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; ++j)
      C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
  }
  long long mul = 1;
  calc[1] = 1;
  for (int i = 2; i <= n; ++i) {
    if (i > 2)
      mul = (mul * n) % mod;
    long long now = 0;
    for (int j = 0; j <= sz[0]; ++j) {
      now = (now + 1LL * dp[0][i][j] * j) % mod;
    }
    calc[i] = now * mul % mod;
    for (int j = 1; j < i; ++j) {
      calc[i] = (calc[i] - calc[j] * C[n-j][i-j]) % mod;
    }
    calc[i] %= mod;
    if (calc[i] < 0) calc[i] += mod;
  }
  for (int i = 1; i <= n; ++i)
    printf("%d%c", (int)calc[n+1-i], i == n ? '\n' : ' ');
  return 0;
}