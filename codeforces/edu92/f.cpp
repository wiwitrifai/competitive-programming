#include <bits/stdc++.h>

using namespace std;

struct SegTree {
  int n;
  vector<int> seg, lazy;
  SegTree() {
  }

  void init(int _n) {
    n = _n;
    seg.assign(n * 2, 0);
    lazy.assign(n * 2, 0);
  }

  void upd(int id, int add) {
    seg[id] += add;
    lazy[id] += add;
  }

  void push(int id, int il, int ir) {
    if (lazy[id] == 0) return;
    upd(il, lazy[id]);
    upd(ir, lazy[id]);
    lazy[id] = 0;
  }

  void update(int x, int y, int v, int id, int l, int r) {
    if (x >= r || l >= y) return;
    if (x <= l && r <= y) {
      upd(id, v);
      return;
    }
    int mid = (l + r) >> 1, il = id + 1, ir = id + 2 * (mid - l);
    push(id, il, ir);
    update(x, y, v, il, l, mid);
    update(x, y, v, ir, mid, r);
    seg[id] = max(seg[il], seg[ir]);
  }

  void update(int x, int y, int v) {
    update(x, y, v, 0, 0, n);
  }

  void update2(int pos, int v, int id, int l, int r) {
    if (r-l < 2) {
      seg[id] = max(seg[id], v);
      return;
    }
    int mid = (l + r) >> 1, il = id + 1, ir = id + 2 * (mid - l);
    push(id, il, ir);
    if (pos < mid)
      update2(pos, v, il, l, mid);
    else
      update2(pos, v, ir, mid, r);
    seg[id] = max(seg[il], seg[ir]);
  }

  void update2(int pos, int v) {
    update2(pos, v, 0, 0, n);
  }
};

void solve() {
  int n;
  scanf("%d", &n);
  vector<tuple<int, int, int>> segments(n);
  vector<int> coors;
  for (int i = 0; i < n; ++i) {
    int t, l, r;
    scanf("%d %d %d", &l, &r, &t);
    --t;
    ++r;
    coors.push_back(r);
    coors.push_back(l);
    segments[i] = make_tuple(r, l, t);
  }
  sort(segments.begin(), segments.end());
  sort(coors.begin(), coors.end());
  coors.erase(unique(coors.begin(), coors.end()), coors.end());
  SegTree segtree[2];
  for (int i = 0; i < 2; ++i)
    segtree[i].init(coors.size() + 2);
  auto get_pos = [&](int x) {
    return lower_bound(coors.begin(), coors.end(), x) - coors.begin();
  };
  int ans = 0;
  for (auto it : segments) {
    int l, r, t;
    tie(r, l, t) = it;
    int cur = 1;
    r = get_pos(r);
    l = get_pos(l);
    segtree[t].update(0, l+1, 1);
    cur = segtree[t].seg[0];
    ans = max(ans, cur);
    segtree[t^1].update2(r, cur);
  }
  printf("%d\n", ans);
}

int main() {
  int tc = 1;
  // scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
