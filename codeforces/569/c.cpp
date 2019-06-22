#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int n, m, q;
int a[N], b[N], ty[N], pos[N], x[N];

vector<int> prices;

int lazy[N << 2];
int ma[N << 2];

void upd(int id, int v) {
  ma[id] += v;
  lazy[id] += v;
}

void propagate(int id, int il, int ir) {
  if (lazy[id] == 0) return;
  upd(il, lazy[id]);
  upd(ir, lazy[id]);
  lazy[id] = 0;
}

void update(int x, int y, int v, int id = 1, int l = 0, int r = (int)prices.size()) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    upd(id, v);
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  propagate(id, il, ir);
  update(x, y, v, il, l, mid);
  update(x, y, v, ir, mid, r);
  ma[id] = max(ma[il], ma[ir]);
}

int get(int id = 1, int l = 0, int r = (int)prices.size()) {
  if (r-l < 2)
    return l;
  if (ma[id] <= 0) return -1;
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  propagate(id, il, ir);
  if (ma[ir] > 0)
    return get(ir, mid, r);
  return get(il, l, mid);
}

void debug(int id = 1, int l = 0, int r = (int)prices.size()) {
  if (r-l < 2) {
    cerr << prices[l] << "(" << ma[id] << ") ";
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  propagate(id, il, ir);
  debug(il, l, mid);
  debug(ir, mid, r);
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    prices.push_back(a[i]);
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d", b+i);
    prices.push_back(b[i]);
  }
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    scanf("%d %d %d", ty+i, pos+i, x+i);
    --pos[i];
    prices.push_back(x[i]);
  }
  sort(prices.begin(), prices.end());
  prices.erase(unique(prices.begin(), prices.end()), prices.end());
  for (int i = 0; i < n; ++i) {
    a[i] = lower_bound(prices.begin(), prices.end(), a[i]) - prices.begin();
    update(0, a[i]+1, +1);
  }
  for (int i = 0; i < m; ++i) {
    b[i] = lower_bound(prices.begin(), prices.end(), b[i]) - prices.begin();
    update(0, b[i]+1, -1);
  }
  for (int i = 0; i < q; ++i) {
    x[i] = lower_bound(prices.begin(), prices.end(), x[i]) - prices.begin();
    int p = pos[i];
    if (ty[i] == 1) {
      if (a[p] != x[i]) {
        update(0, a[p]+1, -1);
        a[p] = x[i];
        update(0, a[p]+1, +1);
      }
    }
    else {
      if (b[p] != x[i]) {
        update(0, b[p]+1, +1);
        b[p] = x[i];
        update(0, b[p]+1, -1);
      }
    }
    int res = get();
    if (res >= 0)
      res = prices[res];
    printf("%d\n", res);
  }
  return 0;
}
