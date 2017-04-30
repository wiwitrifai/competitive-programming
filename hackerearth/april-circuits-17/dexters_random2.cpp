#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6;

int a[N];
int par[20][N], lv[N];
int to[33 * N][2], val[33 * N];
vector < int > g[N];
vector < pair< pair<int, int >, pair< int, int > > > que[N];
int ans[N];
void pre(int v = 0) {
  for (int i = 0; i + 1 < 20; ++i) {
    par[i+1][v] = par[i][par[i][v]];
  }
  for (int u : g[v]) if (u != par[0][v]) {
    par[0][u] = v;
    lv[u] = lv[v] + 1;
    pre(u);
  }
}
int lca(int u, int v) {
  if (lv[u] > lv[v]) swap(u, v);
  int diff = lv[v] - lv[u];
  for (int i = 19; i >= 0; i--) if (diff & (1<<i))
    v = par[i][v];
  if (u == v) return u;
  for (int i = 19; i >= 0; --i) {
    if (par[i][u] != par[i][v])
      u = par[i][u], v = par[i][v];
  }
  return par[0][v];
}

void dfs(int v = 0) {
  int now = lv[v] * 32 + 1, prev = max(now - 32, 0);
  val[now] = lv[v];
  for (int i = 30; i >= 0; --i) {
    to[now][0] = to[prev][0];
    to[now][1] = to[prev][1];
    int b = (a[v] >> i) & 1;
    to[now][b] = now+1;
    prev = to[prev][b];
    now++;
    val[now] = lv[v];
  }
  for (auto it : que[v]) {
    int id = it.first.first, low = it.first.second, c[2];
    c[0] = it.second.first, c[1] = it.second.second;
    for (int j = 0; j < 2; j++) {
      int now = lv[v] * 32 + 1;
      int res = 0;
      for (int i = 30; i >= 0; i--) {
        int b = (c[j] >> i) & 1;
        b = !b;
        if (val[to[now][b]] < low) b = !b;
        res |= b << i;
        now = to[now][b];
        assert(val[now] >= low);
      }
      ans[id] = max(ans[id], res ^ c[j]);
    }
  }
  for (int u : g[v]) if (u != par[0][v]) {
    dfs(u);
  }
}

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  par[0][0] = 0;
  lv[0] = 0;
  pre(0);
  for (int i = 0; i < q; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    int w = lca(u, v);
    que[u].push_back({{i, lv[w]}, {a[u], a[v]}});
    que[v].push_back({{i, lv[w]}, {a[u], a[v]}});
  }
  val[0] = -1;
  to[0][0] = to[0][1] = 0;
  memset(ans, 0, sizeof ans);
  dfs(0);
  for (int i = 0; i < q; ++i) {
    printf("%d\n", ans[i]);
  }
  return 0;
}