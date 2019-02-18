#include <bits/stdc++.h>

using namespace std;


const int N = 105;
const long long mod = 1e9 + 7;
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

int main() {
  long long n, m;
  scanf("%lld %lld", &n, &m);
  matrix b(m, m), a(m, 1);
  b[0][0] = 1;
  b[0][m-1] = 1;
  for (int i = 1; i < m; ++i)
    b[i][i-1] = 1;
  a[0][0] = 1;
  matrix res = (b ^ n) * a;
  printf("%lld\n", res[0][0]);
  return 0;
}