#include <bits/stdc++.h>

using namespace std;

const int N = 5050, inf = 1e9 + 7;

int dp[N][N][3];
int a[N];

void upd(int & var, int val) {
  var = min(var, val);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  int m = (n + 1) / 2;
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= m; ++j) {
      for (int z = 0; z < 3; ++z)
        dp[i][j][z] = inf;
    }
  dp[0][0][0] = 0;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      // kosong
      upd(dp[i+1][j][0], dp[i][j][0]);
      if (i >= 1)
        upd(dp[i+1][j][2], dp[i][j][1] + max(0, a[i] - a[i-1] + 1));
      upd(dp[i+1][j][0], dp[i][j][2]);

      // ada
      int cost = (i > 0) ? max(a[i-1] - a[i] + 1, 0) : 0;
      upd(dp[i+1][j+1][1], dp[i][j][0] + cost);
      cost = inf;
      if (i >= 2) {
        int bef = min(a[i-1], a[i-2]-1);
        cost = max(bef - a[i] + 1, 0);
      }
      upd(dp[i+1][j+1][1], dp[i][j][2] + cost);
    }
  }
  for (int j = 1; j <= m; ++j) {
    int ans = min(dp[n][j][0], min(dp[n][j][1], dp[n][j][2]));
    printf("%d%c", ans, j == m ? '\n' : ' ');
  }
  return 0;
}