#include <bits/stdc++.h>

using namespace std;

const int N = 5050, inf = 1e9 + 7;

char a[N], b[N];
int dp[N][N][2], n, m;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &m);
    scanf("%s %s", a, b);
    n = unique(a, a+n) - a;
    m = unique(b, b+m) - b;
    for (int i = 0; i <= n; ++i)
      for (int j = 0; j <= m; ++j)
        dp[i][j][0] = dp[i][j][1] = inf;
    dp[0][1][1] = 1;
    dp[1][0][0] = 1;
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= m; ++j) {
        if (dp[i][j][0] < inf) {
          if (i < n)
            dp[i+1][j][0] = min(dp[i+1][j][0], dp[i][j][0] + (a[i-1] != a[i]));
          if (j < m)
            dp[i][j+1][1] = min(dp[i][j+1][1], dp[i][j][0] + (a[i-1] != b[j]));
        }
        if (dp[i][j][1] < inf) {
          if (i < n)
            dp[i+1][j][0] = min(dp[i+1][j][0], dp[i][j][1] + (b[j-1] != a[i]));
          if (j < m)
            dp[i][j+1][1] = min(dp[i][j+1][1], dp[i][j][1] + (b[j-1] != b[j]));
        }
      }
    }
    printf("%d\n", min(dp[n][m][0], dp[n][m][1]));
  }
  return 0;
}