#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353, N = 2e5 + 5;

vector<int> child[N];
long long dp[N][3];
long long tmp[3];

void dfs(int v) {
  if (child[v].empty())
    dp[v][2] = 1;
  else
    dp[v][0] = 1;
  for (int u : child[v]) {
    dfs(u);
    memset(tmp, 0, sizeof tmp);
    tmp[0] = (dp[v][0] * (dp[u][2] + dp[u][0])) % mod;
    tmp[1] = (dp[v][1] * (dp[u][0] + dp[u][2]) + (dp[v][0]) * (dp[u][2] + dp[u][1])) % mod;
    tmp[2] = (dp[v][2] * (dp[u][0] + dp[u][2]) + (dp[v][1] + dp[v][2]) * (dp[u][2] + dp[u][1])) % mod;
    for (int i = 0; i < 3; ++i) {
      dp[v][i] = tmp[i];
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int p;
    scanf("%d", &p);
    --p;
    child[p].push_back(i);
  }
  dfs(0);
  long long ans = (dp[0][0] + dp[0][2]) % mod;
  printf("%lld\n", ans);
  return 0;
}
