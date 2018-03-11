// by wiwit
#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5, LG = 20;

int node[N], st[N], en[N], lv[N], cntr = 0, par[N];

vector<int> g[N];

void dfs(int v) {
  node[cntr] = v;
  st[v] = cntr++;
  for (int u : g[v]) {
    if (u == par[v]) continue;
    lv[u] = lv[v] + 1;
    par[u] = v;
    dfs(u);
    node[cntr++] = v;
  }
  en[v] = cntr;
}

int sp[LG][N];
int get_sp(int l, int r) {
  if (l > r) swap(l, r);
  int len = r-l + 1;
  int lg = 31 - __builtin_clz(len);
  int le = sp[lg][l], ri = sp[lg][r-(1 << lg) + 1];
  return lv[le] < lv[ri] ? le : ri;
}

int lca(int u, int v) {
  return get_sp(st[u], st[v]);
}

int dist(int u, int v) {
  int a = lca(u, v);
  return lv[u] + lv[v] - 2 * lv[a];
}

bool ancestor(int u, int v) {
  return st[u] <= st[v] && en[v] <= en[u];
}

bool on_path(int u, int w, int v) {
  int a = lca(u, v);
  if (!ancestor(a, w)) return false;
  return ancestor(w, u) || ancestor(w, v);
}

int p[N];

int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}

int merge(int u, int v) {
  if ((u = find(u)) == (v = find(v))) return false;
  if (lv[u] < lv[v]) swap(u, v);
  p[v] += p[u];
  p[u] = v;
  return true;
}

bool apply(int u, int v) {
  int a = lca(u, v);
  int len = lv[u] + lv[v] - 2 * lv[a] + 1;
  u = find(u);
  v = find(v);
  while (lv[u] > lv[a]) {
    merge(u, par[u]);
    u = find(u);
  }
  while (lv[v] > lv[a]) {
    merge(v, par[v]);
    v = find(v);
  }
  a = find(a);
  return -p[a] == len;
}

int main() {
  int n, f;
  scanf("%d %d", &n, &f);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  cntr = 0;
  lv[0] = 0;
  dfs(0);
  for (int i = 0; i < cntr; ++i)
    sp[0][i] = node[i];
  for (int i = 0; i + 1 < LG; ++i) {
    for (int j = 0; j + (1 << (i+1)) <= cntr; ++j) {
      int le = sp[i][j], ri = sp[i][j+(1<<i)];
      sp[i+1][j] = lv[le] < lv[ri] ? le : ri;
    }
  }
  vector<pair<int, pair<int, int> > > edge;
  for (int i = 0; i < f; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    edge.push_back({dist(u, v), {u, v}});
  }
  memset(p, -1, sizeof p);
  bool ans = 1;
  sort(edge.begin(), edge.end());
  for (auto it : edge) {
    auto uv = it.second;
    int u = uv.first, v = uv.second;
    ans &= apply(u, v);
    if (!ans) break;
  }
  puts(ans ? "Yes" : "No");
  return 0;
}