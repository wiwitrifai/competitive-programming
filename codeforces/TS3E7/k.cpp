#include <bits/stdc++.h>
using namespace std;

const int N = 3344;
const int mod = 1e9 + 7;
long long dp[N][N];
long long C[N][N];
int n, d, t, k;

int main() {
  for (int i = 0; i < N; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++)
      C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
  }
  cin >> n >> d >> t >> k;
  memset(dp, 0, sizeof dp);
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    long long sum = 0;
    for (int j = 0; j < d; j++) {
      dp[i+1][j] = sum % mod;
      sum = (sum + dp[i][j]) % mod;
    }
    for (int j = d; j <= n; j++) {
      sum = (sum + mod - dp[i][j-d]) % mod;
      dp[i+1][j] = sum % mod;
      sum = (sum + dp[i][j]) % mod;
    }
  }
  if (t == 0) {
    long long ans = 0;
    long long mul = k;
    for (int w = 1; w <= n; w++) {
      ans = (ans + mul * dp[w][n]) % mod;
      mul = (mul * (k-1)) % mod;
    }
    cout << ans << endl;
    return 0;
  }
  long long all = k;
  long long ans = 0;
  for (int w = 1; w <= n; w++) {
    for (int x = 1; x <= w; x++) {
      if (x * d + t-d > n)
        break;
      long long tmp = (all * dp[w-x][n-x*d-t+d]) % mod;
      ans = (ans + C[w][x] * tmp) % mod;
    }
    all = (all * (k-1)) % mod;
  } 
  cout << ans << endl;
  return 0;
}