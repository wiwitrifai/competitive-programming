#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int a[N];

struct node {
  set<int > index;
  set<pair<int, int> > val;
  vector<int> bit;
  int off;
  void upd(int x, int v) {
    x += off;
    for (; x < bit.size(); x += x&-x)
      bit[x] += v;
  }
  int get(int x) {
    x += off;
    int ret = 0;
    for (; x > 0; x -= x &-x)
      ret += bit[x];
    return ret;
  }
  void update(int x, int v) {
    auto it = index.lower_bound(x);
    if (it != index.end() && *it == x) {
      upd(x, -1);
      val.erase(make_pair(a[x], x));
      index.erase(it);
    }
    it = index.lower_bound(x);
    if (it != index.begin() && a[*(--it)] >= a[x] + v)
      return;
    while (it != index.end() && *it <= x) it++;
    while (it != index.end() && a[*it] <= a[x] + v) {
      upd(*it, -1);
      val.erase(make_pair(a[*it], *it));
      index.erase(it++);
    }
    upd(x, +1);
    index.insert(x);
    val.insert(make_pair(a[x] + v, x));
  }
  pair<int, int> get(int l, int r) {
    auto itl = val.lower_bound(make_pair(l, -1));
    auto itr = val.lower_bound(make_pair(r, -1));
    if (itl == val.end())
      return make_pair(0, -1);
    if (itr == val.end())
      itr--;
    return make_pair(get(itr->second) - get(itl->second-1), itr->first);
  }
};

int n;
node seg[N << 2];

void build(int id = 1, int l = 0, int r = n) {
  if (r-l < 2) {
    seg[id].bit.assign(2, 0);
    seg[id].off = -l + 1;
    // seg[id].index.insert(l);
    // seg[id].val.insert(make_pair(a[l], l));
    seg[id].upd(l, +1);
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
  seg[id].bit.assign(r-l+1, 0);
  seg[id].off = -l + 1;
  // seg[id].index = seg[il].index;
  // seg[id].val = seg[il].val;
  // int last = a[*seg[id].index.rbegin()];
  // for (int it : seg[ir].index) {
  //   if (a[it] <= last) continue;
  //   last = a[it];
  //   seg[id].index.insert(it);
  //   // seg[id].val.insert(make_pair(a[it], it));
  // }
  for (int it = l; it < r; it++)
    seg[id].upd(it, +1);
}

void upd(int x, int v, int id = 1, int l = 0, int r = n) {
  seg[id].update(x, v);
  if (r-l < 2) {
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  if (x < mid)
    upd(x, v, il, l, mid);
  else
    upd(x, v, ir, mid, r);
}

pair<int, int> get(int x, int lo, int hi, int id = 1, int l = 0, int r = n) {
  if (r <= x) return make_pair(0, -1);
  if (x <= l) {
    return seg[id].get(lo, hi);
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  pair<int, int> ret = get(x, lo, hi, il, l, mid);
  if (ret.second >= hi)
    return ret;
  auto res = get(x, max(lo, ret.second+1), hi, ir, mid, r);
  ret.first += res.first;
  ret.second = max(ret.second, res.second);
  return ret;
}

int main() {
  int t, q;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++)
      scanf("%d", a+i);
    build();
    for (int i = 0; i < q; i++) {
      char c;
      int x, y, z;
      scanf(" %c %d %d", &c, &x, &y);
      if (c == '+') {
        x--;
        upd(x, y);
        a[x] += y;
      }
      else {
        scanf("%d", &z);
        x--;
        printf("%d\n", get(x, y, z).first);
      }
    }
  }
  return 0;
}