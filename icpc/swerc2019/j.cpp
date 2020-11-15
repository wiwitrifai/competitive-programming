#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5, mod = 1e9 + 7;

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

int fac[2*N], inv[2*N];

long long C(int n, int k) {
  if (n < k || k < 0)
    return 0;
  return (fac[n] * (long long)inv[k] % mod) * (long long)inv[n-k] % mod;
}

long long Cat(int n) {
  return C(2 * n, n) * powmod(n+1, mod-2) % mod;
}

const int LG = 22;

int sp[LG][N];
int a[N];

int get(int l, int r) {
  int len = r - l;
  int lg = 31 - __builtin_clz(len);
  int lef = sp[lg][l], rig = sp[lg][r-(1 << lg)];
  return a[lef] <= a[rig] ? lef : rig;
}

long long solve(int l, int r) {
  if (r-l <= 1) return 1;
  int small = a[get(l, r)];
  long long ret = 1;
  int cnt = 0;
  int now = l;
  while (now < r) {
    int mid = get(now, r);
    if (a[mid] == small) {
      ret = ret * solve(now, mid) % mod;
      now = mid + 1;
      ++cnt;
    }
    else
      break;
  }
  if (now < r)
    ret = ret * solve(now, r) % mod;
  ret = ret * Cat(cnt) % mod;
  return ret;
}

int main() {
  fac[0] = inv[0] = 1;
  for (int i = 1; i < 2*N; ++i) {
    fac[i] = 1LL * fac[i-1] * i % mod;
  }
  inv[2*N-1] = powmod(fac[2*N-1], mod-2);
  for (int i = 2*N-2; i > 0; --i) {
    inv[i] = 1LL * inv[i+1] * (i+1) % mod;
  }
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    sp[0][i] = i;
  }
  for (int i = 0; i+1 < LG; ++i) {
    for (int j = 0; j + (1 << (i+1)) <= n; ++j) {
      int lef = sp[i][j], rig = sp[i][j+(1 << i)];
      sp[i+1][j] = a[lef] <= a[rig] ? lef : rig;
    }
  }
  printf("%lld\n", solve(0, n));
  return 0;
}
