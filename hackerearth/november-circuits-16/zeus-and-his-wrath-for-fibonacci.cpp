#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

struct matrix {
  int mat[2][2];
  matrix() {
  }
  void identity() {
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++)
        mat[i][j] = (i == j);
  }
  int * operator[](int id) {
    return mat[id];
  }
  matrix operator * (matrix m) {
    matrix ret;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        int now = 0;
        for (int k = 0; k < 2; k++) {
          now = (now + 1LL * mat[i][k] * m[k][j]) % mod;
        }
        ret[i][j] = now;
      }
    }
    return ret;
  }
  matrix operator^(long long p) {
    matrix ret;
    ret.identity();
    matrix base = *this;
    while (p) {
      if (p & 1)
        ret = (ret * base);
      base = base * base;
      p >>= 1;
    }
    return ret;
  }
  matrix operator+(matrix m) {
    matrix ret;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        ret[i][j] = mat[i][j] + m[i][j];
        if (ret[i][j] >= mod)
          ret[i][j] -= mod;
      }
    }
    return ret;
  }
};


const int N = 1e5 + 6;
matrix fib, ifib;
struct node {
  matrix s, sl, sr, sum;
  bool skip;
  node(bool skip = false) : skip(skip) {
  }
  node(int v, bool skip = false) : sum(sum), skip (skip) {
    s = sl = sr = sum = fib ^ v;
  }
  node(matrix s, matrix sl, matrix sr, matrix sum, bool skip = false) : s(s), sl(sl), sr(sr), sum(sum), skip(skip) {
  }
  node operator+ (node other) {
    node ret;
    ret.s = s + other.s + sr * other.sl;
    ret.sl = sl + other.sl * sum;
    ret.sr = sr * other.sum + other.sr;
    ret.sum = sum * other.sum;
    return ret;
  }
};

int a[N], n;
node seg[N << 2];

void build(int id = 1, int l = 0, int r = n) {
  seg[id].skip = false;
  if (r-l < 2) {
    seg[id] = node(a[l]);
    return;
  }
  int mid = (l+r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
  seg[id] = seg[il] + seg[ir]; 
}

void update(int x, int v, int id = 1, int l = 0, int r = n) {
  if (r-l < 2) {
    seg[id] = node(v);
    return;
  }
  int mid = (l+r) >> 1, il = id << 1, ir = il | 1;
  if (x < mid)
    update(x, v, il, l, mid);
  else
    update(x, v, ir, mid, r);
  seg[id] = seg[il] + seg[ir];
}

node get(int x, int y, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return node(true);
  if (x <= l && r <= y) return seg[id];
  int mid = (l+r) >> 1, il = id << 1, ir = il | 1;
  node resl = get(x, y, il, l, mid), resr = get(x, y, ir, mid, r);
  if (resl.skip)
    return resr;
  else if (resr.skip)
    return resl;
  else
    return resl + resr;
}

int main() {
  fib[0][0] = fib[0][1] = fib[1][0] = 1;
  fib[1][1] = 0;
  ifib[0][0] = 0;
  ifib[0][1] = ifib[1][0] = 1;
  ifib[1][1] = -1;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  build();
  int q;
  scanf("%d", &q);
  while (q--) {
    int t, x, y;
    scanf("%d %d %d", &t, &x, &y);
    x--;
    if (t == 1) {
      update(x, y);
    }
    else {
      node res = get(x, y);
      printf("%d\n", res.s[0][1]);
    }
  }
  return 0;
}