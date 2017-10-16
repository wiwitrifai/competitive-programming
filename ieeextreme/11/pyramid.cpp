#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, mod = 1e9 + 7, L = 19;

long long dp[L][N];
long long ans[N], C[L][L];

void upd(long long &le, long long ri) {
  le += ri;
  if (le >= mod)
    le -= mod;
}

int main() {
  long long sum = 0;
  for (int i = 0; i < L; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++)
      C[i][j] = C[i-1][j-1] + C[i-1][j];
    for (int j = 0; j <= i; j++)
      sum += N/C[i][j];
  }
  for (int len = 1; len < L; len++) {
    memset(dp, 0, sizeof dp);
    dp[0][1] = 1;
    for (int i = 0; i < len; i++) {
      for (int x = 0; x < N; x++) {
        if (x + C[len-1][i] < N) {
          upd(dp[i][x+C[len-1][i]], dp[i][x]);
          if (i + 1 < len) {
            if (x + C[len-1][i+1] < N)
              upd(dp[i+1][x + C[len-1][i+1]], dp[i][x]);
          }
          else {
            upd(dp[i+1][x], dp[i][x]);
          }
        }
      }
    }
    for (int i = 0; i < N; i++)
      upd(ans[i], dp[len][i]); 
  }
  int s;
  scanf("%d", &s);
  ans[s] %= mod;
  if (ans[s] < 0) ans[s] += mod;
  printf("%lld\n", ans[s]);
  return 0;
}