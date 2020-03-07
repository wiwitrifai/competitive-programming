#include <bits/stdc++.h>

using namespace std;

const int N = 7;
const int mod = 1e9 + 7;
struct matrix {
  int n, m;
  int a[N][N];
  matrix(int _n, int _m) : n(_n), m(_m) {
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
  matrix operator+(const matrix& mat) const {
    matrix ret(this->n, mat.m);
    for(int i = 0; i < this->n; ++i) {
      for(int j = 0; j < this->m; ++j) {
        ret[i][j] = (a[i][j] + mat[i][j]);
        if (ret[i][j] >= mod)
          ret[i][j] -= mod;
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

matrix calc(matrix b, long long x) {
  if (x == 1) {
    matrix mat(N, N);
    mat.reset();
    return mat;
  }
  matrix res = calc(b * b, x/2);
  matrix ret = res * b + res;
  if (x & 1)
    ret = ret + (b ^ (x-1));
  return ret;
}


int main() {
  long long n, l, r, d, m;
  cin >> n >> l >> r >> d >> m;
  vector<vector<long long>> mbase =
   {{n-4, 0, 0, n-3, 0, n-3, 0},
    {1, 0, 0, 0, 0, 1, 0},
    {1, 0, 0, 1, 0, 0, 0},
    {0, n-3, 0, 0, 0, 0, n-2},
    {0, 1, 0, 0, 0, 0, 0},
    {0, 0, n-3, 0, n-2, 0, 0},
    {0, 0, 1, 0, 0, 0, 0}
  };

  matrix base(N, N);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      base[i][j] = mbase[i][j] % mod;
      if (base[i][j] < 0)
        base[i][j] += mod;
    }
  }
  matrix a(N, 1);
  a[4][0] = 1LL * n * (n-1) % mod;
  matrix basep = base^m;
  long long k = (l + m - 1) / m;
  while (k * m + d >= l) --k;
  ++k;
  long long lef = k;
  k = (r - d) / m;
  while (k * m + d <= r) ++k;
  --k;
  long long rig = k;
  if (lef > rig) {
    puts("0");
    return 0;
  }
  long long now = lef * m + d;
  matrix cur = (base^(now - 2)) * a;
  matrix ans = calc(basep, rig - lef + 1LL);
  ans = ans * cur;
  printf("%d\n", (ans[0][0] + ans[5][0]) % mod);
  return 0;
}
