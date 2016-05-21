#include <bits/stdc++.h>

using namespace std;

const int N_MAT = 2;
const int mod = 1e9 + 7;

struct matrix {
  int n, m;
  long long _mat[N_MAT][N_MAT];
  matrix(int _n = 2, int _m = 2) : n(_n), m(_m) {
    memset(_mat, 0, sizeof _mat);
  }
  const long long * operator[](int id) const { return _mat[id]; }
  long long * operator[](int id) {return _mat[id]; }
  void identity() {
    for(int i = 0; i<n; i++)
      _mat[i][i] = 1;
  }
  matrix operator*(const matrix& mat) {
    matrix ret(this->n, mat.m);
    for(int i = 0; i<n; i++)
      for(int j = 0; j<mat.m; j++) {
        ret[i][j] = 0;
        for(int k = 0; k<m; k++) {
          ret[i][j] += _mat[i][k] * mat[k][j] % mod;
          ret[i][j] %= mod;
        }
      }
    return ret;
  }
  matrix operator+(const matrix& mat) {
    matrix ret(n, m);
    for(int i = 0; i<n; i++)
      for(int j = 0; j<m; j++)
        ret[i][j] = (_mat[i][j] + mat[i][j]) % mod;
    return ret;
  }
  matrix operator^(long long pw) {
    matrix ret(n, m), base = *this;
    ret.identity();
    while(pw) {
      if(pw & 1)
        ret = ret * base;
      base = base * base;
      pw >>= 1;
    }
    return ret;
  }
  void print() {
    for(int i = 0; i<n; i++) {
      for(int j= 0; j<m; j++)
        cerr << _mat[i][j] << " ";
      cerr << endl;
    }
  }
};

const int N = 1e5 + 5;
matrix seg[N<<2];
matrix O(2, 2);
matrix I(2, 2);
matrix F(2, 2);
int n, q;
int a[N];

void build(int id = 1, int l = 0, int r = n) {
  if(r-l < 2) {
    seg[id] = (F ^ a[l]) + I;
    return;
  }
  int il = id << 1, ir = il + 1, mid = (l + r) >> 1;
  build(il, l, mid);
  build(ir, mid, r);
  seg[id] = seg[il] * seg[ir];
}

void update(int x, int val, int id = 1, int l = 0, int r = n) {
  if(r-l < 2) {
    seg[id] = (F ^ val) + I;
    a[l] = val;
    return;
  }
  int il = id << 1, ir = il + 1, mid = (l + r) >> 1;
  if(x < mid)
    update(x, val, il, l, mid);
  else
    update(x, val, ir, mid, r);
  seg[id] = seg[il] * seg[ir];
}

matrix get(int x, int y, int id = 1, int l = 0, int r = n) {
  if(x >= r || y <= l) return I;
  if(x <= l && r <= y) return seg[id];
  int mid = (l+r) >> 1, il = id<<1, ir = il | 1;
  matrix resl = get(x, y, il, l, mid);
  matrix resr = get(x, y, ir, mid, r);
  return resl * resr;
}

int main() {
  I.identity();
  F[0][0] = F[0][1] = F[1][0] = 1;
  F[1][1] = 0;
  scanf("%d%d", &n, &q);
  for(int i = 0; i<n; i++)
    scanf("%d", a+i), a[i];
  build();
  while(q--) {
    char c[10];
    int l, r;
    scanf("%s%d%d", &c, &l, &r);
    l--;
    if(c[0] == 'C')
      update(l, r);
    else {
      matrix res = get(l, r);
      printf("%lld\n", res[0][1]);
    }
  }
  return 0;
}