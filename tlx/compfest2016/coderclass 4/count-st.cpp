#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int mod = 1e9 + 7;
vector< int > adj[N];
int vis[N];

int dfs(int v, int lvl = 1, int bef = -1) {
  int ret = 1;
  if(vis[v] > 0) {
    ret = (1LL * ret * (lvl - vis[v])) % mod;
    return ret;
  }
  vis[v] = lvl;
  for(int u : adj[v]) if(vis[u] >= 0 && u != bef) {
    ret = (1LL * ret * dfs(u, lvl+1, v)) % mod;
  }
  vis[v] = -1;
  if(ret < 0)
    ret += mod;
  return ret;
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i<n; i++) {
      adj[i].clear();
      vis[i] = 0;
    }
    for(int i = 0; i<m; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      adj[a].push_back(b);
      adj[b].push_back(a);     
    }
    printf("%d\n", dfs(0, 1));
  }
  
  return 0;
}