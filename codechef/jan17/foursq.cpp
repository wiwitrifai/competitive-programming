#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e6 + 6, QN = 4 * sqrt(N) + 5;
const long long mask = (1LL<<20) - 1;
 
long long mod = 1e9 + 7;
long long mull(long long a, long long b) {
  long long k = (long long)((long double) a * b / mod + 0.5);
  return a * b - k * mod;
}
struct foursq {
  long long x[4];
  foursq(long long a = 0, long long b = 0, long long c = 0, long long d = 0) {
    x[0] = a, x[1] = b, x[2] = c, x[3] = d;
  }
  foursq mul(long long k) {
    foursq ret;
    for (int i = 0; i < 4; i++)
      ret.x[i] = x[i] * k;
    return ret;
  }
  foursq mul(foursq f) {
    foursq ret;
    ret.x[0] = (mull(x[0], f.x[0]) + mull(x[1], f.x[1]) + mull(x[2], f.x[2]) + mull(x[3], f.x[3])) % mod;
    ret.x[1] = (mull(x[0], f.x[1]) - mull(x[1], f.x[0]) + mull(x[2], f.x[3]) - mull(x[3], f.x[2])) % mod;
    ret.x[2] = (mull(x[0], f.x[2]) - mull(x[1], f.x[3]) - mull(x[2], f.x[0]) + mull(x[3], f.x[1])) % mod;
    ret.x[3] = (mull(x[0], f.x[3]) + mull(x[1], f.x[2]) - mull(x[2], f.x[1]) - mull(x[3], f.x[0])) % mod;
    // debug();
    // f.debug();
    // ret.debug();
    // assert((get() * f.get()) % mod == ret.get());
    return ret;
  }
  long long get() {
    long long ret = 0;
    for (int i = 0; i < 4; i++) {
      ret += x[i] * x[i];
    }
    ret %= mod;
    return ret;
  }
  void debug() {
    for (int i = 0; i < 4; i++)
      cerr << x[i] << " ";
    cerr << "= " << get() << endl; 
  }
};
foursq f[N];
foursq seg[N * 2];
int n, a[N];
void build(int id = 1, int l = 0, int r = n) {
  if (r-l < 2) {
    seg[id] = f[a[l]];
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
  seg[id] = seg[il].mul(seg[ir]);
}
 
void update(int pos, int y, int id = 1, int l = 0, int r = n) {
  if (r-l < 2) {
    a[l] = y;
    seg[id] = f[y];
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  if (pos < mid)
    update(pos, y, il, l, mid);
  else 
    update(pos, y, ir, mid, r);
  seg[id] = seg[il].mul(seg[ir]);
}
foursq get(int x, int y, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return foursq(1, 0, 0, 0);
  if (x <= l && r <= y) return seg[id];
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  foursq resl = get(x, y, il, l, mid);
  foursq resr = get(x, y, ir, mid, r);
  return resl.mul(resr);
}
 
int main() {
  // Legendre's three square theorem
  // x != 4 ^ p * (8 q + 7) <=> x = a ^ 2 + b ^ 2 + c ^ 3 
  for (int i = 0; i < QN; i++) {
    int ii = i * i;
    for (int j = i; j < QN; j++) {
      int jj = ii + j * j;
      if (jj >= QN) break;
      for (int k = j; k < QN; k++) {
        int kk = jj + k * k;
        if (kk >= QN) break;
        f[kk] = foursq(0, i, j, k);
      }
    }
  }
  // find four square
  for (int i = 0; i < N; i++) {
    if (f[i].get() == i) continue;
    int now = i, mul = 1;
    while (now % 4 == 0) now /= 4, mul *= 2;
    int sq = sqrt(now);
    int res = now - sq * sq;
    if (res == 0) {
      f[i] = foursq(sq * mul, 0, 0, 0);
      assert(i == f[i].get());
      continue;
    }
    while (res % 4 == 0) res /= 4;
    if (res % 8 == 7)
      sq--;
    res = now - sq * sq;
    while (res % 4 == 0) res /= 4;
    assert(res % 8 != 7);
 
    res = now - sq * sq;
    f[i] = f[res].mul(mul);
    f[i].x[0] = mul * sq;
    assert(f[i].get() == i);
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int q;
    scanf("%d %d %lld", &n, &q, &mod); 
    for (int i = 0; i < n; i++)
      scanf("%d", a+i);
    build();
    while (q--) {
      int ty, x, y;
      scanf("%d %d %d", &ty, &x, &y);
      x--;
      if (ty == 1)
        update(x, y);
      else {
        foursq res = get(x, y);
        for (int i = 0; i < 4; i++)
          printf("%lld ", abs(res.x[i]));
        printf("\n");
        // cerr << res.get() % mod << " = "<< now<< endl;
      }
 
    }
  }
 
  return 0;
} 