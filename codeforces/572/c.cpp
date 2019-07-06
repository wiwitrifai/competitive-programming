// AC
#include <bits/stdc++.h>

using namespace std;

const int A = 1e5 + 5, N = 1024, mod = 998244353;

int n, k;
int a[N];
int dp[N][N];

int add(int & x, int y) {
  x += y;
  if (x >= mod)
    x -= mod;
  return x;
}

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  sort(a, a+n);
  for (int i = 1; i <= n; ++i)
    dp[i][1] = i;
  int ans = 0;
  for (int b = A / (k-1); b > 0; --b) {
    for (int i = 0, j = 0; i < n; ++i) {
      while (j <= i && a[i] - a[j] >= b) ++j;
      for (int c = 2; c <= k; ++c) {
        dp[i+1][c] = dp[i][c];
        add(dp[i+1][c], dp[j][c-1]);
      }
    }
    add(ans, dp[n][k]);
  }
  printf("%d\n", ans);
  return 0;
}
