#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int par[N];

int find(int u) {
  return par[u] = (par[u] == u? u : find(par[u])); 
}

void merge(int u, int v) {
  par[find(u)] = find(v);
}

vector<int> adj[N];
vector< int > num, low, S, vis;
int cntr, numCC, comp[N];
int to[N * N];

void tarjanSCC(int v, int st) {
  low[v] = num[v] = ++cntr;
  vis[v] = 1;
  S.push_back(v);
  //printf("sekarang saatnya %d %d\n", v, st);
  for(auto u : adj[v]) {
    if (u == (st ^ 1)) continue;
    //printf("%d %d\n", v, to[u]);
    if(num[to[u]] == -1)
      tarjanSCC(to[u], u);
    if(vis[to[u]])
      low[v] = min(low[v], low[to[u]]);
  }
  if(low[v] == num[v]) {
    ++numCC;
    while(1) {
      int u = S.back(); S.pop_back();
      vis[u] = 0;
      comp[u] = numCC;
      if(u == v)
        break;
    }
  }
}

int main() {
  for (int i = 0; i < N; i++) par[i] = i;
  num.resize(N);
  vis.resize(N);
  low.resize(N);
  
  vector<tuple<int, int, int>> edges;
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    edges.emplace_back(w, u, v);
  }
  sort(edges.begin(), edges.end());
  int ans_cnt = 0, ans_sum = 0;
  for (int i = 0; i < edges.size(); i++) {
    int j = i, w;
    tie(w, ignore, ignore) = edges[i];
    while (j + 1 < edges.size() && get<0>(edges[j]) == get<0>(edges[j + 1])) {
      j++;
    }
    set<int> node;
    //puts("lol");
    int pt = 0;
    for (int k = i; k <= j; k++) {
      int u, v;
      tie(ignore, u, v) = edges[k];
      u = find(u);
      v = find(v);
      if (u != v) {
        //printf("%d %d\n", u, v);
        
        node.insert(u);
        node.insert(v);
        to[pt] = v;
        adj[u].push_back(pt++);
        
        to[pt] = u;
        adj[v].push_back(pt++);
      }
    }
    //puts("haha");
    for (auto it : node) {
      num[it] = -1;
      low[it] = vis[it] = 0;
    }
    cntr = numCC = 0;
    //puts("persiapan tarjan");
    for (auto it : node) {
      if (num[it] == -1) {
        tarjanSCC(it, -1);
      }
    }
    //printf("tarjan %d done\n", w);
    for (auto it : node) {
      //printf("comp %d %d\n", it, comp[it]);
      for (auto near : adj[it]) {
        near = to[near];
        //printf("%d %d\n", it, near);
        if (comp[it] != comp[near] && it < near) {
          ans_cnt++;
          ans_sum += w;
        }
      }
    }
    
    for (auto it : node) {
      //par[it] = it;
      for (auto near : adj[it]) merge(it, to[near]);
      adj[it].clear();
    }
    i = j;
  }
  printf("%d %d\n", ans_cnt, ans_sum);
  return 0;
}