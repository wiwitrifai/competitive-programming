/**
  IEEExtreme Programming Contest 10
  Problem : Finding Shelter
  Solver  : Luqman Arifin S
  Status  : Accepted
*/

#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e18;
const int INF = 1e9;
const int N = 505;
const double eps = 1e-8;

struct Edge {
  int from, to, cap, flow;
  double cost;
  Edge(int from, int to, int cap, int flow, double cost) :
    from(from), to(to), cap(cap), flow(flow), cost(cost) {}
};

struct MCMF {
  int n, s, t;
  vector< vector< int > > adj;
  vector< int > par;
  vector< Edge > vEdge;
  vector< double > dist;
  MCMF(int _n, int _s, int _t) : n(_n), adj(n), s(_s), t(_t) {
  }
  void addEdge(int from, int to, int cap, double cost) {
    adj[from].push_back(vEdge.size());
    adj[to].push_back(vEdge.size());
    vEdge.push_back(Edge(from, to, cap, 0, cost));
  }
  long long augment(int v, long long minflow = inf) {
    if(v == s) {
      return minflow;
    }
    if(par[v] < 0) {
      return 0;
    }
    long long flow;
    Edge &e = vEdge[par[v]];
    if(v == e.from) {
      flow = augment(e.to, min(minflow, (long long) e.flow));
      e.flow -= flow;
    }
    else {
      flow = augment(e.from, min(minflow, (long long) e.cap - e.flow));
      e.flow += flow;
    }
    return flow;
  }
  long long findingPath() {
    //dijkstra
    set< pair< double , int > > st;
    dist.assign(n, inf);
    par.assign(n, -1);
    dist[s] = 0;
    st.insert(make_pair(dist[s], s));
    while(!st.empty()) {
      auto begin = st.begin();
      int v = begin->second;
      st.erase(begin);
      for(int i = 0; i<adj[v].size(); i++) {
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
  pair< double, long long > EdmondKarp() {
    long long maxflow = 0;
    double mincost = 0;
    long long flow;
    while(flow = findingPath()) {
      maxflow += flow;
      mincost += flow * dist[t];
    }
    return make_pair(mincost, maxflow);
  }
};

struct EdgeDinic {
  int from, to, cap, flow, index;
  EdgeDinic(int from, int to, int cap, int flow, int index) :
    from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct Dinic {
  int N;
  vector<vector<EdgeDinic> > G;
  vector<EdgeDinic *> dad;
  vector<int> Q;
 
  Dinic(int N) : N(N), G(N), dad(N), Q(N) {}
 
  void AddEdgeDinic(int from, int to, int cap) {
    G[from].push_back(EdgeDinic(from, to, cap, 0, G[to].size()));
    if (from == to) G[from].back().index++;
    G[to].push_back(EdgeDinic(to, from, 0, 0, G[from].size() - 1));
  }

  long long BlockingFlow(int s, int t) {
    fill(dad.begin(), dad.end(), (EdgeDinic *) NULL);
    dad[s] = &G[0][0] - 1;
    
    int head = 0, tail = 0;
    Q[tail++] = s;
    while (head < tail) {
      int x = Q[head++];
      for (int i = 0; i < G[x].size(); i++) {
        EdgeDinic &e = G[x][i];
        if (!dad[e.to] && e.cap - e.flow > 0) {
          dad[e.to] = &G[x][i];
          Q[tail++] = e.to;
        }
      }
    }
    if (!dad[t]) return 0;

    long long totflow = 0;
    for (int i = 0; i < G[t].size(); i++) {
      EdgeDinic *start = &G[G[t][i].to][G[t][i].index];
      int amt = INF;
      for (EdgeDinic *e = start; amt && e != dad[s]; e = dad[e->from]) {
        if (!e) { amt = 0; break; }
        amt = min(amt, e->cap - e->flow);
      }
      if (amt == 0) continue;
      for (EdgeDinic *e = start; amt && e != dad[s]; e = dad[e->from]) {
        e->flow += amt;
        G[e->to][e->index].flow -= amt;
      }
      totflow += amt;
    }
    return totflow;
  }

  long long GetMaxFlow(int s, int t) {
    long long totflow = 0;
    while (long long flow = BlockingFlow(s, t))
      totflow += flow;
    return totflow;
  }
};

double a[N], b[N], p[N], q[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%lf %lf", a + i, b + i);
  for (int i = 0; i < n; i++) scanf("%lf %lf", p + i, q + i);
  vector<tuple<double, int, int>> all;
  vector<double> dist;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      double d = sqrt((a[i] - p[j])*(a[i] - p[j]) + (b[i] - q[j])*(b[i] - q[j]));
      all.emplace_back(d, i, j);
      dist.push_back(d);
    }
  }
  sort(all.begin(), all.end());
  sort(dist.begin(), dist.end());
  dist.resize(distance(dist.begin(), unique(dist.begin(), dist.end())));
  int l = 0, r = dist.size() - 1;
  while (l < r) {
    int mid = (l + r) >> 1;
    double pol = dist[mid];
    Dinic dinic(2 * n + 2);
    for (int i = 0; i < n; i++) {
      dinic.AddEdgeDinic(0, i + 1, 1);
      dinic.AddEdgeDinic(n + i + 1, 2 * n + 1, 1);
    }
    for (int i = 0; i < all.size(); i++) {
      double a; int b, c;
      tie(a, b, c) = all[i];
      if (a < pol + eps) {
        dinic.AddEdgeDinic(b + 1, n + c + 1, 1);
      }
    }
    if (dinic.GetMaxFlow(0, 2 * n + 1) == n) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  MCMF mcmf(2 * n + 2, 0, 2 * n + 1);
  for (int i = 0; i < n; i++) {
    mcmf.addEdge(0, i + 1, 1, 0);
    mcmf.addEdge(n + i + 1, 2 * n + 1, 1, 0);
  }
  double last = dist[l];
  //cout << last << endl;
  for (int i = 0; i < all.size(); i++) {
    double a; int b, c;
    tie(a, b, c) = all[i];
    if (a < last + eps) {
      mcmf.addEdge(b + 1, n + c + 1, 1, a);
    }
  }
  pair<double, long long> ret = mcmf.EdmondKarp();
  assert(ret.second == n);
  printf("%.15f\n%.15f\n", last, ret.first);
  return 0;
}
