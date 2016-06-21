#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;

int n, m, low[N], num[N], num_cnt;
long long sub[N];

vector< int > adj[N];
vector< int > tree[N];

void dfs(int v, int par){
  low[v] = num[v] = num_cnt++;
  for(int u : adj[v])
    if(num[u] == -1) {
      dfs(u, v);
      if(num[v] < low[u]) {
        tree[v].push_back(u);
        tree[u].push_back(v);
      }
      low[v] = min(low[u], low[v]);
    }
    else if(u != par)
      low[v] = min(low[v], low[u]);
}

void dfs1(int v, int par) {
  num[v] = 1;
  sub[v] = 1;
  for(int u : tree[v]) if(u != par) {
    dfs1(u, v);
    sub[v] += sub[u];
  }
}

long long dfs2(int v, long long size, int par) {
  long long ret = 0;
  for(int u : tree[v]) if(u != par) {
    ret += dfs2(u, size, v);
    ret += 1LL*(size-sub[u]) * sub[u];
  }
  return ret;
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%d%d", &n, &m);
    for(int i = 0; i<=n; i++) {
      adj[i].clear();
      tree[i].clear();
    }
    for(int i = 0; i<m; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      x--; y--;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    memset(num, -1, sizeof num);
    num_cnt = 0;
    for(int i = 0; i<n; i++) if(num[i] == -1)
      dfs(i, -1);
    memset(num, -1, sizeof num);
    long long ans = 0;
    for(int i = 0; i<n; i++)
      if(num[i] == -1) {
        dfs1(i, -1);
        ans += dfs2(i, sub[i], -1);
      }
    printf("%lld\n", ans);
  }
  return 0;
}