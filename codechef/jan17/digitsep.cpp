#include <bits/stdc++.h>

using namespace std;

const int N = 333;

set< long long > dp[N][N];

char s[N];
int n, m, x, y;

long long gcd(long long a, long long b) {
  return a ? gcd(b % a, a) : b;
}

int main() {
  int t;
  dp[0][0].insert(0);
  scanf("%d", &t);
  while (t--) {
    scanf("%d %s", &n, s);
    scanf("%d %d %d", &m, &x, &y);
    x++; y++;
    for (int i = 0; i < n; i++)
      s[i] -= '0';
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= y; j++) {
        dp[i][j].clear();
        long long now = 0, mul = 1;
        int mi = min(m, i);
        for (int k = 1; k <= mi; k++) {
          now += mul * s[i-k];
          mul *= 10;
          for (long long u : dp[i-k][j-1])
            dp[i][j].insert(gcd(now, u));
        }
      }
    }
    long long ans = 0;
    for (int i = x; i <= y; i++)
      for (long long u : dp[n][i])
        ans = max(ans, u);
    printf("%lld\n", ans);
  }
  return 0;
}