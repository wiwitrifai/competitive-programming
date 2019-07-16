#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e12;

struct Edge {
  int from, to, index;
  long long cap, flow;
  Edge(int from, int to, long long cap, long long flow, int index) :
  from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct Dinic {
  int N;
  vector<vector<Edge> > G;
  vector<Edge *> dad;
  vector<int> Q;
 
  Dinic(int N) : N(N), G(N), dad(N), Q(N) {}
 
  void AddEdge(int from, int to, long long cap) {
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
      long long amt = inf;
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

const int N = 155;

int a[N][N];
int d[N][N];

int main() {
  int n, m, sr, sc;
  scanf("%d %d %d %d", &n, &m, &sr, &sc);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j)
      scanf("%d", a[i]+j);
  }
  queue<pair<int, int> > que;
  que.push(make_pair(sr-1, sc-1));
  memset(d, -1, sizeof d);
  while (!que.empty()) {
    int x = que.front().first, y = que.front().second;
    que.pop();
    for (int i = -1; i < 2; ++i) {
      for (int j = -1; j < 2; ++j) {
        if (!i && !j) continue;
        int xx = x + i, yy = y + j;
        if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
        if (d[xx][yy] != -1) continue;
        d[xx][yy] = d[x][y] + 1;
      }
    }
  }
  Dinic mf(n * m * 2 + 2);
  int s = n * m * 2, t = s + 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int cur = i * m +j;
      cur *= 2;
      if (a[i][j] == -1) {
        mf.AddEdge(s, cur + 1, inf);
      }
      else {
        if (i == 0 || i == n-1 || j == 0 || j ==  m-1)
          mf.AddEdge(cur + 1, t, inf);
        mf.AddEdge(cur, cur + 1, a[i][j]);
      }
      for (int k = -1; k < 2; ++k) {
        for (int l = -1; l < 2; ++l) {
          int x = i + k, y = j + l;
          if (!k && !l) continue;
          if (x < 0 || x >= n || y < 0 || y >= m) continue;
          mf.AddEdge(cur+1, (x * m + y) * 2, inf);
        }
      }
    }
  }
  long long ans = mf.GetMaxFlow(s, t);
  printf("%lld\n", ans);
  return 0;
}
