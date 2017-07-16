#include <bits/stdc++.h>

using namespace std;

const int N = 2020, inf = 1e9;

int s[N], f[N], d[N];
int dp[N][N];

int main() {
  time_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    n--;
    for (int i = 0; i < n; i++) {
      scanf("%d %d %d", s+i, f+i, d+i);
    }
    int ans = -1;
    for (int i = 0; i <= n; i++)
      for (int j = 0; j <= n; j++)
        dp[i][j] = inf;
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= i; j++) {
        int now = dp[i][j];
        if (now <= s[i]) {
          dp[i+1][j] = min(s[i] + d[i], dp[i+1][j]);
        }
        else {
          int z = (now - s[i] + f[i] - 1) / f[i];
          dp[i+1][j] = min(s[i] + z * f[i] + d[i], dp[i+1][j]);
        }
        now += m;
        if (now <= s[i]) {
          dp[i+1][j+1] = min(s[i] + d[i], dp[i+1][j+1]);
        }
        else {
          int z = (now - s[i] + f[i] - 1) / f[i];
          dp[i+1][j+1] = min(s[i] + z * f[i] + d[i], dp[i+1][j+1]);
        }
      }
    }
    for (int i = 0; i <= n; i++) {
      if (dp[n][i] <= k)
        ans = max(ans, i);
    }
    if (ans < 0)
      printf("Case #%d: IMPOSSIBLE\n", tc);
    else
      printf("Case #%d: %d\n", tc, ans);
    cerr << "~ #" << tc << " done! time : " << (double)(clock()-startt) * 1000/CLOCKS_PER_SEC << " ms" << endl;
  }
  return 0;
}