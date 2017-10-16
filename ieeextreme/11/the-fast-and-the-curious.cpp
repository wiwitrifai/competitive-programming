#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

/****** Tarjan’s SCC *******/
vector< int > num, low, S, vis;
int cntr, numCC;

vector<int> adj[N];
bool cyc[N];

void tarjanSCC(int v, int bef = -1) {
  low[v] = num[v] = ++cntr;
  vis[v] = 1;
  S.push_back(v);
  for(auto u : adj[v]) {
    if (u == bef) continue;
    if(num[u] == -1)
      tarjanSCC(u, v), low[v] = min(low[v], low[u]);
    if(vis[u])
      low[v] = min(low[v], num[u]);
  }
  if(low[v] == num[v]) {
    //printf("SCC %d :", ++numCC);
    vector<int> num;
    while(1) {
      int u = S.back(); S.pop_back(); vis[u] = 0;
      num.push_back(u);
      if(u == v)
        break;
    }
    if (num.size() > 2) {
      for (auto it : num) cyc[it] = 1;
    }
  }
}


int main() {
// In MAIN();
  int n, m;
  scanf("%d %d", &n, &m);
  num.assign(n + 1, -1);
  low.assign(n + 1, 0);
  vis.assign(n + 1, 0);
  cntr = numCC = 0;
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  
  for(int i = 1; i <= n; i++)
    if(num[i] == -1)
      tarjanSCC(i);
  for (int i = 1; i <= n; i++) if (cyc[i] == 0) printf("%d\n", i);
  return 0;
}
