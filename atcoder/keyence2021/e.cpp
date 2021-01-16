#include <bits/stdc++.h>

using namespace std;

const int N = 404, inf = 1e9 + 7, impossible = -inf-1;

int a[N], n, kmax;
int dp[N][N][N];

int solve(int l, int r, int k) {
  if (l == 1 && r == n) {
    return k == kmax ? 0 : -inf;
  }
  int & ret = dp[l][r][k];
  if (ret != impossible)
    return ret;
  ret = -inf;
  int sz = r - l + 1;
  if (sz <= k + k) {
    if (l > 1)
      ret = max(ret, solve(l-1, r, k) + a[l-1]);
    if (r < n)
      ret = max(ret, solve(l, r+1, k) + a[r+1]);
  }
  if (k < kmax) {
    if (l > 1 && r < n) {
      if (a[l-1] > a[r+1])
        ret = max(ret, solve(l-1, r, k+1));
      else
        ret = max(ret, solve(l, r+1, k+1));
    } else if (l > 1) {
      ret = max(ret, solve(l-1, r, k+1));
    } else {
      ret = max(ret, solve(l, r+1, k+1));
    }
  }
  return ret;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d", a+i);
  kmax = n / 2;
  for (int i = 0; i <= n+1; ++i) {
    for (int j = 0; j <= n+1; ++j) {
      for (int k = 0; k <= kmax; ++k)
        dp[i][j][k] = impossible;
    }
  }
  for (int i = 0; i <= n; ++i) {
    printf("%d\n", solve(i+1, i, 0));
  }
  return 0;
}
