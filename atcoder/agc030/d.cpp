#include <bits/stdc++.h>

using namespace std;

const int N = 3030, mod = 1e9 + 7;

int a[N][N];
int b[N][N];
int s[N];

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; ++i)
    scanf("%d", s+i);
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      if (s[i] < s[j])
        b[i][j] = 1;
      if (s[i] > s[j])
        a[i][j] = 1;
    }
  }
  int inv2 = (mod + 1) / 2;
  for (int it = 0; it < q; ++it) {
    int l, r;
    scanf("%d %d", &l, &r);
    --l, --r;
    if (l > r)
      swap(l, r);
    for (int i = 0; i < l; ++i) {
      a[i][l] = a[i][r] = 1LL * (a[i][l] + a[i][r]) * inv2 % mod;
      b[i][l] = b[i][r] = 1LL * (b[i][l] + b[i][r]) * inv2 % mod;
    }
    for (int i = l+1; i < r; ++i) {
      a[l][i] = b[i][r] = 1LL * (a[l][i] + b[i][r]) * inv2 % mod;
      a[i][r] = b[l][i] = 1LL * (b[l][i] + a[i][r]) * inv2 % mod;
    }
    for (int i = r+1; i < n; ++i) {
      a[l][i] = a[r][i] = 1LL * (a[l][i] + a[r][i]) * inv2 % mod;
      b[l][i] = b[r][i] = 1LL * (b[l][i] + b[r][i]) * inv2 % mod;
    }
    a[l][r] = b[l][r] = 1LL * (a[l][r] + b[l][r]) * inv2 % mod;
  }
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      ans = (ans + a[i][j]) % mod;
    }
  }
  ans = ans * powmod(2, q) % mod;
  if (ans < 0) ans += mod;
  printf("%lld\n", ans);
  return 0;
}