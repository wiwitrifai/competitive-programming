#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector< int > adj[N];
int dp[N][2][2], n;

void dfs(int u, int p = -1) {
  dp[u][0][1] = 0;
  dp[u][1][0] = 1;
  vector< int > dif[2], all[2];
  for (int v : adj[u]) if (p != v) {
    dfs(v, u);
    dp[u][0][1] += min(dp[v][1][0], dp[v][1][1]);
    dp[u][1][0] += min(dp[v][0][0], dp[v][0][1]);
    all[0].push_back(min(dp[v][0][0], dp[v][0][1]));
    all[1].push_back(min(dp[v][1][0], dp[v][1][1]));
    dif[0].push_back(dp[v][0][1]);
    dif[1].push_back(dp[v][1][0]);
  }
  vector< int > sum[2];
  int now[2] = {0, 0};
  for (int i = 0; i < all[0].size(); i++) {
    sum[0].push_back(now[0]);
    sum[1].push_back(now[1]);
    now[0] += all[0][i];
    now[1] += all[1][i];
  }
  dp[u][0][0] = now[1];
  dp[u][1][1] = now[0] + 1;
  now[0] = now[1] = 0;
  for (int i = (int)all[0].size()-1; i >= 0; i--) {
    dp[u][0][0] = min(dp[u][0][0], now[1] + sum[1][i] + dif[0][i]);
    dp[u][1][1] = min(dp[u][1][1], now[0] + sum[0][i] + dif[1][i] + 1);
    now[0] += all[0][i];
    now[1] += all[1][i];
  } 
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      adj[i].clear();
    for (int i = 1; i < n; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      u--; v--;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    dfs(0);
    printf("%d\n", min(dp[0][0][0], dp[0][1][1]));
  }
  return 0;
}