#include <bits/stdc++.h>

using namespace std;

const int N = 1024;
int mod;

int dp[N][N];

int solve(int n, int m) {
  n = min(m, n);
  if (n <= 1)
    return 1;
  int & ret = dp[n][m];
  if (ret != -1)
    return ret;
  ret = solve(n-1, m);
  if (m >= n) {
    ret += solve(n, m-n);
    if (ret >= mod)
      ret -= mod;
  }
  return ret;
}

int main() {
  memset(dp, -1, sizeof dp);
  int t;
  scanf("%d %d", &t, &mod);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    printf("%d\n", solve(n, m));
  }
  return 0;
}