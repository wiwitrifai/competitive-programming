#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6;
pair<int, int> edge[N];
vector<int> num, low, par;
vector<int> adj[N], S;
int cntr = 0, nComp = 0, comp[N];
void dfs(int v) {
  S.push_back(v);
  low[v]= num[v] = ++cntr;
  for(auto u : adj[v]) {
    if(num[u] == -1) {
      par[u] = v;
      dfs(u);
      low[v] = min(low[v], low[u]);
    }
    else if(u != par[v])
      low[v] = min(low[v], num[u]);
  }
  if (num[v] <= low[v]) {
    while (!S.empty()) {
      int u = S.back(); S.pop_back();
      comp[u] = nComp;
      if (u == v) break;
    }
    ++nComp;
  }
}


int deg[N];
bool cycle[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    edge[i] = {u, v};
  }
  cntr = 0;
  num.assign(n, -1);
  low.assign(n, 0);
  par.assign(n, -1);
  memset(comp, -1, sizeof comp);
  for(int i = 0; i<n; i++) if(num[i] == -1) {
    dfs(i);
  }
  for (int i = 0; i < m; ++i) {
    int u = edge[i].first, v = edge[i].second;
    if (comp[u] != comp[v]) continue;
    ++deg[u];
    ++deg[v];
  }
  memset(cycle, 1, sizeof cycle);
  for (int i = 0; i < n; ++i) {
    cycle[comp[i]] &= deg[i] == 2;
  }
  vector<int> ans;
  for (int i = 0; i < m; ++i) {
    int u = edge[i].first, v = edge[i].second;
    if (comp[u] != comp[v]) continue;
    if (cycle[comp[u]]) {
      ans.push_back(i+1);
    }   
  }
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); ++i) {
    if (i) printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}