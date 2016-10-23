/**
  IEEExtreme Programming Contest 10
  Problem : N-Palindromes
  Solver  : Luqman Arifin S
  Status  : Accepted
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 505;
const long long mod = 1e9 + 7;

long long dp[N][N];
char s[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(dp, 0, sizeof(dp));
    int change;
    scanf("%d %s", &change, s);
    int n = strlen(s);
    int til = (n - 1) / 2;
    dp[0][0] = 1;
    for (int i = 0; i <= til; i++) {
      int j = n - 1 - i;
      for (int k = 0; k <= change; k++) {
        if (i == j) {
          dp[i + 1][k] += dp[i][k];
          dp[i + 1][k] %= mod;
          dp[i + 1][k + 1] += dp[i][k] * 25;
          dp[i + 1][k + 1] %= mod;
        } else if (s[i] == s[j]) {
          dp[i + 1][k] += dp[i][k];
          dp[i + 1][k] %= mod;
          dp[i + 1][k + 2] += dp[i][k] * 25;
          dp[i + 1][k + 2] %= mod;
        } else {
          dp[i + 1][k + 1] += dp[i][k] * 2;
          dp[i + 1][k + 1] %= mod;
          dp[i + 1][k + 2] += dp[i][k] * 24;
          dp[i + 1][k + 2] %= mod;
        }
      }
    }
    printf("%lld\n", dp[til + 1][change]);
  }

  return 0;
}
