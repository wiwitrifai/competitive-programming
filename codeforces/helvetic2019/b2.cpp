#include <bits/stdc++.h>

using namespace std;

const int N = 1024, inf = 1e9;

int dist[N][N];
struct Ship {
  int x, a, f;
} ships[N];

vector<pair<int, int>> bases[N];

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

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j)
      dist[i][j] = inf;
    dist[i][i] = 0;
  }
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    dist[u][v] = dist[v][u] = min(dist[u][v], 1);
  }
  for (int k = 1; k <= n; ++k)
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
  int s, b, k, h;
  scanf("%d %d %d %d", &s, &b, &k, &h);
  for (int i = 0; i < s; ++i) {
    int x, a, f;
    scanf("%d %d %d", &x, &a, &f);
    ships[i] = {x, a, f};
  }
  for (int i = 0; i < b; ++i) {
    int x, d;
    scanf("%d %d", &x, &d);
    bases[x].emplace_back(d, i+s);
  }
  Dinic mf(s + b + 2);
  int st = s + b, en = st + 1;
  for (int i = 1; i <= n; ++i) {
    sort(bases[i].begin(), bases[i].end());
    for (int j = 0; j < (int)bases[i].size(); ++j) {
      mf.AddEdge(bases[i][j].second, en, 1);
      if (j) {
        mf.AddEdge(bases[i][j].second, bases[i][j-1].second, inf);
      }
    }
  }
  for (int i = 0; i < s; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (dist[ships[i].x][j] > ships[i].f) continue;
      int id = lower_bound(bases[j].begin(), bases[j].end(), make_pair(ships[i].a+1, -1)) - bases[j].begin();
      if (id) {
        mf.AddEdge(i, bases[j][id-1].second, 1);
      }
    }
    mf.AddEdge(st, i, 1);
  }
  int res = mf.GetMaxFlow(st, en);
  long long ans = 1LL * res * k;
  for (int i = 1; i <= s; ++i) {
    int sisa = min(res, s-i);
    ans = min(1LL * i * h + 1LL * sisa * k, ans);
  }
  printf("%lld\n", ans);
  return 0;
}
