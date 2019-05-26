#include <bits/stdc++.h>

using namespace std;

const int N = 1024, inf = 1e9 + 7;

int dp[2][N][2];
int a[N];
vector<int> p[N];

void upd(int & var, int val) {
  if (var > val)
    var = val;
}

void solve(int tc) {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  for (int i = 0; i < N; ++i)
    p[i].clear();
  for (int i = 0; i < n; ++i) {
    int c;
    scanf("%d", &c);
    p[c].push_back(a[i]);
  }
  int c = 0, b = 1;
  for (int i = 0; i <= k; ++i)
    dp[c][i][0] = dp[c][i][1] = inf;
  dp[c][0][0] = 0;
  for (int i = 0; i < N; ++i) {
    if (p[i].empty()) continue;
    sort(p[i].begin(), p[i].end());
    swap(c, b);
    for (int j = 0; j <= k; ++j) {
      dp[c][j][0] = dp[b][j][0];
      dp[c][j][1] = dp[b][j][1];
    }
    for (int j = 1; j <= (int)p[i].size(); ++j) {
      int x = p[i][j-1];
      for (int d = 0; d+j <= k; ++d) {
        upd(dp[c][d+j][0], dp[b][d][0]+2*x);
        upd(dp[c][d+j][1], dp[b][d][1]+2*x);
        upd(dp[c][d+j][1], dp[b][d][0]+x);
      }
    }
  }
  printf("Case #%d: %d\n", tc, dp[c][k][1]);
}

int main() {
  time_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    solve(tc);
    cerr << "~ #" << tc << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << " s" << endl;
  }
  return 0;
}
