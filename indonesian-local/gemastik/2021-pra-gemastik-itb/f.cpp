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

long long fac[N], inv[N];

long long C(int n, int k) {
  return (fac[n] * inv[k] % mod) * inv[n-k] % mod; 
}

long long check(int sum, int x, int y) {
  while (sum) {
    int d = sum % 10;
    sum /= 10;
    if (d != x && d != y)
      return false;
  }
  return true;
}

int main() {
  fac[0] = inv[0] = 1;
  for (int i = 1; i < N; ++i) {
    fac[i] = i * fac[i-1] % mod;
    inv[i] = powmod(fac[i], mod - 2);
  }
  int x, y, n;
  scanf("%d %d %d", &x, &y, &n);
  long long ans = 0;
  for (int i = 0; i <= n; ++i) {
    int sum = x * i + y * (n-i);
    if (!check(sum, x, y))
      continue;
    ans = (ans + C(n, i)) % mod;
  }
  printf("%lld\n", ans);
  return 0;
}
