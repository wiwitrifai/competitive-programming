#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const long long mod = 1e9 + 7;
struct matrix {
  int n, m;
  long long _mat[N][N];
  matrix(int n, int m) : n(n), m(m) {
  }
  void reset() {
    memset(_mat, 0, sizeof _mat);
    for(int i = 0; i<n; i++)
      _mat[i][i] = 1;
  }
  const long long * operator[](const int id) const {
    return _mat[id];
  }
  long long * operator[](const int id) {
    return _mat[id];
  }
  matrix operator*(const matrix& mat) const {
    matrix ret(this->n, mat.m);
    for(int i = 0; i<this->n; i++) {
      for(int j = 0; j<mat.m; j++) {
        long long &now = ret[i][j];
        now = 0;
        for(int k = 0; k<this->m; k++) {
          now = (now + this->_mat[i][k] * mat[k][j]) % mod;
        }
      }
    }
    return ret;
  }
  void print() {
    for(int i = 0; i<n; i++) {
      for(int j = 0; j<m; j++)
        cout << _mat[i][j] << " ";
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

int main() {
  matrix fib(2, 2);
  fib[0][0] = fib[0][1] = fib[1][0] = 1;
  fib[1][1] = 0;
  int n;
  cin >> n;
  matrix res = fib^n;
  res.print();

  return 0;
}