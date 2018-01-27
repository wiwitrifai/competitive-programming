#include <bits/stdc++.h>

using namespace std;
const int N = 5;
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

const int M = 1e6 + 6;
char s[M];

int main() {
  matrix p(5, 5), a(5, 5);
  p.reset();
  a.reset();
  p[0][1] = 1;
  p[1][2] = 1;
  a[2][3] = 1;
  p[3][4] = 1;
  matrix awal(5, 1);
  awal[4][0] = 1;
  int n, m;
  scanf("%d %d", &n, &m);
  scanf("%s", s);
  matrix b(5, 5);
  b.reset();
  for (int i = 0; i < m; ++i) {
    if (s[i] == 'P')
      b = b * p;
    else
      b = b * a;
  }
  b = b ^ n;
  b = b * awal;
  long long ans = b[0][0];
  ans %= mod;
  if (ans < 0) ans += mod;
  cout << ans << endl;
  return 0;
}