#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, NLOG = 19;

vector< int > adj[N];
int par[NLOG][N], n;
int st[N], en[N], bit1[N<<1], bit2[N<<1], times, lv[N];

int dfs(int v) {
  st[v] = ++times;
  lv[v] = (par[0][v] != v) ? lv[par[0][v]] + 1 : 0;
  for(int i = 1; i<NLOG; i++)
    par[i][v] = par[i-1][par[i-1][v]];
  for(int u : adj[v]) if(u != par[0][v]) {
    par[0][u] = v;
    dfs(u);
  }
  en[v] = ++times;
}

int get(int * bit, int x) {
  int ret = 0;
  for(; x; x -= x&(-x))
    ret += bit[x];
  return ret;
}
void upd(int * bit, int x, int val) {
  for(; x<=times; x += x&(-x))
    bit[x] += val;
}

int lca(int u, int v) {
  if(lv[u] > lv[v])
    swap(u, v);
  int diff = lv[v] - lv[u];
  for(int i = NLOG-1; i>=0; i--)
    if(diff & (1<<i))
      v = par[i][v];
  if(u == v) 
    return v;
  for(int i = NLOG-1; i>=0; i--)
    if(par[i][v] != par[i][u])
      u = par[i][u], v = par[i][v];
  return par[0][v];
}

int main() {
  scanf("%d", &n);
  for(int i = 1; i<n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[--u].push_back(--v);
    adj[v].push_back(u);
  }
  int q;
  scanf("%d", &q);
  par[0][0] = 0;
  times = 0;
  dfs(0);
  while(q--) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--; v--;
    int w = lca(u, v);
    int ans = get(bit1, en[w]) - get(bit1, st[w]-1) + get(bit2, st[u]) + get(bit2, st[v]) - get(bit2, st[w]) - (w ? get(bit2, st[par[0][w]]) : 0);
    printf("%d\n", ans);
    upd(bit1, st[w], -2);
    upd(bit1, st[u], 1);
    upd(bit1, st[v], 1);
    upd(bit2, st[w], 1);
    upd(bit2, en[w], -1);
  }
  return 0;
}