#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000LL
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

const int N = 2505;

int a[N], b[N], ans[N];
vector<long long> val;
int id(long long x) {
  return lower_bound(val.begin(), val.end(), x) - val.begin();
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", a+i, b+i);
    val.push_back(a[i] + b[i]);
    val.push_back(a[i] - b[i]);
    val.push_back(a[i] * 1LL *  b[i]);
  }
  sort(val.begin(), val.end());
  val.erase(unique(val.begin(), val.end()), val.end());
  int s = n + val.size(), t = s+1;
  Dinic mf(t+1);
  for (int i = 0; i < n; i++) {
    mf.AddEdge(s, i, 1);
    mf.AddEdge(i, n+id(a[i]+b[i]), 1);
    mf.AddEdge(i, n+id(a[i]-b[i]), 1);
    mf.AddEdge(i, n+id(a[i]*1LL*b[i]), 1);
  }
  for (int i = 0; i < val.size(); i++) {
    mf.AddEdge(n+i, t, 1);
  }
  long long flow = mf.GetMaxFlow(s, t);
  if (flow != n) {
    puts("impossible");
    return 0;
  }
  memset(ans, -1, sizeof ans);
  for (int i = 0; i < n; i++) {
    for (Edge & e : mf.G[i]) {
      if (e.to >= n && e.to <= n+val.size() && e.flow) {
        ans[i] = e.to - n;
      }
    }
    if (ans[i] == -1) {
      puts("impossible");
      return 0;
    }
  }
  for (int i = 0; i < n; i++) {
    char c;
    if (a[i]+b[i] == val[ans[i]]) {
      c = '+';
    }
    else if (a[i]-b[i] == val[ans[i]]) {
      c = '-';
    }
    else 
      c = '*';
    printf("%d %c %d = %I64d\n", a[i], c, b[i], val[ans[i]]);
  }
  return 0;
}