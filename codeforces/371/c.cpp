#include <bits/stdc++.h>

using namespace std;

const int N = 3e3 + 5;

long long dp[N][N], v[N];
int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
    a[i] -= i;
    v[i] = a[i];
  }
  sort(v, v+n);
  int m = unique(v, v+n)-v;
  for (int i = 0; i < m; i++) {
    dp[0][i] = abs(v[i] - a[0]);
    if (i)
      dp[0][i] = min(dp[0][i], dp[0][i-1]);
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < m; j++) {
      dp[i][j] = abs(a[i] - v[j]) + dp[i-1][j];
      if (j)
        dp[i][j] = min(dp[i][j], dp[i][j-1]);
    }
  }
  printf("%lld\n", dp[n-1][m-1]);
  return 0;
}