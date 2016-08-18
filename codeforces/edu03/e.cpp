#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, LN = 20;

int n, m;
int p[N], par[N][LN], val[N][LN] ;
long long ans[N];
pair< pair< int, int >, pair<int, int> > ed[N];
vector< pair<int, int >  > adj[N];

int find(int x) {
  if(p[x] < 0)
    return x;
  return p[x] = find(p[x]);
}

bool merge(int u, int v) {
  if((u = find(u)) == (v = find(v)))
    return false;
  if(p[u] < p[v])
    swap(u, v);
  p[v] += p[u];
  p[u] = v;
  return true;
}

void dfs(int v, int q, int va = 0) {
  if(q != -1) {
    p[v] = p[q] + 1;
    par[v][0] = q;
    val[v][0] = va;
    for(int i = 0; i<LN-1; i++) if(par[v][i] != -1){
      par[v][i+1] = par[par[v][i]][i];
      val[v][i+1] = max(val[par[v][i]][i], val[v][i]);
    }
  }
  for(auto nx : adj[v]) if(nx.first != q) {
    dfs(nx.first, v, nx.second);
  }
}

long long rmq(int v, int u) {
  if(p[v] < p[u])
    swap(v, u);
  int dif = p[v]-p[u];
  int ret = 0;
  for(int i = 0; i<LN; i++) {
    if(dif & (1<<i)) {
      ret = max(val[v][i], ret);
      v = par[v][i];
    }
  }
  if(u == v)
    return ret;
  for(int i = LN-1; i>=0; i--) {
    if(par[v][i] != par[u][i]) {
      ret = max(ret, val[v][i]);
      ret = max(ret, val[u][i]);
      v = par[v][i];
      u = par[u][i];
    }
  }
  ret = max(ret, val[v][0]);
  ret = max(ret, val[u][0]);
  return ret;
}

int main() {
  scanf("%d%d", &n, &m);
  for(int i = 0; i<m; i++) {
    int a, b, w;
    scanf("%d%d%d", &a, &b, &w);
    ed[i] = {{w, i}, {a, b}};
  }
  sort(ed, ed+m);
  memset(p, -1, sizeof p);
  long long sum = 0;
  for(int i = 0; i<m; i++) {
    if(merge(ed[i].second.first, ed[i].second.second)) {
      sum += ed[i].first.first;
      adj[ed[i].second.first].emplace_back(ed[i].second.second, ed[i].first.first);
      adj[ed[i].second.second].emplace_back(ed[i].second.first, ed[i].first.first);
    }
  }
  memset(p, -1, sizeof p);
  memset(par, -1, sizeof par);
  for(int i = 0; i<n; i++) if(p[i] == -1){
    p[i] = 0;
    dfs(i, -1);
  }
  for(int i = 0; i<m; i++)
    ans[ed[i].first.second] = sum + - rmq(ed[i].second.first, ed[i].second.second) + ed[i].first.first;
  for(int i = 0; i<m; i++)
    printf("%I64d\n", ans[i]);
  return 0;
}