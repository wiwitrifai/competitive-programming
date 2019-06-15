#include <bits/stdc++.h>

using namespace std;

const int N = 5005 * 5005;

int jual[3][3], beli[3][3];
long long dp[N];

int main() {
  int n;
  scanf("%d", &n);
  int a[3], b[3];
  for (int i = 0; i < 3; ++i)
    scanf("%d", a+i);
  for (int i = 0; i < 3; ++i)
    scanf("%d", b+i);
  for (int i = 0; i < 3; ++i) {
    jual[0][i] = a[i];
    beli[0][i] = b[i];

    jual[1][i] = b[i];
    beli[1][i] = a[i];

    jual[2][i] = a[i];
    beli[2][i] = a[i];
  }
  long long ans = 0;
  for (int k = 0; k < 2; ++k) {
    for (int i = 0; i <= n; ++i) {
      dp[i] = i;
      for (int j = 0; j < 3; ++j) {
        if (jual[k][j] > i) continue;
        dp[i] = max(dp[i-jual[k][j]] + beli[k][j], dp[i]);
      }
      ans = max(ans, dp[i]);
    }
    n = ans;
  }
  printf("%lld\n", ans);
  return 0;
}
