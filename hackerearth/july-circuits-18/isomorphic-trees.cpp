#include <bits/stdc++.h>

using namespace std;

const int N = 55;

/** Max Flow Min Cost **/
/* complexity: O(min(E^2 V log V, E log V F)) */
const int maxnodes = N * 4;

typedef long long ll;

struct MCMF {
  int nodes = maxnodes;
  int prio[maxnodes], curflow[maxnodes], prevedge[maxnodes], prevnode[maxnodes], q[maxnodes];
  bool inqueue[maxnodes];

             
  struct Edge {
    int to, f, cap, cost, rev;
  };

  vector<Edge> graph[maxnodes];

  void addEdge(int s,int t,int cap,int cost){
    Edge a ={t,0, cap, cost, (int)graph[t].size()};
    Edge b ={s,0,0,-cost, (int)graph[s].size()};
    graph[s].push_back(a);
    graph[t].push_back(b);
  }

  pair<int, int> minCostFlow(int s,int t,int maxf){
    int flow =0;
    int flowCost =0;
    while(flow < maxf){
      priority_queue<ll, vector<ll>, greater<ll>> q;
      q.push(s);
      fill(prio, prio + nodes,1000000000);
      prio[s]=0;
      curflow[s]=1000000000;
      while(!q.empty()){
        ll cur = q.top();
        int d = cur >>32;
        int u = cur;
        q.pop();
        if(d != prio[u])continue;
        for(int i =0; i <(int) graph[u].size(); i++){
          Edge &e = graph[u][i];
          int v = e.to;
          if(e.cap <= e.f)continue;
          int nprio = prio[u]+ e.cost;
          if(prio[v]> nprio){
            prio[v]= nprio;
            q.push(((ll) nprio <<32)+ v);
            prevnode[v]= u;
            prevedge[v]= i;
            curflow[v]= min(curflow[u], e.cap - e.f);
          }
        }
      }
      if(prio[t]==1000000000)break;
      int df = min(curflow[t], maxf - flow);
      flow += df;
      for(int v = t; v != s; v = prevnode[v]){
        Edge &e = graph[prevnode[v]][prevedge[v]];
        e.f += df;
        graph[v][e.rev].f -= df;
        flowCost += df * e.cost;
      }
    }
    return make_pair(flow, flowCost);
  }

};

map<pair<int, int>, int>  dp[N][N];

int n, m;
vector<int> g[N], h[N];

int solve(int a, int b, int u, int v) {
  auto it = dp[a][u].find(make_pair(b, v));
  if (a == 0 && u == 0) return 0;
  if (it != dp[a][u].end())
    return it->second;
  if (a == 0) {
    int ret = 1;
    for (int w : h[u]) {
      if (w == v) continue;
      ret += solve(0, 0, w, u);
    }
    return dp[a][u][make_pair(b, v)] = ret;
  }
  if (u == 0) {
    int ret = 1;
    for (int c : g[a]) {
      if (c == b) continue;
      ret += solve(c, a, 0, 0);
    }
    return dp[a][u][make_pair(b, v)] = ret;
  }
  int cntl = 0, cntr = 0;
  for (int c : g[a]) {
    if (c == b) continue;
    ++cntl;
  }
  for (int w : h[u]) {
    if (w == v) continue;
    ++cntr;
  }
  MCMF mf;
  mf.nodes = cntl + cntr + 4;
  int i = 0;
  for (int c : g[a]) {
    if (c == b) continue;
    int j = cntl;
    for (int w : h[u]) {
      if (w == v) continue;
      mf.addEdge(i, j, 1, solve(c, a, w, u));
      ++j;
    }
    ++i;
  }
  i = 0;
  for (int c : g[a]) {
    if (c == b) continue;
    mf.addEdge(mf.nodes-2, i, 1, 0);
    if (cntl > cntr)
      mf.addEdge(i, mf.nodes-3, 1, solve(c, a, 0, 0));
    ++i;
  }
  assert(i == cntl);
  i = cntl;
  for (int w : h[u]) {
    if (w == v) continue;
    mf.addEdge(i, mf.nodes-1, 1, 0);
    if (cntl < cntr)
      mf.addEdge(mf.nodes-4, i, 1, solve(0, 0, w, u));
    ++i;
  }
  if (cntl > cntr)
    mf.addEdge(mf.nodes-3, mf.nodes-1, cntl - cntr, 0);
  else if (cntl < cntr)
    mf.addEdge(mf.nodes-2, mf.nodes-4, cntr - cntl, 0);

  auto res = mf.minCostFlow(mf.nodes-2, mf.nodes-1, max(cntl, cntr));
  assert(res.first == max(cntl, cntr));
  return dp[a][u][make_pair(b, v)] = res.second;
}


int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n-1; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 0; i < m-1; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    h[v].push_back(u);
    h[u].push_back(v);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j)
      solve(i, 0, j, 0);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      printf("%d%c", solve(i, 0, j, 0), j == m ? '\n' : ' ');
    }
  }

  return 0;
}