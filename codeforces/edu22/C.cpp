#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int lv[N], ma[N], x, ans, n;
vector< int > g[N];

bool dfs(int v, int par = -1) {
  lv[v] = par == -1 ? 0 : lv[par] + 1;
  ma[v] = lv[v];
  bool found = v == x;
  for (int u : g[v]) if (u != par) {
    found |= dfs(u, v);
    ma[v] = max(ma[u], ma[v]);
  }
  if (found && lv[v] > lv[x]-lv[v])
    ans = max(ans, 2 * ma[v]);
  return found;
}

int main() {
  scanf("%d %d", &n, &x);
  x--;
  for (int i = 0; i < n-1; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  ans = 0;
  dfs(0);
  printf("%d\n", ans);
  return 0;
}