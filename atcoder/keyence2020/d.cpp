#include <bits/stdc++.h>

using namespace std;

const int N = 18, K = 51, inf = 1e7 + 7;

int dp[1 << N][K];

int a[N], b[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  for (int i = 0; i < n; ++i)
    scanf("%d", b+i);
  int nmask = 1 << n;
  for (int i = 0; i < nmask; ++i) {
    for (int j = 0; j < K; ++j)
      dp[i][j] = inf;
  }
  dp[0][0] = 0;
  for (int mask = 0; mask < nmask; ++mask) {
    int cost = 0, odd = __builtin_popcount(mask) & 1;
    for (int i = 0; i < n; ++i) {
      if (mask & (1 << i)) continue;
      int val = ((odd^i) & 1) ? b[i] : a[i];
      int new_mask = mask | (1 << i);
      for (int j = 0; j <= val; ++j) {
        dp[new_mask][val] = min(dp[new_mask][val], cost + dp[mask][j]);
      }
      ++cost;
    }
  }
  int ans = inf;
  for (int i = 0; i < K; ++i)
    ans = min(ans, dp[nmask-1][i]);
  if (ans >= inf)
    ans = -1;
  printf("%d\n", ans);
  return 0;
}
