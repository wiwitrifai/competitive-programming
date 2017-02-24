// Tarjan version again
// directed graph
void dfs(int v) {
  low[v]= num[v] = ++cntr;
  for(auto u : adj[v]) {
    if(num[u] == -1) {
      par[u] = v;
      if(v == Root) rootChild++;
      
      dfs(u);
      
      if(low[u] >= num[v])
        articulation_vertex[v] = true;
      if(low[u] > num[v])
        printf("Edge (%d %d) is a bridge\n", v, u);
      
      low[v] = min(low[v], low[u]);
    }
    else if(u != parent[v])
      low[v] = min(low[v], num[u]);
  }
}

int main() {
  // Inside Main
  cntr = 0;
  num.assign(n, -1);
  low.assign(n, 0);
  par.assign(n, -1);
  articulation_vertex.assign(n, 0);
  for(int i = 0; i<n; i++) if(num[i] == -1) {
    Root = i;
    rootChild = 0;
    dfs(i);
    articulation_vertex[i] = (rootChild > 1);
  }
}