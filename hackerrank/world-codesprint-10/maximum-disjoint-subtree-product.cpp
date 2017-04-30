#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 6, inf = 1e9 + 7;

vector< int > g[N];
int sa[N], si[N], ba[N], bi[N], w[N];
int usa[N], usi[N], uba[N], ubi[N];
void pre(int v, int p = -1) {
  sa[v] = si[v] = w[v];
  ba[v] = -inf;
  bi[v] = inf;
  if (p != -1) {
    usa[v] = usi[v] = w[p];
    uba[v] = -inf;
    ubi[v] = inf;
  }
  for (int u : g[v]) if (u != p) {
    pre(u, v);
    sa[v] += max(0, sa[u]);
    si[v] += min(0, si[u]);
    ba[v] = max(ba[v], ba[u]);
    bi[v] = min(bi[v], bi[u]);
  }
  ba[v] = max(ba[v], sa[v]);
  bi[v] = min(bi[v], si[v]);

}

long long ans;
void dfs(int v, int par = -1) {
  if (par != -1) {
    uba[v] = max(uba[v], usa[v]);
    ubi[v] = min(ubi[v], usi[v]);
    ans = max(ans, 1LL * ba[v] * uba[v]);
    ans = max(ans, 1LL * bi[v] * ubi[v]);
    ans = max(ans, 1LL * ba[v] * ubi[v]);
    ans = max(ans, 1LL * bi[v] * uba[v]);
  }
  int ssa = max(0, usa[v]), ssi = min(0, usi[v]);
  int bba = uba[v], bbi = ubi[v];
  for (int u : g[v]) if (u != par) {
    usa[u] += ssa;
    usi[u] += ssi;
    ssa += max(0, sa[u]);
    ssi += min(0, si[u]);
    uba[u] = max(uba[u], bba);
    ubi[u] = min(ubi[u], bbi);
    bba = max(bba, ba[u]);
    bbi = min(bbi, bi[u]);
  }
  ssa = ssi = 0;
  bba = -inf, bbi = inf;
  for (int i = (int)g[v].size() - 1; i >= 0; i--) {
    int u = g[v][i];
    if (u == par) continue;
    usa[u] += ssa;
    usi[u] += ssi;
    ssa += max(0, sa[u]);
    ssi += min(0, si[u]);
    uba[u] = max(uba[u], bba);
    ubi[u] = min(ubi[u], bbi);
    bba = max(bba, ba[u]);
    bbi = min(bbi, bi[u]);
    dfs(u, v);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", w+i);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  uba[0] = -inf;
  ubi[0] = inf;
  usa[0] = usi[0] = 0;
  pre(0);
  ans = 0;
  dfs(0);
  printf("%lld\n", ans);
  return 0;
}