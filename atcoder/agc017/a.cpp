#include <bits/stdc++.h>

using namespace std;

long long dp[55][2];

int a[55];

int main() {
  int n, p;
  scanf("%d %d", &n, &p);
  dp[0][0] = 1;
  dp[0][1] = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
    a[i] &= 1;
    dp[i+1][0] = dp[i][0];
    dp[i+1][1] = dp[i][1];
    dp[i+1][a[i]] += dp[i][0];
    dp[i+1][a[i]^1] += dp[i][1];
  }
  cout << dp[n][p] << endl;
  return 0;
}