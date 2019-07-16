#include <bits/stdc++.h>

using namespace std;

int dp[55][366];
const int mod = 360;

int main() {
  int n;
  scanf("%d", &n);
  dp[0][0] = 1;
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    for (int j = 0; j < mod; ++j) {
      if (!dp[i][j]) continue;
      dp[i+1][(j + a) % mod] = 1;
      dp[i+1][(j + mod - a) % mod] = 1;
    }
  }
  puts(dp[n][0] ? "YES" : "NO");
  return 0;
}