#include <bits/stdc++.h>

using namespace std;

const int N = 102, mod = 1e9 + 7, M = 5005;

struct matrix {
  int mat[N][N];
  int n, m;
  matrix(int n = 0, int m = 0) : n(n), m(m) {
  }
  int* operator[](int id) {
    return mat[id];
  }
  const int * operator[](int id) const {
    return mat[id];
  }
  matrix operator*(matrix mm) const {
    matrix ret(n, mm.m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < mm.m; j++) {
        int & now = ret[i][j];
        now = 0;
        for (int k = 0; k < m; k++) {
          now = (now + 1LL * mat[i][k] * mm[k][j]) % mod; 
        }
        if (now < 0)
          now += mod;
      }
    }
    return ret;
  }
  matrix operator^(long long pw) const {
    matrix b = *this;
    matrix ret(n, n);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        ret[i][j] = (i == j);
    while (pw) {
      if (pw & 1)
        ret = ret * b;
      b = b * b;
      pw >>= 1;
    }
    return ret;
  }
};

int g[M], f[M];

long long powmod(long long b, long long pw) {
  long long ret = 1;
  while (pw) {
    if (pw & 1)
      ret = (ret * b) % mod;
    b = (b * b) % mod;
    pw >>= 1;
  }
  return ret;
}
matrix bb[17][5];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, q;
    scanf("%d %d", &n, &q);
    f[0] = n;
    for (int i = 1; i <= n; i++) {
      scanf("%d", f+i);
    }
    g[0] = 1;
    for (int i = 1; i <= n; i++) {
      int & now = g[i];
      now = 0;
      int sign = 1;
      for (int j = 1; j <= i; j++) {
        now = (now + 1LL * sign * f[j] * g[i-j]) % mod;
        sign = -sign;
      }
      now = (powmod(i, mod-2) * now) % mod;
      if (now < 0)
        now += mod;
    }
    for (int i = n; i + 1 < M; i++) {
      int & now = f[i+1];
      now = 0;
      long long sign = 1;
      for (int j = 1; j <= n; j++) {
        now = (now + sign * f[i+1-j] * g[j]) % mod;
        sign = -sign;
      }
      if (now < 0)
        now += mod;
    }
    matrix ff(n, 1);
    for (int i = 0; i < n; i++)
      ff[i][0] = f[n-i];
    matrix b(n, n);
    int sign = 1;
    for (int i = 0; i < n; i++) {
      b[0][i] = sign * g[i+1];
      sign = -sign; 
    }
    for (int i = 1; i < n; i++) {
      b[i][i-1] = 1;
    }
    for (int i = 0; i < 4; i++) {
      bb[0][i] = b ^ i;
    }
    for (int i = 1; i < 17; i++) {
      bb[i][0] = bb[i-1][0];
      for (int j = 1; j < 4; j++)
        bb[i][j] = bb[i-1][j] ^ 4;
    }
    int id = 0;
    while (q--) {
      long long x;
      scanf("%lld", &x);
      x %= mod - 1;
      if (x < M) {
        printf("%d ", (int)f[x]);
        continue;
      }
      x -= n;
      int iid = 0;
      matrix now(n, n);
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            now[i][j] = (i == j);
      while (x) {
        if (x & 3)
          now = (now * bb[iid][x & 3]);
        iid++;
        x >>= 2;
      }
      now = (now * ff);
      printf("%d ", (int)now[0][0]);
    }
    printf("\n");
  }
  return 0;
}