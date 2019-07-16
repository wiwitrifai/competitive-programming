#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long powmod(long long b, long long p) {
  long long r =1 ;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

long long inv(long long b) {
  return powmod(b, mod - 2);
}

int main() {
  int t;
  scanf("%d", &t);
  long long inv2 = inv(2), inv6 = inv(6);
  while (t--) {
    int n;
    scanf("%d", &n);
    long long cnt = 1LL * n * (n + 1) % mod;
    cnt = cnt * inv2 % mod;
    long long A = cnt * cnt % mod;
    A = A * inv2 % mod;
    A = mod - A;
    long long B = cnt * (2 * n + 1) % mod;
    B = B * n % mod;
    B = B * inv6 % mod;
    long long C = cnt * (n + 1) % mod;
    C = C * inv2 % mod;
    long long ans = (A + B + C) % mod;
    if (ans < 0) ans += mod;
    printf("%lld\n", ans);
  }
  return 0;
}