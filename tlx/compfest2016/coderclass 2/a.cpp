#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int t, n, m;
vector<int> adj[N];
int vis[N];

int dfs(int v) {
  vis[v] = 1;
  int ret = 1;
  for(int u : adj[v]) if(vis[u] == 0)
    ret += dfs(u);
  return ret;
}


int main() {
  scanf("%d", &t);
  while(t--) {
    scanf("%d%d", &n, &m);
    for(int i = 0; i<n; i++) {
      adj[i].clear();
      vis[i] = 0;
    }
    for(int i = 0; i<m; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      u--; v--;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    long long ans = 0;
    int sum = 0;
    for(int i = 0; i<n; i++) if(vis[i] == 0) {
      int tmp = dfs(i);
      ans += 1LL * sum * tmp;
      sum += tmp;
    }
    printf("%lld\n", ans);
  }

  return 0;
}