#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, LG = 18;

int a[N];
vector<int> g[N];

int par[LG][N], lv[N];
int hig[LG][N];
int up[LG][N];
int down[LG][N];

void dfs(int v, int p = -1) {
  if (p == -1) p = v;
  lv[v] = p == v ? 0 : lv[p] + 1;
  par[0][v] = p;
  hig[0][v] = a[v] > a[p] ? v : p;
  up[0][v] = a[p] > a[v];
  down[0][v] = a[p] < a[v];
  for (int i = 0; i + 1 < LG; ++i) {
    int u = par[i][v];
    par[i+1][v] = par[i][u];
    hig[i+1][v] = a[hig[i][v]] > a[hig[i][u]] ? hig[i][v] : hig[i][u];
    up[i+1][v] = up[i][v] && up[i][u];
    down[i+1][v] = down[i][v] && down[i][u];
  }
  for (int u : g[v]) {
    if (u == p) continue;
    dfs(u, v);
  }
}

int lca(int u, int v) {
  if (lv[u] > lv[v])
    swap(u, v);
  int diff = lv[v] - lv[u];
  for (int i = 0; i < LG; ++i)
    if (diff & (1 << i))
      v = par[i][v];
  if (u == v)
    return v;
  for (int i = LG-1; i >= 0; --i) {
    if (par[i][u] == par[i][v]) continue;
    u = par[i][u];
    v = par[i][v];
  }
  return par[0][v];
}

int gethigh(int v, int diff) {
  int ret = v;
  for (int i = 0; i < LG; ++i) {
    if (diff & (1 << i)) {
      int u = hig[i][v];
      if (a[u] > a[ret])
        ret = u;
      v = par[i][v];
    }
  }
  return ret;
}

bool getup(int v, int diff) {
  bool ret = true;
  for (int i = 0; i < LG; ++i) {
    if (diff & (1 << i)) {
      ret &= up[i][v];
      v = par[i][v];
    }
  }
  return ret;
}

bool getdown(int v, int diff) {
  bool ret = true;
  for (int i = 0; i < LG; ++i) {
    if (diff & (1 << i)) {
      ret &= down[i][v];
      v = par[i][v];
    }
  }
  return ret;
}



int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    int q;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; ++i)
      g[i].clear();
    for (int i = 0; i < n-1; ++i) {
      int u, v;
      scanf("%d %d", &u, &v);
      --u, --v;
      g[u].emplace_back(v);
      g[v].emplace_back(u);
    }
    for (int i = 0; i < n; ++i)
      scanf("%d", a+i);
    dfs(0);
    while (q--) {
      int u, v;
      scanf("%d %d", &u, &v);
      --u, --v;
      int w = lca(u, v);
      int h = gethigh(u, lv[u] - lv[w]), hh = gethigh(v, lv[v] - lv[w]);
      bool ok = 1;
      if (a[h] < a[hh]) {
        ok &= getup(u, lv[u] - lv[w]);
        ok &= getup(v, lv[v] - lv[hh]);
        ok &= getdown(hh, lv[hh] - lv[w]);
      } else {
        ok &= getup(u, lv[u] - lv[h]);
        ok &= getup(v, lv[v] - lv[w]);
        ok &= getdown(h, lv[h] - lv[w]);
      }
      printf("%c", '0' + ok);
    }
    printf("\n");
  }
  return 0;
}
