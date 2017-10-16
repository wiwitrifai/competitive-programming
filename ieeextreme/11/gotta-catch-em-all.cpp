#include <bits/stdc++.h>

using namespace std;

const int N = 202;

int dp[N][N], a[N][N], n, m;

bool can(int x) {
  // cerr << x << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!i && !j) {
        dp[i][j] = x;
        continue;
      }
      dp[i][j] = 0;
      if (i && dp[i-1][j] > 0)
        dp[i][j] = max(dp[i-1][j] + a[i][j], dp[i][j]);
      if (j && dp[i][j-1] > 0)
        dp[i][j] = max(dp[i][j-1] + a[i][j], dp[i][j]);
      // dp[i][j] += a[i][j];
      // cerr << dp[i][j] << " ";
    }
    // cerr << endl;
  }
  return dp[n-1][m-1] > 0;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      scanf("%d", a[i]+j);
  }
  int lo = 0, hi = (n + m) * 1000;
  while (lo < hi) {
    int mid = (lo + hi) >> 1;
    if (can(mid))
      hi = mid;
    else
      lo = mid + 1;
  }
  printf("%d\n", lo);
  return 0;
}