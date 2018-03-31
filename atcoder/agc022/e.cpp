#include <bits/stdc++.h>

using namespace std;

const int N = 9;
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

int nol[][N] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                {1, 0, 1, 0, 0, 0, 0, 0, 0},
                {0, 1, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 1, 0, 1, 0, 0, 0},
                {0, 0, 0, 0, 1, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 1, 0, 1},
                {0, 0, 0, 0, 0, 0, 0, 1, 0}};
int one[][N] = {{0, 1, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 1, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0},
                {1, 0, 0, 0, 1, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 1, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 1, 0, 0, 1, 1, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 1},
                {0, 0, 0, 0, 0, 0, 0, 0, 0}};


const int L = 3e5 + 5;
char s[L];
int main() {
  matrix m0(N, N), m1(N, N), m01(N, N);
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j) {
      m0[i][j] = nol[i][j];
      m1[i][j] = one[i][j];
      m01[i][j] = nol[i][j] + one[i][j];
    }
  matrix res(N, 1);
  res[0][0] = 1;
  scanf("%s", s);
  int n = strlen(s);
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0')
      res = m0 * res;
    else if (s[i] == '1')
      res = m1 * res;
    else
      res = m01 * res;
    // cerr << i << " cek" << end
    // res.print();
  }
  long long ans = res[3][0] + res[6][0] + res[7][0] + res[8][0];
  ans %= mod;
  if (ans < 0) ans += mod;
  printf("%lld\n", ans);
  return 0;
}