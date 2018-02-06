#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int dp[N][2];
bool kosong[N];
vector<int> g[N];

void dfs(int v, int par = -1) {
  dp[v][1] = 0;
  dp[v][0] = 0;
  kosong[v] = 1;
  int child = 0;
  for (int u : g[v]) if (u != par) {
    dfs(u, v);
    int one = dp[v][1] + dp[u][1], zero = dp[v][0] + dp[u][1];
    if (kosong[u])
      one = min(one, dp[v][0]);
    else
      kosong[v] = 0;
    dp[v][1] = one;
    dp[v][0] = zero;
    ++child;
  }
  if (child > 1)
    kosong[v] = 0;
  dp[v][1] = max(dp[v][1], 1);
  dp[v][0] = max(dp[v][0], 1);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int banyak = g[0].size(), root = 0;
  for (int i = 0; i < n; ++i) {
    if (banyak < g[i].size())
      root = i, banyak = g[i].size();
  }
  if (banyak <= 2) {
    puts("1");
    return 0;
  }
  dfs(root);
  printf("%d\n", dp[root][1]);
  return 0;
}