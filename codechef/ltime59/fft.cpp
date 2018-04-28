#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353, N = 1e6 + 6;

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

long long fac[N];
int cnt[N];

int main() {
  fac[0] = 1;
  for (int i = 1; i < N; ++i)
    fac[i] = fac[i-1] * i % mod;
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i <= n; ++i) cnt[i] = 0;
    bool ok = 1;
    for (int i = 0; i < n; ++i) {
      int a;
      scanf("%d", &a);
      if (a >= 1 && a <= n)
        ++cnt[a];
      else ok = 0;
    }
    if (!ok) {
      puts("0");
      continue;
    }
    long long ans = 1;
    for (int i = 1; i <= n; ++i) {
      if (cnt[i] % i) {
        ok = 0;
        break;
      }
      ans = ans * fac[cnt[i]] % mod;
      ans = ans * powmod(i, mod-1-(cnt[i]/i)) % mod;
      ans = ans * powmod(fac[cnt[i]/i], mod-2) % mod;
    }
    if (!ok) {
      puts("0");
      continue;
    }
    if (ans < 0) ans += mod;
    printf("%lld\n", ans);
  }
  return 0;
}