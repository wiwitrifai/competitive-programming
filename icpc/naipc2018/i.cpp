#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, M = 1005, mod = 1e9 + 7;

int dp[N][M];

int st[N], en[N], node[N], cntr = 0, red[N];
vector<int> g[N];
void dfs(int v) {
  node[cntr] = v;
  st[v] = cntr++;
  for (int u : g[v]) {
    dfs(u);
  }
  en[v] = cntr;
}

void add(int & m, int v) {
  m += v;
  if (m >= mod) m -= mod;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i < n; ++i) {
    int p;
    scanf("%d", &p); --p;
    g[p].push_back(i);
  }
  dfs(0);
  dp[0][0] = 1;
  for (int i = 0; i < m; ++i) {
    int r;
    scanf("%d", &r); --r;
    red[r] = 1;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= m; ++j) {
      if (dp[i][j] == 0) continue;
      add(dp[i+1][j], dp[i][j]);
      int v = node[i];
      add(dp[en[v]][j + red[v]], dp[i][j]);
    } 
  }
  for (int i = 0; i <= m; ++i)
    printf("%d\n", dp[n][i]);
  return 0;
}