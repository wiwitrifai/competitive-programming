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
  vector< vector< int > > adj;
  vector< int > par;
  vector< Edge > vEdge;
  vector< long long > dist;
  MCMF(int _n, int _s, int _t) : n(_n), s(_s), t(_t) {
    adj.resize(n);
  }
  void addEdge(int from, int to, int cap, int cost) {
    adj[from].push_back(vEdge.size());
    adj[to].push_back(vEdge.size());
    vEdge.push_back(Edge(from, to, cap, 0, cost));
  }
  long long augment(int v, int minflow = inf) {
    if(v == s) {
      return minflow;
    }
    if(par[v] < 0) {
      return 0;
    }
    long long flow;
    Edge &e = vEdge[par[v]];
    if(v == e.from) {
      flow = augment(e.to, min(minflow, e.flow));
      e.flow -= flow;
    }
    else {
      flow = augment(e.from, min(minflow, e.cap - e.flow));
      e.flow += flow;
    }
    return flow;
  }
  long long findingPath() {
    //dijkstra
    set< pair< long long , int > > st;
    dist.assign(n, inf);
    par.assign(n, -1);
    dist[s] = 0;
    st.insert(make_pair(dist[s], s));
    while(!st.empty()) {
      set< pair< long long, int > >::iterator begin = st.begin();
      int v = begin->second;
      st.erase(begin);
      for(int i = 0; i<(int)adj[v].size(); i++) {
        Edge &e = vEdge[adj[v][i]];
        if(e.from == v) {
          if(e.cap > e.flow && dist[e.to] > dist[v] + e.cost) {
            st.erase(make_pair(dist[e.to], e.to));
            dist[e.to] = dist[v] + e.cost;
            st.insert(make_pair(dist[e.to], e.to));
            par[e.to] = adj[v][i];
          }
        }
        else {
          if(e.flow > 0 && dist[e.from] > dist[v] - e.cost) {
            st.erase(make_pair(dist[e.from], e.from));
            dist[e.from] = dist[v] - e.cost;
            st.insert(make_pair(dist[e.from], e.from));
            par[e.from] = adj[v][i];
          }
        }
      }
    }
    return augment(t, inf);
  }
  pair< long long, long long > EdmondKarp() {
    long long maxflow = 0, mincost = 0;
    long long flow;
    while(flow = findingPath()) {
      maxflow += flow;
      mincost += flow * dist[t];
    }
    return make_pair(mincost, maxflow);
  }
};

int cnt[55];

int main() {
  int n, m, k, c, d;
  scanf("%d %d %d %d %d", &n, &m, &k, &c, &d);
  int w = n + k;
  int nodes = n * w + 2, s = nodes - 2, t = nodes - 1;
  MCMF mf(nodes, s, t);
  for (int i = 0; i < k; ++i) {
    int u;
    scanf("%d", &u);
    --u;
    ++cnt[u];
  }
  for (int i = 0; i < n; ++i) {
    if (cnt[i] > 0) {
      mf.addEdge(s, i * w, cnt[i], 0);
    }
    for (int x = 0; x + 1 < w; ++x)
      mf.addEdge(i * w + x, i * w + x + 1, k, 0);
  }
  for (int j = 0; j < w; ++j)
    mf.addEdge(0 * w + j, t, k, c * j);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    for (int x = 0; x + 1 < w; ++x) {
      for (int z = 0; z < k; ++z) {
        mf.addEdge(u * w + x, v * w + x + 1, 1, d * (2 * z + 1));
        mf.addEdge(v * w + x, u * w + x + 1, 1, d * (2 * z + 1));
      }
    }
  }
  auto res = mf.EdmondKarp();
  printf("%lld\n", res.first);
  return 0;
}
