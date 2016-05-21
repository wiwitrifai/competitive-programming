#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int mod = 1e9 + 7;

int n, m, col[N];

vector< pair<int, int > > adj[N];

bool dfs(int u, int c) {
  col[u] = c;
  for(auto nx : adj[u]) {
    int v = nx.first, d = c ^ nx.second;
    if(col[v] == -1)
      if(!dfs(v, d))
        return false;
    if(col[v] != d)
      return false;
  }
  return true;
}


int main() {
  int tt;
  scanf("%d", &tt);
  while(tt--) {
    scanf("%d%d", &n, &m);
    for(int i = 1; i<n; i++)
      scanf("%*d%*d");
    for(int i = 0; i<n; i++) {
      adj[i].clear();
      col[i] = -1;
    }
    for(int i = 0; i<m; i++) {
      int u, v, x;
      scanf("%d%d%d", &u, &v, &x);
      u--; v--;
      adj[u].push_back({v, x});
      adj[v].push_back({u, x});
    }
    long long ans = (mod+1) / 2;
    for(int i = 0; i<n; i++) if(col[i] == -1) {
      if(!dfs(i, 0)) {
        ans = 0;
        break;
      }
      ans = (ans << 1) % mod;
    }
    printf("%lld\n", ans);
  }

  return 0;
}