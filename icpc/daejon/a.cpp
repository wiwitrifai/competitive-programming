#include <bits/stdc++.h>

using namespace std;

const int N = 5050, inf = 1e9;

int dp[N][N], sz[N];
vector<int> g[N];
int n;
int tmp[N];
vector<pair<int, int> > child[N];

void getSz(int v, int par = -1) {
  sz[v] = 1;
  for (int u : g[v]) if (u != par) {
    getSz(u, v);
    sz[v] += sz[u];
    child[v].emplace_back(sz[u], u);
  }
  sort(child[v].begin(), child[v].end());
  g[v].clear();
  for (auto it : child[v])
    g[v].push_back(it.second);
}

void solve(int v, int par = -1) {
  sz[v] = 1;
  dp[v][0] = -1;
  dp[v][1] = 2;
  for (int i = 2; i <= n; ++i)
    dp[v][i] = -inf;
  for (int u : g[v]) if (u != par) {
    solve(u, v);
    for (int i = 0; i <= sz[u] + sz[v]; ++i)
      tmp[i] = -inf;
    int til = max(sz[v], sz[u] + 1);
    for (int i = 0; i <= sz[v]; ++i) {
      for (int j = 0; j <= sz[u] && i+j <= til; ++j) {
        int mi = min(dp[v][i], dp[u][j]-1), ma = max(dp[v][i], dp[u][j]-1);
        int now = mi;
        if (ma >= abs(mi))
          now = ma;
        tmp[i+j] = max(tmp[i+j], now);
      }
    }
    sz[v] = til;
    for (int i = 0; i <= sz[v]; ++i)
      dp[v][i] = tmp[i];
  }
  for (int i = 0; i <= sz[v]; ++i) tmp[i] = -inf;
  for (int i = 0; i <= sz[v]; ++i) {
    int mulai = max(1, -dp[v][i]-1);
    if (i + mulai <= sz[v])
      tmp[i+mulai] = max(tmp[i+mulai], max(mulai+1, dp[v][i]));
  }
  for (int i = 0; i <= sz[v]; ++i) {
    dp[v][i] = max(dp[v][i], tmp[i]);
    if (i+1 <= sz[v])
      tmp[i+1] = max(tmp[i+1], tmp[i]+1);
  }

}

int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  getSz(0);
  solve(0);
  int ans = n;
  for (int i = 0; i <= n; ++i)
    if (dp[0][i] > 0)
      ans = min(ans, i);
  printf("%d\n", ans);
  return 0;
}