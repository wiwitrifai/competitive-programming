#include <bits/stdc++.h>

using namespace std;

const int N = 5050;
const long long inf = 1e18;

long long dp[N][N];
int p[N];

void upd(long long &a, long long b) {
  if (a > b)
    a = b;
}

int main() {
  int n, a, b;
  scanf("%d %d %d", &n, &a, &b);
  for (int i = 0; i < n; ++i) {
    scanf("%d", p+i);
  }
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= n; ++j)
      dp[i][j] = inf;
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= n; ++j) {
      if (dp[i][j] >= inf) continue;
      upd(dp[i+1][j], dp[i][j] + (j > p[i] ? b : a));
      if (j < p[i])
        upd(dp[i+1][p[i]], dp[i][j]);
    }
  }
  long long ans = inf;
  for (int j = 0; j <= n; ++j)
    upd(ans, dp[n][j]);
  printf("%lld\n", ans);
  return 0;
}