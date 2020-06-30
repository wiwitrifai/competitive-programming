#include <bits/stdc++.h>

using namespace std;

const int N = 66;

string val[N][N];

int dp[N][N];
pair<int, int> pre[N][N];
char a[N], b[N];

void solve() {
  scanf("%s %s", a, b);
  int na = strlen(a), nb = strlen(b);
  for (int i = 0; i <= na; ++i) {
    for (int j = 0; j <= nb; ++j) {
      dp[i][j] = na + nb;
      val[i][j] = "";
    }
  }
  dp[0][0] = 0;
  for (int i = 0; i <= na; ++i) {
    for (int j = 0; j <= nb; ++j) {
      if (i + 1 <= na && dp[i+1][j] > dp[i][j] + 1) { // delete
        dp[i+1][j] = dp[i][j] + 1;
        val[i+1][j] = val[i][j];
        pre[i+1][j] = {i, j};
      }
      if (j + 1 <= nb && dp[i][j+1] > dp[i][j] + 1) { // insert
        dp[i][j+1] = dp[i][j] + 1;
        val[i][j+1] = val[i][j];
        val[i][j+1].push_back(b[j]);
        pre[i][j+1] = {i, j};
      }
      if (i+1 <= na && j+1 <= nb) {
        int cost = (a[i] != b[j]);
        if (dp[i+1][j+1] > dp[i][j] + cost) {
          dp[i+1][j+1] = dp[i][j] + cost;
          val[i+1][j+1] = val[i][j];
          val[i+1][j+1].push_back(b[j]);
          pre[i+1][j+1] = {i, j};
        }
      }
    }
  }
  int d = dp[na][nb];
  string ans = a;
  int x = na, y = nb;
  while (d/2 != dp[x][y] && (x || y)) {
    pair<int, int> p = pre[x][y];
    x = p.first;
    y = p.second;
  }
  ans = val[x][y] + string(a + x);
  printf("%s\n", ans.c_str());
}

int main() {
#ifdef LOCAL
  time_t starttime = clock();
#endif
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    printf("Case #%d: ", tc);
    solve();
#ifdef LOCAL
    cerr << "~ TC#" << tc << " done! execution time: " <<
      (double)(clock()-starttime) / CLOCKS_PER_SEC << " s" << endl;
#endif
  }
  return 0;
}
