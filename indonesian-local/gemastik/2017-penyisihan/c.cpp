/*

Apa salahku
Kau buat begini
Kau tarik ulur hatiku
Hingga sakit yang ku rasa

Apa memang ini yang kamu inginkan
Tak ada sedikitpun niat ‘tuk serius kepadaku

Katakan yang sebenarnya
Jangan mau tak mau seperti ini

Akhirnya kini aku mengerti
Apa yang ada di pikiranmu selama ini
Kau hanya ingin permainkan perasaanku
Tak ada hati tak ada cinta

Apa memang ini yang kamu inginkan
Tak ada sedikitpun niat ‘tuk serius kepadaku
Katakan yang sebenarnya
Jangan mau tak mau seperti ini

*/

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

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

const int N = 55;

int s[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int nodes = 2 * n + 52;
    Dinic dinic(nodes);
    for (int i = 1; i <= n; i++) {
      scanf("%d", s + i);
      dinic.AddEdge(0, i, s[i]);
    }
    for (int i = 1; i <= n; i++) {
      dinic.AddEdge(i, n + i, 1);
      int v;
      scanf("%d", &v);
      while (v--) {
        int c;
        scanf("%d", &c);
        dinic.AddEdge(i, 2 * n + c, 1);
      }
    }
    for (int i = 1; i <= n; i++) {
      dinic.AddEdge(n + i, nodes - 1, 1);
    }
    for (int i = 1; i <= 50; i++) {
      dinic.AddEdge(2 * n + i, nodes - 1, 1);
    }
    printf("%lld\n", dinic.GetMaxFlow(0, nodes - 1));
  }
  return 0;
}