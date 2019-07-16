#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int a[N], n, x;
long long dp[N][5];

void upd(long long & var, long long val) {
  if (var < val)
    var = val;
}

int main() {
  scanf("%d %d", &n, &x);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  memset(dp, 0, sizeof dp);
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    upd(dp[i+1][0], dp[i][0]);
    upd(dp[i+1][1], max(dp[i][0], dp[i][1]) + a[i]);
    upd(dp[i+1][2], max(dp[i][1], dp[i][2]) + 1LL * a[i] * x);
    upd(dp[i+1][3], max(dp[i][2], dp[i][3]) + a[i]);
    upd(dp[i+1][4], max(dp[i][3], dp[i][4]));
    for (int j = 0; j + 1 < 5; ++j)
      upd(dp[i+1][j+1], dp[i+1][j]);
  }
  printf("%lld\n", dp[n][4]);
  return 0;
}
