#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353, N = 3030;

long long dp[N][N][2];

void add(long long & var, long long val) {
  var += val;
  if (var >= mod)
    var -= mod;
}

int main() {
  int a, b, c, d;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  dp[a][b][0] = 1;
  for (int i = a; i <= c; ++i) {
    for (int j = b; j <= d; ++j) {
      add(dp[i+1][j][0], dp[i][j][0] * j % mod);
      add(dp[i][j+1][1], dp[i][j][0] * i % mod);
      add(dp[i+1][j][0], dp[i][j][1]);
      add(dp[i][j+1][1], dp[i][j][1] * i % mod);
    }
  }
  long long ans = (dp[c][d][0] + dp[c][d][1]) % mod;
  printf("%lld\n", ans);
  return 0;
}
