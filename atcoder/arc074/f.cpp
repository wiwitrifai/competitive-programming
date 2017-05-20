#include <bits/stdc++.h>

using namespace std;

const int INF = 1e7;

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

const int N = 111;

char ss[N][N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", ss[i]);
  }
  int s = n * m * 2 + n + m, t = s + 1;
  Dinic mf(t+1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int cur = i * m + j;
      if (ss[i][j] == 'S')
        mf.AddEdge(s, cur * 2 + 1, INF);
      if (ss[i][j] == 'T')
        mf.AddEdge(cur * 2, t, INF);
      if (ss[i][j] != '.') {
        mf.AddEdge(cur * 2, cur * 2 + 1, 1);
        mf.AddEdge(cur * 2 + 1, n * m * 2 + i, INF);
        mf.AddEdge(n * m * 2 + i, cur * 2,  INF);
        mf.AddEdge(cur * 2 + 1, n * m * 2 + n + j, INF);
        mf.AddEdge(n * m * 2 + n + j, cur * 2,  INF);
      }
    }
  }
  long long res = mf.GetMaxFlow(s, t);
  if (res >= INF) res = -1;
  cout << res << endl;
  return 0;
}