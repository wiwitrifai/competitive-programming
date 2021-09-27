#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7, K = 20;

vector<vector<pair<int, int>>> g;
vector<vector<int>> down, up;
vector<int> par;
vector<int> tmp(K+1);

long long dfs(int v) {
  long long ret = 0;
  ++down[v][K];
  for (auto & e : g[v]) {
    int u = e.first;
    if (u == par[v]) continue;
    par[u] = v;
    ret = (ret + dfs(u)) % mod;
    int w = e.second;
    for (int i = 0; i <= K; ++i) {
      int val = min(i, w);
      for (int j = 0; j <= K; ++j) {
        long long cur = min(val, j) * 1LL * down[v][i] % mod;
        ret = (ret + cur * down[u][j]) % mod;
      }
    }
    for (int i = 0; i <= K; ++i) {
      down[v][min(i, w)] += down[u][i];
    }
  }
  return ret;
}

long long spread(int v, long long tot) {
  long long ret = 1;
  for (auto & e : g[v]) {
    int u = e.first;
    if (u == par[v]) continue;
    int w = e.second;
    tmp = down[v];
    for (int i = 0; i <= K; ++i) {
      tmp[min(i, w)] -= down[u][i];
    }
    for (int i = 0; i <= K; ++i) {
      up[u][min(i, w)] += up[v][i] + tmp[i];
    }
    ret = (ret * spread(u, tot)) % mod;
    long long sum = 0;
    for (int i = 0; i <= K; ++i) {
      int val = min(i, w);
      for (int j = 0; j <= K; ++j) {
        long long cur = min(val, j) * 1LL * up[u][i] % mod;
        sum = (sum + cur * down[u][j]) % mod;
      }
    }
    sum = (mod + tot - sum) % mod;
    ret = (ret * sum) % mod;
  }
  return ret;
}


void solve() {
  int n;
  scanf("%d", &n);
  g.resize(n);
  for (int i = 0; i < n; ++i) {
    g[i].clear();
  }
  for (int i = 0; i < n-1; ++i) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    --u, --v;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }
  par.assign(n, -1);
  down.assign(n, vector<int>(K + 1, 0));
  up.assign(n, vector<int>(K + 1, 0));
  long long tot = dfs(0);
  long long ans = spread(0, tot);
  cout << ans << endl;
}

int main(int argc, char * argv[]) {
  clock_t starttime = clock();
  int seed = time(0);
  if (argc >= 2) {
    seed = atoi(argv[1]);
  }
  cerr << "random seed\t= " << seed << endl;
  srand(seed);

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
