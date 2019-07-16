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

char g[55][55];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

int main() {
  int r, c;
  scanf("%d %d", &r, &c);
  for (int i = 0; i < r; ++i)
    scanf("%s", g[i]);
  Dinic mf(r * c + 2);
  int s = r * c, t = s + 1;
  int sum = 0;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      int cap = g[i][j] == '-' ? 2 : 1;
      sum += cap;
      if ((i+j)&1)
        mf.AddEdge(s, i * c + j, cap);
      else
        mf.AddEdge(i * c + j, t, cap);
      for (int k = 0; k < 4; ++k) {
        int x = i+dx[k], y = j+dy[k];
        if (0 > x || x >= r || 0 > y || y >= c) continue;
        if ((i+j)&1)
          mf.AddEdge(i*c+j, x*c+y, 1);
        else  
          mf.AddEdge(x*c+y, i*c+j, 1);  
      }
    }
  }
  if (sum & 1) {
    puts("N");
    return 0;
  }
  int res = mf.GetMaxFlow(s, t);
  puts(res == sum/2 ? "Y" : "N");
  return 0;
}