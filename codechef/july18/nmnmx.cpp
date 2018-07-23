#include <bits/stdc++.h>

using namespace std;

const int N = 5050, mod = 1e9 + 7, euler = mod - 1;

int a[N];
long long C[N][N];

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

int main() {
  for (int i = 0; i < N; ++i) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; ++j)
      C[i][j] = (C[i-1][j-1] + C[i-1][j]) % euler;
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i)
      scanf("%d", a+i);
    sort(a, a+n);
    long long ans = 1;
    for (int i = 1; i+1 < n; ++i) {
      long long p = C[n-1][k-1] - C[n-i-1][k-1] - C[i][k-1];
      p %= euler;
      if (p < 0) p += euler;
      ans = (ans * powmod(a[i], p)) % mod;
    }
    if (ans < 0) ans += mod;
    printf("%lld\n", ans);
  }
  return 0;
}