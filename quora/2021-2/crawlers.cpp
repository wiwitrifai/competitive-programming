#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6, INF = 1e8 + 7;

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

  int find(int v) {
    for (auto & e : G[v]) {
      if (e.flow > 0) {
        --e.flow;
        if (e.to == N-2) {
          return v;
        } else {
          return find(e.to);
        }
      }
    }
    return -1;
  }

  long long GetMaxFlow(int s, int t) {
    long long totflow = 0;
    while (long long flow = BlockingFlow(s, t))
      totflow += flow;
    return totflow;
  }
};

vector<int> g[N];
set<int> dag[N];

int elem[N], scc = 0, num[N], low[N], vis[N], tmpt = 0, group[N];

bool starting[N];

vector<int> nodes;

void dfs(int v) {
  nodes.push_back(v);
  num[v] = low[v] = tmpt++;
  vis[v] = true;
  for (int u : g[v]) {
    if (num[u] == -1) {
      dfs(u);
    }
    if (vis[u]) {
      low[v] = min(low[v], low[u]);
    }
  }
  if (num[v] == low[v]) {
    elem[scc] = v;
    while (true) {
      int w = nodes.back();
      nodes.pop_back();
      group[w] = scc;
      vis[w] = false;
      if (w == v)
          break;
    }
    ++scc;
  }
}

int match[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
  }
  memset(num, -1, sizeof num);
  for (int i = 0; i < n; ++i) {
    if (num[i] == -1) {
      dfs(i);
    }
  }
  fill(starting, starting + scc, true);
  for (int v = 0; v < n; ++v) {
    for (int u : g[v]) {
      if (group[u] != group[v]) {
        dag[group[v]].insert(group[u]);
        starting[group[u]] = false;
      }
    }
  }
  Dinic mf(scc + 2);
  int source = scc, sink = source + 1;
  for (int v = 0; v < scc; ++v) {
    if (starting[v])
      mf.AddEdge(source, v, 1);
    if (dag[v].empty())
      mf.AddEdge(v, sink, 1);
    for (int u : dag[v]) {
      mf.AddEdge(v, u, scc);
    }
  }
  vector<int> bef(scc, -1);
  vector<int> aft(scc, -1);
  vector<int> din(scc, 0);
  for (int v = 0; v < scc; ++v) {
    for (int u : dag[v]) {
      ++din[u];
    }
  }
  vector<int> topo;
  iota(bef.begin(), bef.end(), 0);
  iota(aft.begin(), aft.end(), 0);
  for (int v = 0; v < scc; ++v) {
    if (din[v] == 0) {
      topo.push_back(v);
    }
  }
  for (int v : topo) {
    for (int u : g[v]) {
      --din[u];
      if (din[u] == 0)
        topo.push_back(u);
    }
  }
  for (int v : topo) {
    for (int u : dag[v]) {
      bef[u] = bef[v];
    }
  }
  for (int i = (int)topo.size()-1; i >= 0; --i) {
    int v = topo[i];
    for (int u : dag[v]) {
      aft[v] = aft[u];
    }
  }
  memset(match, -1, sizeof match);
  vector<pair<int, int>> seg;
  mf.GetMaxFlow(source, sink);
  for (auto & e : mf.G[source]) {
    if (e.flow > 0) {
      int res = mf.find(e.to);
      assert(res != -1);
      match[e.to] = res;
      match[res] = e.to;
      seg.emplace_back(e.to, res);
    }
  }
  for (int i = 0; i < scc; ++i) {
    if (dag[i].empty() && match[i] == -1) {
      seg.emplace_back(bef[i], i);
    } else if (starting[i] && match[i] == -1) {
      seg.emplace_back(i, aft[i]);
    }
  }
  sort(seg.begin(), seg.end());
  seg.erase(unique(seg.begin(), seg.end()), seg.end());
  if (seg.size() == 0) {
    puts("0");
    return 0;
  }
  if (seg.size() == 1 && seg[0].first == seg[0].second) {
    puts("0");
    return 0;
  }
  printf("%d\n", (int)seg.size());
  seg.push_back(seg[0]);
  for (int i = 0; i + 1 < (int)seg.size(); ++i) {
    printf("%d %d\n", elem[seg[i].second]+1, elem[seg[i+1].first]+1);
  }
  return 0;
}
