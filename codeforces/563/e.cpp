#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6, mod = 1e9 + 7;

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

long long fac[N], inv[N];

long long C(int n, int k) {
  if (n < 0 || k < 0 || n < k)
    return 0;
  return (fac[n] * inv[n-k] % mod) * inv[k] % mod;
}

long long dp[N];
int cntp[N], smallp[N];

int main() {
  fac[0] = inv[0] = 1;
  for (int i = 1; i < N; ++i) {
    fac[i] = (1LL * fac[i-1] * i) % mod;
    inv[i] = powmod(fac[i], mod - 2);
  }
  int n;
  scanf("%d", &n);
  cntp[1] = 0;
  for (int i = 2; i <= n; ++i) {
    if (smallp[i]) continue;
    for (int j = i; j <= n; j += i)
      if (smallp[j] == 0)
        smallp[j] = i;
  }
  int best = 0;
  for (int i = 2; i <= n; ++i) {
    cntp[i] = cntp[i/smallp[i]] + 1;
    best = max(best, cntp[i]);
  }
  dp[1] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = i+i; j <= n; j += i) {
      int p = j/i;
      if (smallp[p] != p) continue;
      int all = n - n/j, bef = n - n/i;
      long long mul = C(all-1, bef) * fac[all-bef] % mod;
      dp[j] = (dp[j] + dp[i] * mul) % mod;
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (cntp[i] != best) continue;
    ans = (ans + dp[i]) % mod;
  }
  if (ans < 0) ans += mod;
  printf("%lld\n", ans);
  return 0;
}
