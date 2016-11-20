#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 6;
const int mod = 1e9 + 7, prim = 37;

long long powmod(long long b, long long p) {
  long long ret = 1;
  while (p) {
    if (p & 1) 
      ret = (ret * b) % mod;
    b = (b * b) % mod;
    p >>= 1;
  }
  return ret;
}

char s[N], p[N];
int b[N];
long long dp[N];

int main() {
  int t;
  scanf("%d", &t);
  long long inv = powmod(prim, mod-2);

  while (t--) {
    scanf("%s %s", s, p);
    int n = strlen(s), m = strlen(p);
    long long pm = inv;
    long long hs = 0;
    for (int i = 0; i < m; i++) {
      pm = (pm * prim) % mod;
      hs += pm * (p[i] - 'a' + 1) % mod;
      hs %= mod;
    }
    if (hs < 0)
      hs += mod;
    long long now = 0;
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
      if (i >= m)
        now = (now + mod - s[i-m] + 'a' - 1) % mod;
      now = (now * inv) % mod;
      now += pm * (s[i] - 'a' + 1);
      now %= mod;
      if (now < 0)
        now += mod;
      dp[i+1] = dp[i];
      if (now == hs) {
        dp[i+1] += dp[i+1-m] + 1;
        dp[i+1] %= mod;
      }
    }
    dp[n] %= mod;
    if (dp[n] < 0)
      dp[n] += mod;
    printf("%lld\n", dp[n]);
  }
  return 0;
}