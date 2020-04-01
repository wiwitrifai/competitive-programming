#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353, N = 2;

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

struct matrix {
  int n, m;
  int a[N][N];
  matrix(int n_, int m_) : n(n_), m(m_) {
    memset(a, 0, sizeof a);
  }
  void reset() {
    memset(a, 0, sizeof a);
    for(int i = 0; i<n; ++i)
      a[i][i] = 1;
  }
  const int * operator[](const int id) const {
    return a[id];
  }
  int * operator[](const int id) {
    return a[id];
  }
  matrix operator*(const matrix& mat) const {
    matrix ret(this->n, mat.m);
    for(int i = 0; i < this->n; ++i) {
      for(int j = 0; j < mat.m; ++j) {
        long long now = 0;
        for(int k = 0; k<this->m; ++k) {
          now = (now + (long long)this->a[i][k] * mat[k][j]) % mod;
        }
        ret[i][j] = now;
      }
    }
    return ret;
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

ostream& operator<<(ostream& os, const matrix & mat) {
  for(int i = 0; i < mat.n; ++i) {
    for(int j = 0; j < mat.m; ++j)
      os << mat.a[i][j] << " ";
    os << endl;
  }
  return os;
}

int main() {
  int n, m, l, r;
  scanf("%d %d %d %d", &n, &m, &l, &r);
  if ((n & 1) && (m&1)) {
    long long ans = powmod(r-l+1, 1LL * n * m);
    printf("%lld\n", ans);
    return 0;
  }
  long long cnt = 1LL * n * m / 2;
  int odd = 0, even = 0;
  odd = even = (r-l + 1) /2;
  if ((l & 1) == (r&1)) {
    if (r & 1)
      ++odd;
    else
      ++even;
  }
  matrix a(2, 1), b(2, 2);
  a[0][0] = 1;
  a[1][0] = 0;
  b[0][0] = even;
  b[0][1] = odd;
  b[1][0] = odd;
  b[1][1] = even;
  matrix res = (b ^ cnt) * a;
  long long ans = (1LL * res[1][0] * res[1][0] + 1LL * res[0][0] * res[0][0]) % mod;
  printf("%lld\n", ans);
  return 0;
}
