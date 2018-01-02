#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9+7;

long long powmod(long long b, long long p) {
  long long r =1 ;
  for (; p; p >>= 1, b = b*b % mod)
    if (p & 1)
      r = b * r % mod;
  return r; 
}

long long gcd(long long a, long long b) {
  return a ? gcd(b % a, a) : b;
}

const int N = 2024;
long long dp[N][N], dp2[N][N];

int main() {
  int k, a, b;
  cin >> k >> a >> b;
  long long p = powmod(a + b, mod - 2), q = p;
  p = (p * a) % mod;
  q = (q * b) % mod;
  long long ip = powmod(p, mod - 2), iq = powmod(q, mod - 2);
  dp[1][k] = 1;
  long long ans = 0;
  long long cur = (p-1) * (p-1) % mod;
  cur = (p * powmod(cur, mod - 2)) % mod;
  for (int i = 1; i <= k; ++i) {
    for (int j = k; j >= 0; --j) {
      dp[i+1][j] = (dp[i+1][j] + dp[i][j] * p) % mod;
      if (j-i >= i) {
        dp[i][j-i] = (dp[i][j-i] + dp[i][j] * q) % mod;
      }
      if (j-i >= 1)
        dp2[i][j-i] = (dp2[i][j-i] + dp[i][j] * q) % mod;
      if (i > j) {
        long long used = (k-j+i-1) * 1LL * dp2[i][j] % mod;
        used = (used * p) % mod;
        ans = (ans + used * iq) % mod;
        ans = (ans + cur * dp2[i][j]) % mod;
      }
      else if (i == j) {
        long long used = (k-j+i-1) * 1LL * dp[i][j] % mod;
        used = (used * p) % mod;
        ans = (ans + used * iq) % mod;
        ans = (ans + cur * dp[i][j]) % mod;
      }
    }
  }
  ans = (ans * q) % mod;
  ans = (ans * ip) % mod;
  ans %= mod;
  if (ans < 0) ans += mod;
  cout << ans << endl;
  return 0;
}