/**
  IEEExtreme Programming Contest 10
  Problem : Island Hopping 1
  Solver  : Wiwit Rifa'i
  Status  : Accepted
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 52, F = 102, inf = 1e8;
int dist[N][F];
vector< pair<int, int > > adj[N];
int f[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < F; j++)
        dist[i][j] = inf;
    map< string, int > mp;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      mp[s] = i;
      cin >> f[i];
      adj[i].clear();
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
      string a, b;
      int c;
      cin >> a >> b >> c;
      int u = mp[a], v = mp[b];
      adj[u].push_back({v, c});
      adj[v].push_back({u, c});
    }
    int s = mp["start"], t = mp["end"];
    // cerr << s << " " << t << endl;
    set < pair<int, pair<int, int > > > st;
    dist[s][0] = 0;
    st.insert({0, {s, 0}});
    int ans = inf;
    while (!st.empty()) {
      auto it = st.begin();
      int v = it->second.first, r = min(it->second.second + f[v], 100);
      int cost = it->first;
      if (v == t) {
        ans = cost;
        break;
      }
      // cerr << v << " " << r << " " <<  cost << endl;
      st.erase(it);
      for (auto nx : adj[v]) if (nx.second <= r) {
        int p = r-nx.second, u = nx.first;
        if (dist[u][p] > cost + nx.second) {
          st.erase({dist[u][p], {u, p}});
          dist[u][p] = cost + nx.second;
          st.insert({dist[u][p], {u, p}});
        }
      }
    }
    if (ans == inf)
      puts("Impossible");
    else
      printf("%d\n", ans);
  }
  return 0;
}