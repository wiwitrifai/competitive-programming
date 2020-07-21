#include <bits/stdc++.h>

using namespace std;

const int N = 4040;

int dp[N][N], p[N];
int maxi[N][N];

void solve() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < 2 * n; ++i) {
    scanf("%d", p+i);
  }
  int n2 = 2 * n;
  for (int i = 0; i < n2; ++i) {
    int cur = 0;
    for (int j = i; j < n2; ++j) {
      cur = max(cur, p[j]);
      maxi[i][j+1] = cur;
    }
  }
  fill(dp[0], dp[0] + 2 * n + 1, -1);
  dp[0][0] = 0;
  for (int i = 0; i < 2 * n; ++i) {
    fill(dp[i+1], dp[i+1] + 2 * n + 1, -1);
    for (int j = 0; j <= i; ++j) {
      if (dp[i][j] < 0) continue;
      int res = dp[i][j];
      dp[i+1][j+1] = max(dp[i+1][j+1], res);
      if (maxi[res][i] < p[i])
        dp[i+1][(i-j) + 1] = i;
    }
  }
  puts(dp[n2][n] >= 0 ? "YES" : "NO");
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
