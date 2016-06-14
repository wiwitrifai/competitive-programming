#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5, M = (1<<10) + 5;
const long long inf = 1e17 + 9;
vector< pair< int, int > > adj[N];
long long dist[N][M];
int n, m , k, val[N];


int main() {
  scanf("%d%d%d", &n, &m, &k);
  for(int i = 0; i<n; i++) {
    int t;
    scanf("%d", &t);
    val[i] = 0;
    while(t--) {
      int x;
      scanf("%d", &x); x--;
      val[i] |= 1<<x;
    }
  }
  for(int i = 0; i<m; i++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    u--; v--;
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
  }
  set< pair< long long, pair<int, int> > > st;
  st.insert({0, {0, val[0]}});
  int nk = 1<<k;
  for(int i = 0; i<n; i++)
    for(int j = 0; j<nk; j++)
      dist[i][j] = inf;
  dist[0][val[0]] = 0;
  while(!st.empty()) {
    auto it = st.begin();
    int u = it->second.first, mask = it->second.second;
    // cerr << u << " " << mask << " " << it->first << " " << dist[u][mask] << endl;
    st.erase(it);
    for(auto nx : adj[u]) if(dist[u][mask] + nx.second < dist[nx.first][mask|val[nx.first]]){
      int bmask = mask | val[nx.first];
      st.erase({dist[nx.first][bmask], {nx.first, bmask}});
      dist[nx.first][bmask] = dist[u][mask] + nx.second;
      st.insert({dist[nx.first][bmask], {nx.first, bmask}});
    }
  }
  for(int i = nk-1; i>=0; i--) {
    for(int j = i; j<nk; j = (j+1)|i)
      dist[n-1][i] = min(dist[n-1][j], dist[n-1][i]);
  }
  long long ans = inf;
  int mask = nk-1;
  for(int i = 0; i<nk; i++) {
    ans = min(ans, max(dist[n-1][i], dist[n-1][mask^i]));
    // cerr << i << " " << dist[n-1][i] << " " << dist[n-1][mask^i] << endl;
  }
  cout << ans << endl;
  return 0;
}