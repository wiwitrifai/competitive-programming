#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7, N = 1e6 + 5;
long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = b * r % mod;
  return r;
}
long long fac[N], inv[N];
long long C(long long n, long long k) {
  if (k < 0 || n < k || n < 0) return 0;
  return (fac[n] * inv[k] % mod) * inv[n-k] % mod; 
}

int main() {
  fac[0] = inv[0] = 1;
  for (long long i = 1; i < N; ++i) {
    fac[i] = fac[i-1] * i % mod;
    inv[i] = powmod(fac[i], mod-2);
  }
  long long t;
  scanf("%lld", &t);
  while (t--) {
    long long n, m;
    long long k;
    scanf("%lld %lld %lld", &n, &m, &k); ++k;
    long long ans = 0;
    if (n > m) swap(n, m);
    if (k == 1)
      ans = 1L * n * m % mod;
    else if (k == 3) {
      for (long long i = 1; ; ++i) {
        long long x = i + 1, y = i * 2 + 1;
        if (x > n || y > m) break;
        ans = (ans + 2LL * (n-x+1) * (m-y+1)) % mod;
      }
      for (long long i = 1; ; ++i) {
        long long y = i + 1, x = i * 2 + 1;
        if (x > n || y > m) break;
        ans = (ans + 2LL * (n-x+1) * (m-y+1)) % mod;
      }
      for (long long i = 1; ; ++i) {
        long long x = i + 1, y = i+1;
        if (x > n || y > m) break;
        ans = (ans + 4LL * (n-x+1) * (m-y+1)) % mod;
      }
    }
    else if (k == 4) {
      // for (long long i = 1; ; ++i) {
      //   long long x = i + 1, y = i * 2 + 1;
      //   if (x > n || y > m) break;
      //   ans = (ans + 2LL * (n-x+1) * (m-y+1)) % mod;
      // }
      // for (long long i = 1; ; ++i) {
      //   long long y = i + 1, x = i * 2 + 1;
      //   if (x > n || y > m) break;
      //   ans = (ans + 2LL * (n-x+1) * (m-y+1)) % mod;
      // }
      for (long long i = 1; ; ++i) {
        long long x = i + 1, y = i+1;
        if (x > n || y > m) break;
        ans = (ans + 1LL * (n-x+1) * (m-y+1)) % mod;
      }
      // for (long long i = 1; ; ++i) {
      //   long long x = 2 * i + 1, y = x;
      //   if (x > n || y > m) break;
      //   ans = (ans + 4LL * (n-x+1) * (m-y+1)) % mod;
      // }
      for (long long i = 1; ; ++i) {
        long long x = 2 * i + 1, y = x;
        if (x > n || y > m) break;
        ans = (ans + 1LL * (n-x+1) * (m-y+1)) % mod;
      }
    }
    else if (k == 5) {
      // for (long long i = 1; ; ++i) {
      //   long long x = i*2 + 1, y = x;
      //   if (x > n || y > m) break;
      //   ans = (ans + 1LL * (n-x+1) * (m-y+1)) % mod;
      // }
      // for (long long i = 1; ; ++i) {
      //   long long x = 2 * i + 1, y = x;
      //   if (x > n || y > m) break;
      //   ans = (ans + 1LL * (n-x+1) * (m-y+1)) % mod;
      // }
    }
    else if (k == 2) {
      if (k <= m) {
        ans = (ans + C(m, k) * n) % mod;
      }
      if (k <= n) {
        ans = (ans + C(n, k) * m) % mod;
      }
      for (long long i = k; i < n; ++i) {
        ans = (ans + 4LL * C(i, k)) % mod;
      }
      if (k <= n)
        ans = (ans + 2LL * C(n, k) * (m-n+1)) % mod;
    }
    ans %= mod;
    if (k < N)
      ans = (ans * fac[k]) % mod;
    else
      assert(ans == 0);
    if (ans < 0) ans += mod;
    cout << ans << endl;
  }
  return 0;
}