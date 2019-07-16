#include <bits/stdc++.h>

using namespace std;

const int N = 3e4 + 4, S = 101, mod = 1e9 + 7;

int dp[S][N], c[N];

int main() {
  int n, l;
  scanf("%d %d", &n, &l);
  for (int i = 0; i < n; ++i)
    scanf("%d", c+i);
  dp[0][0] = 1;
  for (int i = 0; i < n; ++i) {
    long long sum = 0;
    c[i] *= 2;
    for (int j = 0; j <= l; ++j) {
      if (j >= c[i])
        sum = (sum + mod - dp[i][j-c[i]]) % mod;
      dp[i+1][j] = sum;
      sum = (sum + dp[i][j]) % mod;
    }
  }
  printf("%d\n", dp[n][l]);
  return 0;
}
