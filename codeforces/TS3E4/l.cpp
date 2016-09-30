#include <bits/stdc++.h>

using namespace std;

const int N = 1024, inf = 1e8;

vector< pair<int, int> > adj[N];
int dist[N], dp[N], dp2[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
      adj[i].clear();
      dist[i] = inf;
      dp[i] = dp2[i] = 0;
    }
    for (int i = 0; i < m; i++) {
      int u, v, w;
      scanf("%d %d %d", &u, &v, &w);
      adj[u].push_back({v, w});
    }
    int a, b;
    scanf("%d %d", &a, &b);
    set < pair<int, int > > st;
    dist[a] = 0;
    dp[a] = 1;
    st.insert({dist[a], a});
    while (!st.empty()) {
      auto it = st.begin();
      int v = it->second;
      st.erase(it);
      for (auto w : adj[v]) if (dist[w.first] > dist[v] + w.second) {
        st.erase({dist[w.first], w.first});
        dist[w.first] = dist[v] + w.second;
        dp[w.first] = dp[v];
        st.insert({dist[w.first], w.first});
      }
      else if (dist[w.first] == dist[v] + w.second) {
        dp[w.first] += dp[v];
      }
    }
    int ans = dp[b];
    for (int i = 1; i <= n; i++) {
      for (auto u : adj[i]) if (dist[u.first] + 1 == dist[i] + u.second) {
        dp2[u.first] += dp[i];
      }
    }
    vector< pair< int, int > > vp;
    for (int i = 1; i <= n; i++) {
      vp.push_back({dist[i], i});
    }
    sort(vp.begin(), vp.end());
    for (int i = 0; i < n; i++) {
      int v = vp[i].second;
      for (auto u : adj[v]) if (dist[u.first] == dist[v] + u.second) {
        dp2[u.first] += dp2[v];
      }
    }
    ans += dp2[b];
    printf("%d\n", ans);
  }
  

  return 0;
}