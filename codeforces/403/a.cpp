#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
vector< int > g[N];
int k = 0;
set< int > st[N];
int col[N];

void dfs(int u, int par = -1) {
  if (par != -1)
    st[u].insert(col[par]);
  int cur = 1;
  if (col[u] == -1) {
    while (st[u].count(cur)) cur++;
    col[u] = cur;
  }
  st[u].insert(col[u]);
  for (int v : g[u]) if (v != par) {
    if (col[v] == -1) {
      while (st[u].count(cur)) cur++;
      col[v] = cur;
    }
    st[u].insert(col[v]);
  }
  for (int v : g[u]) if (v != par) {
    dfs(v, u);
  }
}

int main() {
  memset(col, -1, sizeof col);
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0);
  k = 0;
  for (int i = 0; i < n; i++)
    k = max(k, col[i]);
  printf("%d\n", k);
  for (int i = 0; i < n; i++)
    printf("%d ", col[i]);
  printf("\n");
  return 0;
}