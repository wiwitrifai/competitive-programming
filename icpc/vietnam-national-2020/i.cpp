#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long powmod(long long b, long long e) {
  long long r = 1;
  for (; e; e >>= 1, b = b * b % mod)
    if (e & 1)
      r = r * b % mod;
  return r;
}


const int N = 3e6 + 6;

long long fac[N], inv[N];
long long f[N];

long long C(int n, int k) {
  if (k < 0 || n < k)
    return 0;
  return (fac[n] * inv[k] % mod) * inv[n-k] % mod;
}

void solve() {
  int x, y;
  scanf("%d %d", &x, &y);
  if (x == 0 || y == 0) {
    printf("%lld\n", f[x+y]);
    return;
  }
  long long ans = 0;
  for (int i = x; i > 0; --i) {
    ans = (ans + C(y + (x-i)-1, y-1) * f[i]) % mod;
  }
  for (int i = y; i > 0; --i) {
    ans = (ans + C(x + (y-i)-1, x-1) * f[i]) % mod;
  }
  ans %= mod;
  if (ans < 0)
    ans += mod;
  printf("%lld\n", ans);
}

int main() {
  fac[0] = inv[0] = 1;
  for (int i = 1; i < N; ++i) {
    fac[i] = fac[i-1] * i % mod;
  }
  inv[N-1] = powmod(fac[N-1], mod - 2);
  for (int i = N-2; i > 0; --i) {
    inv[i] = inv[i+1] * (i+1) % mod;
  }
  f[0] = 0;
  f[1] = 1;
  for (int i = 2; i < N; ++i) {
    f[i] = (f[i-1] + f[i-2]) % mod;
  }
  int tc = 1;
  // scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
