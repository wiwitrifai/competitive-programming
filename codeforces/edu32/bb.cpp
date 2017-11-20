
#include <bits/stdc++.h>

using namespace std;

const int N = 2048, inf = 1e9 + 7;

int dp[N][N];
int acc[2][N];
int n;

int a[N];

int main() {
  scanf("%d %d %d", &n, a, a+1);
  for (int i = 0; i < n; i++)
    scanf("%d", a+2+i);
  n += 2;
  for (int i = 0; i <= n; i++)
    acc[0][i] = inf;
  for (int i = 0; i <= n; i++)
    acc[1][i] = 0;
  for (int j = n-1; j >= 0; j--) {
    for (int i = n-2; i > j; i--) {
      // minimize
      dp[i][j] = min(abs(a[i]-a[n-1]), acc[0][i]);
      acc[1][j] = max(dp[i][j], acc[1][j]);
      // maximize
      dp[j][i] = max(abs(a[i]-a[n-1]), acc[1][i]);
      acc[0][j] = min(dp[j][i], acc[0][j]);
    }
  }
  printf("%d\n", dp[0][1]);
  return 0;
}