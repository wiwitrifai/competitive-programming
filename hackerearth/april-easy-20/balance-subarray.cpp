#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, mod = 1e9 + 7;

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

pair<int, int> seg[N << 2];
int swap_lazy[N << 2];
int a[N], n;

long long calc(int k) {
  return 1LL * k * (k + 1) / 2;
}

void build(int id = 1, int l = 0, int r = n) {
  if (r-l < 2) {
    seg[id] = {1, 0};
    if (a[l])
      swap(seg[id].first, seg[id].second);
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
  seg[id] = {seg[il].first + seg[ir].first, seg[il].second + seg[ir].second};
}

void swap_val(int id) {
  swap(seg[id].first, seg[id].second);
  swap_lazy[id] ^= 1;
}

void push(int id, int il, int ir) {
  if (!swap_lazy[id]) return;
  swap_val(il);
  swap_val(ir);
  swap_lazy[id] = 0;
}

void update(int x, int y, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    swap_val(id);
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  push(id, il, ir);
  update(x, y, il, l, mid);
  update(x, y, ir, mid, r);
  seg[id] = {seg[il].first + seg[ir].first, seg[il].second + seg[ir].second};
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    a[i] &= 1;
  }
  build();
  int q;
  scanf("%d", &q);
  long long d = powmod(calc(n) % mod, mod-2);
  while (q--) {
    int l, r, x;
    scanf("%d %d %d", &l, &r, &x);
    --l;
    if (x & 1) {
      update(l, r);
    }
    long long ans = (calc(seg[1].first) + calc(seg[1].second)) * d % mod;
    if (ans < 0)
      ans += mod;
    printf("%lld\n", ans);
  }
  return 0;
}
