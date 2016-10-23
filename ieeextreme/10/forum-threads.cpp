/**
  IEEExtreme Programming Contest 10
  Problem : Forum Threads
  Solver  : Wiwit Rifa'i
  Status  : Accepted
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1024, inf = 1e8;

int dp[N][N];
int a, n, x[N], p[N], cnt[N];

int main() {
  while (scanf("%d %d", &a, &n) == 2) {
    for (int i = 0; i < n; i++)
      cnt[i] = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", p+i);
      if (p[i] == 0)
        p[i] = i;
      else
        p[i]--;
      int now = p[i];
      while (p[now] != now) {
        now = p[now];
      }
      p[i] = now;
      cnt[now]++;
    }
    int m = 0; 
    for (int i = 0; i < n; i++) if (p[i] == i) {
      x[m++] = cnt[i];
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
      dp[0][i] = -1;
    for (int i = 0; i < m; i++) {
      int ma = inf;
      for (int j = 0; j <= n; j++) {
        dp[i+1][j] = -1; 
        if (dp[i][j] >= 0) {
          ma = min(ma, max(dp[i][j], abs(j-a)));
        }
      }
      for (int j = x[i]; j <= n; j++) {
        dp[i+1][j] = dp[i][j-x[i]];
      }
      if (dp[i+1][x[i]] == -1 || dp[i+1][x[i]] > ma)
        dp[i+1][x[i]] = ma;
    }
    int ans = inf;
    for (int i = 0; i <= n; i++) if (dp[m][i] >= 0) {
      ans = min(ans, max(dp[m][i], abs(i-a)));
    } 
    printf("%d\n", ans);
  }
  return 0;
}