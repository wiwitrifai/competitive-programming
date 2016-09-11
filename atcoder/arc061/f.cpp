#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const int mod = 1e9 + 7;

long long fac[N], inv[N];

long long C(int n, int k) {
  if (k > n) return 0;
  return (((fac[n] * inv[k]) % mod) * inv[n-k]) % mod;
}
long long powmod(long long b, long long p) {
  long long ret = 1;
  while (p) {
    if (p & 1)
      ret = (ret * b) % mod;
    b = (b * b) % mod;
    p >>= 1;
  }
  return ret;
}

int main() {
  fac[0] = inv[0] = 1;
  for (int i = 1; i < N; i++) {
    fac[i] = (fac[i-1] * i) % mod;
    inv[i] = powmod(fac[i], mod - 2);
  }
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  long long ans = 0;
  long long cur = 1;
  for (int i = 0; i <= m + k; i++) {
    ans = (ans + (((C(n - 1 + i, i) * cur) % mod) * powmod(3, m + k - i)) % mod) % mod;
    cur = (cur * 2) % mod;
    if (i >= m)
      cur = (cur + mod - C(i, m)) % mod;
    if (i >= k)
      cur = (cur + mod - C(i, k)) % mod;
  }
  if (ans < 0)
    ans += mod;
  printf("%lld\n", ans);
  return 0;
}