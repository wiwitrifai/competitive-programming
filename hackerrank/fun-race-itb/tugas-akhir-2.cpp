// O(Q + N log N)

#include <bits/stdc++.h>

using namespace std;

const int N = 1024, Q = 1e5 + 5;
vector< pair< int, int > > que[N];
vector< int > adj[N];
int c[N], cnt[N], sz[N], ans[Q];

void gets(int v, int par = -1) {
  sz[v] = 1;
  for (int u : adj[v]) if (u != par) {
    gets(u, v);
    sz[v] += sz[u];
  }
}

void add(int v, int par, int val ) {
  cnt[c[v]] += val;
  for (int u : adj[v]) if (u != par)
    add(u, v, val);
}

void dfs(int v, int par = -1) {
  int bg = -1;
  for (int u : adj[v]) if (u != par) {
    if (bg == -1 || sz[bg] < sz[u])
      bg = u;
  }
  for (int u : adj[v]) if (u != par && u != bg) {
    dfs(u, v);
    add(u, v, -1);
  }
  if (bg != -1) {
    dfs(bg, v);
  }
  cnt[c[v]]++;
  for (int u : adj[v]) if (u != par && u != bg) {
    add(u, v, 1);
  }
  for (auto it : que[v]) {
    ans[it.first] = cnt[it.second];
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", c+i);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int x, v;
    scanf("%d %d", &x, &v);
    x--;
    que[x].push_back(make_pair(i, v));
  } 
  memset(cnt, 0, sizeof cnt);
  gets(0);
  dfs(0); 
  for (int i = 0; i < q; i++)
    printf("%d\n", ans[i]);
  return 0;
}