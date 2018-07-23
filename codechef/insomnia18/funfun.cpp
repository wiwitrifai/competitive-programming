#include <bits/stdc++.h>

using namespace std;

const int N = 2020, mod = 1e9 + 7;

long long f[N];
int m;
long long C[N][N], fac[N];

long long solve(int n) {
  if (n == 0) return 1;
  if (f[n] != -1) return f[n];
  long long & ret = f[n];
  ret = 0;
  for (int ambil = 1; ambil <= n; ++ambil) {
    long long cost = C[n-1][ambil-1] * fac[ambil-1] % mod;
    cost = cost * m % mod;
    if ((ambil & 1) == 0)
      cost = cost * m % mod;
    ret = (ret + solve(n - ambil) * cost) % mod;
  }
  return ret;
}

int main() {
  for (int i = 0; i < N; ++i) {
    C[i][0] = C[i][i] = 1;
    fac[i] = i ? fac[i-1] * i % mod : 1;
    for (int j = 1; j < i; ++j) {
      C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
    }
  }
  memset(f, -1, sizeof f);
  int n;
  scanf("%d %d", &n, &m);
  printf("%lld\n", solve(n));
  return 0;
}