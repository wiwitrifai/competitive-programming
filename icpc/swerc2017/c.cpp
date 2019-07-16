#include <bits/stdc++.h>

using namespace std;

const int N = 1 << 8, mod = 1e9;
struct matrix {
  int a[N][N], n, m;
  matrix(int n = 0, int m = 0) : n(n), m(m) { memset(a, 0, sizeof a); }
  matrix operator*(matrix & mat) {
    matrix ret(n, mat.m);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < mat.m; ++j) {
        int & cur = ret.a[i][j];
        cur = 0;
        for (int k = 0; k < m; ++k) {
          cur = (cur + 1LL * a[i][k] * mat.a[k][j]) % mod;
        }
      }
    }
    return ret;
  }
};

ostream& operator<<(ostream& os, matrix mat) {
  os << " size: " << mat.n << "x" << mat.m << endl;
  for (int i = 0; i < mat.n; ++i) {
    for (int j = 0; j < mat.m; ++j)
      os << mat.a[i][j] << " ";
    os << endl;
  }
  return os;
}

int cost[N];

int main() {
  int n;
  long long m;
  scanf("%d %lld", &n, &m);
  int nmask = 1 << n;
  matrix b(nmask, nmask), a(nmask, 1);
  cost[0] = 1;
  for (int i = 0; i < nmask; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i & (1 << j)) break;
      cost[i|(1 << j)] = (cost[i|(1 << j)] + cost[i]) % mod;
      if (j)
        cost[i|(3 << (j-1))] = (cost[i|(3 << (j-1))] + cost[i]) % mod;
    }
  }
  for (int i = 0; i < nmask; ++i)
    a.a[i][0] = cost[i];
  for (int i = 0; i < nmask; ++i) {
    for (int j = 0; j < nmask; ++j) {
      b.a[i][j] = ((i | j) == (nmask - 1)) ? cost[i & j] : 0;
    }
  }
  for (; m; m >>= 1, b = b * b) {
    if (m & 1)
      a = b * a;
  }
  printf("%d\n", a.a[0][0]);
  return 0;
}
