#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 4, mod = 1e9 + 7;

char g[3][N];
long long dp[N][3];


int main() {
  clock_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; ++tc) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 3; ++i) {
      scanf("%s", g[i]);
    }
    dp[0][0] = 1;
    dp[0][1] = dp[0][2] = 0;
    for (int i = 0; i < n; ++i) {
      dp[i+1][0] = (g[0][i] == '.' && g[1][i] == '.') ? dp[i][1] : 0;
      dp[i+1][2] = (g[2][i] == '.' && g[1][i] == '.') ? dp[i][1] : 0;
      dp[i+1][1] = 0;
      if (g[0][i] == '.' && g[1][i] == '.')
        dp[i+1][1] += dp[i][0];
      if (g[2][i] == '.' && g[1][i] == '.')
        dp[i+1][1] += dp[i][2];
      dp[i+1][1] %= mod;
    }
    int ans = dp[n][2] % mod;
    if (ans < 0)
      ans += mod;
    printf("Case #%d: %d\n", tc, ans);
    cerr << " TC# " << tc << " done ! time : " << (double)(clock() - startt) * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
  }
  return 0;
}