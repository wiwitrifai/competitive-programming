#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
int dp[15][606][2];
int main() {
  int n, m;
  scanf("%d%d%*d", &n, &m);
  dp[0][0][0] = 1;
  for(int i = 1; i<=m; i++) {
    for(int j = 1; j<=n; j++) {
      for(int k = 1; k<=j; k++) {
        dp[i][j][0] += (dp[i-1][j-k][(k&1) ? 0 : 1]);
        dp[i][j][0] %= mod;
        dp[i][j][1] += (dp[i-1][j-k][(k&1) ? 1 : 0]);
        dp[i][j][1] %= mod;
      }
    }
  }
  cout << dp[m][n][1] << endl;

  return 0;
}