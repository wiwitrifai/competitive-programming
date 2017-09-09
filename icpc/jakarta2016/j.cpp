/**
 *  ACM ICPC Regional Jakarta 2016 - J : Super Sum
 */

#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1) r = r * b % mod;
  return r;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    int n;
    scanf("%d", &n);
    long long ans = 1;
    for (int i = 0; i < n; i++) {
      long long a, b, c;
      scanf("%lld %lld %lld", &a, &b, &c);
      if (a == 1)
        ans = (ans * (c-b+1)) % mod;
      else {
        ans = ans * (powmod(a, c+1) - powmod(a, b)) % mod;
        ans = ans * powmod(a-1, mod-2) % mod;
        if (ans < 0)
          ans += mod;
      }
    }
    printf("Case #%d: %lld\n", tc, ans);
  }  
  return 0;
}