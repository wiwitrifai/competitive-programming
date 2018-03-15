#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e16 + 7, MUL = 1e10;

struct Edge {
  int from, to, index, no;
  long long cap, flow, water;
  Edge(int from, int to, long long cap, long long flow, int index, int no) :
    from(from), to(to), cap(cap), flow(flow), index(index), no(no), water(0) {}
};

struct Dinic {
  int N;
  vector<vector<Edge> > G;
  vector<Edge *> dad;
  vector<int> Q;
  vector<long long> val;
  vector<bool> inside;
 
  Dinic(int N) : N(N), G(N), dad(N), Q(N), val(N), inside(N) {}

  void reset() {
    for (int i = 0; i < N; ++i)
      for (Edge & e : G[i])
        e.flow = e.water = 0;
  }
 
  void AddEdge(int from, int to, long long cap, int no) {
    G[from].push_back(Edge(from, to, cap, 0, G[to].size(), no));
    if (from == to) G[from].back().index++;
    G[to].push_back(Edge(to, from, cap, 0, G[from].size() - 1, -no));
  }

  long long BlockingFlow(int s, int t) {
    fill(dad.begin(), dad.end(), (Edge *) NULL);
    dad[s] = &G[0][0] - 1;
    
    int head = 0, tail = 0;
    Q[tail++] = s;
    while (head < tail) {
      int x = Q[head++];
      for (int i = 0; i < G[x].size(); i++) {
    Edge &e = G[x][i];
    if (!dad[e.to] && e.cap - e.flow > 0) {
      dad[e.to] = &G[x][i];
      Q[tail++] = e.to;
    }
      }
    }
    if (!dad[t]) return 0;

    long long totflow = 0;
    for (int i = 0; i < G[t].size(); i++) {
      Edge *start = &G[G[t][i].to][G[t][i].index];
      long long amt = INF;
      for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
    if (!e) { amt = 0; break; }
    amt = min(amt, e->cap - e->flow);
      }
      if (amt == 0) continue;
      for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
    e->flow += amt;
    G[e->to][e->index].flow -= amt;
      }
      totflow += amt;
    }
    return totflow;
  }

  void solve() {
    long long awal = 0;
    for (Edge & e : G[0])
      if (e.to == 2)
        awal = e.flow;
    val.assign(N, 0);
    val[2] = awal;
    queue<int> que;
    que.push(2);
    inside[2] = 1;
    while (!que.empty()) {
      int v = que.front(); que.pop();
      inside[v] = 0;
      if (val[v] == 0) continue;
      for (Edge & e : G[v]) {
        if (e.flow > 0) {
          long long add = min(val[v], e.flow);
          e.water += add;
          e.flow -= add;
          G[e.to][e.index].flow += add;
          G[e.to][e.index].water -= add;
          val[v] -= add;
          val[e.to] += add;
          if (!inside[e.to]) {
            inside[e.to] = 1;
            que.push(e.to);
          }
        }
      }
    }
  }

  long long GetMaxFlow(int s, int t) {
    long long totflow = 0;
    while (long long flow = BlockingFlow(s, t))
      totflow += flow;
    return totflow;
  }
};

const int N = 5e4;
long long flubber[N], water[N];

int main() {
  int n, p;
  double v, a;
  scanf("%d %d %lf %lf", &n, &p, &v, &a);
  // a *= MUL;
  Dinic mf(n+1);
  for (int i = 0; i < p; ++i) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    mf.AddEdge(u, v, w * MUL , i+1);
  }
  mf.AddEdge(0, 1, INF, p+2);
  mf.AddEdge(0, 2, INF, p+1);
  mf.G[0][0].cap = mf.G[1][mf.G[0][0].index].cap = INF;
  mf.G[0][1].cap = mf.G[2][mf.G[0][1].index].cap = 0;
  mf.reset();
  long long flow1 = mf.GetMaxFlow(0, 3); 
  mf.G[0][0].cap = mf.G[1][mf.G[0][0].index].cap = 0;
  mf.G[0][1].cap = mf.G[2][mf.G[0][1].index].cap = INF;
  mf.reset();
  long long flow2 = mf.GetMaxFlow(0, 3);
  mf.G[0][0].cap = mf.G[1][mf.G[0][0].index].cap = INF;
  mf.G[0][1].cap = mf.G[2][mf.G[0][1].index].cap = INF;
  mf.reset();
  long long combine = mf.GetMaxFlow(0, 3);
  long long optimal = combine * a;
  optimal = max(min(optimal, flow1), combine - flow2);
  mf.G[0][0].cap = mf.G[1][mf.G[0][0].index].cap = optimal;
  mf.G[0][1].cap = mf.G[2][mf.G[0][1].index].cap = combine - optimal;
  mf.reset();
  mf.GetMaxFlow(0, 3);
  mf.solve();
  memset(water, 0, sizeof water);
  memset(flubber, 0, sizeof flubber);
  for (int i = 1; i <= n; ++i) {
    for (auto & e : mf.G[i]) if (e.no > 0) {
      water[e.no] += e.water;
      flubber[e.no] += e.flow;
    }
  }
  for (int i = 1; i <= p; ++i) {
    printf("%.10lf %.10lf\n", (double)flubber[i]/MUL/v, (double)water[i]/MUL);
  }
  double le = (double)optimal/MUL/v, ri = (double)(combine - optimal)/MUL;
  double val = pow(le, a) * pow(ri, 1-a);
  printf("%.10lf\n", val);
  return 0;
}