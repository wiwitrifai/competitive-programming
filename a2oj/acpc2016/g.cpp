#include <bits/stdc++.h>

using namespace std;

const int inf = 1e7;
int dp[2][4];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    memset(dp, 0, sizeof dp);
    int last = 0;
    char s[2][10];
    scanf("%s", s[0]);
    for (int i = 0; i < 4; i++)
      dp[0][i] = inf;
    dp[0][0] = 0;
    for (int i = 1; i < n; i++) {  
      int c = i & 1, b = !c;
      scanf("%s", s[c]);
      for (int j = 0; j < 4; j++) {
        dp[c][j] = inf;
        for (int k = 0; k < 4; k++) {
          if (j == 3 && s[c][0] == s[b][0] && s[c][1] == s[b][1]) {
            dp[c][j] = min(dp[c][j], dp[b][k]);
          }
          if (j == 2 && s[c][0] == s[b][0]) {
            if ((k & 1) == 1)
              dp[c][j] = min(dp[c][j], dp[b][k]);
            else
              dp[c][j] = min(dp[c][j], dp[b][k]+1);
          }
          if (j == 1 && s[c][1] == s[b][1]) {
            if ((k & 2)== 2)
              dp[c][j] = min(dp[c][j], dp[b][k]);
            else
              dp[c][j] = min(dp[c][j], dp[b][k]+1);
          }
          if (j == 0 && k == 0  && s[b][0] == s[b][1])
            dp[c][j] = min(dp[c][j], dp[b][k]);
          if (j == 0) {
            dp[c][j] = min(dp[c][j], dp[b][k] + 2 - __builtin_popcount(k));
          }
        }
        // cerr << dp[c][j] << " " ;
      }
      // cerr << i << endl;
    }
    int ans = inf, c = !(n & 1);
    for (int i = 0; i < 4; i++) {
      int tmp = dp[c][i] + 2 - __builtin_popcount(i);
      if (i == 0 && s[c][0] == s[c][1])
        tmp -= 2;
      ans = min(ans, tmp);
    }
    printf("%d\n", ans);
  }
  return 0;
}