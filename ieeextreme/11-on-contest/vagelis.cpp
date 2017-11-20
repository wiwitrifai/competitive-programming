#include <bits/stdc++.h>

using namespace std;

const int N = 1045, M = 1e4 + 5;

vector<int> g[N];

int a[M], b[M];
bool vis[M];

bool dfs(int v, int par = -1) {
  if (vis[v])
    return true;
  vis[v] = 1;
  for (int e : g[v]) if (e != par) {
    int u = v ^ a[e] ^ b[e];
    if (dfs(u, e))
      return true; 
  }
  return false;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    fill(vis, vis+n, false);
    for (int i = 0; i < n; i++)
      g[i].clear();
    for (int i = 0; i < m; i++) {
      scanf("%d %d", a+i, b+i);
      g[a[i]].push_back(i);
      g[b[i]].push_back(i);
    }
    bool ok = 0;
    for (int i = 0; i < n; i++) if (!vis[i])
      ok |= dfs(i);
    puts(ok ? "1" : "0");
  }
  return 0;
}