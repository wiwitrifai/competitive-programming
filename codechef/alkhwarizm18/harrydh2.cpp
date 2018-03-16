#include <bits/stdc++.h>

using namespace std;


const int M = 3, mod = 1e6 + 3;

struct matrix {
  int n, m;
  int a[M][M];
  matrix(int n = M, int m = M) : n(n), m(m) {
    identity();
    // memset(a, 0, sizeof a);
  }
  void identity() {
    memset(a, 0, sizeof a);
    for(int i = 0; i<n; i++)
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
    for(int i = 0; i<this->n; i++) {
      for(int j = 0; j<mat.m; j++) {
        int &now = ret[i][j];
        now = 0;
        for(int k = 0; k<this->m; k++) {
          now = (now + 1LL * this->a[i][k] * mat[k][j]) % mod;
        }
      }
    }
    return ret;
  }
  matrix operator+(const matrix& mat) const {
    matrix ret(n, m);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) {
        ret[i][j] = a[i][j] + mat[i][j];
        if (ret[i][j] > mod) ret[i][j] -= mod;
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
    ret.identity();
    while(pw) {
      if(pw & 1)
        ret = ret*base;
      base = base*base;
      pw >>= 1;
    }
    return ret;
  }
};

int fr[][3] = {{1929, 70004, 928071}, {1, 0, 0}, {0, 1, 0}};

const int N = 1e5 + 5;
matrix init[N];
matrix mat[N << 2];
int n;
struct item {
  int a, l, u, id;
  long long s;
  item() {}
  item(int id, int a, int l, int u, long long s) : id(id), a(a), l(l), u(u), s(s) {}
  bool operator<(const item & o) const {
    return a < o.a;
  }
};

matrix res, e;
void build(int id = 1, int l = 0, int r = n) {
  if (r-l < 2) {
    mat[id] = init[l] + e;
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
  mat[id] = mat[ir] * mat[il];
}

void get(int x, int y, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    // cerr << " mul " << l << " " << r << endl;
    res = mat[id] * res;
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  get(x, y, il, l, mid);
  get(x, y, ir, mid, r);
}

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

item p[N];
long long ans[N];

int main() {
  // f[0] = 10, f[1] = 8, f[2] = 1;
  // long long inv = powmod(928071, mod-2);
  // long long val = (mod - 70004LL) * inv % mod; 
  // long long vbl = (mod - 1929LL) * inv % mod; 
  // long long vcl = inv % mod; 
  // for (int i = 3; i < 10; ++i) {
  //   f[i] = (f[i-1] * val + f[i-2] * vbl + f[i-3] * vcl) % mod;
  //   cerr << i << " " << f[i] << endl;
  // }
  matrix rel(3, 3), awal(3, 1);
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
      rel[i][j] = fr[i][j];
  awal[0][0] = 1;
  awal[1][0] = 472421;
  awal[2][0] = 712234;
  e.identity();
  scanf("%d", &n);
  vector<int> va;
  for (int i = 0; i < n; ++i) {
    int a, l, u;
    long long s;
    scanf("%lld %d %d %d", &s, &a, &l, &u);
    p[i] = item(i, a, l, u, s);
    va.push_back(a);
  }
  sort(va.begin(), va.end());
  sort(p, p+n);
  for (int i = 0; i < n; ++i) {
    p[i].l = lower_bound(va.begin(), va.end(), p[i].l) - va.begin();
    p[i].u = upper_bound(va.begin(), va.end(), p[i].u) - va.begin();
    init[i] = (rel^p[i].s);
  }
  build();
  for (int i = 0; i < n; ++i) {
    res = init[i] * awal;
    long long cur = res[0][0];
    if (i < p[i].l || p[i].u <= i)
      get(p[i].l, p[i].u);
    else {
      get(p[i].l, i);
      get(i+1, p[i].u);
    }
    ans[p[i].id] = (res[0][0]-cur) % mod;
    if (ans[p[i].id] < 0) ans[p[i].id] += mod;
  }
  for (int i = 0; i < n; ++i)
    printf("%d%c", ans[i], i == n-1 ? '\n' : ' ');
  return 0;
}
