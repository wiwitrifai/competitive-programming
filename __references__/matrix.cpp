#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const int mod = 1e9 + 7;
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

int main() {
  matrix fib(2, 2);
  fib[0][0] = fib[0][1] = fib[1][0] = 1;
  fib[1][1] = 0;
  int n;
  cin >> n;
  matrix res = fib^(2 * mod+2);
  res.print();

  return 0;
}