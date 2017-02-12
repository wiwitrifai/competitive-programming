#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 56;

vector< int > adj[N];
int depth[N], sz[N];

void dfs1(int u, int par = -1) {
  depth[u] = 1;
  sz[u] = 1;
  for (int v : adj[u]) if (v != par) {
    dfs1(v, u);
    depth[u] = max(depth[v]+1, depth[u]);
    sz[u] += sz[v];
  }
}

int n;
int ans, c;
void dfs2(int u, int par = -1, int up = 0) {
  int ma = up, cnt = up > 0;
  int sma = up >= 3 ? n - sz[u] : 0;
  vector< int > pre;
  for (int v : adj[u]) if (v != par) {
    pre.push_back(ma);
    cnt++;
    ma = max(ma, depth[v]);
    if (depth[v] >= 3)
      sma = max(sz[v], sma);
  }
  if (cnt >= 5 && ma >= 3) {
    int nans = sma + cnt;
    if (nans > ans || (nans == ans && c > u))
      ans = nans, c = u;
  }
  ma = 0;
  for (int i = (int)adj[u].size() - 1, j = (int)pre.size()-1; i >= 0; i--) if (adj[u][i] != par) {
    int v = adj[u][i];
    dfs2(v, u, max(ma, pre[j])+1);
    ma = max(ma, depth[v]);
    j--; 
  }
}


int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  ans = -1; c = 0;
  dfs1(0);
  dfs2(0);
  if (ans <= 0)
    puts("-1");
  else
    printf("%d %d\n", ans, c+1); 
  return 0;
}