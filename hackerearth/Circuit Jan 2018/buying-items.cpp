#include <bits/stdc++.h>

using namespace std;
long long dp[1 << 22];
int c[505][505];
int ada[505];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j <= n; ++j)
      scanf("%d", c[i]+j);
  }
  long long all = 0;
  for (int i = 0; i < m; ++i)
    all += c[i][n];
  if (n < m) {
    int nmask = 1 << n;
    fill(dp, dp+nmask, all);
    dp[0] = 0;
    for (int i = 0; i < m; ++i) {
      int now = c[i][n], mask = 0;
      for (int j = 0; j < n; ++j)
        mask |= c[i][j] << j;
      for (int j = 0; j < nmask; ++j)
        dp[mask|j] = min(dp[mask|j], dp[j] + now);
    }
    printf("%lld\n", dp[nmask-1]);
  }
  else {
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j)
        ada[j] |= c[i][j] << i;
    }
    long long ans = all;
    int nmask = 1 << m;
    for (int mask = 0; mask < nmask; ++mask) {
      bool ok = 1;
      for (int j = 0; j < n; ++j)
        ok &= (mask & ada[j]) != 0;
      if (ok) {
        long long now = 0;
        for (int j = 0; j < m; ++j)
          if (mask & (1 << j))
            now += c[j][n];
        ans = min(ans, now);
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}