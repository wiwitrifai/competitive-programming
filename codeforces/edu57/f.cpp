#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353, N = 1e6 + 5;

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

long long fac[N];
int p[N];
int used[N], s[N];

long long bit[N];

long long get(int x) {
  long long r = 0;
  for (; x < N; x += x&-x)
    r += bit[x];
  r %= mod;
  return r;
}

void upd(int x, int v) {
  for (; x; x -= x&-x)
    bit[x] += v;
}

long long allinv(int n) {
  long long r = 1LL * n * (n-1) % mod;
  r = r * fac[n] % mod;
  r = r * powmod(4, mod-2) % mod;
  return r;
}

int main() {
  fac[0] = 1;
  for (int i = 1; i < N; ++i)
    fac[i] = fac[i-1] * 1LL * i % mod;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", p+i);
    if (p[i] != -1)
      used[p[i]] = 1;
  }
  int m = 0;
  for (int i = 1; i <= n; ++i)
    if (!used[i])
      s[m++] = i;
  long long x = 0;
  long long inv = 0;
  for (int i = 0; i < n; ++i) {
    if (p[i] == -1) {
      x = (x + inv * fac[m-1]) % mod;
    }
    else {
      inv += lower_bound(s, s+m, p[i]) - s;
      inv %= mod;
      x = (x + 1LL * get(p[i]) * fac[m]) % mod;
      upd(p[i], +1);
    }
  }
  inv = 0;
  for (int i = n-1; i >= 0; --i) {
    if (p[i] == -1) {
      x = (x + inv * fac[m-1]) % mod;      
    }
    else {
      inv += m - (lower_bound(s, s+m, p[i]) - s);
      inv %= mod;
    }
  }
  x = (x + allinv(m)) % mod;
  x = x * powmod(fac[m], mod - 2) % mod;
  if (x < 0) x += mod;
  printf("%lld\n", x);
  return 0;
}