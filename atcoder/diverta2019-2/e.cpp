#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6, mod = 1e9 + 7;
long long dp[N];

int main() {
  int n, h, d;
  long long sum = 0, fac = 1;
  scanf("%d %d %d", &n, &h, &d);
  for (int i = 1; i <= n; ++i) {
    fac = fac * i % mod;
    sum = (sum + fac) % mod;
  }
  dp[0] = fac;
  long long cur = fac;
  for (int i = 1; i < h; ++i) {
    dp[i] = sum * cur % mod;
    cur = (cur + dp[i]) % mod;
    if (i >= d)
      cur = (cur + mod - dp[i-d]) % mod;
  }
  cur %= mod;
  if (cur < 0)
    cur += mod;
  printf("%lld\n", cur);
  return 0;
}
