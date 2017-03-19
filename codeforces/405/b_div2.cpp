#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

vector< int > g[N];
int n, m, vis[N];

int dfs(int u, int deg) {
  if (vis[u]) return 0;
  vis[u] = 1;
  int ret = 1;
  if (g[u].size() != deg)
    return -1;
  for (int v : g[u]) {
    int res = dfs(v, deg);
    if (res == -1)
      return -1;
    ret += res;
  }
  return ret;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 0; i < n; i++) {
    if (vis[i]) continue;
    int res = dfs(i, g[i].size());
    if (res != g[i].size()+1) {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
  return 0;
}