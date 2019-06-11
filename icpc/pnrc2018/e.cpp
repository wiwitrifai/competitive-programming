#include <bits/stdc++.h>

using namespace std;

const int inf = 1e8 + 7;

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

  void AddEdge(int from, int to, int cap, int rev = 0) {
    G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
    if (from == to) G[from].back().index++;
    G[to].push_back(Edge(to, from, rev, 0, G[from].size() - 1));
  }

  long long BlockingFlow(int s, int t) {
    fill(dad.begin(), dad.end(), (Edge *) NULL);
    dad[s] = &G[0][0] - 1;

    int head = 0, tail = 0;
    Q[tail++] = s;
    while (head < tail) {
      int x = Q[head++];
      for (int i = 0; i < (int)G[x].size(); i++) {
        Edge &e = G[x][i];
        if (!dad[e.to] && e.cap - e.flow > 0) {
          dad[e.to] = &G[x][i];
          Q[tail++] = e.to;
        }
      }
    }
    if (!dad[t]) return 0;

    long long totflow = 0;
    for (int i = 0; i < (int)G[t].size(); i++) {
      Edge *start = &G[G[t][i].to][G[t][i].index];
      int amt = inf;
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

const int N = 33;
char board[N][N];
int cost[N];

int main() {
  int n, m, c;
  scanf("%d %d %d", &n, &m, &c);
  for (int i = 0; i < m; ++i) {
    scanf("%s", board[i]);
  }
  for (int i = 0; i < c; ++i)
    scanf("%d", cost+i);
  Dinic mf(n * m * 2 + 1);
  int s = -1, t = n * m * 2;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      int now = i * n + j;
      static int dx[] = {-1, 0, 1, 0};
      static int dy[] = {0, -1, 0, 1};
      for (int k = 0; k < 4; ++k) {
        int x = i + dx[k], y = j + dy[k];
        if (x < 0 || x >= m || y < 0 || y >= n) continue;
        int nxt = x * n + y;
        mf.AddEdge(now * 2 + 1, nxt * 2, inf);
      }
      if (board[i][j] == 'B') {
        s = now * 2 + 1;
        if (i == 0 || i == m-1 || j == 0 || j == n-1) {
          puts("-1");
          return 0;
        }
      }
      else if (board[i][j] == '.') {
        mf.AddEdge(now * 2, now * 2 + 1, inf);
      }
      else {
        mf.AddEdge(now * 2, now * 2 + 1, cost[board[i][j]-'a']);
      }
    }
  }
  for (int i = 0; i < m; ++i) {
    int now = i * n;
    mf.AddEdge(now * 2 + 1, t, inf);
    now = i * n + n-1;
    mf.AddEdge(now * 2 + 1, t, inf);
  }
  for (int i = 1; i < n-1; ++i) {
    int now = i;
    mf.AddEdge(now * 2 + 1, t, inf);
    now = (m-1) * n + i;
    mf.AddEdge(now * 2 + 1, t, inf);
  }
  long long res = mf.GetMaxFlow(s, t);
  if (res >= inf)
    res = -1;
  printf("%lld\n", res);
  return 0;
}
