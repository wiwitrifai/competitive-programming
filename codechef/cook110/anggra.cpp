#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7, N = 2e5 + 5;

long long powmod(long long b, long long p) {
  long long r= 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

long long fac[N], inv[N];

long long C(int n, int k) {
  if (n < k || k < 0 || n < 0)
    return 0;
  return (fac[n] * inv[k] % mod) * inv[n-k] % mod;
}

void solve() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  long long ans = 0;
  for (int i = k; i <= n; ++i) {
    ans = (ans + C(n, i) * powmod(m-1, n-i)) % mod;
  }
  printf("%lld\n", ans);
}

int main() {
  fac[0] = inv[0] = 1;
  for (int i = 1; i < N; ++i) {
    fac[i] = 1LL * fac[i-1] * i % mod;
    inv[i] = powmod(fac[i], mod - 2);
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
