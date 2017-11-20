#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7, N = 1e6 + 6;

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1) r = r * b % mod;
  return r;
}

long long fac[N], inv[N];
long long C(long long n, long long k) {
  if (k < 0 || n < k) return 0;
  return (fac[n] * inv[k] % mod) * inv[n-k] % mod; 
}
long long dua[N], duaempat[N], dualima[N], f[N];

long long solve(int a, int b, int k) {
  f[0] = 1;
  for (int i = 1; i <= b; i++) {
    f[i] = f[i-1] + dualima[i] * C(b, i);
    f[i] %= mod;
    if (f[i] < 0) f[i] += mod;
  }
  long long ans = 0;
  for (int c = 0; c <= a; c++) {
    int dmax = k-a-c;
    if (dmax < 0) break;
    dmax /= 2;
    dmax = min(dmax, b);
    long long cur = C(a, c) * duaempat[c] % mod;
    cur = cur * dua[a-c] % mod;
    ans = (ans + cur * f[dmax]) % mod;
  }
  return ans;
}

char s[N];

int main() {
  fac[0] = inv[0] = 1;
  for (int i = 1;  i < N; i++) {
    fac[i] = fac[i-1] * i % mod;
    inv[i] = powmod(fac[i], mod - 2);
  }
  dua[0] = dualima[0] = duaempat[0] = 1;
  for (int i = 1; i < N; i++) {
    dua[i] = dua[i-1] * 2 % mod;
    duaempat[i] = duaempat[i-1] * 24 % mod;
    dualima[i] = dualima[i-1] * 25 % mod;
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    scanf("%s", s);
    int a = 0;
    for (int i = 0, j = n-1; i < j; i++, j--) {
      a += (s[i] != s[j]);
    }
    long long ans = 0;
    if (n & 1) {
      ans = solve(a, n/2-a, k) + solve(a, n/2-a, k-1) * 25;
    }
    else {
      ans = solve(a, n/2-a, k);
    }
    ans %= mod;
    if (ans < 0) ans += mod;
    printf("%lld\n", ans);
  }
  return 0;
}