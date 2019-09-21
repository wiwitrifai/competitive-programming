#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6, mod = 998244353;

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

int sum[N], sq[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    sum[x] += x;
    if (sum[x] >= mod)
      sum[x] -= mod;
    sq[x] = (sq[x] + 1LL * x * x) % mod;
  }
  for (int i = 1; i < N; ++i) {
    for (int j = i+i; j < N; j += i) {
      sum[i] += sum[j];
      if (sum[i] >= mod)
        sum[i] -= mod;
    }
    for (int j = i+i; j < N; j += i) {
      sq[i] += sq[j];
      if (sq[i] >= mod)
        sq[i] -= mod;
    }
    sum[i] = (1LL * sum[i] * sum[i] - sq[i]) % mod;
    sum[i] = 1LL * sum[i] * ((mod + 1) / 2) % mod;
  }
  long long ans = 0;
  for (int i = N-1; i >= 1; --i) {
    for (int j = i+i; j < N; j += i) {
      sum[i] += mod - sum[j];
      if (sum[i] >= mod)
        sum[i] -= mod;
    }
    ans = (ans + 1LL * sum[i] * powmod(i, mod-2)) % mod;
  }
  printf("%lld\n", ans);
  return 0;
}
