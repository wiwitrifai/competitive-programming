#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

long long dp[N][4];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    dp[0][0] = 1;
    dp[0][1] = dp[0][2] = dp[0][3] = 0;
    int ma = max(a, max(b, c));
    for (int i = 1; i <= ma; i++) {
      int now = (i <= a) + (i <= b) + (i <= c);
      dp[i][0] = dp[i-1][0];
      dp[i][1] = dp[i-1][1];
      dp[i][2] = dp[i-1][2];
      dp[i][3] = dp[i-1][3];
      if (now == 3) {
        dp[i][1] += dp[i-1][0] * 3;
        dp[i][2] += dp[i-1][1] * 2;
        dp[i][2] += dp[i-1][0] * 3;
        dp[i][3] += dp[i-1][2];
        dp[i][3] += dp[i-1][1];
        dp[i][3] += dp[i-1][0];
      }
      else if (now == 2) {
        dp[i][2] += dp[i-1][1] * 2;
        dp[i][3] += dp[i-1][2];
        dp[i][3] += dp[i-1][1];
      }
      else if (now == 1) {
        dp[i][3] += dp[i-1][2];
      }
    }
    printf("%lld\n", dp[ma][3]);
  }
  return 0;
}