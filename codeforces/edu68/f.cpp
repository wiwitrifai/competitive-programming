#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, mod = 1e9 + 7, inv2 = (mod + 1) / 2;

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

long long fac[N], inv[N];

long long C(int n, int k) {
  if (n < 0 || k < 0 || n < k)
    return 0;
  return (fac[n] * inv[k] % mod) * inv[n-k] % mod;
}

int t[N];

int main() {
  fac[0] = inv[0] = 1;
  for (int i = 1; i < N; ++i) {
    fac[i] = 1LL * fac[i-1] * i % mod;
  }
  inv[N-1] = powmod(fac[N-1], mod-2);
  for (int i = N-2; i >= 0; --i) {
    inv[i] = inv[i+1] * (i + 1) % mod;
  }
  int n;
  long long tot;
  scanf("%d %lld", &n, &tot);
  for (int i = 0; i < n; ++i) {
    scanf("%d", t+i);
  }
  int maks = 0;
  long long cur = 0, cnt = 1, mul = 1, ans = 0;
  for (int i = 1; i <= n; ++i) {
    cur += t[i-1];
    if (cur > tot) break;
    ++maks;
    cnt = cnt * 2 % mod;
    if (cnt < 0)
      cnt += mod;
    mul = mul * inv2 % mod;
    if (cur + maks > tot) {
      --maks;
      cnt -= C(i-1, maks);
      if (cnt < 0)
        cnt += mod;
    }
    while (cur + maks > tot) {
      cnt -= C(i, maks);
      if (cnt < 0)
        cnt += mod;
      --maks;
    }
    ans = (ans + cnt * mul) % mod;
  }
  ans %= mod;
  if (ans < 0) ans += mod;
  printf("%lld\n", ans);
  return 0;
}
