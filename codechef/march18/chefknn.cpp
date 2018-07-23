#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5, mod = 163577857;

int dp[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i)
      dp[i] = 0;
    dp[0] = 1;
    for (int i = 0; i <= k; ++i) {
      long long now = 0;
      for (int j = 0; j <= n; ++j) {
        int bef = dp[j];
        if (i == k && j == n) dp[j] = 0;
        dp[j] += now;
        if (dp[j] >= mod) dp[j] -= mod;
        now = (now + bef * 1LL * (j+1)) % mod;
      }
    }
    cout << dp[n] << endl;
  }
  return 0;
}