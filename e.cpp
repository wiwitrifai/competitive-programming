#include <bits/stdc++.h>

using namespace std;

const int N = 103;
const int mod = 1e9 + 7;

struct matrix {
  int n, m;
  long long a[N][N];
  matrix(int n, int m) : n(n), m(m) {
    memset(a, 0, sizeof a);
  }
  void diag() {
    for(int i = 0; i<n; i++)
      a[i][i] = 1;
  }
  const long long * operator[](int id) const {
    return a[id];
  }
  long long * operator[](int id) {
    return a[id];
  }
  // void print() {
  //   for(int i = 0; i<n; i++) {
  //     for(int j = 0; j<m; j++)
  //       printf("%lld ", a[i][j]);
  //     printf("\n");
  //   }
  // }
};

matrix operator*(const matrix& p, const matrix& q) {
  matrix r(p.n, q.m);
  for(int i = 0; i<p.n; i++) {
    for(int j = 0; j<q.m; j++) {
      long long &now = r[i][j];
      now = 0;
      for(int k = 0; k < p.m; k++)
        now = (now + p[i][k]*q[k][j]) % mod;
    }
  }
  return r;
}

matrix operator^(matrix base, long long pw) {
  matrix res(base.n, base.m);
  res.diag();
  while(pw) {
    if(pw & 1)
      res = res * base;
    base = base * base;
    pw >>= 1;
  }
  return res;
}

int main() {
  int n, b, k, x;
  int a[N];
  memset(a, 0, sizeof a);
  scanf("%d%d%d%d", &n, &b, &k, &x);
  for(int i = 0; i<n; i++) {
    int y;
    scanf("%d", &y);
    a[y % x]++;
  }
  matrix c(x, 1);
  for(int i = 0; i<x; i++)
    c[i][0] = a[i];
  matrix d(x, x);
  for(int i = 0; i<x; i++) {
    for(int j = 0; j<min(x, 10); j++)
      d[(10*i+j) % x][i] += a[j];
  }
  d = d^(b-1);
  d = d*c;
  cout << d[k][0] << endl;
  return 0;
}