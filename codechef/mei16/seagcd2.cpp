#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int mod = 1e9 + 7;

int dp[16][1<<15], sum[30];
int prim[30], np, hp, n, m;

long long fac[N], inv[N], bs[105];

long long powmod(long long base, long long pw) {
  long long ret = 1;
  while(pw) {
    if(pw & 1)
      ret = (ret * base) % mod;
    base = (base * base) % mod;
    pw >>= 1;
  }
  return ret;
}
long long C(long long a, long long b) {
  if(a < 0 || a < b || b < 0)
    return 0;
  return (((fac[a] * inv[b]) % mod) * inv[a-b]) % mod;
}

int main() {
  fac[0] = 1;
  inv[0] = 1;
  for(int i = 1; i<N; i++) {
    fac[i] = (fac[i-1] * i ) % mod;
    inv[i] = powmod(fac[i], mod-2);
  }
  m = 104;
  for(int i = 2; i<=m; i++) {
    bool isprim = true;
    for(int j = 2; j<i; j++)
      if(i % j == 0)
        isprim = false;
    if(isprim) {
      prim[np++] = i;
    }
  }
  for(int i = 1; i<=m; i++) {
    bs[i] = 0;
    for(int j = 0; j<15; j++)
      if(i % prim[j] == 0)
        bs[i] |= 1 << j;
  }
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%d%d", &n, &m);
    np = 0;
    while(prim[np] <= m) np++;
    hp = min(15, np);
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    for(int i = 0; i<hp; i++) {
      int nloop = 1<<hp;
      for(int j = 0; j<nloop; j++) {
        for(int k = 2; k<=m; k++) {
          if(bs[k] > 0 && ((bs[k] & j) == 0)) {
            dp[i+1][bs[k] | j] = (dp[i+1][bs[k] | j] + dp[i][j]) % mod;
          }
        }
      }
    }
    memset(sum, 0, sizeof sum);
    for(int i = 0; i<=hp; i++) {
      int nloop = 1<<hp;
      for(int j = 0; j<nloop; j++)
        sum[i] = (sum[i] + dp[i][j]) % mod;
    }
    long long ans = 0;
    for(int i = 0; i<=hp; i++) {
      long long now = 0;
      for(int j = min(np - hp, n-i); j>=0; j--) {
        now += (((inv[n-i-j] * C(np-hp, j)) % mod));
        now %= mod;
      }
      ans += (((sum[i] * now) % mod) * inv[i]) % mod;
      ans %= mod;
      if(ans < 0)
        ans += mod;
    }
    ans = (ans * fac[n]) % mod;
    if(ans < 0)
      ans += mod;
    cout << ans << endl;
  }
  return 0;
}