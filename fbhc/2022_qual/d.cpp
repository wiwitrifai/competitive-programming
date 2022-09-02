#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  int sq = (int)sqrt(n) + 1;
  vector<vector<pair<int, int>>> g(n);
  map<pair<int, int>, int> mapw;
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
    mapw[make_pair(u, v)] = w;
    mapw[make_pair(v, u)] = w;
  }
  vector<int> id(n, -1);
  vector<int> big;
  for (int i = 0; i < n; ++i) {
    if ((int)g[i].size() <= sq) continue;
    id[i] = big.size();
    big.push_back(i);
  }
  int nbig = big.size();
  vector<vector<long long>> cost(nbig, vector<long long>(nbig, 0));
  for (int i = 0; i < n; ++i) {
    vector<pair<int, int>> cur;
    for (auto [u, w] : g[i]) {
      if (id[u] < 0) continue;
      int b1 = id[u];
      for (auto [b2, w2] : cur) {
        assert(b1 != b2);
        int res = min(w, w2);
        cost[b1][b2] += res;
        cost[b2][b1] += res;
      }
      cur.emplace_back(b1, w);
    }
  }
  vector<long long> ans(q, 0);
  vector<int> x(q), y(q);
  vector<vector<pair<int, int>>> process(n);
  for (int i = 0; i < q; ++i) {
    cin >> x[i] >> y[i];
    --x[i];
    --y[i];
    ans[i] = 2LL * mapw[make_pair(x[i], y[i])];
    int bx = id[x[i]];
    int by = id[y[i]];
    if (bx >= 0 && by >= 0) {
      ans[i] += cost[bx][by];
    } else if (g[x[i]].size() < g[y[i]].size()) {
      process[y[i]].emplace_back(x[i], i);
    } else {
      process[x[i]].emplace_back(y[i], i);
    }
  }
  vector<int> curw(n, 0);
  for (int v = 0; v < n; ++v) {
    for (auto [u, w] : g[v]) {
      curw[u] = w;
    }
    for (auto [u, i] : process[v]) {
      for (auto [other, w2] : g[u]) {
        ans[i] += min(w2, curw[other]);
      }
    }
    for (auto [u, w] : g[v]) {
      curw[u] = 0;
    }
  }

  for (int i = 0; i < q; ++i) {
    printf("%lld%c", ans[i], i+1 == q ? '\n' : ' ' );
  }
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
