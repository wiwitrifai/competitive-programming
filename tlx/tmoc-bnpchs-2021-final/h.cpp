#include <bits/stdc++.h>

using namespace std;


struct SegTree {
  int n;
  vector<long long> sum;
  vector<long long> unlocked_sum;
  vector<int> unlocked_cnt;
  vector<int> lazy, lock;
  SegTree(int _n, const vector<int>& a) : n(_n), sum(2 * n), unlocked_sum(2 * n, 0), unlocked_cnt(2 * n, 0), lazy(2 * n, 0), lock(2 * n, 1) {
    build(a, 0, 0, n);
  }

  void upd(int id, int v) {
    if (lock[id] == 2) return;
    if (v == 0) return;
    sum[id] -= unlocked_sum[id];
    unlocked_sum[id] =  1LL * v * unlocked_cnt[id];
    sum[id] += unlocked_sum[id];
    lazy[id] = v;
  }

  void combine(int id, int il, int ir, int l, int r) {
    sum[id] = sum[il] + sum[ir];
    unlocked_sum[id] =  unlocked_sum[il] + unlocked_sum[ir];
    unlocked_cnt[id] =  unlocked_cnt[il] + unlocked_cnt[ir];
    if (lock[id] == 2) {
      unlocked_cnt[id] = 0;  
      unlocked_sum[id] = 0;
    }
  }

  void pushdown(int id, int il, int ir) {
    upd(il, lazy[id]);
    upd(ir, lazy[id]);
    lazy[id] = 0;
  }

  void build(const vector<int>& a, int id, int l, int r) {
    lazy[id] = 0;
    lock[id] = 1;
    if (r-l < 2) {
      sum[id] = a[l];
      unlocked_sum[id] = a[l];
      unlocked_cnt[id] = 1;
      return;
    }
    int mid = (l+r) >> 1, il = id + 1, ir = id + (mid-l) * 2;
    build(a, il, l, mid);
    build(a, ir, mid, r);
    combine(id, il, ir, l, r);
  }

  void update(int x, int y, int v, int id, int l, int r) {
    if (x >= r || l >= y || lock[id] == 2) return;
    if (x <= l && r <= y) {
      if (r-l >= 2) {
        int mid = (l+r) >> 1, il = id + 1, ir = id + (mid-l) * 2;
        pushdown(id, il, ir);
      }
      upd(id, v);
      return;
    }
    int mid = (l+r) >> 1, il = id + 1, ir = id + (mid-l) * 2;
    pushdown(id, il, ir);
    update(x, y, v, il, l, mid);
    update(x, y, v, ir, mid, r);
    combine(id, il, ir, l, r);
  }

  void update(int x, int y, int v) {
    update(x, y, v, 0, 0, n);
  }

  void set_lock(int x, int y, int v, int id, int l, int r) {
    if (x >= r || l >= y) return;
    if (x <= l && r <= y) {
      if (r-l >= 2) {
        int mid = (l+r) >> 1, il = id + 1, ir = id + (mid-l) * 2;
        pushdown(id, il, ir);
      }
      if (v == 2) {
        assert(lock[id] == 1);
        assert(unlocked_cnt[id] == r-l);
        unlocked_cnt[id] = 0;
        unlocked_sum[id] = 0;
      } else {
        assert(lock[id] == 2);
        assert(v == 1);
        assert(unlocked_cnt[id] == 0);
        unlocked_cnt[id] = r-l;
        unlocked_sum[id] = sum[id];
      }
      lock[id] = v;
      return;
    }
    int mid = (l+r) >> 1, il = id + 1, ir = id + (mid-l) * 2;
    pushdown(id, il, ir);
    set_lock(x, y, v, il, l, mid);
    set_lock(x, y, v, ir, mid, r);
    combine(id, il, ir, l, r);
  }

  void set_lock(int x, int y, int v) {
    set_lock(x, y, v, 0, 0, n);
  }

  long long get(int x, int y, int id, int l, int r) {
    if (x >= r || l >= y) return 0;
    if (x <= l && r <= y) {
      return sum[id];
    }
    int mid = (l+r) >> 1, il = id + 1, ir = id + (mid-l) * 2;
    pushdown(id, il, ir);
    long long ret = get(x, y, il, l, mid);
    ret += get(x, y, ir, mid, r);
    return ret;
  }

  long long get(int x, int y) {
    return get(x, y, 0, 0, n);
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n+m, 0);
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  SegTree tree(n + m, a);
  set<pair<int, int>> locked;
  vector<pair<int, int>> to_delete;
  auto find_ranges = [&](int l, int r) {
    to_delete.clear();
    auto it = locked.lower_bound(make_pair(l, -1));
    while (it != locked.begin()) {
      auto pre = it;
      --pre;
      if (pre->second >= l) {
        it = pre;
      } else {
        break;
      }
    }
    while (it != locked.end()) {
      if (it->first <= r) {
        to_delete.push_back(*it);
        auto nxt = it;
        ++nxt;
        tree.set_lock(it->first, it->second, 1);
        locked.erase(it);
        it = nxt;
      } else {
        break;
      }
    }
  };
  for (int i = 0; i < m; ++i) {
    char op;
    int l, r, v;
    cin >> op;
    if (op == 'F') {
      cin >> l >> r >> v;
      --l;
      tree.update(l, r, v);
    } else if (op == 'I') {
      cin >> v;
      tree.update(n, n+1, v);
      ++n;
    } else if (op == 'L') {
      cin >> l >> r;
      --l;
      find_ranges(l, r);
      for (auto it : to_delete) {
        l = min(l, it.first);
        r = max(r, it.second);
      }
      tree.set_lock(l, r, 2);
      locked.insert(make_pair(l, r));
    } else if (op == 'C') {
      cin >> l >> r;
      --l;
      find_ranges(l, r);
      int lef = l, rig = r;
      for (auto it : to_delete) {
        lef = min(lef, it.first);
        rig = max(rig, it.second);
      }
      if (lef < l) {
        tree.set_lock(lef, l, 2);
        locked.insert(make_pair(lef, l));
      }
      if (r < rig) {
        tree.set_lock(r, rig, 2);
        locked.insert(make_pair(r, rig));
      }
    } else {
      cin >> l >> r;
      --l;
      cout << tree.get(l, r) << '\n';
    }
  }
  return 0;
}
