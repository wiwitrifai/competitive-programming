#include <bits/stdc++.h>

using namespace std;

const int N = 102, OFF = N * N;

int dp[2][N][OFF+OFF], a[N], b[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  for (int i = 0; i < n; i++)
    scanf("%d", b+i);
  memset(dp, -1, sizeof dp);
  dp[0][0][OFF] = 0;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int bef = i & 1, cur = !bef;
    sum += b[i];
    for (int j = 0; j <= i+1; j++) {
      for (int k = -sum; k <= sum; k++) {
        int val = k+a[i];
        int &now = dp[cur][j][k+OFF];
        now = -1;
        if (val < OFF) {
          val += OFF; 
          int dpbef = dp[bef][j][val];
          if (dpbef >= 0)
            now = dp[bef][j][val] + a[i];
        }
        val = k-b[i]+a[i]+OFF;
        if (j > 0 && val >= 0) {
          int dpbef = dp[bef][j-1][val];
          if (dpbef >= 0 && (now == -1 || dpbef < now))
            now = dpbef;
        }
      }
    }
  }
  int last = n & 1;
  int ans1 = -1, ans2 = sum;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= sum; j++) {
      if (dp[last][i][j+OFF] >= 0) {
        ans1 = i;
        ans2 = min(ans2, dp[last][i][j+OFF]);
      }
    }
    if (ans1 >= 0)
      break;
  }
  printf("%d %d\n", ans1, ans2);
  return 0;
}