#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5, mod = 1e9 + 7;

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1) r = r * b % mod;
  return r;
}
long long fac[N], inv[N];
long long C(int n, int k) {
  if (k < 0 || k > n) return 0;
  return ((fac[n] * inv[k] % mod) * inv[n-k]) % mod;
}
int n, k;
long long a[N];

int main() {
  fac[0] = inv[0] = 1;
  for (int i = 0; i < N; ++i) {
    fac[i] = (1LL * fac[i-1] * i) % mod;
    inv[i] = powmod(fac[i], mod-2);
  }
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++)
    scanf("%lld", a+i);
  long long val = 0;
  for (int i = 62; i >= 0; i--) {
    val |= 1LL << i;
    int cnt = 0;
    for (int j = 0; j < n; j++)
      cnt += ((val & a[i]) == val);
    if (cnt < k)
      val ^= 1LL << i;
  }
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    cnt += ((val & a[i]) == val);
  }
  printf("%lld\n%lld\n", val, C(cnt, k));
  return 0;
}