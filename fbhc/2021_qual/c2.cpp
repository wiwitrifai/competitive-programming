#include <bits/stdc++.h>

using namespace std;

const int N = 55, K = 55, inf = 1e9 + 7, Z = 3;

vector<int> c;
vector<vector<int>> g;
int dp[N][K][Z];
int tmp[K][Z];

inline void upd(int & var, int val) {
  if (var < val)
    var = val;
}

inline int add(int lef, int rig) {
  if (lef < 0 || rig < 0)
    return -1;
  return lef + rig;
}

void dfs(int v, int k, int par = -1) {
  dp[v][0][0] = 0;
  dp[v][1][1] = c[v];
  for (int u : g[v]) {
    if (u == par) continue;
    dfs(u, k, v);
    for (int i = 0; i <= k; ++i) {
      for (int j = 0; j < Z; ++j)
        tmp[i][j] = dp[v][i][j];
    }
    for (int i = 0; i <= k; ++i) {
      for (int j = 0; i + j - 1 <= k; ++j) {
        int best = max(dp[u][j][2], max(dp[u][j][0], dp[u][j][1]));

        upd(tmp[i + j][0], add(dp[v][i][0], best));
        upd(tmp[i + j][1], add(dp[v][i][1], best));
        upd(tmp[i + j][2], add(dp[v][i][2], best));

        upd(tmp[i + j][1], add(dp[v][i][0], add(c[v], dp[u][j][1])));

        upd(tmp[i + j][1], add(dp[v][i][2], dp[u][j][1]));
        if (i + j > 0) {
          upd(tmp[i + j - 1][2], add(dp[v][i][1], dp[u][j][1]));
        }
      }
    }
    for (int i = 0; i <= k; ++i) {
      for (int j = 0; j < Z; ++j)
        dp[v][i][j] = tmp[i][j];
    }
  }
}

void solve() {
  int n, k = 1;
  scanf("%d %d", &n, &k);
  c.resize(n);
  g.resize(n);
  for (int i = 0; i < n; ++i) {
    g[i].clear();
    scanf("%d", &c[i]);
  }
  for (int i = 0; i < n-1; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= k; ++j) {
      for (int z = 0; z < Z; ++z) {
        dp[i][j][z] = -1;
      }
    }
  }
  dfs(0, k);
  int ans = c[0];
  for (int i = 0; i <= k; ++i) {
    ans = max(ans, dp[0][i][1]);
    ans = max(ans, dp[0][i][2]);
  }
  printf("%d\n", ans);
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
