#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7, N = 1e5 + 5;

int dp[N][11];

int solve(int n, int k) {
  if (n == 1) {
    return k == 1;
  }
  int & ret = dp[n][k];
  if (ret != -1)
    return ret;
  ret = solve(n-1, k) * 2 % mod;
  if (k == 0) {
    ++ret;
    if (ret >= mod) ret -= mod;
  }
  for (int i = 0; i <= k; ++i) {
    ret = (ret + 1LL * solve(n-1, i) * solve(n-1, k-i)) % mod;
  }
  // cerr << n << " " << k << " " << ret << endl;
  return ret;
}

int main() {
  int n, k;
  memset(dp, -1, sizeof dp);
  scanf("%d %d", &n, &k);
  printf("%d\n", solve(n, k));
  return 0;
}