#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9 + 7;

void solve() {
  int n, z;
  scanf("%d %d", &n, &z);
  vector<int> p(n), r(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &p[i], &r[i]);
  }
  vector<int> vp = p;
  sort(vp.begin(), vp.end());
  vp.erase(unique(vp.begin(), vp.end()), vp.end());
  for (int i = 0; i < n; ++i) {
    p[i] = lower_bound(vp.begin(), vp.end(), p[i]) - vp.begin();
  }
  vector<vector<pair<int, int>>> pos(n);
  for (int i = 0; i < n; ++i) {
    pos[p[i]].emplace_back(i, r[i]);
  }
  vector<vector<int>> dp(n+1, vector<int>(n+2, inf)), tmp;
  dp[0][n+1] = 0;
  for (int i = 0; i < n; ++i) {
    tmp = dp;
    vector<int> cost(n+1);
    for (int j = 0; j <= n; ++j) {
      int bef = 0, aft = 0;
      for (auto it : pos[i]) {
        if (it.first < j) {
          bef += it.second == 1;
        } else {
          aft += it.second == 0;
        }
      }
      cost[j] = bef + aft;
    }
    for (int j = 0; j <= n; ++j) {
      for (int k = 0; k <= n; ++k) {
        dp[j][k] = tmp[j][k] + cost[k];
      }
      if (cost[n] == 0)
        dp[j][n+1] = tmp[j][n+1];
      else
        dp[j][n+1] = inf;
    }
    for (int j = 0; j <= n; ++j) {
      int all = tmp[j][n+1];
      for (int k = 0; k <= n; ++k) {
        all = min(all, tmp[j][k]);
      }
      if (j + 1 <= n) {
        for (int k = 0; k <= n; ++k) {
          dp[j+1][k] = min(dp[j+1][k], all + cost[k]);
        }
      }
      if (cost[n] == 0)
        dp[j][n+1] = min(dp[j][n+1], all + cost[n]);
    }
  }
  int ans = n+1;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n+1; ++j) {
      if (dp[i][j] > z)
        continue;
      ans = min(ans, i);
    }
  }
  if (ans >= n)
    ans = -1;
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
