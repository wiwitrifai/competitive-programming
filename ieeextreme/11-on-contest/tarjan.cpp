#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int num[N], low[N], cntr = 0;
int cyc[N], d[N];
void dfs(int v, int par = -1) {
  num[v] = low[v] = ++cntr;
  for (int u : g[v]) if (u != par) {
    if (num[u] == -1) {
      dfs(u, v);
      low[v] = min(low[v], low[u]);
    }
    else
      low[v] = min(low[v], num[u]);
    if (low[u] > num[v]) {
      d[u]--;
      d[v]--;
    }
  }
}

int main() {
// In MAIN();
  int n, m;
  scanf("%d %d", &n, &m);
  cntr = 0;
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 0; i < n; i++)
    d[i] = g[i].size();
  
  for(int i = 0; i < n; i++)
    if(num[i] == -1)
      dfs(i);
  for (int i = 0
  for (int i = 1; i <= n; i++) if (cyc[i] == 0) printf("%d\n", i);
  return 0;
}
