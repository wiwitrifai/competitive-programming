#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7, N = 2e5 + 5;

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

long long invmod(long long x) {
  return powmod(x, mod - 2);
}

int l[N], r[N];
long long len[N], inv[N];
long long cnt[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", l+i);
  for (int i = 0; i < n; ++i)
    scanf("%d", r+i);
  long long square = 0, distinct = 0, all = 1;
  for (int i = 0; i < n; ++i) {
    len[i] = r[i] - l[i] + 1;
    all = all * len[i] % mod;
    inv[i] = invmod(len[i]);
  }
  long long single = 0;
  for (int  i = 0; i + 1 < n; ++i) {
    int low = max(l[i], l[i+1]);
    int hig = min(r[i], r[i+1]);
    long long now = 1LL * len[i] * len[i+1] % mod;
    if (hig >= low) {
      now = (now - (hig - low + 1)) % mod;
      if (now < 0)
        now += mod;
    }
    now = now * inv[i] % mod;
    now = now * inv[i+1] % mod;
    cnt[i] = now;
    square = (square + now) % mod;
    if (i >= 2)
      single = (single + cnt[i-2]) % mod;
    distinct = (distinct + now * single) % mod;
  }
  for (int i = 0; i + 2 < n; ++i) {
    long long now = 1LL * len[i] * len[i+1] % mod;
    now = 1LL * now * len[i+2] % mod;
    {
      int low = max(l[i], l[i+1]);
      int hig = min(r[i], r[i+1]);
      if (hig >= low) {
        now = (now - 1LL * (hig - low + 1) * len[i+2]) % mod;
        if (now < 0)
          now += mod;
      }
    }
    {
      int low = max(l[i+1], l[i+2]);
      int hig = min(r[i+1], r[i+2]);
      if (hig >= low) {
        now = (now - 1LL * (hig - low + 1) * len[i]) % mod;
        if (now < 0)
          now += mod;
      }
    }
    {
      int low = max(l[i], max(l[i+1], l[i+2]));
      int hig = min(r[i], min(r[i+1], r[i+2]));
      if (hig >= low) {
        now = (now + 1LL * (hig - low + 1)) % mod;
        if (now < 0)
          now += mod;
      }
    }
    now = now * inv[i] % mod;
    now = now * inv[i+1] % mod;
    now = now * inv[i+2] % mod;
    distinct = (distinct + now) % mod;
  }
  single = 0;
  for (int i = 0; i + 1 < n; ++i)
    single = (single + cnt[i]) % mod;
  square = (square + 1) * all % mod;
  distinct = (distinct + single) * all % mod;
  long long ans = (square + 2LL * distinct) % mod;
  ans = ans * invmod(all) % mod;
  if (ans < 0)
    ans += mod;
  printf("%lld\n", ans);
  return 0;
}
