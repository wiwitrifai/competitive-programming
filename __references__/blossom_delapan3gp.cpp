#include <cmath>
#include <vector>
#include <iostream>
 
using namespace std;
 
/** Maximum Matching on General Graph **/
/* Blossom | O(V^3) */

typedef vector<int> VI;
typedef vector<VI> VVI;
 
int lca(vector<int>&match, vector<int>&base, vector<int>&p,int a,int b){
  vector<bool> used(match.size());
  while(true){
    a = base[a];
    used[a]=true;
    if(match[a]==-1)break;
    a = p[match[a]];
  }
  while(true){
    b = base[b];
    if(used[b])return b;
    b = p[match[b]];
  }
  return-1;
}
 
void markPath(vector<int>&match, vector<int>&base, vector<bool>&blossom, vector<int>&p,int v,int b,int children){
  for(; base[v]!= b; v = p[match[v]]){
    blossom[base[v]]= blossom[base[match[v]]]=true;
    p[v]= children;
    children = match[v];
  }
}
 
int findPath(vector<vector<int>>&graph, vector<int>&match, vector<int>&p,int root){
  int n = graph.size();
  vector<bool> used(n);
  for(auto it = p.begin(); it != p.end(); ++it)*it =-1;
  vector<int> base(n);
  for(int i =0; i < n;++i) base[i]= i;
 
  used[root]=true;
  int qh =0;
  int qt =0;
  vector<int> q(n);
  q[qt++]= root;
  while(qh < qt){
    int v = q[qh++];
    for(auto it = graph[v].begin(); it != graph[v].end(); ++it){
      int to =*it;
      if(base[v]== base[to]|| match[v]== to)continue;
      if(to == root || match[to]!=-1&& p[match[to]]!=-1){
        int curbase = lca(match, base, p, v, to);
        vector<bool> blossom(n);
        markPath(match, base, blossom, p, v, curbase, to);
        markPath(match, base, blossom, p, to, curbase, v);
        for(int i =0; i < n;++i){
          if(blossom[base[i]]){
            base[i]= curbase;
            if(!used[i]){
              used[i]=true;
              q[qt++]= i;
            }
          }
        }
      }else if(p[to]==-1){
        p[to]= v;
        if(match[to]==-1)return to;
        to = match[to];
        used[to]=true;
        q[qt++]= to;
      }
    }
  }
  return-1;
}
 
int maxMatching(vector<vector<int>> graph){
  int n = graph.size();
  vector<int> match(n,-1);
  vector<int> p(n);
  for(int i =0; i < n;++i){
    if(match[i]==-1){
      int v = findPath(graph, match, p, i);
      while(v !=-1){
        int pv = p[v];
        int ppv = match[pv];
        match[v]= pv;
        match[pv]= v;
        v = ppv;
      }
    }
  }
 
  int matches = 0;
  for(int i = 0; i < n;++i){
    if(match[i]!=-1){
      ++matches;
    }
  }
  return matches/2;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  VVI g(n, VI(n, 0));
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    scanf("%d %d", &u, &v); --u, --v;
    g[u][v] = 1;    
  }
  auto res = maxMatching(g);
  printf("%d\n", res);
  return 0;
}