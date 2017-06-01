#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, LN = 19, M = 5e4 + 2;

vector< int > adj[N], g[N];
int c[N], nc, tmpst, num[N], low[N], vis[N];
bitset< M > vs[M];

vector< int > vers;
void dfs(int v) {
  num[v] = low[v] = tmpst++;
  vis[v] = 1;
  vers.push_back(v);
  for (int u : adj[v]) {
    if (num[u] == -1)
      dfs(u);
    if (vis[u])
      low[v] = min(low[v], low[u]);
  }
  if (low[v] == num[v]) {
    vis[v] = 0;
    while (1) {
      int u = vers.back(); vers.pop_back();
      c[u] = nc; vis[u] = 0;
      if (u == v) break;
    }
    nc++;
  }
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    adj[u].push_back(v);
  }
  tmpst = nc = 0;
  memset(vis, 0, sizeof vis);
  memset(num, -1, sizeof num);
  for (int i = 0; i < n; i++) if (num[i] == -1)
    dfs(i);
  for (int i = 0; i < n; i++) {
    for (int u : adj[i]) if (c[u] != c[i]) {
      g[c[i]].emplace_back(c[u]);
    }
  }
  for (int i = 0; i < nc; i++) {
    sort(g[i].begin(), g[i].end());
    g[i].erase(unique(g[i].begin(), g[i].end()), g[i].end());
  }
  vector< pair< int, int > > que;
  int q;
  scanf("%d", &q);
  while (q--) {
    int t, x, y;
    scanf("%d %d %d", &t, &x, &y);
    x--;
    if (t == 1) {
      x = c[x];
      if (y)
        g[nc].push_back(x);
      else
        g[x].push_back(nc);
      c[n++] = nc++;
    }
    else {
      y--;
      x = c[x], y = c[y];
      que.emplace_back(x, y);
    }
  }
  memset(vis, 0, sizeof vis);
  for (int i = 0; i < nc; i++) {
    for (int u : g[i])
      vis[u]++;
  }
  stack< int > st;
  for (int i = 0; i < nc; i++) {
    if (vis[i] == 0)
      st.push(i);
  }
  vector< int > topo;
  while (!st.empty()) {
    int v = st.top(); st.pop();
    topo.push_back(v);
    for (int u : g[v]) {
      vis[u]--;
      if (vis[u] == 0)
        st.push(u);
    }
  }
  for (int i = (int)topo.size()-1; i >= 0; i--) {
    int v = topo[i];
    vs[v][v] = 1;
    for (int u : g[v])
      vs[v] = vs[v] | vs[u];
  }
  for (auto it : que)
    puts(vs[it.first][it.second] ? "Yes" : "No");
  return 0;
}