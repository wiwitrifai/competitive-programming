#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, mod = 1e9 + 7;

int a[N];
long long dp[N][2];
vector<int> g[N];
int n, x;

void dfs(int v, int par = -1) {
  for (int u : g[v]) {
    if (u == par) continue;
    dfs(u, v);
    a[v] ^= a[u];
  }
}

void dfs2(int v, int par = -1) {
  dp[v][0] = 1;
  dp[v][1] = 0;
  for (int u : g[v]) {
    if (u == par) continue;
    dfs2(u, v);
    long long tmp0 = (dp[v][0] * dp[u][0] + dp[v][1] * dp[u][1]) % mod;
    long long tmp1 = (dp[v][0] * dp[u][1] + dp[v][1] * dp[u][0]) % mod;
    dp[v][0] = tmp0;
    dp[v][1] = tmp1;
  }
  if (a[v] == 0)
    dp[v][0] = (dp[v][0] + dp[v][1]) % mod;
  else if (a[v] == x)
    dp[v][1] = (dp[v][0] + dp[v][1]) % mod;
}

int main() {
  int t = 1;
  while (t--) {
    scanf("%d %d", &n, &x);
    for (int i = 0; i < n; ++i) {
      scanf("%d", a+i);
      g[i].clear();
    }
    for (int i = 0; i < n-1; ++i) {
      int u, v;
      scanf("%d %d", &u, &v);
      --u, --v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    dfs(0);
    long long ans = 1;
    if (x == 0) {
      if (a[0] != 0)
        ans = 0;
      else {
        for (int i = 1; i < n; ++i) {
          if (a[i] != 0) continue;
          ans += ans;
          if (ans >= mod)
            ans -= mod;
        }
      }
    }
    else {
      dfs2(0);
      if (a[0] == 0)
        ans = dp[0][1];
      else if (a[0] == x)
        ans = dp[0][0];
    }
    ans %= mod;
    if (ans < 0) ans += mod;
    printf("%lld\n", ans);
  }
  return 0;
}