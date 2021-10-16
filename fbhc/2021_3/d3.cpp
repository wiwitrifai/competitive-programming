#include <bits/stdc++.h>

using namespace std;

struct SegTree {
  int n;
  vector<set<int>> seg;
  SegTree(int _n) : n(_n), seg(2 * n) {
    build(0, 0, n);
  }

  void build(int id, int l, int r) {
    seg[id].clear();
    if (r-l < 2)
      return;
    int mid = (l+r) >> 1, il = id + 1, ir = id + (mid-l) * 2;
    build(il, l, mid);
    build(ir, mid, r);
  }

  void add(int x, int y, int v, int id, int l, int r) {
    if (x >= r || l >= y) return;
    if (x <= l && r <= y) {
      seg[id].insert(v);
      return;
    }
    int mid = (l+r) >> 1, il = id + 1, ir = id + (mid-l) * 2;
    add(x, y, v, il, l, mid);
    add(x, y, v, ir, mid, r);
  }

  void add(int x, int y, int v) {
    add(x, y, v, 0, 0, n);
  }

  void remove(int x, int y, int v, int id, int l, int r) {
    if (x >= r || l >= y) return;
    if (x <= l && r <= y) {
      seg[id].erase(v);
      return;
    }
    int mid = (l+r) >> 1, il = id + 1, ir = id + (mid-l) * 2;
    remove(x, y, v, il, l, mid);
    remove(x, y, v, ir, mid, r);
  }

  void remove(int x, int y, int v) {
    remove(x, y, v, 0, 0, n);
  }

  int get(int x, int id, int l, int r) {
    if (r-l < 2) {
      return (seg[id].empty() ? -1 : *seg[id].rbegin());
    }
    int mid = (l+r) >> 1, il = id + 1, ir = id + (mid-l) * 2;
    int ret = (seg[id].empty() ? -1 : *seg[id].rbegin());
    if (x < mid)
      ret = max(ret, get(x, il, l, mid));
    else
      ret = max(ret, get(x, ir, mid, r));
    return ret;
  }

  int get(int x) {
    return get(x, 0, 0, n);
  }
};

struct Dsu {
  vector<int> p;
  Dsu(int _n) : p(_n, -1) {
  }
  int find(int x) { return p[x] < 0 ? x : p[x] = find(p[x]); }

  bool merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
      return false;
    if (-p[u] > -p[v])
      swap(u, v);
    p[v] += p[u];
    p[u] = v;
    return true;
  }
};

vector<int> dr = {-1, 0, 1, 0};
vector<int> dc = {0, -1, 0, 1};

vector<vector<int>> tree, parent;
vector<int> weight, in, out, usage, euler, leaf;

void dfs(int v) {
  for (int i = 0; i + 1 < (int)parent.size(); ++i) {
    parent[i+1][v] = parent[i][parent[i][v]];
  }
  in[v] = euler.size();
  euler.push_back(v);
  for (int u : tree[v]) {
    parent[0][u] = v;
    dfs(u);
  }
  out[v] = euler.size();
}

int find_anc(int v, int val) {
  for (int i = (int)parent.size()-1; i >= 0; --i) {
    int u = parent[i][v];
    if (weight[u] > val) {
      v = u;
    }
  }
  return v;
}

void solve() {
  int n, m;
  cin >> n >> m;
  auto enc = [&](int r, int c) {
    return r * m + c;
  };
  int tot = n * m;
  vector<vector<int>> h(n, vector<int>(m));
  vector<vector<int>> s(n, vector<int>(m));
  vector<int> all;
  weight.resize(tot);
  vector<pair<int, int>> ids;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> h[i][j];
      ids.emplace_back(i, j);
      all.push_back(h[i][j]);
      weight[enc(i, j)] = h[i][j];
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> s[i][j];
    }
  }
  sort(ids.begin(), ids.end(), [&](pair<int, int>& le, pair<int, int>& ri) {
    return h[le.first][le.second] > h[ri.first][ri.second];
  });
  Dsu dsu(tot);
  auto it1 = ids.begin();
  sort(all.begin(), all.end());
  all.erase(unique(all.begin(), all.end()), all.end());
  reverse(all.begin(), all.end());
  tree.resize(tot);
  for (int i = 0; i < tot; ++i) {
    tree.clear();
  }
  vector<bool> used(tot, 0);
  for (auto e : all) {
    while (it1 != ids.end() && h[it1->first][it1->second] == e) {
      int r, c;
      tie(r, c) = *it1;
      int now = enc(r, c);
      for (int k = 0; k < 4; ++k) {
        int rx = r + dr[k], cx = c + dc[k];
        if (rx < 0 || rx >= n || cx < 0 || cx >= m) continue;
        int other = enc(rx, cx);
        if (!used[other]) continue;
        int child = dsu.find(other);
        if (child == now) continue;
        assert(dsu.find(now) == now);
        tree[now].push_back(child);
        dsu.p[child] = now;
      }
      used[now] = true;
      ++it1;
    }
  }
  int root = dsu.find(0);
  for (int i = 0; i < tot; ++i) {
    assert(dsu.find(i) == root);
  }
  in.resize(tot);
  out.resize(tot);
  int lg = 32 - __builtin_clz(tot);
  parent.assign(lg, vector<int>(tot));
  parent[0][root] = root;
  euler.clear();
  dfs(root);
  usage.assign(tot, 0);
  leaf.assign(tot, 0);
  SegTree stree(tot);
  set<int> leaves;
  auto add_node = [&](int v) {
    auto it = leaves.lower_bound(in[v]);
    if (it == leaves.end() || *it >= out[v]) {
      leaves.insert(in[v]);
      leaf[v] = 1;
    }

    int u = stree.get(in[v]);
    if (u != -1) {
      u = euler[u];
      if (leaf[u]) {
        leaves.erase(in[u]);
        leaf[u] = 0;
      }
    }
    stree.add(in[v], out[v], in[v]);
  };
  auto remove_node = [&](int v) {
    stree.remove(in[v], out[v], in[v]);
    if (leaf[v]) {
      leaf[v] = 0;
      leaves.erase(in[v]);

      int u = stree.get(in[v]);
      if (u != -1) {
        u = euler[u];
        auto it = leaves.lower_bound(in[u]);
        if (it == leaves.end() || *it >= out[u]) {
          leaves.insert(in[u]);
          leaf[u] = 1;
        }
      }
    }
  };
  long long sum = 0;
  auto update = [&](int x, int v) {
    sum += v;
    int bef = usage[x];
    usage[x] += v;
    if (bef == 0) {
      assert(usage[x] > 0);
      add_node(x);
    } else if (usage[x] == 0) {
      assert(bef > 0);
      remove_node(x);
    }
  };
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i][j] >= h[i][j]) continue;
      int v = enc(i, j);
      int u = find_anc(v, s[i][j]);
      update(u, +1);
    }
  }
  int k;
  cin >> k;
  long long sumx = 0, sumy = 0;
  int lasty = 0;
  for (int i = 0; i < k; ++i) {
    int a, b, x;
    cin >> a >> b >> x;
    a ^= lasty;
    b ^= lasty;
    x ^= lasty;
    --a, --b;
    int v = enc(a, b);
    if (s[a][b] < h[a][b]) {
      int u = find_anc(v, s[a][b]);
      update(u, -1);
    }
    s[a][b] = x;
    if (s[a][b] < h[a][b]) {
      int u = find_anc(v, s[a][b]);
      update(u, +1);
    }
    lasty = leaves.size();
    sumx += sum;
    sumy += leaves.size();
  }
  cout << sumx << " " << sumy << endl;
}

int main(int argc, char * argv[]) {
  clock_t starttime = clock();
  int seed = time(0);
  if (argc >= 2) {
    seed = atoi(argv[1]);
  }
  cerr << "random seed\t= " << seed << endl;
  srand(seed);

  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; ++tc) {
    printf("Case #%d: ", tc);
    solve();
    fflush(stdout);
    cerr << "~ TC#" << tc << " done! execution time : " <<
      (double)(clock() - starttime) / CLOCKS_PER_SEC << " s " << endl;
  }
  return 0;
}
