#include <bits/stdc++.h>

using namespace std;

const int N = 102, inf = 1e7;

vector< pair<int, int > > adj[N];

int dist[N][N];

int main() {
  int t;
  scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
      adj[i].clear();
    for (int i = 0; i < m; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      u--; v--;
      adj[u].push_back({v, 0});
      adj[v].push_back({u, 1});
    }
    for (int i = 0; i < n; i++) {
      set< pair<int , int > > st;
      for (int j = 0; j < n; j++)
        dist[i][j] = inf;
      dist[i][i] = 0;
      st.insert({0, i});
      while (!st.empty()) {
        auto it = st.begin();
        int v = it->second;
        st.erase(it);
        for (auto nx : adj[v]) {
          int u = nx.first, w = nx.second;
          if (dist[i][u] > dist[i][v] + w) {
            st.erase({dist[i][u], u});
            dist[i][u] = dist[i][v] + w;
            st.insert({dist[i][u], u});
          }
        }
      }
      for (int j = 0; j < n; j++)
        if (dist[i][j] == inf)
          dist[i][j] = -1;
    }
    printf("Case #%d:\n", tc);
    int q;
    scanf("%d", &q);
    while (q--) {
      int u, v;
      scanf("%d %d", &u, &v);
      u--; v--;
      printf("%d\n", dist[u][v]);
    }
  }
  return 0;
}