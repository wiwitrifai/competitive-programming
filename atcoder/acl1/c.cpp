#include <bits/stdc++.h>

using namespace std;


/**
 *  Min Cost Max Flow
 *
 *  Complexity: O(min(E^2 V log V, E log V F))
 *  valid for negative cost, but not for negative cycle
 *  Usage:
 *    MaxFlowMinCost<FlowType, CostType> maxflow(nodes, kMaxFlow, kLongestCost);
 *    addEdge (source, target, capacity, cost);
 *    run(source, target, kMaxFlow, kLongestCost) -><flow, flowCost>
 *    run(source, target) -><flow, flowCost>
 */

template<typename F, typename C>
struct MaxFlowMinCost {
  const static int MAX_NODES = 5010;
  const F kMaxFlow = 1000000000;
  const C kLongestCost = 1000000000;
  int nodes;

  MaxFlowMinCost(int _nodes = MAX_NODES, F _kMaxFlow = 1000000000, C _kLongestCost = 1000000000)
    : kMaxFlow(_kMaxFlow), kLongestCost(_kLongestCost), nodes(_nodes) {
  }

  C prio[MAX_NODES], pot[MAX_NODES];
  F curflow[MAX_NODES];
  int prevedge[MAX_NODES], prevnode[MAX_NODES];
  bool inqueue[MAX_NODES];

  struct Edge {
    int to;
    F f, cap;
    C cost;
    int rev;
  };

  vector<Edge> graph[MAX_NODES];

  void addEdge(int s, int t, F cap, C cost){
    Edge a = {t, 0, cap, cost, (int)graph[t].size()};
    Edge b = {s, 0, 0, -cost, (int)graph[s].size()};
    graph[s].push_back(a);
    graph[t].push_back(b);
  }

  void bellmanFord(int s, C dist[]) {
    fill(dist, dist + nodes, kLongestCost);
    dist[s] = 0;
    queue<int> que;
    que.push(s);
    while (!que.empty()) {
      int u = que.front();
      que.pop();
      inqueue[u] = false;
      for (Edge &e : graph[u]){
        if (e.cap <= e.f) continue;
        int v = e.to;
        C ndist = dist[u] + e.cost;
        if (dist[v] > ndist) {
          dist[v]= ndist;
          if(!inqueue[v]) {
            inqueue[v]=true;
            que.push(v);
          }
        }
      }
    }
  }

  pair<F, C> run(int s, int t) {
    return run(s, t, kMaxFlow, kLongestCost);
  }

  pair<F, C> run(int s, int t, F maxf, C maxc) {
    // bellmanFord can be safely commented if edges costs are non-negative
    bellmanFord(s, pot);
    F flow = 0;
    C flowCost = 0;
    while (flow < maxf){
      fill(prio, prio + nodes, kLongestCost);
      prio[s]=0;
      priority_queue<pair<C, int>, vector<pair<C, int>>, greater<pair<C, int>>> pq;
      pq.emplace(0, s);
      curflow[s] = kMaxFlow;
      while (!pq.empty()){;
        C d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if(d != prio[u])continue;
        for(int i =0; i < (int)graph[u].size(); i++){
          Edge &e = graph[u][i];
          int v = e.to;
          if(e.cap <= e.f)continue;
          C nprio = prio[u] + e.cost + pot[u] - pot[v];
          if (prio[v]> nprio) {
            prio[v] = nprio;
            pq.emplace(nprio, v);
            prevnode[v] = u;
            prevedge[v] = i;
            curflow[v] = min(curflow[u], e.cap - e.f);
          }
        }
      }
      if (prio[t] == kLongestCost) break;
      for (int i = 0; i < nodes; i++) pot[i] += prio[i];
      if (pot[t] >= maxc) break;

      F df = min(curflow[t], maxf - flow);
      flow += df;
      for (int v = t; v != s; v = prevnode[v]) {
        Edge &e = graph[prevnode[v]][prevedge[v]];
        e.f += df;
        graph[v][e.rev].f -= df;
        flowCost += df * e.cost;
      }
    }
    return make_pair(flow, flowCost);
  }
};


const int inf = 1'000'007;
const int N = 55;

char s[N][N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i)
    scanf("%s", s[i]);
  MaxFlowMinCost<int, int> g(n * m + 2);
  int source = n * m, sink = source + 1;
  auto enc = [&](int i, int j) { return i * m + j; };
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == 'o') {
        g.addEdge(source, enc(i, j), 1, 0);
      } else if (s[i][j] == '.') {
      } else if (s[i][j] == '#') {
        continue;
      }
      g.addEdge(enc(i, j), sink, 1, 0);
      if (i + 1 < n && s[i+1][j] != '#') {
        g.addEdge(enc(i, j), enc(i+1, j), inf, -1);
      }
      if (j + 1 < m && s[i][j+1] != '#') {
        g.addEdge(enc(i, j), enc(i, j+1), inf, -1);
      }
    }
  }
  auto res = g.run(source, sink);
  printf("%d\n", -res.second);
  return 0;
}
