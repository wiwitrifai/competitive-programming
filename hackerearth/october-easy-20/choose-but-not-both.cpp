#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5, inf = 1e9 + 7;

int a[N];
int vis[N], cycle[N];

vector<int> child[N];
int dp[N][2];

void dfs(int v) {
  dp[v][0] = 0;
  dp[v][1] = 1;
  for (int u : child[v]) {
    dfs(u);
    dp[v][0] += dp[u][1];
    dp[v][1] += dp[u][0];
  }
  dp[v][1] = max(dp[v][0], dp[v][1]);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    --a[i];
  }
  for (int i = 0; i < n; ++i) {
    if (vis[i]) continue;
    int v = i;
    while (vis[v] == 0) {
      vis[v] = 1;
      v = a[v];
    }
    if (vis[v] == 1) {
      while (!cycle[v]) {
        cycle[v] = 1;
        v = a[v];
      }
    }
    v = i;
    while (vis[v] == 1) {
      vis[v] = 2;
      v = a[v];
    }
  }
  for (int i = 0; i < n; ++i) {
    if (cycle[i]) continue;
    child[a[i]].push_back(i);
  }
  for (int i = 0; i < n; ++i) {
    if (!cycle[i]) continue;
    dfs(i);
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (!cycle[i] || vis[i] != 2) continue;
    vector<int> nodes;
    int v = i;
    while (vis[v] == 2) {
      vis[v] = 3;
      nodes.push_back(v);
       v = a[v];
    }
    int cur = 0;
    if (nodes.size() == 1) {
      cur = dp[nodes[0]][0];
    } else {
      int s = nodes.back();
      nodes.pop_back();
      int best[2], tmp[2];
      best[0] = dp[s][0];
      best[1] = dp[s][1];
      for (int x : nodes) {
        tmp[0] = dp[x][0] + max(best[1], best[0]);
        tmp[1] = dp[x][1] + best[0];
        best[0] = tmp[0];
        best[1] = max(tmp[1], tmp[0]);
      }
      cur = max(cur, best[0]);
      best[0] = dp[s][0];
      best[1] = -inf;
      for (int x : nodes) {
        tmp[0] = dp[x][0] + max(best[1], best[0]);
        tmp[1] = dp[x][1] + best[0];
        best[0] = tmp[0];
        best[1] = max(tmp[1], tmp[0]);
      }
      cur = max(cur, best[1]);
    }
    ans += cur;
  }
  printf("%d\n", ans);
  return 0;
}
