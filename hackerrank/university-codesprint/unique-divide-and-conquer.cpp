#include <bits/stdc++.h>

using namespace std;

const int N = 3030;
long long m;
long long dp[N];
long long s[N][N];
long long C[N][N], inv[N];

long long solve(int n);
long long powmod(long long b, long long p) {
  long long ret = 1;
  while (p) {
    if (p & 1)
      ret = (ret * b) % m;
    b = (b * b) % m;
    p >>= 1;
  }
  return ret;
}

long long calc(int n, int lim) {
  if (lim == 1 || n == 0)
    return 1;
  if (lim == 0)
    return 0;
  if (s[n][lim] >= 0)
    return s[n][lim];
  long long & ret = s[n][lim];
  ret = 0;
  long long mul = 1;
  long long slim = (lim * solve(lim)) % m;
  int res = n;
  for (int i = 1; res >= 0; i++) {
    ret = (ret + calc(res, lim-1) * mul) % m;
    mul = (mul * slim) % m;
    mul = (mul * C[res][lim]) % m;
    mul = (mul * inv[i]) % m;
    res -= lim;
  }
  if (ret < 0)
    ret += m;
  return ret;
}

long long solve(int n) {
  if (dp[n] >= 0)
    return dp[n];
  dp[n] = (n * calc(n-1, (n-1)/2)) % m;
  if (dp[n] < 0)
    dp[n] += m;
  return dp[n];
}

int main() {
  memset(dp, -1, sizeof dp);
  memset(s, -1, sizeof s);
  int n;
  cin >> n >> m;
  for (int i = 0; i <= n; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++)
      C[i][j] = (C[i-1][j-1] + C[i-1][j]) % m;
  }
  for (int i = 1; i <= n; i++)
    inv[i] = powmod(i, m-2);
  printf("%lld\n", solve(n));
  return 0;
}