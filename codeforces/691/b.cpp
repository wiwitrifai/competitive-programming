#include <bits/stdc++.h>

using namespace std;

const int N = 102, inf = 1e9 + 7;

int dp[2][N][N * N];

int a[N], b[N];

inline void upd(int & var, int val) {
  if (var < val)
    var = val;
}

int main() {
  int n;
  scanf("%d", &n);
  int tot = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", a+i, b+i);
    tot += a[i];
  }
  int cur = 0, pre = 1;
  auto reset_dp = [&](int c){
    for (int i = 0; i <= n; ++i)
      for (int j = 0; j <= tot; ++j)
        dp[c][i][j] = -inf;
  };
  reset_dp(0);
  reset_dp(1);
  dp[cur][0][0] = 0;
  int curtot = 0;
  for (int i = 0; i < n; ++i) {
    swap(pre, cur);
    int rest = (a[i] - b[i]) * 2;
    reset_dp(cur);
    for (int j = 0; j <= i; ++j) {
      for (int k = 0; k <= curtot; ++k) {
        if (dp[pre][j][k] <= -inf) continue;
        upd(dp[cur][j+1][k + a[i]], dp[pre][j][k] - rest);
      }
    }
    curtot += a[i];
    int add = b[i];
    for (int j = 0; j <= i; ++j) {
      for (int k = 0; k <= curtot; ++k) {
        if (dp[pre][j][k] <= -inf) continue;
        upd(dp[cur][j][k], dp[pre][j][k] + add);
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    int ans = -inf;
    for (int k = 0; k <= tot; ++k) {
      if (dp[cur][i][k] <= -inf) continue;
      int now = k * 2 + min(dp[cur][i][k], 0);
      ans = max(ans, now);
    }
    printf("%d.%d000000000%c", ans/2, (ans & 1) * 5, i == n ? '\n' : ' ');
  }
  return 0;
}
