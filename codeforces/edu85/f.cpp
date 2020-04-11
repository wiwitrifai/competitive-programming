#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;
const long long inf = 1e18;

int len;
long long add[N << 2], seg[N << 2];

void build(int id = 1, int l = 0, int r = len) {
  add[id] = 0;
  seg[id] = inf;
  if (r-l < 2) {
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
}

inline void upd(int id, long long x) {
  seg[id] += x;
  add[id] += x;
}

inline void push(int id, int il, int ir) {
  if (add[id] == 0) return;
  upd(il, add[id]);
  upd(ir, add[id]);
  add[id] = 0;
}

inline void combine(int id, int il, int ir) {
  seg[id] = min(seg[il], seg[ir]);
}

void update(int x, int y, long long v, int id = 1, int l = 0, int r = len) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    upd(id, v);
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  push(id, il, ir);
  update(x, y, v, il, l, mid);
  update(x, y, v, ir, mid, r);
  combine(id, il, ir);
}

void update1(int x, long long v, int id = 1, int l = 0, int r = len) {
  if (r-l < 2) {
    seg[id] = min(seg[id], v);
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  push(id, il, ir);
  if (x < mid)
    update1(x, v, il, l, mid);
  else
    update1(x, v, ir, mid, r);
  combine(id, il, ir);
}

long long get(int x, int y, int id = 1, int l = 0, int r = len) {
  if (x >= r || l >= y) return inf;
  if (x <= l && r <= y) {
    return seg[id];
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  push(id, il, ir);
  return min(get(x, y, il, l, mid), get(x, y, ir, mid, r));
}

int n;
int a[N], p[N], b[N], c[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  for (int i = 0; i < n; ++i)
    scanf("%d", p+i);
  int m;
  scanf("%d", &m);
  memset(b, -1, sizeof b);
  for (int i = 0; i < m; ++i) {
    scanf("%d", c+i);
    b[c[i]] = i;
  }
  len = m;
  long long sum = 0;
  int cnt = 0;
  build();
  for (int i = 0; i < n; ++i) {
    long long cur = inf;
    int x = a[i];
    if (b[x] != -1 && b[x] <= cnt) {
      cur = b[x] == 0 ? sum : get(b[x]-1, b[x]);
    }
    sum += p[i];
    if (p[i] < 0) {
      update(0, cnt, p[i]);
    }
    else if (p[i] > 0) {
      int pos = lower_bound(c, c+m, x) - c;
      update(0, min(cnt, pos), p[i]);
    }
    if (b[x] != -1 && b[x] <= cnt) {
      cnt += b[x] == cnt;
      update1(b[x], cur);
    }
  }
  if (cnt < m) {
    puts("NO");
    return 0;
  }
  long long ans = get(m-1, m);
  printf("YES\n%lld\n", ans);
  return 0;
}
