#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;


struct SegTree {
  int n;
  vector<pair<int, int>> maxi;
  function<pair<int, int>(pair<int, int>, pair<int, int>)> opr;
  pair<int, int> def;
  SegTree(int _n, function<pair<int, int>(pair<int, int>, pair<int, int>)> _opr, pair<int, int> _def) : n(_n), maxi(2 * n) {
    opr = _opr;
    def = _def;
    build(0, 0, n);
  }
  void build(int id, int l, int r) {
    if (r-l < 2) {
      maxi[id] = {l, l};
      return;
    }
    int mid = (l + r) >> 1, il = id + 1, ir = id + 2 * (mid - l);
    build(il, l, mid);
    build(ir, mid, r);
    maxi[id] = opr(maxi[il], maxi[ir]);
  }

  void update(int x, int v, int id, int l, int r) {
    if (r-l < 2) {
      maxi[id] = {v, x};
      return;
    }
    int mid = (l + r) >> 1, il = id + 1, ir = id + 2 * (mid - l);
    if (x < mid)
      update(x, v, il, l, mid);
    else
      update(x, v, ir, mid, r);
    maxi[id] = opr(maxi[il], maxi[ir]);
  }

  void update(int x, int v) {
    update(x, v, 0, 0, n);
  }


  pair<int, int> get(int x, int y, int id, int l, int r) {
    if (x <= l && r <= y) {
      return maxi[id];
    }
    if (x >= r || l >= y) {
      return def;
    }
    int mid = (l + r) >> 1, il = id + 1, ir = id + 2 * (mid - l);
    return opr(get(x, y, il, l, mid), get(x, y, ir, mid, r));
  }

  pair<int, int> get(int x, int y) {
    return get(x, y, 0, 0, n);
  }
};

struct Dsu {
  vector<int> p;
  Dsu(int _n) : p(_n, -1) {
  }
  int find(int x) {
    return p[x] < 0 ? x : p[x] = find(p[x]);
  }
};

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  SegTree smax(n, [&](pair<int, int> a, pair<int, int> b) { return max(a, b); }, {-1, -1});
  SegTree smin(n, [&](pair<int, int> a, pair<int, int> b) { return min(a, b); }, {n, n});
  Dsu dsu(n);
  vector<set<int>> elems(n);
  for (int i = 0; i < n; ++i) {
    elems[i].insert(i);
  }
  auto merge = [&](int u, int v) {
    u = dsu.find(u);
    v = dsu.find(v);
    if (u == v)
      return;
    if (elems[u].size() > elems[v].size())
      swap(u, v);
    for (int x : elems[u]) {
      auto ita = elems[v].lower_bound(x), itb = ita;
      int bef = x, aft = x;
      if (ita == elems[v].begin()) {
        bef = *--elems[v].end();
      } else {
        bef = *(--ita);
      }
      if (itb == elems[v].end()) {
        aft = *elems[v].begin();
      } else {
        aft = *itb;
      }

      if (bef < x) {
        smax.update(bef, x);
        smin.update(x, bef);
      }
      if (x < aft) {
        smax.update(x, aft);
        smin.update(aft, x);
      }
      elems[v].insert(x);
    }
    dsu.p[u] = v;
  };
  string ans;
  for (int i = 0; i < m; ++i) {
    int e, u, v;
    scanf("%d %d %d", &e, &u, &v);
    --u, --v;
    int l = u, r = v;
    if (l > r)
      swap(l, r);
    u = dsu.find(u);
    v = dsu.find(v);
    if (e == 1) {
      merge(u, v);
      while (true) {
        auto it = smax.get(l+1, r);
        if (it.first <= r) break;
        merge(it.second, u);
      }
      while (true) {
        auto it = smin.get(l+1, r);
        if (it.first >= l) break;
        merge(it.second, u);
      }
    } else {
      ans.push_back(u == v ? '1' : '0');
    }
  }
  printf("%s\n", ans.c_str());
  return 0;
}
