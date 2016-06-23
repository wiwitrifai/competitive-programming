#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, c[N], sz[N], cnt[N], cur = 0;
bool skip[N];
long long sum[N], ans[N];
vector< int > adj[N];

void getSize(int v = 0, int p = -1) {
  sz[v] = 1;
  for(int u : adj[v]) if(u != p) {
    getSize(u, v);
    sz[v] += sz[u];
  }
}

void add(int v, int p, int val) {
  int bef = cnt[c[v]];
  cnt[c[v]] += val;
  sum[bef] -= c[v];
  sum[cnt[c[v]]] += c[v];
  if(val >= 1) {
    cur = max(cur, cnt[c[v]]);
  }
  for(auto u : adj[v]) if(u != p && !skip[u]) {
    add(u, v, val);
  }
}

void dfs(int v = 0, int p = -1, bool keep = 0) {
  int bg = -1, bgz = -1;
  for(int u : adj[v]) if(u != p) {
    if(sz[u] > bgz) {
      bg = u;
      bgz = sz[u];
    }
  }
  if(bg != -1)
    skip[bg] = 1;
  for(int u : adj[v]) if(u != p && u != bg) {
    dfs(u, v, 0);
  }
  if(bg != -1)
    dfs(bg, v, 1);
  add(v, p, 1);
  while(sum[cur] == 0 && cur > 0) cur--;
  ans[v] = sum[cur];
  if(bg != -1)
    skip[bg] = 0;
  if(!keep) {
    add(v, p, -1);
  }
}

int main() {
  memset(sum, 0, sizeof sum);
  memset(cnt, 0, sizeof cnt);
  cur = 0;
  scanf("%d", &n);
  for(int i = 0; i<n; i++) {
    scanf("%d", c+i);
    sum[0] += c[i];
  }
  for(int i = 1; i<n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--; y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  getSize();
  dfs();
  for(int i = 0; i<n; i++)
    cout << ans[i] << " ";
  cout << endl;
  return 0;
}