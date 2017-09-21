#include <bits/stdc++.h>

using namespace std;

/** Max Flow Min Cost **/
/* complexity: O(min(E^2 V log V, E log V F)) */
const int maxnodes = 2010;


int nodes = maxnodes;
int prio[maxnodes], curflow[maxnodes], prevedge[maxnodes], prevnode[maxnodes], q[maxnodes], pot[maxnodes];
bool inqueue[maxnodes];

           
struct Edge {
  int to, f, cap, cost, rev;
};

vector<Edge> graph[maxnodes];

void addEdge(int s,int t,int cap,int cost){
  Edge a ={t,0, cap, cost, (int)graph[t].size()};
  Edge b ={s,0,0,-cost, (int)graph[s].size()};
  graph[s].push_back(a);
  graph[t].push_back(b);
}


void bellmanFord(int s,int dist[]){
  fill(dist, dist + nodes,1000000000);
  dist[s]=0;
  int qt =0;
  q[qt++]= s;
  for(int qh =0;(qh - qt)% nodes !=0; qh++){
    int u = q[qh % nodes];
    inqueue[u]=false;
    for(int i =0; i <(int) graph[u].size(); i++){
      Edge &e = graph[u][i];
      if(e.cap <= e.f)continue;
      int v = e.to;
      int ndist = dist[u]+ e.cost;
      if(dist[v]> ndist){
        dist[v]= ndist;
        if(!inqueue[v]){
          inqueue[v]=true;
          q[qt++% nodes]= v;
        }
      }
    }
  }
}


pair<int, int> minCostFlow(int s,int t,int maxf){
  // bellmanFord can be safely commented if edges costs are non-negative
  bellmanFord(s, pot);
  int flow =0;
  int flowCost =0;
  while(flow < maxf){
    priority_queue<long long , vector<long long >, greater<long long >> q;
    q.push(s);
    fill(prio, prio + nodes,1000000000);
    prio[s]=0;
    curflow[s]=1000000000;
    while(!q.empty()){
      long long  cur = q.top();
      int d = cur >>32;
      int u = cur;
      q.pop();
      if(d != prio[u])continue;
      for(int i =0; i <(int) graph[u].size(); i++){
        Edge &e = graph[u][i];
        int v = e.to;
        if(e.cap <= e.f)continue;
        int nprio = prio[u]+ e.cost + pot[u]- pot[v];
        if(prio[v]> nprio){
          prio[v]= nprio;
          q.push(((long long ) nprio <<32)+ v);
          prevnode[v]= u;
          prevedge[v]= i;
          curflow[v]= min(curflow[u], e.cap - e.f);
        }
      }
    }
    if(prio[t]==1000000000)break;
    for(int i =0; i < nodes; i++) pot[i]+= prio[i];
    int df = min(curflow[t], maxf - flow);
    flow += df;
    for(int v = t; v != s; v = prevnode[v]){
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

const int N = 111;

int lo[N], hi[N], n, m;

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++)
    lo[i] = 1, hi[i] = n;
  for (int i = 0; i < m; i++) {
    int t, l, r, v;
    scanf("%d %d %d %d", &t, &l, &r, &v);
    if (t == 1) {
      for (int j = l; j <= r; j++)
        lo[j] = max(lo[j], v);
    }
    else {
      for (int j = l; j <= r; j++)
        hi[j] = min(hi[j], v);
    }
  }
  for (int i = 1; i <= n; i++)
    if (lo[i] > hi[i]) {
      puts("-1");
      return 0;
    }
  nodes = 2 * (n + 1);
  int s = 0, t = nodes-1;
  for (int i = 1; i <= n; i++) {
    addEdge(s, i, 1, 0);
    for (int j = lo[i]; j <= hi[i]; j++)
      addEdge(i, j+n, 1, 0);
    for (int j = 0; j < n; j++)
      addEdge(i+n, t, 1, 2 * j + 1);
  }
  pair<int, int> ans = minCostFlow(s, t, n * n);
  if (ans.first != n)
    puts("-1");
  else
    printf("%d\n", ans.second);
  return 0;
}