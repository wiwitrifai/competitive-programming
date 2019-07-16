#include <bits/stdc++.h>

using namespace std;

const int N = 1024;
const long long inf = 2e10 + 7;

long long dp[N][N];
vector<pair<int, int> > g[N];
int sz[N];
long long tmp[N];

void upd(long long & var, long long val) {
  if (var > val)
    var = val;
}

void dfs(int v, int par = -1) {
  sz[v] = 1;
  dp[v][0] = 0;
  dp[v][1] = inf;
  for (auto it : g[v]) {
    if (it.first == par) continue;
    dfs(it.first, v);
    int u = it.first;
    for (int i = 0; i < sz[v] + sz[u]; ++i)
      tmp[i] = inf;
    for (int i = 0; i < sz[v]; ++i) {
      for (int j = 0; j < sz[u]; ++j) {
        int last = j & 1;
        upd(tmp[i+j+last], dp[v][i]+dp[u][j]+2*it.second);
        upd(tmp[i+j+!last], dp[v][i]+dp[u][j]+it.second);
      }
    }
    sz[v] += sz[u];
    for (int i = 0; i < sz[v]; ++i)
      dp[v][i] = tmp[i];
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; ++i)
      g[i].clear();
    for (int i = 1; i < n; ++i) {
      int u, v, w;
      scanf("%d %d %d", &u, &v, &w);
      --u, --v;
      g[u].emplace_back(v, w);
      g[v].emplace_back(u, w);
    }
    dfs(0);
    long long ans = inf;
    for (int i = 0; i <= min(2 * m, n-1); ++i) {
      ans = min(ans, dp[0][i] + 1LL * k * ((i+1)/2));
    }
    printf("%lld\n", ans);
  }
  return 0;
}