#include <bits/stdc++.h>

using namespace std;

const int inf = 1e8;

struct Edge {
  int from, to, cap, flow, cost;
  Edge(int from, int to, int cap, int flow, int cost) :
    from(from), to(to), cap(cap), flow(flow), cost(cost) {}
  
};

struct MCMF {
  int n, s, t;
  vector<vector<int>> adj;
  vector<int> par;
  vector<Edge> vEdge;
  vector<long long> dist;

  MCMF(int _n, int _s, int _t) : n(_n), adj(n), s(_s), t(_t) {
  }

  void addEdge(int from, int to, int cap, int cost) {
    adj[from].push_back(vEdge.size());
    adj[to].push_back(vEdge.size());
    vEdge.push_back(Edge(from, to, cap, 0, cost));
  }

  long long augment(int v, int minflow = inf) {
    if (v == s) return minflow;
    if (par[v] < 0) return 0;
    long long flow;
    Edge& e = vEdge[par[v]];
    if (v == e.from) {
      flow = augment(e.to, min(minflow, e.flow));
      e.flow -= flow;
    } else {
      flow = augment(e.from, min(minflow, e.cap - e.flow));
      e.flow += flow;
    }
    return flow;
  }

  long long findingPath() {
    queue<pair<int, int>> st;
    dist.assign(n, inf);
    par.assign(n, -1);
    dist[s] = 0;
    st.emplace(dist[s], s);
    while (!st.empty()) {
      int v = st.front().second;
      st.pop();
      for (int i = 0; i < adj[v].size(); i++) {
        Edge &e = vEdge[adj[v][i]];
        if (e.from == v) {
          if (e.cap > e.flow && dist[e.to] == inf) {
            dist[e.to] = dist[v] + e.cost;
            st.emplace(dist[e.to], e.to);
            par[e.to] = adj[v][i];
          }
        } else {
          if (e.flow > 0 && dist[e.from] == inf) {
            dist[e.from] = dist[v] - e.cost;
            st.emplace(dist[e.from], e.from);
            par[e.from] = adj[v][i];
          }
        }
      }
    }
    return augment(t, inf);
  }

  pair<int, int> EdmondKarp() {
    long long maxflow = 0, mincost = 0;
    long long flow;
    while (flow = findingPath()) {
      maxflow += flow;
      mincost += flow * dist[t];
    }
    return make_pair(mincost, maxflow);
  }

};

vector<int> can[505];
int n, m, rust, t, k;

MCMF get_maxflow(int pol) {
  MCMF mcmf(n + m + 2, 0, n + m + 1);
  for (int i = 0; i < n; i++) {
    mcmf.addEdge(0, i + 1, pol, 1);
    for (auto it : can[i]) {
      mcmf.addEdge(i + 1, n + 1 + it, 1, 1);
    }
  }
  for (int i = 0; i < m; i++) {
    mcmf.addEdge(n + 1 + i, n + m + 1, 1, 1);
  }
  return mcmf;
}

int done[505];

int main() {
  freopen("contest.in", "r", stdin);
  freopen("contest.out", "w", stdout);
  scanf("%d %d %d %d %d", &n, &m, &rust, &t, &k);
  for (int i = 0; i < k; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--;
    v--;
    can[u].push_back(v);
  }
  int solved = get_maxflow(t / rust).EdmondKarp().second;
  int l = 0, r = solved;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (get_maxflow(mid).EdmondKarp().second == solved) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  long long penalty = 0;
  MCMF mcmf = get_maxflow(l);
  mcmf.EdmondKarp();
  for (Edge it : mcmf.vEdge) {
    if (it.from <= n && n < it.to && it.flow == 1) {
      done[it.from]++;
      penalty += 1LL * done[it.from] * rust;
    }
  }
  memset(done, 0, sizeof(done));
  printf("%d %lld\n", solved, penalty);
  for (Edge it : mcmf.vEdge) {
    //printf("debug %d %d %d\n", it.from, it.to, it.flow);
    if (it.from <= n && n < it.to && it.flow == 1) {
      printf("%d %d %d\n", it.from, it.to - n, done[it.from] * rust);
      done[it.from]++;
    }
  }

  return 0;
}