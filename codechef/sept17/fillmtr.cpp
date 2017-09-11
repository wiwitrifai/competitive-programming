#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int n, m;

vector<pair<int,int>> g[N];
int col[N];

bool dfs(int v, int c) {
  if (col[v] != -1)
    return col[v] == c;
  col[v] = c;
  for (auto it : g[v]) {
    if (!dfs(it.first, c ^ it.second))
      return false;
  }
  return true;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
      g[i].clear();
    fill(col, col+n, -1);
    for (int i = 0; i < m; i++) {
      int u, v, w;
      scanf("%d %d %d", &u, &v, &w);
      u--; v--;
      g[u].emplace_back(v, w);
      g[v].emplace_back(u, w);
    }
    bool ok = 1;
    for (int i = 0; i < n; i++) if (col[i] == -1) {
      ok &= dfs(i, 0);
    }
    puts(ok ? "yes" : "no");
  }
  return 0;
}