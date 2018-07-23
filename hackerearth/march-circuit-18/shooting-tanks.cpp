#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

long long h[N][N], v[N][N];

long long dp[N][N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      scanf("%lld", h[i]+j);
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      scanf("%lld", v[i]+j);
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j)
      v[i][j] += v[i][j-1];
    for (int j = n; j >= 1; --j)
      h[i][j] += h[i][j+1];
  }
  for (int i = 1; i <= n; ++i) {
    long long now = 0;
    for (int j = n; j >= 0; --j) {
      now = max(now, dp[i-1][j]);
      long long cur = h[i][j+1] + v[i][j];
      dp[i][j] = cur + now;
    }
  }
  long long ans = 0;
  for (int i = 0; i <= n; ++i)
    ans = max(dp[n][i], ans);
  printf("%lld\n", ans);
  return 0;
}