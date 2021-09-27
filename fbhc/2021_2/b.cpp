#include <bits/stdc++.h>

using namespace std;

const int LN = 22;
vector<vector<int>> g;
vector<int> f, anc;
vector<int> par[LN], lv;

void dfs(int v) {
  for (int i = 0; i + 1 < LN; ++i) {
    par[i+1][v] = par[i][par[i][v]];
  }
  for (int u : g[v]) {
    if (u == par[0][v]) continue;
    lv[u] = lv[v] + 1;
    par[0][u] = v;
    dfs(u);
  }
}

int lca(int u, int v) {
  if (lv[u] > lv[v])
    swap(u, v);
  int diff = lv[v] - lv[u];
  assert(diff >= 0);
  for (int i = 0; i < LN; ++i) {
    if (diff & (1 << i)) {
      v = par[i][v];
    }
  }
  assert(lv[v] == lv[u]);
  if (u == v)
    return v;
  for (int i = LN-1; i >= 0; --i) {
    if (par[i][u] != par[i][v]) {
      u = par[i][u];
      v = par[i][v];
    }
  }
  return par[0][v];
}

vector<int> val;

int dfs2(int v) {
  int ret = 0;
  for (int u : g[v]) {
    if (u == par[0][v]) continue;
    ret += dfs2(u);
    if (val[u] == 0) {
      ++ret;
    }
    val[v] += val[u];
  }
  return ret;
}

void solve() {
  int n;
  cin >> n;
  g.resize(n);
  for (int i = 0; i < n; ++i) {
    g[i].clear();
  }
  for (int i = 0; i < n-1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  f.resize(n);
  anc.assign(n+1, -1);
  for (int i = 0; i < n; ++i) {
    cin >> f[i];
  }
  for (int i = 0; i < LN; ++i) {
    par[i].resize(n);
  }
  lv.assign(n, 0);
  par[0][0] = 0;
  dfs(0);
  for (int i = 0; i < n; ++i) {
    int x = f[i];
    if (anc[x] == -1)
      anc[x] = i;
    else
      anc[x] = lca(anc[x], i);
  }
  val.assign(n, 0);
  for (int i = 0; i < n; ++i) {
    int x = f[i];
    ++val[i];
    --val[anc[x]];
  }
  int ans = dfs2(0);
  cout << ans << endl;
}

int main(int argc, char * argv[]) {
  clock_t starttime = clock();

  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; ++tc) {
    printf("Case #%d: ", tc);
    solve();
    fflush(stdout);
    cerr << "~ TC#" << tc << " done! execution time : " <<
      (double)(clock() - starttime) / CLOCKS_PER_SEC << " s " << endl;
  }
  return 0;
}
