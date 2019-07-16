#include <bits/stdc++.h>

using namespace std;

const int K = 3, mod = 1e9 + 7;

struct matrix {
  int a[K][K];
  matrix() {
    memset(a, 0, sizeof a);
  }
  matrix operator*(matrix m) {
    matrix r;
    for (int i = 0; i < K; ++i) {
      for (int j = 0; j < K; ++j) {
        int & now = r.a[i][j];
        now = 0;
        for (int k = 0; k < K; ++k) {
          now = (now + 1LL * a[i][k] * m.a[k][j]) % mod;
        }
      }
    }
    return r;
  }

  void identity() {
    for (int i = 0; i < K; ++i)
      for (int j = 0; j < K; ++j)
        a[i][j] = i == j;
  }

  matrix operator^(long long p) {
    matrix ret;
    ret.identity();
    matrix base = * this;
    for (; p; p >>= 1, base = base * base)
      if (p & 1)
        ret = ret * base;
    return ret;
  }
  void print() {
    for (int i = 0; i < K; ++i) {
      for (int j = 0; j < K; ++j)
        cerr << a[i][j] << " ";
      cerr <<endl;
    }
  }
};

int m_base[][3] = {{1, 1, 0}, {0, 1, 1}, {0, 1, 0}};

int main() {
  matrix init;
  init.a[1][0] = 1;
  matrix base;
  for (int i = 0; i < K; ++i)
    for (int j = 0; j < K; ++j)
      base.a[i][j] = m_base[i][j];
  int t;
  scanf("%d", &t);
  while (t--) {
    long long n;
    scanf("%lld", &n);
    matrix ans = (base^n) * init;
    // ans.print();
    printf("%d\n", ans.a[0][0]);
  }
  return 0;
}