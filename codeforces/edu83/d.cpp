#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

long long C(int n, int k) {
  long long up = 1, down = 1;
  for (int i = 0; i < k; ++i) {
    up = up * (n - i) % mod;
    down = down * (i+1) % mod;
  }
  return up * powmod(down, mod-2) % mod;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  if (n <= 2) {
    puts("0");
    return 0;
  }
  long long ans = C(m, n-1) * (n-2) % mod;
  ans = ans * powmod(2, n-3) % mod;
  printf("%lld\n", ans);
  return 0;
}
