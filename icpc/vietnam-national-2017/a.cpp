#include <bits/stdc++.h>

using namespace std;

const int M = 4, mod = 1e9 + 7;
struct matrix {
  int n, m, a[M][M];
  matrix(int n = M, int m = M) : n(n), m(m) {}
  void reset() {
    memset(a, 0, sizeof a);
  }
  void identity() {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        a[i][j] = i == j;
    }
  }
  matrix operator*(const matrix& b) const {
    matrix res(n, b.m);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < b.m; ++j) {
        int now = 0;
        for (int k = 0; k < m; ++k) {
          now = (now +1LL * a[i][k] * b.a[k][j]) % mod;
        }
        res.a[i][j] = now;
      }
    }
    return res;
  }
  matrix operator+(const matrix& b) const {
    matrix res;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        res.a[i][j] = a[i][j] + b.a[i][j];
        if (res.a[i][j] >= mod)
          res.a[i][j] -= mod;
      }
    }
    return res;
  }
  
  matrix operator^(long long p) const {
    matrix b = *this;
    matrix res;
    res.identity();
    for (; p; p >>= 1, b = b * b) {
      if (p &1)
        res = res * b;
    }
    return res;
  }
  void print() {
    for (int i = 0; i < M; i++) {
      for (int j =0; j< M; j++)
        cerr << a[i][j] << " ";
      cerr << endl;
    }
  }
};
matrix iden;
matrix powersum(matrix mat, long long p) {
  if (p == 1) {
    return iden;
  }
  matrix res = powersum(mat * mat, p >> 1);
  res = res * (mat + iden);
  if (p & 1)
    res = res * mat + iden;
  return res;
}
const int N = 1e5 + 5;
matrix lz[N << 2];
bool blz[N << 2];
matrix b, a, ia;
matrix ps[N], pw[N];
int mb[4][4] = {{1, 3, 6, 6}, {0, 1, 2, 2}, {0, 0, 1, 1}, {0, 0, 0, 1}};
long long sum[N << 2];
int n;
void build(int id = 1, int l = 0, int r = n) {
  lz[id].m = 1;
  blz[id] = 0;
  sum[id] = 0;
  if (r-l < 2) {
    return ;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il| 1;
  build(il, l, mid);
  build(ir, mid, r);
}

void upd(int id, int l, int r, const matrix& add) {
  matrix res = ps[r-l] * add;
  sum[id] += res.a[0][0];
  if (sum[id] >= mod) sum[id] -= mod;
  lz[id] = lz[id] + add;
  blz[id] = 1;
}

void push(int id, int l, int r) {
  if (!blz[id]) return;
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  upd(il, l, mid, lz[id]);
  matrix addr = pw[mid-l] * lz[id];
  upd(ir, mid, r, addr);
  lz[id].reset();
  blz[id] = 0;
}

void update(int x, int y, const matrix & add, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    upd(id, l, r, add);
    return;
  }
  push(id, l, r);
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  update(x, y, add, il, l, mid);
  matrix addr = x < mid ? pw[mid-max(l, x)] * add : add;
  update(x, y, addr, ir, mid, r);
  sum[id] = sum[il] + sum[ir];
  if (sum[id] >= mod)
    sum[id] -= mod;
}

long long get(int x, int y, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return 0;
  if (x <= l && r <= y) {
    return sum[id];
  }
  push(id, l, r);
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  long long res = get(x, y, il, l, mid) + get(x, y, ir, mid, r);
  if (res >= mod)
    res -= mod;
  return res;
}

int main() {
  for (int i = 0; i < M; i++)
    for (int j = 0; j < M; j++)
      b.a[i][j] = mb[i][j];
  a.reset();
  a.m = 1;
  a.a[3][0] = 1;
  a = b * a;
  ia.reset();
  ia.m = 1;
  ia.a[3][0] = mod - 1;
  ia = b * ia;
  ps[0].reset();
  pw[0].identity();
  for (int i = 0; i + 1 < N; i++) {
    pw[i+1] = pw[i] * b;
    ps[i+1] = ps[i] + pw[i];
  }
  int m;
  scanf("%d %d", &n, &m);
  build();
  while (m--) {
    int t, x, y;
    scanf("%d %d %d", &t, &x, &y); x--;
    if (t == 0) {
      long long ans = get(x, y) % mod;
      if (ans < 0) ans += mod;
      printf("%lld\n", ans);
    }
    else if (t == 1) {
      update(x, y, a);
    }
    else
      update(x, y, ia);
  }
  return 0;
}