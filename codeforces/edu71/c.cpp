#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

const long long inf = 1e18;

char s[N];
long long dp[N][2];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    long long a, b;
    scanf("%d %lld %lld %s", &n, &a, &b, s);
    dp[0][0] = 0;
    dp[0][1] = inf;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '1') {
        dp[i+1][0] = inf;
        dp[i+1][1] = dp[i][1] + b;
      }
      else {
        dp[i+1][0] = min(dp[i][0], dp[i][1] + a);
        dp[i+1][1] = min(dp[i][1], dp[i][0] + a) + b;
      }
    }
    long long ans = dp[n][0] + 1LL * n * a + 1LL * (n + 1) * b;
    printf("%lld\n", ans);
  }
  return 0;
}
