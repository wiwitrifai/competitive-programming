#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
vector< int > g[N];
int dfs(int v, int par = -1) {
  int ret = 0;
  for (int u : g[v]) if (u != par)
    ret ^= (1 + dfs(u, v));
  return ret;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int ans = dfs(0);
  puts(ans ? "Alice" : "Bob");
  return 0;
}