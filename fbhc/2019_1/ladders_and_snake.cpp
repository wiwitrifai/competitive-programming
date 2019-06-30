#include <bits/stdc++.h>

using namespace std;

const int N = 55, H = 1e5 + 5, inf = 1e9 + 7;
int n, h;
vector<tuple<int, int, int>> ladders;

void read_input() {
  scanf("%d %d", &n, &h);
  assert(1 <= h && h <= int(1e5));
  assert(1 <= n && n <= 50);
  ladders.resize(n);
  for (int i = 0; i < n; ++i) {
    int x, a, b;
    scanf("%d %d %d", &x, &a, &b);
    assert(a < b);
    ladders[i] = {x, a, b};
  }
}

int g[N][N];
int last[H];

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
 
  void AddEdge(int from, int to, int cap, int rev) {
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

void solve() {
  sort(ladders.begin(), ladders.end());
  fill(last, last+h, -1);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      g[i][j] = 0;
  for (int i = 0; i < n; ++i) {
    int x, a, b;
    tie(x, a, b) = ladders[i];
    for (int j = a; j < b; ++j) {
      if (last[j] != -1) {
        ++g[last[j]][i];
      }
      last[j] = i;
    }
  }
  int s = n, t = n+1;
  Dinic mf(n+2);
  for (int i = 0; i < n; ++i) {
    int x, a, b;
    tie(x, a, b) = ladders[i];
    if (a == 0)
      mf.AddEdge(s, i, inf, 0);
    if (b == h)
      mf.AddEdge(i, t, inf, 0);
    for (int j = 0; j < n; ++j) {
      if (g[i][j] == 0) continue;
      mf.AddEdge(i, j, g[i][j], g[i][j]);
    }
  }
  long long res = mf.GetMaxFlow(s, t);
  if (res >= inf)
    res = -1;
  printf("%lld\n", res);
}

int main(int argc, char * argv[]) {
  clock_t starttime = clock();
  int seed = time(0);
  if (argc >= 2) {
    seed = atoi(argv[1]);
  }
  cerr << "random seed\t= " << seed << endl;
  srand(seed);

  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; ++tc) {
    printf("Case #%d: ", tc);
    read_input();
    solve();
    fflush(stdout);
    cerr << "~ TC#" << tc << " done! execution time : " <<
      (double)(clock() - starttime) / CLOCKS_PER_SEC << " s " << endl;
  }
  return 0;
}
