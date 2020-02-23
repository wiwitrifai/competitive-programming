#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, LG = 21;

vector<int> g[N];
int lv[N], par[LG][N];

void dfs(int v, int p) {
  par[0][v] = p;
  for (int i = 0; i + 1 < LG; ++i) {
    par[i+1][v] = par[i][par[i][v]];
  }
  for (int u : g[v]) {
    if (u == p) continue;
    lv[u] = lv[v] + 1;
    dfs(u, v);
  }
}

int lca(int u, int v) {
  if (lv[v] < lv[u])
    swap(u, v);
  int diff = lv[v] - lv[u];
  for (int i = 0; i < LG; ++i) {
    if (diff & (1 << i)) {
      v = par[i][v];
    }
  }
  if (u == v)
    return u;
  for (int i = LG-1; i >= 0; --i) {
    if (par[i][u] != par[i][v]) {
      u = par[i][u];
      v = par[i][v];
    }
  }
  return par[0][v];
}

int dist(int u, int v) {
  return lv[u] + lv[v] - 2 * lv[lca(u, v)];
}

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n-1; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0, 0);
  while (q--) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    if (u == v) {
      printf("%d\n", n);
      continue;
    }
    int d = dist(u, v) + 1;
    long long ans = n + 1LL * d * (d-1) / 2;
    printf("%lld\n", ans);
  }
  return 0;
}
