#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, M = 1e3 + 6;

int a[M], n, m;
bool vis[M];
int match[N];
vector< int > adj[M];

bool dfs(int v) {
  if (vis[v])
    return false;
  vis[v] = true;
  for (int u : adj[v]) 
    if (match[u] == -1 || dfs(match[u]))
      return match[u] = v, true;
  return false;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  memset(match, -1, sizeof match);
  for (int i = 0; i < n; i++) {
    for (int j = 1; j * j <= a[i] && j <= m; j++) if ((a[i] % j) == 0){
      adj[i].push_back(j);
      int b = a[i]/j;
      if (b <= m && b != j)
        adj[i].push_back(b);
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    memset(vis, 0, sizeof vis);
    dfs(i);
  }
  for (int i = 1; i <= m; i++)
    if (match[i] != -1)
      ans++;
  printf("%d\n", ans);
  return 0;
}