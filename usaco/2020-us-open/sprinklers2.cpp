#include <bits/stdc++.h>

using namespace std;

const int N = 2020, mod = 1e9 + 7;

long long powmod(long long b, long long p) {
  long long r = 1;
  if (p < 0)
    p += mod - 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

char grid[N][N];
long long dp[N][N];
int cnt[N];

int main() {
  const string prob = "sprinklers2";
  freopen((prob + ".in").c_str(), "r", stdin);
  freopen((prob + ".out").c_str(), "w", stdout);

  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", grid[i]);
    cnt[i] = 0;
    for (int j = 0; j < n; ++j) {
      cnt[i] += grid[i][j] != 'W';
    }
  }
  dp[0][0] = powmod(2, cnt[0]-1);
  for (int i = 0; i < n; ++i) {
    if (grid[0][i] == 'W') continue;
    dp[0][i+1] = powmod(2, cnt[0] - 1 - (i < n-1));
  }
  for (int i = 1; i < n; ++i) {
    long long now = powmod(2, cnt[i]);
    for (int j = 0; j <= n; ++j) {
      dp[i][j] = dp[i-1][j] * now % mod;
    }
    long long sum = 0;
    now = powmod(2, cnt[i] - 2);
    for (int j = 0; j < n; ++j) {
      if (j > 0 && grid[i][j-1] != 'W')
        dp[i][j] = (dp[i][j] + sum * now) % mod;
      if (grid[i-1][j] != 'W') {
        sum = (sum + dp[i-1][j]) % mod;
      }
    }
    if (grid[i][n-1] != 'W')
      dp[i][n] = (dp[i][n] + sum * powmod(2, cnt[i]-1)) % mod;
  }
  long long ans = 0;
  for (int i = 0; i <= n; ++i) {
    if (i < n && grid[n-1][i] == 'W') continue;
    ans = (ans + dp[n-1][i]) % mod;
  }
  if (ans < 0)
    ans += mod;
  printf("%lld\n", ans);
  fclose(stdin);
  fclose(stdout);
  return 0;
}
