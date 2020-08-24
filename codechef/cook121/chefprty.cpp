#include <bits/stdc++.h>

using namespace std;

struct SegTree {
public:
  SegTree(int _n) : len(_n) {
    mini.resize(len * 2, 0);
    lazy.resize(len * 2, -1);
  }

  void update(int lef, int rig, int val) {
    update(lef, rig, val, 0, 0, len);
  }

  int get() {
    return mini[0];
  }

private:
  int len;
  vector<int> mini, lazy;

  inline void upd(int id, int val) {
    mini[id] = max(mini[id], val);
    lazy[id] = max(lazy[id], val);
  }

  inline void push_down(int id, int il, int ir) {
    if (lazy[id] == -1) return;
    upd(il, lazy[id]);
    upd(ir, lazy[id]);
    lazy[id] = -1;
  }

  void update(int lef, int rig, int val, int id, int l, int r) {
    if (lef >= r || l >= rig) return;
    if (lef <= l && r <= rig) {
      upd(id, val);
      return;
    }
    int mid = (l + r) >> 1, il = id + 1, ir = id + 2 * (mid - l);
    push_down(id, il, ir);
    update(lef, rig, val, il, l, mid);
    update(lef, rig, val, ir, mid, r);
    mini[id] = min(mini[il], mini[ir]);
  }
};

void solve() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  vector<int> f(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &f[i]);
    --f[i];
  }
  vector<int> id(n), st(m, n), en(m, 0);
  iota(id.begin(), id.end(), 0);
  sort(id.begin(), id.end(), [&](int le, int ri) {
    return f[le] < f[ri];
  });
  vector<int> pos(n);
  for (int i = 0; i < n; ++i) {
    pos[id[i]] =  i;
    int x = f[id[i]];
    st[x] = min(st[x], i);
    en[x] = max(en[x], i);
  }
  SegTree segtree(n);
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    int x = f[i];
    if (st[x] < pos[i])
      segtree.update(st[x], pos[i], i+1);
    if (pos[i] < en[x])
      segtree.update(pos[i]+1, en[x]+1, i+1);
    for (int j = 0; j < k; ++j) {
      int d;
      scanf("%d", &d);
      --d;
      segtree.update(pos[d], pos[d]+1, i+1);
    }
    ans += segtree.get();
  }
  printf("%lld\n", ans);
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
