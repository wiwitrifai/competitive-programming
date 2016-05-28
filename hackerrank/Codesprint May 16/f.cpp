#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;
const int mod = 1e9 + 7;

long long fac[N], inv[N];

long long powmod(long long base, long long pw) {
  long long ret = 1;
  while(pw) {
    if(pw & 1)
      ret =(ret * base) % mod;
    base = (base * base) % mod;
    pw >>= 1;
  }
  return ret;
}

long long C(int n, int k) {
  if(k < 0 || n < 0 || n < k)
    return 0;
  return (((fac[n] * inv[k]) % mod) * inv[n-k]) % mod;
}
long long P(int n, int k) {
  if(k < 0 || n < 0 || n < k)
    return 0;
  return (fac[n] * inv[n-k]) % mod;
}

long long cat(int n) {
  return (powmod(n+1, mod-2) * C(2*n, n)) % mod;
}

long long dp[202][202];

int main() {
  fac[0] = inv[0] = 1;
  for(int i = 1; i<N; i++) {
    fac[i] = (fac[i-1] * i) % mod;
    inv[i] = powmod(fac[i], mod-2);
  }
  for(int i = 1; i<202; i++)
    dp[1][i] = cat(i-1);
  for(int i = 2; i<202; i++)
    for(int j = i; j<202; j++) {
      long long &now = dp[i][j];
      now = 0;
      for(int k = j-i+1; k>0; k--) {
        now += (dp[i-1][j-k] * cat(k-1)) % mod;
        now %= mod;
      }
    }
  int t; 
  scanf("%d", &t);
  while(t--) {
    int n, k;
    scanf("%d%d", &n, &k);
    long long ans = 0;
    for(int i = 1; i<=k; i++) {
      ans += (dp[i][k] * C(2*n+i, i)) % mod;
      ans %= mod;
    }
    ans = (((ans * fac[k]) % mod) * fac[n]) % mod;
    if(ans < 0)
      ans += mod;
    ans = (ans * cat(n)) % mod;
    if(ans < 0)
      ans += mod;
    printf("%lld\n", ans);
  }
  return 0;
}