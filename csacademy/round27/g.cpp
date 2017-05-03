#include <bits/stdc++.h>

using namespace std;

const int N = 103, M = 2e5 + 4;
int dp[2][N][N * N], fac[M], inv[M];
int m;
int C(int n, int k) {
  if (n < 0 || k > n) return 0;
  return (1LL * fac[n] * inv[k] % m) * 1LL * inv[n-k] % m; 
}
long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % m)
    if (p & 1) r = r * b % m;
  return r;
}
int n, x;

int main() {
  scanf("%d %d %d", &n, &x, &m);
  fac[0] = inv[0] = 1;
  for (int i = 1; i < M; i++) {
    fac[i] = 1LL * i * fac[i-1] % m;
    inv[i] = powmod(fac[i], m-2);
  }
  memset(dp, 0, sizeof dp);
  int c = 0, b = 1;
  dp[c][1][0] = 1;
  int sum = 2;
  for (int i = 2; i <= n; i++) {
    sum += i * 2;
    sum = min(sum, N*N-1);
    swap(c, b);
    for (int j = 1; j <= i; j++) {
      for (int k = 0; k <= sum; k++) {
        int & r = dp[c][j][k];
        r = 1LL * dp[b][j-1][k] * j % m;
        if (k >= i) {
          int & v = dp[b][j][k-i];
          if (v != 0)
            r = (r + 2LL * dp[b][j][k-i] * j) % m;
        }
        if (k >= 2 * i) {
          int & v = dp[b][j+1][k-2*i];
          if (v != 0)
            r = (r + 1LL * v * j) % m;
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < min(x+1, N * N); i++) {
    if (dp[c][1][i] == 0) continue;
    ans = (ans + 1LL * C(x-i+n-1, n) * dp[c][1][i]) % m; 
  }
  ans %= m;
  if (ans < 0) ans += m;
  printf("%lld\n", ans);
  return 0;
}