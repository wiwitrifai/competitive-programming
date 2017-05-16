#include <bits/stdc++.h>

using namespace std;
const int inf = 1e8;

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

const int N = 105, M = 2e5 + 5;
int p[N], c[N], l[N];

bool isprim[M];

int main() {
  memset(isprim, true, sizeof isprim);
  isprim[0] = isprim[1] = 0;
  for (int i = 2; i < M; i++) if (isprim[i])
    for (int j = i+i; j < M; j += i)
      isprim[j] = 0;
  int n, lim;
  scanf("%d %d", &n, &lim);
  vector< int > vl;
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", p+i, c+i, l+i);
    vl.push_back(l[i]);
  }
  sort(vl.begin(), vl.end());
  vl.erase(unique(vl.begin(), vl.end()), vl.end());
  int le = 0, ri = vl.size();
  vl.push_back(-1);
  while (le < ri) {
    int mid = (le + ri) / 2;
    int satu = -1;
    vector< int > id;
    for (int i = 0; i < n; i++) if (l[i] <= vl[mid]) {
      if (c[i] == 1) {
        if (satu == -1 || p[satu] < p[i])
          satu = i;
      }
      else
        id.push_back(i);
    }
    if (satu != -1)
      id.push_back(satu);
    Dinic maxflow(id.size() + 2);
    long long tot = 0;
    for (int i = 0; i < id.size(); i++) {
      int v = id[i];
      tot += p[v];
      if (c[v] & 1) {
        maxflow.AddEdge(id.size(), i, p[v]);
        for (int j = 0; j < id.size(); j++) if ((c[id[j]] & 1) == 0 && isprim[c[v] + c[id[j]]])
          maxflow.AddEdge(i, j, inf);
      }
      else
        maxflow.AddEdge(i, id.size() + 1, p[v]);
    }
    if (tot - maxflow.GetMaxFlow(id.size(), id.size()+1) >= lim)
      ri = mid;
    else
      le = mid + 1;
  }
  printf("%d\n", vl[le]);
  return 0;
}