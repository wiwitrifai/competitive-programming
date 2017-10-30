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

const int N = 202, C = 26;

char s[N];
int b[N], n;

int main() {
  scanf("%d", &n);
  scanf("%s", s);
  for (int i = 0; i < n; i++)
    scanf("%d", b+i);
  int m = n/2;
  nodes = 2 + n + 26 * m + m;
  int st = nodes-2, t = nodes-1;
  for (int i = 0; i < n; i++) {
    addEdge(st, i, 1, 0);
    for (int j = 0; j < n; j++) {
      int nopair = min(j, n-1-j);
      addEdge(i, n + nopair * 26 + s[i]-'a', 1, (i == j) ? -b[i] : 0);
    }
  }
  for (int i = 0; i < m; i++) {
    for (int c = 0; c < 26; c++)
      addEdge(n + i * 26 + c, n + m * 26 + i, 1, 0);
    addEdge(n + m * 26 + i, t, 2, 0);
  }
  cout << -minCostFlow(st, t, n).second << endl;
}