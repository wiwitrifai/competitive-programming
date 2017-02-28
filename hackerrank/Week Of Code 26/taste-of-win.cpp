#include <bits/stdc++.h>

using namespace std;

const int N = 5;

long long dp[2][1<<N][1<<N];

int main() {
  for (int m = 1; m <= N; m++) {
    memset(dp, 0, sizeof dp);
    dp[0][0][0] = 1;
    long long mul = 1;
    for (int n = 1; n <= N * 3; n++) {
      int c = n & 1, b = !c;
      long long sum = 0;
      for (int i = 0; i < (1<<m); i++) {
        for (int j = 0; j < (1<<m); j++) {
          dp[c][i][j] = 0;
          for (int k = 0; k < j; k++) {
            dp[c][i][j] += dp[b][i^j][k];
          }
          if (i == 0)
            sum += dp[c][i][j];
        }
      }
      cout << m << " " << n << " " << sum << endl;
    }
  }

  return 0;
}