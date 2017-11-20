#include <bits/stdc++.h>

using namespace std;

const int N = 202, mod = 1e9 + 7;

long long powmod(long long b, long long p) {
  long long r =1 ;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1) r = r * b % mod;
  return r;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    long long ans = 0;
    for (int i = 1; i < k; i++) {
      ans += powmod(i, n+m-2);
      if (ans >= mod) ans -= mod;
    }
    ans = (ans * powmod(k, n * m - (n + m - 1)) % mod) * n % mod;
    ans = ans * m % mod;
    ans = (ans + powmod(k, n * m)) % mod;
    if (ans < 0) ans += mod;
    printf("Case #%d: %lld\n", tc, ans);
  }
  return 0;
}