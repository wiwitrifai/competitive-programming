#include <bits/stdc++.h>

using namespace std;

const int N = 6;

const int mod = 1e9 + 6;

struct matrix {
  int n, m;
  int a[N][N];
  matrix(int n, int m) : n(n), m(m) {
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

int calc_pwc(long long n) {
  matrix b(5, 5);
  b[0][0] = b[0][1] = b[0][2] = 1;
  b[0][3] = 2;
  b[0][4] = mod - 6;
  b[1][0] = 1;
  b[2][1] = 1;
  b[3][3] = 1;
  b[3][4] = 1;
  b[4][4] = 1;
  matrix a(5, 1);
  a[0][0] = a[1][0] = a[2][0] = 0;
  a[3][0] = 4;
  a[4][0] = 1;
  return ((b ^ (n - 3)) * a)[0][0];
}

int calc_pwf1(long long n) {
  matrix b(3, 3);
  b[0][0] = b[0][1] = b[0][2] = 1;
  b[1][0] = 1;
  b[2][1] = 1;
  matrix a(5, 1);
  a[0][0] = 0;
  a[1][0] = 0;
  a[2][0] = 1;
  return ((b ^ (n - 3)) * a)[0][0];
}

int calc_pwf2(long long n) {
  matrix b(3, 3);
  b[0][0] = b[0][1] = b[0][2] = 1;
  b[1][0] = 1;
  b[2][1] = 1;
  matrix a(5, 1);
  a[0][0] = 0;
  a[1][0] = 1;
  a[2][0] = 0;
  return ((b ^ (n - 3)) * a)[0][0];
}

int calc_pwf3(long long n) {
  matrix b(3, 3);
  b[0][0] = b[0][1] = b[0][2] = 1;
  b[1][0] = 1;
  b[2][1] = 1;
  matrix a(5, 1);
  a[0][0] = 1;
  a[1][0] = 0;
  a[2][0] = 0;
  return ((b ^ (n - 3)) * a)[0][0];
}

long long powmod(long long b, long long p, long long m) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % m)
    if (p & 1)
      r = r * b % m;
  return r;
}

int main() {
  int f1, f2, f3, c;
  long long n;
  scanf("%lld %d %d %d %d", &n, &f1, &f2, &f3, &c);
  long long ans = powmod(c, calc_pwc(n), mod+1);
  ans = ans * powmod(f1, calc_pwf1(n), mod+1) % (mod + 1);
  ans = ans * powmod(f2, calc_pwf2(n), mod+1) % (mod + 1);
  ans = ans * powmod(f3, calc_pwf3(n), mod+1) % (mod + 1);
  printf("%lld\n", ans);
  return 0;
}
