#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int node[N][2];
bool bridge[N];
int dp[N][2][2];
int num[N], low[N], cntr = 0;

vector<int> g[N];


void dfs(int v, int e = -1) {
  num[v] = low[v] = ++cntr;
  for (int i : g[v]) {
    if (i == e) continue;
    int u = node[i][0]^node[i][1]^v;
    if (num[u] == -1) {
      dfs(u, i);
      if (num[v] < low[u])
        bridge[i] = 1;
      low[v] = min(low[v], low[u]);
    }
    else
      low[v] = min(low[v], num[u]);
  }
}
int rec(int e, int s, int cyc) {
  int & ret = dp[e][s][cyc];
  if (ret != -1) return ret;
  ret = !cyc;
  int v = node[e][s];
  for (int i : g[v]) {
    if (i == e) continue;
    if (!cyc && !bridge[i]) continue;
    ret += rec(i, v == node[i][0], (cyc == 1) && bridge[i]);
  }
  return ret;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i)
      g[i].clear();
    for (int i = 0; i < m; ++i) {
      scanf("%d %d", node[i], node[i]+1);
      --node[i][0];
      --node[i][1];
      g[node[i][0]].push_back(i);
      g[node[i][1]].push_back(i);
      bridge[i] = 0;
    }
    cntr = 0;
    fill(num, num+n, -1);
    for (int i = 0; i < n; ++i) {
      if (num[i] != -1) continue;
      dfs(i);
    }
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < 2; ++j)
        for (int k = 0; k < 2; ++k)
          dp[i][j][k] = -1;
    for (int i = 0; i < m; ++i) {
      long long ans = 1;
      if (!bridge[i])
        ans = 1LL * rec(i, 0, 0) * rec(i, 1, 0);
      else
        ans = 1LL * rec(i, 0, 0) * rec(i, 1, 0) + 1LL * rec(i, 0, 1) * rec(i, 1, 0) + 1LL * rec(i, 0, 0) * rec(i, 1, 1);
      printf("%lld\n", ans);
    }
  }
  return 0;
}