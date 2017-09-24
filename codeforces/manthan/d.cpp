#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<pair<int, int> > g[N];
int p[19][N], lv[N], d[N];

void dfs(int v) {
  for (int i = 0; i+1 < 19; i++)
    p[i+1][v] = p[i][p[i][v]];
  for (auto it : g[v]) {
    int u = it.first;
    p[0][u] = v;
    lv[u] = lv[v]+1;
    d[u] = d[v]+it.second;
    dfs(u);
  }
}

int lca(int u, int v) {
  if (lv[u] > lv[v])
    swap(u, v);
  int diff = lv[v] - lv[u];
  for (int i = 18; i >= 0; i--)
    if (diff & (1 << i))
      v = p[i][v];
  assert(lv[v] == lv[u]);
  if (v == u) return v;
  for (int i = 18; i >= 0; i--)
    if (p[i][u] != p[i][v])
      u = p[i][u], v = p[i][v];
  u = p[0][u];
  v = p[0][v];
  if (u != v)
    return -1;
  return v;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int u, w;
    scanf("%d %d", &u, &w);
    u--;
    if (u < 0 && w < 0) continue;
    g[u].emplace_back(i, w); 
  }
  memset(lv, -1, sizeof lv);
  for (int i = 0; i < n; i++) if (lv[i] < 0) {
    p[0][i] = i;
    lv[i] = d[i] = 0;
    dfs(i);
  }
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int t, u, v;
    scanf("%d %d %d", &t, &u, &v);
    u--; v--;
    int w = lca(u, v);
    if (u == v || w == -1) {
      puts("NO");
      continue;
    }
    if (t == 1) {
      bool ok = (w == u) && ((d[v]-d[u]) == 0) && (lv[v] - lv[u]) > 0;
      puts(ok ? "YES" : "NO");
    }
    else {
      bool ok = (v != w) && ((d[v]-d[w]) == (lv[v]-lv[w])) && ((d[u]-d[w]) == 0);
      puts(ok ? "YES" : "NO");
    }
  }

  return 0;
}