#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9+7;

// long double powmod(long double b, long long p) {
//   long double r =1 ;
//   for (; p; p >>= 1, b = b*b % mod)
//     if (p & 1)
//       r = b * r % mod;
//   return r; 
// }

const int N = 2024;
long double dp[N][N];

int main() {
  int k;
  long double a, b;
  cin >> k >> a >> b;
  long double p = a/(a+b), q = b / (a+b);
  long double ip = 1/p, iq = 1/q;
  dp[1][k] = 1;
  long double ans = 0;
  long double cur = (p-1) * (p-1);
  // cur = p/cur;
  // ans = (ans * cur) % mod;
  // cerr << q * q % mod << endl;
  // cerr << cur << endl;
  for (int i = 1; i <= k; ++i) {
    for (int j = k; j >= 0; --j) {
      dp[i+1][j] = (dp[i+1][j] + dp[i][j] * p);
      if (j-i >= i)
        dp[i][j-i] = (dp[i][j-i] + dp[i][j] * q);
      if (i == j) {
        long double used = (k-j+i-1) * dp[i][j];
        used = (used * p) ;
        ans = (ans + used * iq);
        ans = (ans + cur * dp[i][j]);
        cerr << i << " " << j << " " << dp[i][j] << endl;
        cerr << " " << (k-j+i-1) * p * iq << " " << cur << endl;
      }
    }
  }
  // cerr << ans << endl;
  ans = ans * q * ip;
  // ans = (ans * q) % mod;
  // ans = (ans * ip) % mod;
  // ans %= mod;
  // if (ans < 0) ans += mod;
  // cerr << ans * 100 % mod << endl;
  cout << ans << endl;
  return 0;
}