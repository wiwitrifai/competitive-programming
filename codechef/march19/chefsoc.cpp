#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, mod = 1e9 + 7;

int dp[N][4], a[N];

void add(int & x, int y) {
  x += y;
  if (x >= mod)
    x -= mod;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    memset(dp[0], 0, sizeof dp[0]);
    dp[0][0] = 1;
    int ans = 1;
    for (int i = 0; i < n; ++i) {
      scanf("%d", a+i);
      if (i == 0) continue;
      memset(dp[i], 0, sizeof dp[i]);
      dp[i][0] = dp[i-1][0];
      if (a[i] == 2) {
        add(dp[i][1], dp[i-1][2]);
        add(dp[i][1], dp[i-1][3]);
      }
      if (i > 1 && a[i-2] == 2) {
        add(dp[i][0], dp[i-2][0]);
        add(dp[i][0], dp[i-1][3]);

        add(dp[i][3], dp[i-2][0]);
        add(dp[i][2], dp[i-1][1]);
      }
      for (int j = 0; j < 4; ++j)
        add(ans, dp[i][j]);
    }
    printf("%d\n", ans);
  }
  return 0;
}