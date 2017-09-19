#include <bits/stdc++.h>

using namespace std;

const int INF = 1e7 + 5;

struct Edge {
  int from, to, cap, flow, index;
  Edge(int from, int to, int cap, int flow, int index) :
  from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct Dinic {
  int N;
  vector<vector<Edge> > G;
  vector<Edge *> dad;
  vector<int> Q;
 
  Dinic(int N) : N(N), G(N), dad(N), Q(N) {}
 
  void AddEdge(int from, int to, int cap) {
    G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
    if (from == to) G[from].back().index++;
    G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
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
      int amt = INF;
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

  long long GetMaxFlow(int s, int t) {
    long long totflow = 0;
    while (long long flow = BlockingFlow(s, t))
      totflow += flow;
    return totflow;
  }
};
int n, m;
int s, t;
int a[5050], b[5050];

bool can(int x, Dinic & mf) {
  for (int i = 0; i < mf.N; i++)
    for (Edge & e : mf.G[i])
      e.flow = 0;
  for (int i = 1; i <= n; i++)
    for (Edge & e : mf.G[i]) if (e.to == t)
      e.cap = x;
  long long res = mf.GetMaxFlow(s, t);
  // cerr << x << " " << res << endl;
  return (res == m);
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++)
    scanf("%d %d", a+i, b+i); 
  s = 0, t = n + m + 1;
  Dinic mf(t+1);
  for (int i = 1; i <= n; i++) {
    mf.AddEdge(i, t, 1);
  }
  for (int i = 1; i <= m; i++) {
    mf.AddEdge(s, i+n, 1);
    mf.AddEdge(i+n, a[i], 1);
    mf.AddEdge(i+n, b[i], 1);
  }
  int l = 0, r = m;
  while (l < r) {
    int mid = (l + r)/ 2;
    if (can(mid, mf))
      r = mid;
    else
      l = mid + 1;
  }
  assert(can(l, mf));
  printf("%d\n", l);
  for (int i = 1; i <= m; i++) {
    int selected = a[i];
    for (Edge e : mf.G[i+n]) {
      if (e.to >= 1 && e.to <= n && e.flow)
        selected = e.to;
    }
    if (selected != a[i])
      swap(a[i], b[i]);
    printf("%d %d\n", a[i], b[i]);
  }
  return 0;
}