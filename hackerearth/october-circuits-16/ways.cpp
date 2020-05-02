#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int N = 1e3 + 5, inf = 1e8 + 5;

vector< pair<int, int > > adj[N];
int dist[N];
long long cnt[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
      adj[i].clear();
      dist[i] = inf;
      cnt[i] = 1;
    }
    for (int i = 0; i < m; i++) {
      int a, b, c;
      scanf("%d %d %d", &a, &b, &c);
      a--;
      b--;
      adj[a].push_back({b, c});
      adj[b].push_back({a, c});
    }
    set < pair<int, int > > st;
    dist[0] = 0;
    st.insert({0, 0});
    while (!st.empty()) {
      auto it = st.begin();
      int v = it->second;
      st.erase(it);
      for (auto u : adj[v]) if (dist[u.first] > dist[v] + u.second) {
        st.erase({dist[u.first], u.first});
        dist[u.first] = dist[v] + u.second;
        st.insert({dist[u.first], u.first});
        cnt[u.first] = 1;
      }
      else if (dist[u.first] == (dist[v] + u.second))
        cnt[u.first]++;
    }
    long long ans = 1;
    for (int i = 0; i < n; i++) {
      ans = (ans * cnt[i]) % mod;
    }
    printf("%lld\n", ans); 
  }

  return 0;
}