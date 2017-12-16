#include <bits/stdc++.h>

using namespace std;

struct Tree
{
  int n, LN;
  vector<vector< int > > adj;
  vector<int> lv;
  vector<vector<int> >  par;
  Tree(int n = 0) : n(n) {
    lv.assign(n, -1);
    LN = 0;
    while ((1LL << LN) <= n) ++LN;
    ++LN;
    par.resize(LN);
    for (int i = 0; i < LN; ++i)
      par[i].assign(n, -1);
    adj.resize(n);
    for (int i = 0; i < n; ++i)
      adj[i].clear();
  }
  void add(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  void dfs(int u, int p = -1) {
    lv[u] = (p == -1 ? 0 : lv[p] + 1);
    par[0][u] = (p == -1 ? u : p);
    for (int i = 0; i + 1 < LN; i++)
      par[i+1][u] = par[i][par[i][u]];
    for (auto v : adj[u]) if (lv[v] == -1) {
      dfs(v, u);
    }
  }
  int ancestor(int v, int lev) {
    if (lev > lv[v])
      return -1;
    int d = lv[v] - lev;
    for (int i = LN-1; i >= 0; i--)
      if (d & (1<<i))
        v = par[i][v];
    return v;        
  }
  int lca(int u, int v) {
    if (lv[u] > lv[v])
      swap(u, v);
    v = ancestor(v, lv[u]);
    if (u == v)
      return u;
    for (int i = LN-1; i >= 0; i--)
      if (par[i][u] != par[i][v])
        u = par[i][u], v = par[i][v];
    return par[0][v];
  }

  void build() {
    for (int i = 0; i < n; ++i) {
      sort(adj[i].begin(), adj[i].end());
      adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
    }
    for (int i = 0; i < n; ++i) if (lv[i] == -1) {
      dfs(i);
    }
  }

  bool pathACwoB(int a, int b, int c) {
    if (par[LN-1][a] != par[LN-1][c]) return false;
    if (par[LN-1][a] != par[LN-1][b]) return true;
    int ac = lca(a, c);
    if (lv[b] < lv[ac]) return true;
    return (ancestor(a, lv[b]) != b) && (ancestor(c, lv[b]) != b);
  }
};