#include <bits/stdc++.h>

using namespace std;

long long x, y, d; // ax + by = d
void extendedEuclidean(long long a, long long b) {
  if(b == 0) { x = 1; y = 0; d = a; return; } 
  extendedEuclidean(b, a % b); 
  long long xx, yy;
  xx = y;
  yy = x - (a/b)*y;
  x = xx; y = yy;
}

const int N = 1e6 + 6, mod = 998244353;

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}
long long fac[N], inv[N];
long long C(long long n, long long k) {
  return (fac[n] * inv[k] % mod) * inv[n-k] % mod;
}

int main() {
  fac[0] = inv[0] = 1;
  for (int i = 1; i < N; ++i) {
    fac[i] = fac[i-1] * i % mod;
    inv[i] = powmod(fac[i], mod-2);
  }
  long long n, a, b, k;
  cin >> n >> a >> b >> k;
  extendedEuclidean(a, b);
  if (k % d) {
    puts("0");
    return 0;
  }
  a /= d;
  b /= d;
  k /= d;
  x *= k;
  y *= k;
  long long z = x/b;
  x -= z * b;
  y += z * a;
  while (x > 0) x -= b, y += a;
  long long ans = 0;
  while (x <= n) {
    if (0 <= min(x, y) && max(x, y) <= n) {
      ans = (ans + C(n, x) * C(n, y)) % mod;
    }
    x += b;
    y -= a;
  }
  ans %= mod;
  if (ans < 0) ans += mod;
  cout << ans << endl;
  return 0;
}