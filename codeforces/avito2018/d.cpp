#include <bits/stdc++.h>

using namespace std;

const int N = 55;

long long a[N];
long long sum[N];
int dp[N][N];
int n, k;
bool can(long long ans) {
  memset(dp, 0, sizeof dp);
  dp[0][0] = 1;
  for (int i = 0; i <= n; ++i) {
    for (int z = i+1; z <= n; ++z) {
      if (((sum[z]-sum[i]) & ans) == ans) {
        for (int j = 0; j <= k; ++j) {
          if (dp[i][j] == 0) continue;
          dp[z][j+1] = 1;
        }
      }
    }
  }
  return dp[n][k];
}

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", a+i);
  }
  sum[0] = 0;
  for (int i = 0; i < n; ++i)
    sum[i+1] = sum[i] + a[i];
  long long ans = 0;
  for (int i = 60; i >= 0; --i) {
    if (can(ans|(1LL << i)))
      ans |= 1LL << i;
  }
  printf("%lld\n", ans);
  return 0;
}