#include <bits/stdc++.h>

using namespace std;

const int N = 1 << 10, mod = 1e9 + 7;
long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>=1, b = b * b % mod)
    if (p & 1) r = r * b % mod;
  return r;
}
long long cnt[1 << 10][20];
long long cal[1 << 10];
long long pp[11][30];
int x[19];
void process(long long b) {
  int n = 0;
  while (b) {
    x[n++] = b % 10;
    b /= 10;
  }
  for (int mask = 0; mask < N; mask++) {
    long long & now = cal[mask];
    now = 0;
    for (int i = 1; i < n; i++)
      now += cnt[mask][i];
    int sisa = 10 - __builtin_popcount(mask);
    for (int i = n-1; i >= 0; i--) {
      for (int j = i == (n-1); j < x[i]; j++) {
        if (mask & (1 << j)) continue;
        now += pp[sisa][i];
      }
      if (mask & (1 << x[i])) break;
    }
  }
}

long long tanpa[N], ada[N];

int main() {
  for (int i = 0; i <= 10; i++) {
    long long now = 1;
    for (int j = 0; j < 30; j++)
      pp[i][j] = now, now *= i;
  }
  memset(cnt, 0, sizeof cnt);
  for (int mask = 0; mask < N; mask++) {
    long long now = 1;
    int sisa = 10 - __builtin_popcount(mask);
    for (int i = 0; i < 19; i++) {
      cnt[mask][i] = now;
      now *= sisa;
    }
    if ((mask & 1) == 0) {
      for (int i = 1; i < 19; i++) {
        for (int j = 0; j < i; j++)
          cnt[mask][i] -= cnt[mask][j];
      }
    }
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    long long a, b;
    int k, d;
    scanf("%lld %lld %d %d", &a, &b, &k, &d);
    process(b+1);
    for (int i = 0; i< N; i++)
      tanpa[i] = cal[i];
    process(a);
    for (int i = 0; i< N; i++)
      tanpa[i] -= cal[i];
    for (int i = 0; i < N; i++) {
      ada[i] = tanpa[0];
      for (int j = i; j; j = (j-1) & i)
        if (__builtin_popcount(j) & 1)
          ada[i] -= tanpa[j];
        else
          ada[i] += tanpa[j];
    }
    assert(ada[0] == (b-a+1));
    long long inv = 1;
    for (int i = 1; i <= k; i++)
      inv = inv * i % mod;
    inv = powmod(inv, mod - 2);
    for (int i = 0; i < N; i++) {
      if (ada[i] < k)
        ada[i] = 0;
      else {
        long long now = 1;
        long long cur = ada[i] % mod;
        for (int j = 0; j < k; j++) {
          now = now * cur % mod;
          cur--;
          if (cur < 0) cur += mod;
        }
        now = now * inv % mod;
        ada[i] = now;
      }
    }
    long long ans = 0;
    for (int i = N-1; i >= 0; i--) {
      if (i)
        ada[0] -= ada[i];
      if (ada[0] < 0) ada[0] += mod;
      for (int j = (i-1) & i; j; j = (j-1) & i) {
        ada[j] -= ada[i];
        if (ada[j] < 0) ada[j] += mod;
      }
      if (__builtin_popcount(i) == d) {
        ans += ada[i];
        if (ans >= mod)
          ans -= mod;
      }
    }
    ans %= mod;
    if (ans < 0) ans += mod;
    printf("%lld\n", ans);
  }
  return 0;
}