#include <bits/stdc++.h>

using namespace std;

const int N = 2, mod = 1e6 + 3;

struct matrix {
  int n, m;
  long long a[N][N];
  matrix(int n, int m) : n(n), m(m) {
    memset(a, 0, sizeof a);
  }
  void reset() {
    memset(a, 0, sizeof a);
    for(int i = 0; i<n; i++)
      a[i][i] = 1;
  }
  const long long * operator[](const int id) const {
    return a[id];
  }
  long long * operator[](const int id) {
    return a[id];
  }
  matrix operator*(const matrix& mat) const {
    matrix ret(this->n, mat.m);
    for(int i = 0; i<this->n; i++) {
      for(int j = 0; j<mat.m; j++) {
        long long &now = ret[i][j];
        now = 0;
        for(int k = 0; k<this->m; k++) {
          now = (now + this->a[i][k] * mat[k][j]) % mod;
        }
      }
    }
    return ret;
  }
  void print() {
    for(int i = 0; i<n; i++) {
      for(int j = 0; j<m; j++)
        cout << a[i][j] << " ";
      cout << endl;
    }
  }
  matrix operator^(long long pw) const {
    matrix ret(n, m), base = *this;
    ret.reset();
    while(pw) {
      if(pw & 1)
        ret = ret*base;
      base = base*base;
      pw >>= 1;
    }
    return ret;
  }
};

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = b * r % mod;
  return r;
}

const int M = 1e6 + 7;
long long fac[M], inv[M];

long long comb(int n, int k) {
  if (n < k || k < 0 || n < 0) return 0;
  return (fac[n] * inv[k] % mod) * inv[n-k] % mod;
}

long long C(int n, int k) {
  if (n == 0 && k == 0) return 1;
  int rn = n % mod, rk = k % mod;
  long long ret = comb(rn, rk);
  if (ret == 0) return 0;
  return ret * C(n/mod, k/mod) % mod;
}



int main() {
  fac[0] = inv[0] = 1;
  for (int i = 1; i < M; ++i) {
    fac[i] = fac[i-1] * i % mod;
    inv[i] = powmod(fac[i], mod-2);
  }
  matrix fib(2, 2);
  fib[0][0] = fib[0][1] = fib[1][0] = 1;
  fib[1][1] = 0;
  int q;
  int inv2 = (mod + 1) /2;
  scanf("%d", &q);
  while (q--) {
    int n;
    scanf("%d", &n);
    long long ans = 0;
    if ((n & 1) == 0) {
      long long dua = powmod(2, n);
      long long mid = C(n, n/2);
      long long sisi = (dua - mid) * inv2 % mod;
      ans = (sisi + mid) % mod;
      if (ans < 0) ans += mod;
    }
    else
      ans = powmod(2, n-1);
    matrix fc = fib^n;
    // cerr << ans << " " << fc[0][0] << endl;
    ans = (ans - fc[0][0]) % mod;
    if (ans < 0) ans += mod;
    printf("%lld\n", ans);
  }
  return 0;
}