#include <bits/stdc++.h>

using namespace std;

const int N = 2048, mod = 1e9 + 7;

long long C[N][N];
long long sum[N], d[N][N];
long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1) r = r * b % mod;
  return r;
}

int main() {
  for (int i = 0; i < N; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++)
      C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    sum[0] = n;
    sum[1] = (1LL * n * (n+1) / 2) % mod;
    for (int i = 2; i <= k; i++) {
      long long c = powmod(n+1, i+1)-1;
      for (int j = 0; j < i; j++) {
        c = (c - 1LL * C[i+1][j] * sum[j]) % mod;
      }
      c %= mod;
      if (c < 0) c += mod;
      c = (c * powmod(C[i+1][i], mod-2)) % mod;
      if (c < 0) c += mod;
      sum[i] = c;
    }
    d[1][0] = sum[1];
    d[2][0] = sum[2];
    long long cc = sum[1] * sum[1] % mod;
    cc = (cc-sum[2]) % mod;
    cc = (cc * ((mod + 1)/2)) % mod;
    if (cc < 0) cc += mod;
    d[2][1] = cc;
    for (int i = 3; i <= k; i++) {
      d[i][0] = sum[i];
      for (int j = 1; j < i; j++) {
        long long c = d[j][j-1] * sum[i-j] % mod;
        c = (c - d[i][j-1]) % mod;
        if (c < 0) c += mod;
        d[i][j] = c;
      }
      d[i][i-1] = (d[i][i-1] * powmod(i, mod-2)) % mod;
    }
    printf("%lld\n", d[k][k-1]); 
  }
  return 0;
}