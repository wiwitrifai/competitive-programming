#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;

int a[N];
int n;
long long sum[N<<2];
long long lazy[N<<2];

void build(int id = 1, int l = 0, int r = n) {
  // cerr << id << endl;
  sum[id] = 0;
  lazy[id] = 0;
  if (r-l < 2) {
    sum[id] = a[l];
    // cerr << id << " " << sum[id] << " " << l << " " << a[l] << endl;
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
  sum[id] = sum[il] + sum[ir];
  // cerr << sum[id] << endl;
}

void upd(int id, int l, int r, long long v) {
  sum[id] += v * (r-l);
  lazy[id] += v;
}

void shift(int id, int l, int r) {
  if (lazy[id] == 0)
    return;
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  upd(il, l, mid, lazy[id]);
  upd(ir, mid, r, lazy[id]);
  lazy[id] = 0;
}

void update(int x, int y, long long v, int id = 1, int l = 0, int r = n) {
  // cerr << l << " " << r << endl;
  if (x >= r || y <= l) return;
  if (x <= l && r <= y) {
    upd(id, l, r, v);
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  shift(id, l, r);
  update(x, y, v, il, l, mid);
  update(x, y, v, ir, mid, r);
  sum[id] = sum[il] + sum[ir];
}

long long get(int x, int id = 1, int l = 0, int r = n) {
  // cerr << l << " " << r << " " << sum[id] << endl;
  if (r-l < 2) {
    return sum[id];
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  shift(id, l, r);
  if (x < mid)
    return get(x, il, l, mid);
  else
    return get(x, ir, mid, r);
}

int p[N];
int main() {
  int c;
  scanf("%d %d", &n, &c);
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
    // cerr << a[i] << " ";
  }
  for (int i = 0; i < n; i++)
    scanf("%d", p+i);
  // for (int i = 0; i < n; i++)
  //   cerr << a[i] << " " << i << endl ;
  build();
  // for (int i = 0; i < n; i++)
  //   cerr << a[i] << " " << i << endl ;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    // cerr << "build su" << endl;
    long long cur = get(i);
    long long d = min(cur, (long long)p[i]);
    // cerr << cur << " " << p[i] << endl;
    ans += d;
    cur -= d;
    long long k = c ? cur/c : 0;
    if (i+k+1 > n) {
      k = n-i-1;
    }
    if (k > 0)
      update(i+1, i+k+1, c);
    cur -= k * c;
    if (cur > c)
      cur = c;
    if ((i+k+1 < n) && cur > 0)
      update(i+k+1, i+k+2, cur);
  }
  printf("%lld\n", ans);
  return 0;
}