#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1024, M = 100 * N, inf = 1e8 + 8;
int w[N], n, m, k, p[N];
vector< pair< int, int > > g[N];
pair< int, pair< int, int > > edge[M];
bool used[N];
int d[N];
 
int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}
 
bool merge(int u, int v) {
  if ((u = find(u)) == (v = find(v)))
    return false;
  if (p[u] > p[v])
    swap(u, v);
  p[u] += p[v];
  p[v] = u;
  return true;
}
 
int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < n; i++)
    scanf("%d", w+i);
  for (int j = 0; j < m; j++) {
    int u, v, c;
    scanf("%d %d %d", &u, &v, &c);
    u--; v--;
    g[u].emplace_back(v, c);
    g[v].emplace_back(u, c);
    edge[j] = make_pair(c, make_pair(u, v));
  }
  sort(edge, edge + m);
  int ans = -inf;
  vector< pair< int, int > > eans;
  for (int startt = 0; startt < n; startt++) {
    for (int i = 0; i < n; i++)
      d[i] = inf, used[i] = 0;
    set< pair< int, int > > st;
    d[startt] = 0;
    st.insert(make_pair(-w[startt], startt));
    int profit = 0;
    int best = 0, bprofit = -inf;
    vector< pair< int, int > > vmst;
    while (!st.empty()) {
      auto it = st.begin();
      int v = it->second;
      profit -= it->first;
      st.erase(it);
      used[v] = 1;
      for (auto nx : g[v]) {
        int u = nx.first;
        int c = nx.second;
        if (c < d[u]) {
          if (used[u]) {
            profit += d[u]-c;
            d[u] = c;
            continue;
          }
          st.erase(make_pair(d[u]-w[u], u));
          d[u] = c;
          st.insert(make_pair(d[u]-w[u], u));
        }
      }
      vmst.emplace_back(v, profit);
      if (bprofit < profit)
        bprofit = profit, best = vmst.size();
    }
    for (int i = 0; i < n; i++) p[i] = -1, used[i] = 0;
    for (int i = 0; i < best; i++) {
      used[vmst[i].first] = 1;
    }
    profit = 0;
    for (int i = 0; i < n; i++) if (used[i])
      profit += w[i];
    vector< pair< int, int > > vedge;
    for (int i = 0; i < m; i++) {
      int u = edge[i].second.first, v = edge[i].second.second;
      if (!used[u] || !used[v]) continue;
      if (!merge(u, v)) continue;
      profit -= edge[i].first;
      vedge.push_back(edge[i].second);
    }
    if (ans < profit) {
      eans.swap(vedge);
      ans = profit;
    }
  }
  memset(used, 0, sizeof used);
  for (auto it : eans)
    used[it.first] = used[it.second] = 1;
  int cnt = 0;
  for (int i = 0; i < n; i++)
    cnt += used[i];
  printf("%d %d\n", cnt, eans.size());
  for (int i = 0; i < n; i++)
    if (used[i]) printf("%d ", i+1);
  printf("\n");
  for (auto it : eans) {
    printf("%d %d\n", it.first + 1, it.second + 1);
  }
  return 0;
}