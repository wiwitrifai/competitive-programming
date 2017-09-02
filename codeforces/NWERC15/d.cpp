#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

long long dp[N], r, p;

long long solve(int n) {
  if (n <= 1) return 0;
  if (dp[n] != -1) return dp[n];
  long long & ret = dp[n];
  ret = 1LL * p * (n - 1) + r;
  for (int k = 2; k * k <= n; k++) {
    ret = min(ret, solve((n+k-1)/k) + 1LL * (k-1) * p + r); 
    int x = (n + k -1) / k;
    if (x != k) {
      ret = min(ret, solve((n + x - 1) / x) + 1LL * (x-1) * p + r);
    }
  }
  return ret;
}

int main() {
  memset(dp, -1, sizeof dp);
  int n;
  cin >> n >> r >> p;
  cout << solve(n) << endl;
  return 0;
}