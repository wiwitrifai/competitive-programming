#include <bits/stdc++.h>

using namespace std;

/** Max Flow Min Cost With SPFA **/

const int maxnodes = 3024;


int nodes = maxnodes;
int prio[maxnodes], curflow[maxnodes], prevedge[maxnodes], prevnode[maxnodes], q[maxnodes];
bool inqueue[maxnodes];

           
struct Edge {
  int to, f, cap, cost, rev;
};

vector<Edge> graph[maxnodes];

void addEdge(int s,int t,int cap,int cost){
  Edge a ={t,0, cap, cost, graph[t].size()};
  Edge b ={s,0,0,-cost, graph[s].size()};
  graph[s].push_back(a);
  graph[t].push_back(b);
}

pair<int, int> minCostFlow(int s,int t,int maxf){
  // bellmanFord can be safely commented if edges costs are non-negative
  int flow =0;
  int flowCost =0;
  while(flow < maxf){
    fill(prio, prio + nodes,1000000000);
    prio[s]=0;
    curflow[s]=1000000000;
    int qt =0;
    q[qt++]= s;
    inqueue[s] = true;
    for(int qh =0; qh != qt;){
      int u = q[qh++];
      if (qh >= maxnodes) qh -= maxnodes;
      inqueue[u] = false;
      for(int i =0; i <(int) graph[u].size(); i++){
        Edge &e = graph[u][i];
        int v = e.to;
        if(e.cap <= e.f)continue;
        int nprio = prio[u]+ e.cost;
        if(prio[v]> nprio){
          prio[v]= nprio;
          if (!inqueue[v]) {
            q[qt++] = v;
            if (qt >= maxnodes) qt -= maxnodes;
            inqueue[v] = true;
          }
          prevnode[v]= u;
          prevedge[v]= i;
          curflow[v]= min(curflow[u], e.cap - e.f);
        }
      }
    }
    if(prio[t]==1000000000)break;
    int df = min(curflow[t], maxf - flow);
    flow += df;
    for(int v = t; v != s; v = prevnode[v]) {
      Edge &e = graph[prevnode[v]][prevedge[v]];
      e.f += df;
      graph[v][e.rev].f -= df;
      flowCost += df * e.cost;
    }
  }
  return make_pair(flow, flowCost);
}


/* usage example:
* addEdge (source, target, capacity, cost)
* minCostFlow(source, target, INF) -><flow, flowCost>
*/

const int N = 44;

int sr[N][N], sc[N][N];
bool ess[N][N];


int main() {
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    int n, m;
    scanf("%d %d", &n, &m);
    nodes = n * m * 2 + 2;
    for (int i = 0; i < nodes; i++)
      graph[i].clear();
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m-1; j++)
        scanf("%d", sc[i]+j);
    for (int i = 0; i < n-1; i++)
      for (int j = 0; j < m; j++)
        scanf("%d", sr[i]+j);
    int e;
    scanf("%d", &e);
    memset(ess, 0, sizeof ess);
    for (int i = 0; i < e; i++) {
      int r, c;
      scanf("%d %d", &r, &c);
      r--; c--;
      ess[r][c] = 1;
    }
    int s = nodes - 2, t = nodes-1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int now = i * m + j;
        addEdge(s, now * 2, 1, 0);
        addEdge(now * 2 + 1, t, 1, 0);
        if (!ess[i][j])
          addEdge(now * 2, now * 2 + 1, 1, 0);
        if ((i + j) & 1) {
          if (i + 1 < n) addEdge(now * 2, (now + m) * 2 + 1, 1, -sr[i][j]);
          if (j + 1 < m) addEdge((now + 1) * 2, now * 2 + 1, 1, -sc[i][j]);
        }
        else {
          if (i + 1 < n) addEdge((now + m) * 2, now * 2 + 1, 1, -sr[i][j]);
          if (j + 1 < m) addEdge(now * 2, (now + 1) * 2 + 1, 1, -sc[i][j]);
        }
      }
    }
    pair<int, int> ans = minCostFlow(s, t, n * m + 1);
    printf("Case #%d: ", tc);
    if (ans.first != n * m)
      puts("Impossible");
    else
      printf("%d\n", -ans.second);
  }
  return 0;
}