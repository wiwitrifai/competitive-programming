// solved by luqman
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e5 + 5;
const long long mod = 2e9 + 89;
const long long inf = 1e18;
 
/****** Tarjan???s SCC *******/
vector< int > num, low, S, vis, comp, adj[N];
int cntr, numCC;
 
void tarjanSCC(int v, int bef = -1) {
  low[v] = num[v] = ++cntr;
  vis[v] = 1;
  S.push_back(v);
  for(auto u : adj[v]) {
    if (u == bef) continue;
    if(num[u] == -1)
      tarjanSCC(u, v);
    if(vis[u])
      low[v] = min(low[v], low[u]);
  }
  if(low[v] == num[v]) {
    numCC++;
    while(1) {
      int u = S.back(); S.pop_back(); vis[u] = 0;
      comp[u] = numCC;
      if(u == v)
        break;
    }
  }
}
 
void dijkstra(int start, long long* d, vector<tuple<int, int, int>> edge[N]) {
  fill(d, d + N, inf);
  d[start] = 0;
  priority_queue<pair<long long, int>> pq;
  pq.emplace(-d[start], start);
  while (!pq.empty()) {
    long long cost;
    int now;
    tie(cost, now) = pq.top();
    pq.pop();
    cost = -cost;
    if (d[now] != cost) continue;
    for (auto it : edge[now]) {
      long long add; int near;
      tie(near, add, ignore) = it;
      long long ncos = cost + add;
      if (ncos < d[near]) {
        d[near] = ncos;
        pq.emplace(-d[near], near);
      }
    }
  }
}
 
long long d[N], drev[N];
int u[N], v[N], w[N];
vector<tuple<int, int, int>> edge[N];           // node - cost - id
vector<tuple<int, int, int>> rev[N];            // node - cost - id
bool good[N], done[N];
 
void dfs(int now) {
  if (done[now]) return;
  done[now] = 1;
  for (auto it : rev[now]) {
    int to, cost, id;
    tie(to, cost, id) = it;
    if (d[to] + cost == d[now]) {
      good[id] = 1;
      dfs(to);
    }
  }
}
 
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", u + i, v + i, w + i);
    edge[u[i]].emplace_back(v[i], w[i], i);
    rev[v[i]].emplace_back(u[i], w[i], i);
  }
  dijkstra(1, d, edge);
  dijkstra(2, drev, rev);
   
  dfs(2);
  for (int i = 0; i < m; i++) {
    if (good[i]) {
      adj[u[i]].push_back(v[i]);
      adj[v[i]].push_back(u[i]);
    }
  }
  num.assign(n + 1, -1);
  low.assign(n + 1, 0);
  vis.assign(n + 1, 0);
  comp.assign(n + 1, -1);
  cntr = numCC = 0;
  for(int i = 1; i <= n; i++)
    if(num[i] == -1)
      tarjanSCC(i);
   
  /*
  puts("d");
  for (int i = 1; i <= n; i++) printf("%lld ", d[i]); printf("\n");
  puts("good");
  for (int i = 0; i < m; i++) printf("%d ", good[i]); printf("\n");
  puts("comp");
  for (int i = 1; i <= n; i++) printf("%d ", comp[i]); printf("\n");
  */
  for (int i = 0; i < m; i++) {
    if (d[v[i]] + drev[u[i]] + w[i] < d[2]) {
      puts("HAPPY");
    } else if (good[i] && comp[u[i]] != comp[v[i]]) {
      puts("SAD");
    } else {
      puts("SOSO");
    }
  }
   
 
  return 0;
}