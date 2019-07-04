#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

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
  vector<bool> vis;
 
  Dinic(int N) : N(N), G(N), dad(N), Q(N), vis(N) {}
 
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

  void Bfs(int s) {
    vis.assign(N, false);
    vis[s] = 1;
    queue<int> que;
    que.push(s);
    while (!que.empty()) {
      int v = que.front();
      que.pop();
      for (auto & e : G[v]) {
        if (e.cap - e.flow <= 0) continue;
        if (vis[e.to]) continue;
        vis[e.to] = true;
        que.push(e.to);
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

const int N = 1024;

char command[N + N];
char grid[N][N];

int main() {
  int r, c;
  scanf("%d %d", &r, &c);
  scanf("%s", command);
  for (int i = 0; i < r; ++i) {
    scanf("%s", grid[i]);
  }
  Dinic mf(r * c * 2 + 2);
  int nowr = 0, nowc = 0;
  grid[0][0] = '*';
  for (int i = 0; i < r + c - 2; ++i) {
    if (command[i] == '>')
      ++nowc;
    else
      ++nowr;
    grid[nowr][nowc] = '*';
  }
  int s = r * c * 2, t = s + 1;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      int now = i * c + j;
      if (grid[i][j] == '.') {
        mf.AddEdge(now * 2, now * 2 + 1, 1);
      }
      else if (grid[i][j] == '*') {
        mf.AddEdge(s, now * 2 + 1, inf);
        mf.AddEdge(now * 2, t, inf);
      }
      if (grid[i][j] == '#') continue;
      if (i+1 < r && grid[i+1][j] != '#') {
        if (grid[i][j] != '*' || grid[i+1][j] != '*')
          mf.AddEdge((i * c + j) * 2 + 1, ((i+1) * c + j) * 2, inf);
      }
      if (j+1 < c && grid[i][j+1] != '#') {
        if (grid[i][j] != '*' || grid[i][j+1] != '*')
          mf.AddEdge((i * c + j) * 2 + 1, (i * c + j + 1) * 2, inf);
      }
    }
  }
  long long res = mf.GetMaxFlow(s, t);
  cerr << " Minimum cells to be removed: " << res << endl;
  mf.Bfs(s);
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (grid[i][j] == '*') {
        grid[i][j] = '.';
        continue;
      }
      if (grid[i][j] == '#') continue;
      int now = i * c + j;
      if (mf.vis[now * 2] && !mf.vis[now * 2 + 1]) {
        grid[i][j] = 'x';
      }
    }
  }
  for (int i = 0; i < r; ++i)
    printf("%s\n", grid[i]);
  return 0;
}
