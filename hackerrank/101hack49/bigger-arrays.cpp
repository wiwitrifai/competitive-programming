#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, mod = 1e9 + 7;
long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1) r = r * b % mod;
  return r;
}

int n, q;
int a[N], lz[N << 2];
long long mul[N << 2], mul2[N << 2];
void build(int id = 1, int l = 0, int r = n) {
  lz[id] = 0;
  if (r-l < 2) {
    mul[id] = a[l];
    mul2[id] = a[l]-1;
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
  mul[id] = (mul[il] * mul[ir]) % mod;
  mul2[id] = (mul2[il] * mul2[ir]) % mod;
}
void upd(int id, int l, int r, int val) {
  if (!val) return;
  mul[id] = powmod(val, r-l);
  mul2[id] = powmod(val-1, r-l);
  lz[id] = val;
}
void push(int id, int l, int r) {
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  if (!lz[id]) return;
  upd(il, l, mid, lz[id]);
  upd(ir, mid, r, lz[id]);
  lz[id] = 0;
}
void update(int x, int y, int val, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    upd(id, l, r, val);
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  push(id, l, r);
  update(x, y, val, il, l, mid);
  update(x, y, val, ir, mid, r);
  mul[id] = (mul[il] * mul[ir]) % mod;
  mul2[id] = (mul2[il] * mul2[ir]) % mod;
}
pair< long long, long long > get(int x, int y, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return make_pair(1, 1);
  if (x <= l && r <= y) return make_pair(mul[id], mul2[id]);
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  push(id, l, r);
  pair< long long, long long > a = get(x, y, il, l, mid), b = get(x, y, ir, mid, r);
  a.first = (a.first * b.first) % mod;
  a.second = (a.second * b.second) % mod;
  return a;
}

int main() {
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  build();
  while (q--) {
    int t, l, r;
    scanf("%d %d %d", &t, &l, &r);
    l--;
    if (t == 1) {
      int x;
      scanf("%d", &x);
      update(l, r, x);
    }
    else {
      pair< long long, long long > res = get(l, r);
      long long ans = res.first - res.second;
      ans %= mod;
      if (ans < 0) ans += mod;
      printf("%lld\n", ans);
    }
  }
  return 0;
}