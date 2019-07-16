#include <bits/stdc++.h>

using namespace std;

const int maxnodes = 4010;

int nodes = maxnodes;
int prio[maxnodes], curflow[maxnodes], prevedge[maxnodes], prevnode[maxnodes], q[maxnodes], pot[maxnodes];
bool inqueue[maxnodes];

const int inf = 1e9;
struct Edge {
  int to, f, cap, cost, rev;
};

vector<Edge> graph[maxnodes];

void addEdge(int s, int t, int cap, int cost) {
  Edge a = {t, 0, cap, cost, (int)graph[t].size()};
  Edge b = {s, 0, 0, -cost, (int)graph[s].size()};
  graph[s].push_back(a);
  graph[t].push_back(b);
}

void bellmanFord(int s, int dist[]) {
  fill(dist, dist+nodes, inf);
  dist[s] = 0;
  int qt = 0;
  q[qt++] = s;
  for (int qh = 0; (qh-qt)% nodes != 0; ++qh) {
    int u = q[qh % nodes];
    inqueue[u] = false;
    for (int i = 0; i < (int)graph[u].size(); ++i) {
      Edge & e = graph[u][i];
      if (e.cap <= e.f) continue;
      int v = e.to;
      int ndist = dist[u] +e.cost;
      if (dist[v] > ndist) {
        dist[v] = ndist;
        if (!inqueue[v]) {
          inqueue[v] = true;
          q[qt++%nodes] = v;
        }
      }
    }
  }
}

pair<int,int> minCostFlow(int s, int t) {
  //~ bellmanFord(s, pot);
  int flow = 0;
  int flowCost = 0;
  while (1) {
    queue<int> q;
    q.push(s);
    fill(prio, prio+nodes, inf);
    fill(inqueue, inqueue+nodes, 0); 
    prio[s] = 0;
    inqueue[s] = 1;
    curflow[s] = inf;
    while (!q.empty()) {
      int u = q.front(); q.pop(); inqueue[u] = 0;
      for (int i = 0; i < (int)graph[u].size(); ++i) {
        Edge & e = graph[u][i];
        int v = e.to;
        if (e.cap <= e.f) continue;
        int nprio = prio[u] + e.cost;
        if (prio[v] > nprio) {
          prio[v] = nprio;
          prevnode[v] = u;
          prevedge[v] = i;
          curflow[v] = min(curflow[u], e.cap - e.f);
          if (!inqueue[v]) {
            q.push(v);
            inqueue[v] = 1;
          }
        }
      }
    }    
    if (prio[t] == inf) break;
    int df = curflow[t];
    int newCost = 0;
    for (int v = t; v != s; v = prevnode[v]) {
      Edge & e = graph[prevnode[v]][prevedge[v]];
      e.f += df;
      graph[v][e.rev].f -= df;
      newCost += df * e.cost;
    }
    if (newCost >= 0) break;
    flowCost += newCost;
    flow += df;
  }
  return make_pair(flow, flowCost);
}

const int N = 1e3 + 5;
pair<int, int> c[N], w[N], ori;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i)
    scanf("%d %d", &w[i].first, & w[i].second);
  for (int i = 0; i < m; ++i)
    scanf("%d %d", &c[i].first, & c[i].second);
  scanf("%d %d", &ori.first, & ori.second);
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += abs(ori.first - w[i].first) + abs(ori.second - w[i].second);
  }
  ans *= 2;
  nodes = n + m + 2;
  int s = n + m, t = s + 1;
  int mi = inf;
  for (int i = 0; i < n; ++i) {
    addEdge(s, i, 1, 0);
    int bef = abs(ori.first - w[i].first) + abs(ori.second - w[i].second);
    for (int j = 0; j < m; ++j) {
      int now = abs(w[i].first - c[j].first) + abs(w[i].second - c[j].second);
      mi = min(mi, now - bef);
      if (now < bef)
        addEdge(i, j+n, 1, now-bef);
    }
  }
  for (int i = 0; i < m; ++i)
    addEdge(i+n, t, 1, 0); 
  pair<int, int> res = minCostFlow(s, t);
  if (res.first > 0)
    mi = min(mi, res.second);
  printf("%lld\n", ans + mi);
  return 0;
}
