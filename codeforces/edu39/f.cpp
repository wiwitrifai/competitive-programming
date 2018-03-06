#include <bits/stdc++.h>

using namespace std;


const int N = 105;
const long long mod = 1e9 + 7;
struct matrix {
  int n, m;
  long long a[N][N];
  matrix() : n(0), m(0) {
    memset(a, 0, sizeof a);
  }
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

char s[N];

matrix f[N];

int main() {
  int n, x;
  scanf("%d %d", &n, &x);
  scanf("%s", s);
  matrix satu(n+2, n+2), nol(n+2, n+2);
  satu.reset();
  nol.reset();
  satu[n+1][n+1] = nol[n+1][n+1] = 2;
  string asli(s);
  for (int i = 0; i <= n; ++i) {
    string cur = asli.substr(0, i);
    // nol
    string now = cur + "0";
    int z = min((int)now.size(), n);
    while (now.substr((int)now.size()-z, z) != asli.substr(0, z)) --z;
    ++nol[z][i];
    if (z == n)
      ++nol[z+1][i];
    // satu
    now = cur + "1";
    z = min((int)now.size(), n);
    while (now.substr((int)now.size()-z, z) != asli.substr(0, z)) --z;
    ++satu[z][i];
    if (z == n)
      ++satu[z+1][i];
  }
  matrix basis(n+2, 1);
  basis[0][0] = 1;
  f[0] = nol;
  f[1] = satu;
  for (int i = 2; i <= x; ++i) {
    f[i] = f[i-2] * f[i-1];
  }
  matrix res = f[x] * basis;
  printf("%d\n", res[n+1][0]);
  return 0;
}