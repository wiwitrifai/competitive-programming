#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

long long sum[N << 2];
int lazy[N << 2], n;

void build(int id = 1, int l = 0, int r = n) {
  sum[id] = lazy[id] = 0;
  if (r-l < 2)
    return ;
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
}

inline void upd(int id, int l, int r, int v) {
  sum[id] += 1LL * v * (r - l);
  lazy[id] += v;
}

inline void push(int id, int l, int r) {
  if (lazy[id] == 0) return;
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  upd(il, l, mid, lazy[id]);
  upd(ir, mid, r, lazy[id]);
  lazy[id] = 0;
}

void update_range(int x, int y, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    upd(id, l, r, +1);
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  push(id, l, r);
  update_range(x, y, il, l, mid);
  update_range(x, y, ir, mid, r);
  sum[id] = sum[il] + sum[ir];
}

long long get_range(int x, int y, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return 0;
  if (x <= l && r <= y) {
    return sum[id];
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  push(id, l, r);
  return get_range(x, y, il, l, mid) + get_range(x, y, ir, mid, r);
}

int l[N], r[N], p[N];
vector<int> posl[N], posr[N];
long long ans[N];

int main() {
  int q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; ++i)
    scanf("%d", p+i);
  for (int i = 0; i < q; ++i) {
    scanf("%d", l+i); --l[i];
    posl[l[i]].push_back(i);
  }
  for (int i = 0; i < q; ++i) {
    scanf("%d", r+i); --r[i];
    posr[r[i]].push_back(i);
  }
  vector<int> decr;
  build();
  for (int i = 0; i < n; ++i) {
    while (!decr.empty() && p[decr.back()] < p[i]) decr.pop_back();
    update_range(decr.empty() ? 0 : decr.back() + 1, i);
    decr.push_back(i);
    for (int u : posr[i]) {
      ans[u] += get_range(l[u], i);
    }
  }
  vector<int> incr;
  build();
  for (int i = n-1; i >= 0; --i) {
    while (!incr.empty() && p[incr.back()] < p[i]) incr.pop_back();
    update_range(i, incr.empty() ? n : incr.back());
    incr.push_back(i);
    for (int u : posl[i]) {
      ans[u] += get_range(i, r[u] + 1);
    }
  }
  for (int i = 0; i < q; ++i)
    printf("%lld%c", ans[i], i+1 == q ? '\n' : ' ');
  return 0;
}