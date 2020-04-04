#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector<int> g[N];
int vis[N];

int dfs(int v, int par = -1) {
  if (vis[v])
    return 1;
  int ret = 1;
  vis[v] = 1;
  for (int u : g[v]) {
    if (u == par) continue;
    ret += dfs(u, v);
  }
  return ret;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 0; i < n; ++i)
    scanf("%d", vis+i);
  int ans = 0;
  for (int i = 0; i < n; ++i)
    ans = max(ans, dfs(i));
  printf("%d\n", ans);
  return 0;
}
