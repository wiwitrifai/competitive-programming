#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, inf = 1e8 + 7;

set<int> g[N];
char s[N];
bool dead[N];

int dp[N][4];
int tmp[4];
void upd(int & var, int val) {
  if (var > val) var = val;
}
void dfs(int v, int par = -1) {
  for (int i = 0; i < 4; ++i)
    dp[v][i] = 0;
  int parity = 1;
  if (s[v] == 'B') parity = 0;
  int pas = g[v].size(), kurang = max(pas - 1, 0);
  if ((pas & 1) != parity) ++pas;
  if ((kurang & 1) != parity) ++kurang;
  for (int u : g[v]) {
    if (u == par) continue;
    dfs(u, v);
    for (int i = 0; i < 4; ++i)
      tmp[i] = inf;
    upd(tmp[0], dp[v][0] + dp[u][0]);
    
    upd(tmp[1], dp[v][0] + dp[u][1]);
    upd(tmp[1], dp[v][1] + dp[u][0]);
    
    upd(tmp[2], dp[v][0] + dp[u][2]);
    upd(tmp[2], dp[v][2] + dp[u][0]);
    upd(tmp[2], dp[v][0] + dp[u][0]);

    upd(tmp[3], dp[v][0] + dp[u][3]);
    upd(tmp[3], dp[v][3] + dp[u][0]);
    upd(tmp[3], dp[v][1] + dp[u][0]);
    upd(tmp[3], dp[v][0] + dp[u][1]);
    upd(tmp[3], dp[v][2] + dp[u][1] + kurang - pas);
    upd(tmp[3], dp[v][1] + dp[u][2] + kurang - pas);
    for (int i = 0; i < 4; ++i)
      dp[v][i] = tmp[i];
  }
  dp[v][0] += pas;
  dp[v][1] += kurang;
  dp[v][2] += kurang;
  dp[v][3] += pas;
  upd(dp[v][3], dp[v][0]);
  upd(dp[v][3], dp[v][2]);
  int cnt = g[v].size();
  if (par != -1) --cnt;
  if (cnt > 1)
    upd(dp[v][3], dp[v][1]);
}


int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].insert(v);
    g[v].insert(u);
  }
  scanf("%s", s);
  queue<int> que;
  for (int i = 0; i < n; ++i) {
    if (g[i].size() == 1 && s[i] == 'B') {
      que.push(i);
      dead[i] = 1;
    }
  }
  while (!que.empty()) {
    int v = que.front(); que.pop();
    for (int u : g[v]) {
      g[u].erase(v);
      if (s[u] == 'B' && g[u].size() == 1 && !dead[u])
        que.push(u), dead[u] = 1;
    }
    g[v].clear();
  }
  int root = -1;
  for (int i = 0; i < n; ++i) if (s[i] != 'B' && g[i].size() <= 1)
    root = i;
  if (root == -1) {
    puts("0");
    return 0;
  }
  if (g[root].empty()) {
    puts("1");
    return 0;
  }
  dfs(root);
  int ans = inf;
  for (int i = 0; i < 4; ++i)
    ans = min(ans, dp[root][i]);
  printf("%d\n", ans);
  return 0;
}