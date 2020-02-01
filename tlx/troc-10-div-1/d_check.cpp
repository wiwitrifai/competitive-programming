#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int dp[N][N];
int k, l;
int solve(int x, int y) {
  if (x == 0) return 1;
  if (y == 0) return 0;
  if (dp[x][y] != -1) return dp[x][y];
  for (int i = 1; i <= l; ++i) {
    int v = x - i;
    if (v < 0) break;
    if (abs(v - y) > k) continue;
    if (!solve(y, v)) {
      dp[x][y] = 1;
      break;
    }
  }
  if (dp[x][y] == -1)
    dp[x][y] = 0;
  return dp[x][y];
}

int main() {
  int n;
  scanf("%d %d %d", &n, &k, &l);
  memset(dp, -1, sizeof dp);
  for (int i = 1; i <= n; ++i) {
    cerr << i << " " << solve(i, i) << endl;
  }
  return 0;
}
