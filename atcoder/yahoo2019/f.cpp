#include <bits/stdc++.h>

using namespace std;

const int N = 4040, mod = 998244353;

int dp[N][N], C[N][N];
char s[N];

void add(int & var, int x) {
  var += x;
  if (var >= mod)
    var -= mod;
}

int main() {
  for (int i = 0; i < N; ++i) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; ++j)
      C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
  }
  dp[0][0] = 1;
  scanf("%s", s);
  int n = strlen(s);
  for (int i = 0; i < n; ++i)
    s[i] -= '0';
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      if (dp[i][j] == 0) continue;
      int b = j + s[i], r = 2 * i - j + (2 - s[i]);
      if (b)
        add(dp[i+1][b-1], dp[i][j]);
      if (r)
        add(dp[i+1][b], dp[i][j]); 
    }
  }
  long long ans = 0;
  for (int i = 0; i <= n; ++i) {
    ans = (ans + 1LL * C[n][i] * dp[n][i]) % mod;
  }
  if (ans < 0) ans += mod;
  printf("%lld\n", ans);
  return 0;
}