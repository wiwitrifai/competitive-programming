#include <bits/stdc++.h>

using namespace std;

const int N = 77;
const long long inf = 1e18;

long long dp[N][N * N], sum[N];
int a[N];

int main() {
  int n, k;
  long long m;
  scanf("%d %d %I64d", &n, &k, &m);
  for (int i = 0; i < k; i++)
    scanf("%d", a+i);
  sort(a, a+k);
  sum[0] = 0;
  for (int i = 0; i < k; i++)
    sum[i+1] = sum[i] + a[i];
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n *(k + 1); j++)
      dp[i][j] = inf;
  dp[0][0] = 0;
  int tot = n * (k + 1);
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= tot; j++) {
      if (dp[i][j] >= inf) continue;
      for (int z = 0; z <= k; z++) {
        dp[i+1][j+z] = min(dp[i+1][j+z], dp[i][j] + sum[z]);
      }
      dp[i+1][j+k+1] = min(dp[i+1][j+k+1], dp[i][j] + sum[k]);
    }
  }
  int ans = 0;
  for (int i = 0; i <= tot; i++) {
    if (dp[n][i] > m) continue;
    ans = max(ans, i);
  }
  printf("%d\n", ans);
  return 0;
}