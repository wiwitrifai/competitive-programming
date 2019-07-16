#include <bits/stdc++.h>

using namespace std;

const int N = 303, S = N * N, mod = 998244353;
int a[N];

int dp[N][S * 2][3];

void add(int & var, int val) {
  var += val;
  if (var >= mod)
    var -= mod;
}

int main() {
  int n;
  scanf("%d", &n);
  dp[0][S][0] = 1;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    for (int j = 0; j < 2 * S; ++j) {
      for (int k = 0; k < 3; ++k) {
        int now = dp[i][j][k];
        if (now == 0) continue;
        // cerr << i << " " << j-S << " " << k << " = " << now << endl;
        if (j + a[i] < 2 * S) {
          add(dp[i+1][j+a[i]][k], now);
        }
        if (j - a[i] >= 0) {
          if (k == 0)
            add(dp[i+1][j-a[i]][1], now);
          else {
            add(dp[i+1][j-a[i]][k], now);
            add(dp[i+1][j-a[i]][min(k+1, 2)], now);
          }
        }
      }
    }
  }
  int ans = 1;
  for (int i = 0; i < n; ++i)
    ans = (1LL * ans * 3) % mod;
  int sum = 0;
  for (int i = S; i < 2 * S; ++i) {
    int mul = 3;
    for (int k = 0; k <= 2; ++k) {
      if (dp[n][i][k] == 0) continue;
      // cerr << i - S << " " << k << " " << dp[n][i][k] << endl;
      if (k)
        mul = 6;
      if (k == 1 && i == S)
        mul = 3;
      add(sum, 1LL * mul * dp[n][i][k] % mod);
    }
  }
  // cerr << sum << endl;
  ans = (ans - sum) % mod;
  if (ans < 0) ans += mod;
  printf("%d\n", ans);
  return 0;
}
