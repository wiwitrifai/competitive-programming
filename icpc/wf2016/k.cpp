// by wiwit
#include <bits/stdc++.h>

using namespace std;

const int N = 2e4 + 5;

int presum[N];
int dig[N];
int get(int l, int r) {
  return presum[r+1] - presum[l];
}

bool dp[N][101][2];

int main() {
  int n;
  scanf("%d", &n);
  int len = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    if (i)
      dig[len++] = 0;
    while (a--) dig[len++] = 1;
  }
  for (int i = 0; i < len; ++i)
    presum[i+1] = presum[i] + dig[i];
  n = len;
  int ans = 0;
  for (int k = 90; k > 0; --k) {
    if (get(0, k-1) != k) continue;
    if (get(n-k, n-1) != k) continue;
    if (2 * (k-1) >= n) continue;
    for (int i = 0; i <= n; ++i)
      for (int j = 0; j <= k; ++j)
        dp[i][j][0] = dp[i][j][1] = 0;
    dp[k][k][0] = 1;
    if (k == 1)
      dp[k][k][1] = 1;
    for (int i = k; i < n-k; ++i) {
      if (dig[i] == 0) {
        for (int j = 0; j <= k; ++j)
          for (int z = 0; z < 2; ++z)
            dp[i+1][j][z] |= dp[i][j][z];
      }
      for (int j = 1; j <= k; ++j) 
        for (int z = 0; z < 2; ++z) {
          if (!dp[i][j][z]) continue;
          if (j == 1)
            dp[i][j][1] = 1;
          if (z && get(i, i+j-1) == j)
            dp[i+j][j+1][z] = 1;
          if (j > 1 && get(i, i+j-2) == j-1)
            dp[i+j-1][j-1][0] = 1;
        }
    }
    if (dp[n-k][k][1]) {
      ans = k;
      break;
    }
  }
  if (ans < 1)
    puts("no quotation");
  else
    printf("%d\n", ans);
  return 0;
}