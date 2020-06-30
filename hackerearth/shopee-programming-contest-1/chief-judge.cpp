#include <bits/stdc++.h>

using namespace std;

const int N = 1024;
const long long inf = 1e18;

int p[N];
long long dp[N][N];

void solve(int tc) {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", p+i);
  }
  for (int i = 0; i <= k; ++i)
    dp[0][i] = inf;
  dp[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= k; ++j) {
      dp[i][j] = dp[i-1][j];
      if (i >= 2 && j >= 2) {
        dp[i][j] = min(dp[i][j], dp[i-2][j-2] + min(p[i-2], p[i-1]));
      }
      if (j)
        dp[i][j] = min(dp[i][j], dp[i-1][j-1] + p[i-1]);
    }
  }
  printf("Case %d: %lld\n", tc, dp[n][k]);
}


int main() {
  int t;
  scanf("%d", &t);
  for (int tc = 1; tc <= t; ++tc) {
    solve(tc);
  }
  return 0;
}
