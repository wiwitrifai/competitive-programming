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

const int N = 606;

int deg[N];
int ans[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    Dinic mf(n + m + 2);
    int s = n + m, t = s + 1;
    fill(deg, deg+n, 0);
    for (int i = 0; i < m; ++i) {
      int u, v;
      scanf("%d %d", &u, &v);
      --u, --v;
      ++deg[u];
      ++deg[v];
      mf.AddEdge(u, i+n, 1);
      mf.AddEdge(v, i+n, 1);
      mf.AddEdge(i+n, t, 1);
    }
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      int hapus = max(deg[i] - k, 0);
      mf.AddEdge(s, i, hapus * 2);
      sum += hapus * 2;
    }
    long long res = mf.GetMaxFlow(s, t);
    fill(ans, ans+m, 0);
    if (res == sum) {
      vector<pair<int, int> > mp;
      for (int i = 0; i < n; ++i) {
        for (auto & e : mf.G[i]) {
          if (e.to < n || e.to >= n+m) continue;
          if (e.flow == 0) continue;
          mp.emplace_back(i, e.to - n);
        }
      }
      sort(mp.begin(), mp.end());
      mp.erase(unique(mp.begin(), mp.end()), mp.end());
      assert((mp.size() & 1) == 0);
      int cnt = 0;
      for (int i = 0; i < mp.size(); i += 2) {
        assert(mp[i].first == mp[i+1].first);
        ++cnt;
        ans[mp[i].second] = cnt;
        ans[mp[i+1].second] = cnt;
      }
      for (int i = 0; i < m; ++i)
        if (ans[i] == 0)
          ans[i] = ++cnt;
    }
    for (int i = 0; i < m; ++i)
      printf("%d%c", ans[i], i == m-1 ? '\n' : ' ');
  }
  return 0;
}