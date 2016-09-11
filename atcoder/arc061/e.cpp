#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e5 + 5, M = 2e6 + 5;
const long long inf = 1e16;
map< pair<int, int>, int> id;
int lastid;
vector< pair<int, int> > adj[N + M];
long long dist[N + M];

void addEdge(int u, int v, int c1, int c2) {
  adj[u].push_back({v, c1});
  adj[v].push_back({u, c2});
}

int getId(int u, int c) {
  if (id.count({u, c})) return id[{u, c}];
  addEdge(u, lastid, 1, 0);
  id[{u, c}] = lastid;
  return lastid++;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  lastid = n+1;
  for (int i = 1; i <= m; i++) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    a = getId(a, c);
    b = getId(b, c);
    addEdge(a, b, 0, 0);
  }
  for (int i = 0; i < lastid; i++)
    dist[i] = inf;
  set < pair< long long, int > > st;
  st.insert({0, 1});
  dist[1] = 0;
  while (!st.empty()) {
    auto it = st.begin();
    int v = it->second;
    long long now = it->first;
    st.erase(it);
    if (v == n) {
      printf("%lld\n", now);
      return 0;
    }
    for (auto it : adj[v]) {
      long long cur = now + it.second;
      if (dist[it.first] > cur) {
        st.erase(make_pair(dist[it.first], it.first));
        dist[it.first] = cur;
        st.insert(make_pair(cur, it.first));
      }
    }
  }
  puts("-1");
  return 0;
}