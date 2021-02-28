#include <bits/stdc++.h>

using namespace std;

/** Min Cost Max Flow **/
/* complexity: O(min(E^2 V log V, E log V F)) */
/* Valid for negative cost, but not for negative cycle */

template<typename F, typename C>
struct MaxFlowMinCost {
  const static int MAX_NODES = 5010;
  const F kMaxFlow = 1000000000LL;
  const C kLongestCost = 1000000000LL;
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

  void addEdge(int s, int t, F cap, C cost) {
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

/* usage example:
 * addEdge (source, target, capacity, cost)
 * run(source, target, INF) -><flow, flowCost>
 */


int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  MaxFlowMinCost<int, long long> mf(n + m + 2, 1e9, 1e18);
  int source = n + m, sink = source + 1;
  vector<long long> cost(m);
  for (int i = 0; i < m; ++i) {
    long long cur = 1;
    for (int j = 0; j < 7; ++j)
      cur *= (i+1);
    cost[i] = cur;
  }
  for (int i = m-1; i > 0; --i)
    cost[i] -= cost[i-1];
  for (int i = 0; i < m; ++i) {
    mf.addEdge(source, i, 1, 0);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j)
      mf.addEdge(m+i, sink, 1, cost[j]);
  }
  for (int i = 0; i < m; ++i) {
    int l, r;
    scanf("%d %d", &l, &r);
    --l;
    for (int j = l; j < r; ++j) {
      mf.addEdge(i, m+j, 1, 0);
    }
  }
  auto res = mf.run(source, sink);
  printf("%lld\n", res.second);
  for (int i = 0; i < m; ++i) {
    int ans = -1;
    for (auto & e : mf.graph[i]) {
      if (e.to < m || e.to >= n + m || e.f <= 0) continue;
      ans = e.to-m + 1;
    }
    printf("%d%c", ans, i+1 == m ? '\n' : ' ');
  }
  return 0;
}
