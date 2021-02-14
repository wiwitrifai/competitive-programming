#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

struct SegTree {
  int n;
  vector<int> seg, lazy;
  SegTree(int _n) : n(_n), seg(n * 2, -1), lazy(n * 2, -1) {
  }

  void upd(int id, int v, bool force) {
    if (seg[id] < 0 && !force)
      return;
    seg[id] = max(seg[id], v);
    lazy[id] = max(lazy[id], v);
  }

  void push_down(int id, int il, int ir) {
    if (lazy[id] < 0)
      return;
    upd(il, lazy[id], false);
    upd(ir, lazy[id], false);
    lazy[id] = -1;
  }

  void update(int x, int y, int v, bool force, int id, int l, int r) {
    if (l >= y || x >= r) return;
    if (x <= l && r <= y) {
      upd(id, v, force);
      return;
    }
    int mid = (l + r) >> 1, il = id + 1, ir = id + (r-l) * 2;
    push_down(id, il, ir);
    update(x, y, v, force, il, l, mid);
    update(x, y, v, force, ir, mid, r);
    seg[id] = max(seg[il], seg[ir]);
  }

  void update(int x, int y, int v, bool force = false) {
    update(x, y, v, force, 0, 0, n);
  }

  int get(int x, int y, int id, int l, int r) {
    if (l >= y || x >= r) return -1;
    if (x <= l && r <= y) {
      return seg[id];
    }    
    int mid = (l + r) >> 1, il = id + 1, ir = id + (r-l) * 2;
    push_down(id, il, ir);
    return max(get(x, y, il, l, mid), get(x, y, ir, mid, r));
  }

  int get(int x, int y) {
    return get(x, y, 0, 0, n);
  }
};

void solve() {
  int n;
  scanf("%d", &n);
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &p[i]);
  }
  vector<vector<int>> dp(n+1, vector<int>(2, -1));
  vector<vector<int>> pre(n+1, vector<int>(2, -1));
  SegTree segtree(n);
  auto enc = [&](int id, int full, int right) {
    return (id << 2) | (full << 1) | right;
  };
  auto upd = [&](int i, int to, int val, int val_pre) {
    if (dp[i][to] < val) {
      dp[i][to] = val;
      pre[i][to] = val_pre;
    }
  };
  for (int i = 0; i < n; ++i) {
    int last = dp[i][1];
    int left = -1;
    int res = segtree.get(max(0, i - p[i]), i);
    if (res >= i)
      left = max(left, res);
    if (last >= i)
      left = max(left, last);
    if (left >= i) {
      segtree.update(i, i+1, left, true);
    }
    int right = -1;
    if (last >= i-1) {
      right = max(right, max(last, i+p[i]));
      segtree.update(i, i+1, right, true);
    }
    segtree.assign(i, dp[i+1][0], enc(i, 0, 0));
    if (last >= i)
      last = max(last, right);
    last = max(left, last);
    segtree.update(0, i, i+p[i]);
  }
  if (last >= n-1) {
    puts("YES");
  } else {
    puts("NO");
  }
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
