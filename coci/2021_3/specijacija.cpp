// AC after contest

#include <bits/stdc++.h>

using namespace std;

struct PersistentSegTree {
  vector<int> il, ir;
  vector<int> sum;
  int n;

  PersistentSegTree(int _n) {
    il.clear();
    ir.clear();
    sum.clear();
    n = _n;
  }

  int newNode(int val = 0) {
    int id = sum.size();
    il.push_back(-1);
    ir.push_back(-1);
    sum.push_back(val);
    return id;
  }

  int build(int l, int r) {
    int id = newNode();
    if (r-l < 2) {
      sum[id] = 1;
      return id;
    }
    int mid = (l + r) >> 1;
    int res = build(l, mid);
    il[id] = res;
    res = build(mid, r);
    ir[id] = res;
    sum[id] = sum[il[id]] + sum[ir[id]];
    return id;
  }

  int update(int x, int val, int oldId, int l, int r) {
    int id = newNode(val);
    if (r-l < 2) {
      sum[id] = val;
      return id;
    }
    int mid = (l + r) >> 1;
    il[id] = il[oldId];
    ir[id] = ir[oldId];
    if (x < mid) {
      int res = update(x, val, il[oldId], l, mid);
      il[id] = res;
    } else {
      int res = update(x, val, ir[oldId], mid, r);
      ir[id] = res;
    }
    sum[id] = sum[il[id]] + sum[ir[id]];
    return id;
  }

  int update(int x, int val, int version) {
    return update(x, val, version, 0, n);
  }

  int get(int x, int id, int l, int r) {
    while(sum[id] < x);
    if (r-l < 2) {
      return l;
    }
    int mid = (l + r) >> 1;
    if (sum[il[id]] < x)
      return get(x-sum[il[id]], ir[id], mid, r);
    else
      return get(x, il[id], l, mid);
  }

  int get(int x, int version) {
    return get(x, version, 0, n);
  }
};

const int LG = 22;
const int N = 2e5 + 5;

vector<pair<int, int>> nodes[N];
vector<int> g[N * 3];
vector<int> depth, in, out;
vector<int> euler[LG];
vector<long long> value;

void dfs(int v) {
  in[v] = euler[0].size();
  euler[0].push_back(v);
  for (int u : g[v]) {
    depth[u] = depth[v] + 1;
    dfs(u);
    euler[0].push_back(v);
  }
  out[v] = euler[0].size();
}

int get_lca(int u, int v) {
  int l = in[u], r = in[v];
  if (l > r)
    swap(l, r);
  int len = r - l + 1;
  int lg = 31 - __builtin_clz(len);
  int lef = euler[lg][l], rig = euler[lg][r-(1 << lg) + 1];
  return depth[lef] < depth[rig] ? lef : rig;
}

int main() {
  int n, q, t;
  scanf("%d %d %d", &n, &q, &t);
  vector<long long> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &a[i]);
  }
  vector<long long> lower;
  for (int i = 0; i <= n; ++i) {
    lower.push_back(1LL * i * (i+1) / 2);
  }
  int cur_nodes = 0;
  for (int i = 0; i <= n; ++i) {
    nodes[i].emplace_back(0, cur_nodes++);
    value.push_back(lower.back() + i + 1);
  }
  auto get_id = [&](long long x) {
    int lv = lower_bound(lower.begin(), lower.end(), x) - lower.begin() - 1;
    int col = x - lower[lv];
    lv = n - lv;
    return make_pair(lv, col);
  };
  auto checkAncestor = [&](long long child, long long anc) {
    auto pchild = get_id(child);
    auto panc = get_id(anc);
    int cur = pchild.second;
    for (int i = n-pchild.first-1; i >= n-panc.first; --i) {
      auto p = get_id(a[i]);
      if (p.second < cur)
        --cur;
    }
  };
  PersistentSegTree segtree(n+1);
  vector<int> root;
  root.push_back(segtree.build(0, n+1));
  for (int i = n-1; i >= 0; --i) {
    auto pos = get_id(a[i]);
    int col = segtree.get(pos.second, root.back()),
        nxt = segtree.get(pos.second + 1, root.back());
    g[cur_nodes].push_back(nodes[col].back().second);
    g[cur_nodes].push_back(nodes[nxt].back().second);
    nodes[nxt].emplace_back(n-i, cur_nodes);
    nodes[col].emplace_back(n-i, nodes[col].back().second);
    ++cur_nodes;
    value.push_back(a[i]);
    int newroot = segtree.update(col, 0, root.back());
    root.push_back(newroot);
  }
  depth.assign(cur_nodes, 0);
  in.assign(cur_nodes, 0);
  out.assign(cur_nodes, 0);
  dfs(cur_nodes-1);
  for (int i = 0; i + 1 < LG; ++i) {
    for (int j = 0; j + (1 << i) < (int)euler[i].size(); ++j) {
      int lef = euler[i][j], rig = euler[i][j+(1 << i)];
      euler[i+1].push_back(depth[lef] < depth[rig] ? lef : rig);
    }
  }
  long long tot = 1LL * (n + 1) * (n + 2) / 2;
  auto get_vertex = [&](long long x) {
    auto posx = get_id(x);
    int colx = segtree.get(posx.second, root[posx.first]);
    auto res = lower_bound(nodes[colx].begin(), nodes[colx].end(), make_pair(posx.first, -1));
    int u = res->second, v = u;
    if (res->first != posx.first)
      v = (--res)->second;
    return make_pair(u, v);
  };
  long long ans = 0;
  while (q--) {
    long long x, y;
    scanf("%lld %lld", &x, &y);
    x = ((x - 1 + t * ans) % tot) + 1;
    y = ((y - 1 + t * ans) % tot) + 1;
    if (x > y)
      swap(x, y);
    auto uc = get_vertex(x);
    auto vc = get_vertex(y);
    int u = uc.first;
    int c = uc.second;
    int v = vc.first;
    if (uc == vc || (in[c] <= in[v] && out[v] <= out[c])) {
      ans = x;
    } else {
      ans = value[get_lca(u, v)];
    }
    printf("%lld\n", ans);
  }
  return 0;
}
