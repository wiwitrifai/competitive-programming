#include <bits/stdc++.h>

using namespace std;

const int N = 15, inf = 1e8;

int dp[1<<N];
int a[N][N];
int n;

int solve(int mask) {
  if (mask == 0)
    return inf;
  if (dp[mask] >= 0)
    return dp[mask];
  int &ret = dp[mask];
  ret = 0;
  for (int i = 0; i < n; i++) if ((mask & (1<<i))) {
    for (int j = i+1; j < n; j++) if (mask & (1<<j))
      for (int k = j+1; k < n; k++) if (mask & (1<<k)) {
        ret = max(ret, min(solve(mask ^ (1<<i) ^ (1<<j) ^ (1<<k)), a[i][j] + a[j][k] + a[k][i]));
      }
    break;
  }
  return ret;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    scanf("%d", &n);
    n *= 3;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        scanf("%d", a[i]+j);
    memset(dp, -1, sizeof dp);
    printf("Case #%d: %d\n", tc, solve((1<<n)-1));
  }

  return 0;
}