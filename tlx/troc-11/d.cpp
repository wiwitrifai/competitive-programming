#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> g[N];

/****** Tarjan’s SCC *******/
// directed graph
vector< int > num, low, S, vis, cc;
int cntr, numCC;

void tarjanSCC(int v) {
  low[v] = num[v] = ++cntr;
  vis[v] = 1;
  S.push_back(v);
  for(auto u : g[v]) {
    if(num[u] == -1)
      tarjanSCC(u);
    if(vis[u])
      low[v] = min(low[v], low[u]);
  }
  if(low[v] == num[v]) {
    while(1) {
      int u = S.back(); S.pop_back(); vis[u] = 0;
      cc[u] = numCC;
      if(u == v)
        break;
    }
    ++numCC;
  }
}
vector<vector<int>> dag;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
  }
  num.assign(n, -1);
  low.assign(n, -1);
  vis.assign(n, false);
  cc.assign(n, -1);
  cntr = numCC = 0;
  for (int i = 0; i < n; ++i) {
    if (num[i] != -1) continue;
    tarjanSCC(i);
  }
  dag.resize(numCC, vector<int>());
  for (int i = 0; i < n; ++i) {
    for (int u : g[i]) {
      if (cc[i] != cc[u])
        dag[cc[i]].push_back(cc[u]);
    }
  }
  vector<int> din(numCC, 0);
  for (int i = 0; i < numCC; ++i) {
    sort(dag[i].begin(), dag[i].end());
    dag[i].erase(unique(dag[i].begin(), dag[i].end()), dag[i].end());
    for (int u : dag[i])
      ++din[u];
  }
  vector<int> topo;
  for (int i = 0; i < numCC; ++i) {
    if (din[i] == 0)
      topo.push_back(i);
  }
  for (int i = 0; i < (int) topo.size(); ++i) {
    int v = topo[i];
    for (int u : dag[v]) {
      --din[u];
      if (din[u] == 0) {
        topo.push_back(u);
      }
    }
  }
  if ((int)topo.size() != numCC) {
    puts("TIDAK");
    return 0;
  }
  bool ok = 1;
  for (int i = 0; ok && i + 1 < (int)topo.size(); ++i) {
    bool found = 0;
    for (int u : dag[topo[i]]) {
      if (u == topo[i+1]) {
        found = 1;
        break;
      }
    }
    ok &= found;
  }
  puts(ok ? "YA" : "TIDAK");
  return 0;
}
