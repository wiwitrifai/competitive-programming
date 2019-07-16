#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, inf = 1e8 + 7;

vector<int> g[N];
vector< int > num, low, S, vis, cc;
int cntr, numCC;
vector<vector<int>> elem;

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
    elem.push_back(vector<int>());
    while(1) {
      int u = S.back(); S.pop_back(); vis[u] = 0;
      cc[u] = numCC;
      elem[numCC].push_back(u);
      if(u == v)
        break;
    }
    ++numCC;
  }
}

char s[N][55];
int col[N], ncol[N];

int nc;
bool coloring(int v, int c) {
  if (col[v] != -1) {
    return col[v] != c;
  }
  col[v] = c;
  ++c;
  if (c >= nc)
    c = 0;
  for (int u : g[v]) {
    if (cc[u] != cc[v]) continue;
    bool res = coloring(u, c); 
    if (res)
      return true;
  }
  return false;
}
vector<int> cost[N], dp[N];
vector<pair<int, int> > dag[N];
int din[N];

int main() {
  int n, m, d;
  scanf("%d %d %d", &n, &m, &d);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
  }
  for (int i = 0; i < n; ++i)
    scanf("%s", s[i]);

  num.assign(n, -1);
  low.assign(n, 0);
  vis.assign(n, 0);
  cc.assign(n, -1);
  cntr = numCC = 0;
  for(int i = 0; i<n; i++)
    if(num[i] == -1)
      tarjanSCC(i);
  vector<int> fact;
  for (int i = d; i > 1; --i) {
    if (d % i) continue;
    fact.push_back(i);
  }
  // cerr << " done " << endl;
  for (int i = 0; i < numCC; ++i) {
    ncol[i] = 1;
    for (int x : fact) {
      nc = x;
      for (int u : elem[i])
        col[u] = -1;
      bool res = coloring(elem[i][0], 0);
      if (!res) {
        ncol[i] = x;
        break;
      }
    }
    if (ncol[i] == 1) {
      for (int e : elem[i])
        col[e] = 0;
    }
    cost[i].assign(ncol[i], 0);
    dp[i].assign(ncol[i], -inf);
    for (int of = 0; of < ncol[i]; ++of) {
      for (int u : elem[i]) {
        bool ok = 0;
        int day = (col[u] - of + ncol[i]) % ncol[i];
        for (int j = day; j < d; j += ncol[i]) {
          ok |= s[u][j] == '1';
        }
        cost[i][of] += ok;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int u : g[i]) {
      if (cc[u] == cc[i]) continue;
      dag[cc[i]].emplace_back(i, u);
      ++din[cc[u]];
    }
  }
  vector<int> topo;
  for (int i = 0; i < numCC; ++i) {
    if (din[i] == 0)
      topo.push_back(i);
  }
  for (int i = 0; i < topo.size(); ++i) {
    int v = topo[i];
    for (auto it : dag[v]) {
      int u = cc[it.second];
      --din[u];
      if (din[u] == 0)
        topo.push_back(u);
    }
  }
  dp[cc[0]][col[0]] = cost[cc[0]][col[0]];
  int ans = 0;
  for (int i = 0; i < topo.size(); ++i) {
    int v = topo[i];
    for (int x : dp[v])
      ans = max(ans, x);
    for (auto it : dag[v]) {
      int x = it.first, y = it.second;
      int u = cc[y];
      for (int of = 0; of < dp[v].size(); ++of) {
        if (dp[v][of] == -inf) continue;
        int day = (col[x] - of + ncol[v]+1) % ncol[v];
        for (int od = day; od < d; od += ncol[v]) {
          int og = (col[y] - od + d) % ncol[u];
          if (og < 0) og += ncol[u];
          dp[u][og] = max(dp[u][og], dp[v][of] + cost[u][og]);
          // c - og = od
        }
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}