/****** Tarjan’s SCC *******/
vector< int > num, low, S, vis;
int cntr, numCC;

void tarjanSCC(int v) {
  low[v] = num[v] = ++cntr;
  vis[v] = 1;
  S.push_back(v);
  for(auto u : adj[v]) {
    if(num[u] == -1)
      tarjanSCC(u);
    if(vis[u])
      low[v] = min(low[v], low[u]);
  }
  if(low[v] == num[v]) {
    printf("SCC %d :", ++numCC);
    while(1) {
      int u = S.back(); S.pop_back(); vis[u] = 0;
      printf(" %d", u);
      if(u == v)
        break;
    }
  }
}

// In MAIN();
  num.assign(n, -1);
  low.assign(n, 0);
  vis.assign(n, 0);
  cntr = numCC = 0;
  for(int i = 0; i<n; i++))
    if(num[i] == -1)
      tarjanSCC(i);
