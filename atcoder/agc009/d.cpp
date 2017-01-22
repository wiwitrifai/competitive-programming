#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6;
const int mod = 1e9 + 7;

int n;
long long a, b, s[N];
long long sum[N << 2];
bool laz[N << 2];

void build(int id = 1, int l = 0, int r = n) {
  sum[id] = laz[id] = 0;
  if (r-l < 2) {
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
}

void shift(int id) {
  if (!laz[id]) return;
  int il = id << 1, ir = il | 1;
  laz[il] = laz[ir] = laz[id];
  sum[il] = sum[ir] = 0;
  laz[id] = 0;
}

void update1(int x, long long val, int id = 1, int l = 0, int r = n) {
  if (r-l < 2) {
    sum[id] = val % mod;
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  shift(id);
  if (x < mid)
    update1(x, val, il, l, mid);
  else
    update1(x, val, ir, mid, r);
  sum[id] = (sum[il] + sum[ir]) % mod;
}
void update2(int x, int y, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    sum[id] = 0;
    laz[id] = 1;
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  shift(id);
  update2(x, y, il, l, mid);
  update2(x, y, ir, mid, r);
  sum[id] = (sum[il] + sum[ir]) % mod;
}
long long get(int x, int id = 1, int l = 0, int r = n) {
  if (l >= x) return 0;
  if (r <= x) return sum[id];
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  return (get(x, il, l, mid) + get(x, ir, mid, r)) % mod;
}

int main() {
  scanf("%d %lld %lld", &n, &a, &b);
  n++;
  for (int i = 1; i < n; i++) {
    scanf("%lld", s+i);
  }
  build();
  update1(0, 1);
  for (int i = 1; i < n; i++) {
    int ia = upper_bound(s+1, s+n, s[i]-a) - s;
    int ib = upper_bound(s+1, s+n, s[i]-b) - s;
    cerr << ia << " " << ib << " " << get(ib) << endl;
    update1(i, get(ib));
    if (i > 1 && s[i] - s[i-1] < a)
      update2(0, i-1);
    // update2(0, ia);
    for (int j = 1; j <= n; j++)
      cerr << get(j) << " | ";
    cerr << endl;
  }
  printf("%lld\n", get(n));
  return 0;
}