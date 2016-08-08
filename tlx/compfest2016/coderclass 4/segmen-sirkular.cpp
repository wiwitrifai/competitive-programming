#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int gcd(int a, int b) {
  return a ? gcd(b % a, a) : b;
}

long long powmod(long long b, long long pw) {
  long long ret = 1;
  while (pw) {
    if (pw & 1)
      ret = (ret * b) % mod;
    b = (b * b) % mod;
    pw >>= 1;
  }
  return ret;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int a, b;
    scanf("%d%d", &b, &a);
    int d = gcd(a, b);
    a /= d; b /= d;
    long long a2 = (((1LL * (a-1) * a) % mod) * d) % mod, a3 = (((((1LL * a2 * d) % mod) * (2 * a - 1)) % mod) * powmod(6, mod-2)) % mod;
    long long b2 = (((1LL * (b-1) * b) % mod) * d) % mod, b3 = (((((1LL * b2 * d) % mod) * (2 * b - 1)) % mod) * powmod(6, mod-2)) % mod;
    long long k4 = (1LL * a * b) % mod;
    long long k3 = (1LL * a * b2 + a2 * b) % mod;
    long long k2 = (1LL * a * b3 + a2 * b2 + a3 * b) % mod;
    long long k1 = (a2 * b3 + a3 * b2) % mod;
    long long k0 = (a3 * b3) % mod;
    long long x0 = d;
    long long x1 = (1LL * d * (d+1)/ 2) % mod;
    long long x2 = (((x1 * (2 * d + 1)) % mod) * powmod(3, mod-2)) % mod;
    long long x3 = (x1 * x1) % mod;
    long long x4 = (((x2 * ((((3LL * d * d) % mod) + 3LL * d -1) % mod)) % mod) * powmod(5, mod-2)) % mod;
    long long ans = (k0 * x0) % mod;
    ans = (ans + k1 * x1) % mod;
    ans = (ans + k2 * x2) % mod;
    ans = (ans + k3 * x3) % mod;
    ans = (ans + k4 * x4) % mod;
    if (ans < 0)
      ans += mod;
    printf("%lld\n", ans);
  }
  return 0;
}