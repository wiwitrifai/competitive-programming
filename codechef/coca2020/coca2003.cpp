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

long long fact[N], inv[N];

long long C(int n, int k) {
  if (k < 0 || n < k) return 0;
  return (fact[n] * inv[k] % mod) * inv[n-k] % mod;
}

int solve() {
  int n;
  scanf("%d", &n);
  long long ans = fact[2 * n] * powmod(2, mod - 1 - n) % mod;
  printf("%lld\n", ans);
  return 0;
}


int main() {
  fact[0] = inv[0] = 1;
  for (int i = 1; i < N; ++i) {
    fact[i] = fact[i-1] * i % mod;
    inv[i] = powmod(fact[i], mod - 2);
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
