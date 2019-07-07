#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9 + 7;
const long long infll = 1e18;

struct Edge {
  int from, to, index;
  long long cap, flow;
  Edge(int from, int to, long long cap, long long flow, int index) :
  from(from), to(to), index(index), cap(cap), flow(flow) {}
};

struct Dinic {
  int N;
  vector<vector<Edge> > G;
  vector<Edge *> dad;
  vector<int> Q;

  Dinic(int N) : N(N), G(N), dad(N), Q(N) {}

  void AddEdge(int from, int to, long long cap) {
    G[from].push_back(Edge(from, to, cap, 0LL, G[to].size()));
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
      long long amt = infll;
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

const int N = 1e5 + 5;

int dist[111][111];
struct Ship {
  int x, a, f, p;
} ships[N];

int best[111];
int num[N];

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
  int s, b, k;
  scanf("%d %d %d", &s, &b, &k);
  vector<pair<int, int>> spaces(s);
  for (int i = 0; i < s; ++i) {
    int x, a, f, p;
    scanf("%d %d %d %d", &x, &a, &f, &p);
    ships[i] = {x, a, f, p};
    spaces[i] = make_pair(a, i);
  }
  vector<tuple<int, int, int>> bases(b);
  for (int i = 0; i < b; ++i) {
    int x, d, g;
    scanf("%d %d %d", &x, &d, &g);
    bases[i] = make_tuple(d, x, g);
  }
  sort(spaces.begin(), spaces.end());
  sort(bases.begin(), bases.end());
  memset(best, -1, sizeof best);
  for (int i = 0, j = 0; i < s; ++i) {
    int now = spaces[i].second;
    while (j < (int)bases.size() && get<0>(bases[j]) <= spaces[i].first) {
      int x, g;
      tie(ignore, x, g) = bases[j];
      ++j;
      best[x] = max(best[x], g);
    }
    int cur = -1;
    for (int j = 1; j <= n; ++j) {
      if (dist[ships[now].x][j] > ships[now].f) continue;
      cur = max(cur, best[j]);
    }
    if (cur < 0)
      ships[now].p = -inf;
    else
      ships[now].p = cur - ships[now].p;
  }
  vector<pair<int, int>> cons(k);
  vector<int> nodes;
  for (int i = 0; i < k; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    cons[i] = make_pair(u, v);
    nodes.push_back(u);
    nodes.push_back(v);
  }
  sort(nodes.begin(), nodes.end());
  nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());
  Dinic mf((int)nodes.size() + 2);
  int st = nodes.size(), en = st + 1;
  long long tot = 0;
  for (int i = 0; i < s; ++i) {
    if (ships[i].p > 0) {
      tot += ships[i].p;
    }
    int v = lower_bound(nodes.begin(), nodes.end(), i) - nodes.begin();
    if (v == (int)nodes.size() || nodes[v] != i)
      continue;
    if (ships[i].p > 0) {
      mf.AddEdge(st, v, ships[i].p);
    }
    else if (ships[i].p <= -inf) {
      mf.AddEdge(v, en, infll);
    }
    else {
      mf.AddEdge(v, en, -ships[i].p);
    }
  }
  for (auto it : cons) {
    int u = it.first, v = it.second;
    u = lower_bound(nodes.begin(), nodes.end(), u) - nodes.begin();
    v = lower_bound(nodes.begin(), nodes.end(), v) - nodes.begin();
    mf.AddEdge(u, v, inf);
  }
  tot -= mf.GetMaxFlow(st, en);
  printf("%lld\n", tot);
  return 0;
}
