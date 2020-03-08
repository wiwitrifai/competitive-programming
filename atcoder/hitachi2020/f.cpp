#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, mod = 998244353;

vector<int> g[N];
int par[N], lv[N];
long long dp[N][3], tmp[3];

void add(long long & var, long long val) {
  var += val;
  if (var >= mod)
    var -= mod;
}

void dfs(int v, int p) {
  par[v] = p;
  for (int u : g[v]) {
    if (u == p) continue;
    lv[u] = lv[v] + 1;
    dfs(u, v);
  }
}

void solve(int v, int p, int depth) {
  memset(dp[v], 0, sizeof dp[v]);
  dp[v][(depth == 0)] = 1;
  --depth;
  for (int u : g[v]) {
    if (u == p) continue;
    solve(u, v, depth);
    memset(tmp, 0, sizeof tmp);
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        add(tmp[min(i+j, 2)], dp[v][i] * dp[u][j] % mod);
        add(tmp[i], 2LL * dp[v][i] * dp[u][j] % mod);
      }
    }
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
  lv[0] = 0;
  dfs(0, 0);
  int root = 0;
  for (int i = 0; i < n; ++i) {
    if (lv[i] > lv[root])
      root = i;
  }
  lv[root] = 0;
  dfs(root, -1);
  int leaf = 0;
  for (int i = 0; i < n; ++i) {
    if (lv[i] > lv[leaf])
      leaf = i;
  }
  int diam = lv[leaf];
  long long ans = 0;
  if (diam & 1) {
    int a = leaf;
    for (int i = 0; i < diam/2; ++i) {
      a = par[a];
    }
    int b = par[a];
    solve(a, b, diam/2);
    solve(b, a, diam/2);
    ans = 1LL * dp[a][1] * dp[b][1] % mod;
  }
  else {
    int c = leaf;
    for (int i = 0; i < diam/2; ++i) {
      c = par[c];
    }
    long long best[3];
    memset(best, 0, sizeof best);
    best[0] = 1;
    for (int u : g[c]) {
      solve(u, c, diam/2-1);
      memset(tmp, 0, sizeof tmp);
      if (diam == 2)
        dp[u][0] = dp[u][1];
      else {
        dp[u][0] = (dp[u][0] - dp[u][1] - dp[u][2]) % mod;
        dp[u][0] = (3LL * dp[u][0] + 4LL * dp[u][1] + 4LL * dp[u][2]) % mod;
      }
      tmp[0] = (best[0] * dp[u][0]) % mod;
      tmp[1] = (best[0] * dp[u][1] + best[1] * dp[u][0]) % mod;
      tmp[2] = (best[1] * dp[u][1] + best[2] * dp[u][0]) % mod;
      for (int i = 0; i < 3; ++i)
        best[i] = tmp[i];
    }
    ans = best[2];
  }
  ans %= mod;
  if (ans < 0)
    ans += mod;
  printf("%lld\n", ans);
  return 0;
}
