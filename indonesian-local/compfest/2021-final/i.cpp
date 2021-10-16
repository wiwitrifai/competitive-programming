#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, LG = 20;

struct Fenwick {
  long long sum[N];
  Fenwick() {
    memset(sum, 0, sizeof sum);
  }
  long long get(int x) {
    long long ret = 0;
    for (++x; x; x -= x&-x)
      ret += sum[x];
    return ret;
  }
  void update(int x, int v) {
    for (++x; x < N; x += x&-x)
      sum[x] += v;
  }
};

vector<int> g[N];

int a[N];
int par[LG][N], lv[N], in[N], out[N], nevent = 0;

void dfs(int v) {
  for (int i = 0; i + 1 < LG; ++i) {
    par[i+1][v] = par[i][par[i][v]];
  }
  in[v] = nevent++;
  for (int u : g[v]) {
    if (u == par[0][v]) continue;
    par[0][u] = v;
    lv[u] = lv[v] + 1;
    dfs(u);
  }
  out[v] = nevent;
}

int lca(int u, int v) {
  if (lv[u] > lv[v])
    swap(u, v);
  int diff = lv[v] - lv[u];
  for (int i = 0; i < LG; ++i) {
    if (diff & (1 << i)) {
      v = par[i][v];
    }
  }
  if (u == v)
    return v;
  for (int i = LG-1; i >= 0; --i) {
    if (par[i][u] == par[i][v]) continue;
    u = par[i][u];
    v = par[i][v];
  }
  return par[0][v];
}

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  for (int i = 0; i < n-1; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0);
  Fenwick fen;
  for (int i = 0; i < n; ++i) {
    a[i] = abs(a[i]);
    fen.update(in[i], a[i]);
    fen.update(out[i], -a[i]);
  }
  while (q--) {
    int t, x, y;
    scanf("%d %d %d", &t, &x, &y);
    --x;
    if (t == 1) {
      y = abs(y);
      int diff = y - a[x];
      a[x] += diff;
      fen.update(in[x], diff);
      fen.update(out[x], -diff);
    } else {
      --y;
      int z = lca(x, y);
      long long ans = fen.get(in[x]) + fen.get(in[y]) - fen.get(in[z]);
      if (par[0][z] != z) {
        ans -= fen.get(in[par[0][z]]);
      }
      ans = ans * 2 - a[x] - a[y];
      printf("%lld\n", ans);
    }
  }
  return 0;
}
