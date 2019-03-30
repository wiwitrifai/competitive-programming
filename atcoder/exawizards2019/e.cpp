#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, mod = 1e9 + 7;

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
  assert(n < N);
  return  (1LL * fac[n] * inv[k] % mod) * inv[n-k] % mod;
}

long long invers(long long b, long long p = 1) {
  return powmod(b, mod - 1 - p);
}

int main() {
  fac[0] = inv[0] = 1;
  for (int i = 1; i < N; ++i) {
    fac[i] = 1LL * fac[i-1] * i % mod;
    inv[i] = invers(fac[i]);
  }
  int b, w;
  scanf("%d %d", &b, &w);
  long long sum = 0, cnt = 1, last = 0;;
  for (int i = 0; i < b + w; ++i) {
    int left = i, right = b + w - i - 1;
    if (left >= w) {
      cnt -= C(left-1, w-1);
    }
    if (right < w) {
      int mi = w - right - 1;
      cnt -= C(left-1, mi);
    }
    cnt %= mod;
    if (cnt < 0) cnt += mod;
    if (right == 0)
      cnt = 0;
    long long ans = invers(2, left + 1) * cnt % mod;
    if (left >= w) {
      sum = (sum + 1LL * invers(2, left) * C(left-1, w-1)) % mod;
    }
    ans = (ans + sum) % mod;
    if (ans < 0)
      ans += mod;
    printf("%lld\n", ans);
    cnt = (2LL * cnt) % mod;
  }
  return 0;
}
