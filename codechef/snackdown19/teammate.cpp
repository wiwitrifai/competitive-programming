#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6, mod = 1e9 + 7, inv2 = (mod + 1) / 2;

int a[N];
int fac[N], inv[N];

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

int main() {
  fac[0] = 1;
  for (int i = 1; i < N; ++i) {
    fac[i] = 1LL * i * fac[i-1] % mod;
  }
  inv[N-1] = powmod(fac[N-1], mod-2);
  for (int i = N-2; i >= 0; --i)
    inv[i] = 1LL * inv[i+1] * (i+1) % mod;
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
      scanf("%d", a+i);
    sort(a, a+n);
    long long ans = 1;
    int cnt = 0, last = -1;
    for (int i = 0; i < n; ++i) {
      if (a[i] != last) {
        ans = ans * fac[cnt] % mod;
        cnt = 0;
        last = a[i];
      }
      ++cnt;
    }
    ans = ans * fac[cnt] % mod;
    cnt = 0;
    last = -1;
    for (int i = 0; i < n; i += 2) {
      if (a[i] != a[i+1]) {
        ans = ans * inv[cnt] % mod;
        cnt = 0;
        continue;
      }
      ans = ans * inv2 % mod;
      if (a[i] != last) {
        ans = ans * inv[cnt] % mod;
        cnt = 0;
        last = a[i];
      }
      ++cnt;
    }
    ans = ans * inv[cnt] % mod;
    printf("%lld\n", ans);
  }
  return 0;
}