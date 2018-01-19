#include <bits/stdc++.h>

using namespace std;

const int N = 707;

int a[N][N];
long long dp[N][N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < n; ++j)
        scanf("%d", a[i]+j);
      sort(a[i], a[i]+n);
      for (int j = 0, k = 0; j < n; ++j) {
        while (k < n && a[i-1][k] < a[i][j]) ++k;
        dp[i][j] = (k == 0 || dp[i-1][k-1] < 0) ? -1 : dp[i-1][k-1] + a[i][j];
        if (j)
          dp[i][j] = max(dp[i][j], dp[i][j-1]);
      }
    }
    printf("%lld\n", dp[n][n-1]);
  }
  return 0;
}