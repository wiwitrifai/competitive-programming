#include <bits/stdc++.h>

using namespace std;

const int N = 1024;
const long long inf = 1e15;
vector< pair<int, int> > adj[N];
int n, m, k, q, s[N];
long long dist[N][N];

int main() {
  scanf("%d %d %d %d", &n, &m, &k, &q);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    u--; v--;
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
  } 
  for (int i = 0; i < k; i++)
    scanf("%d", s+i), s[i]--;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      dist[i][j] = inf;
    set< pair< long long, int > > st;
    dist[i][i] = 0;
    st.insert(make_pair(dist[i][i], i));
    while (!st.empty()) {
      auto it = st.begin();
      int v = it->second;
      int now = dist[i][v];
      st.erase(it);
      for (auto e : adj[v]) {
        if (dist[i][e.first] > now + e.second) {
          st.erase(make_pair(dist[i][e.first], e.first));
          dist[i][e.first] = now + e.second;
          st.insert(make_pair(dist[i][e.first], e.first));
        }
      }
    }
  }
  vector< pair<int, int> > ans;
  while (q--) {
    int v;
    scanf("%d", &v); v--;
    int near = 0;
    for (int i = 1; i < k; i++)
      if (dist[s[i]][v] < dist[s[near]][v])
        near = i;
    if (s[near] != v) {
      s[near] = v;
      ans.emplace_back(near, v);
    }
    ans.emplace_back(-1, -1);
  }
  printf("%d\n", ans.size());
  for (auto it : ans) {
    if (it.first < 0)
      puts("HANDLE");
    else
      printf("MOVE %d %d\n", it.first+1, it.second+1);
  }
  return 0;
}