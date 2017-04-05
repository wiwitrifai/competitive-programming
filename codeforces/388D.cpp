#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long powmod(long long b, long long p) {
  long long ret = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1) ret = ret * b % mod;
  return ret;
}

const int N = 40;
long long dp[N][N], full[N], dp2[N][N][2];
int k, b[N];

int main() {
  dp[0][0] = 1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= i; j++) {
      if (dp[i][j] == 0) continue;
      long long now = dp[i][j];
      for (int k = i+1; k < N; k++) {
        int l = j + k-i-1;
        dp[k][l] = (dp[k][l] + now * powmod(2, l)) % mod;
      }
    }
  }
  for (int i = 0; i < N; i++) {
    full[i] = i ? full[i-1] : 0;
    for (int j = 0; j <= i; j++) {
      full[i] += dp[i][j];
      if (full[i] >= mod) full[i] -= mod;
    }
  }
  cin >> k;
  if (k == 0) {
    puts("1");
    return 0;
  }
  int n = 0;
  while (k) {
    b[n++] = k&1;
    k >>= 1;
  }
  reverse(b, b+n);
  dp2[1][1][0] = 1;
  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= i; j++) {
      for (int k = 0; k < 2; k++) {
        long long & now = dp2[i][j][k];
        // zero
        int nk = k | b[i];
        dp2[i+1][j][nk] = (dp2[i+1][j][nk] + now * powmod(2, j-1)) % mod;

        if (b[i] || k) {
          // one 
          dp2[i+1][j][k] = (dp2[i+1][j][k] + now * powmod(2, j-1)) % mod;
          dp2[i+1][j+1][k] = (dp2[i+1][j+1][k] + now) % mod;
        }
      }
    }
  }
  long long ans = full[n-1];
  for (int j = 1; j <= n; j++){
    ans += dp2[n][j][0];
    if (ans >= mod) ans -= mod;
    ans += dp2[n][j][1];
    if (ans >= mod) ans -= mod;
  } 
  cout << ans << endl;
  return 0;
}