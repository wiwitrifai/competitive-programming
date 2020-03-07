#include <bits/stdc++.h>

using namespace std;

struct CntSeg {
  int n;
  vector<int> seg;
  CntSeg(int _n) : n(_n), seg(_n * 4, 0) {
    build(1, 0, n);
  }
  void build(int id, int l, int r) {
    if (r-l < 2) {
      seg[id] = 1;
      return;
    }
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    build(il, l, mid);
    build(ir, mid, r);
    seg[id] = seg[il] + seg[ir];
  }
  void _upd(int x, int v, int id, int l, int r) {
    seg[id] += v;
    if (r-l < 2)
      return;
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    if (x < mid)
      _upd(x, v, il, l, mid);
    else
      _upd(x, v, ir, mid, r);
  }
  void update(int x, int v) {
    _upd(x, v, 1, 0, n);
  }
  int _get(int x, int y, int id, int l, int r) {
    if (x >= r || l >= y) return 0;
    if (x <= l && r <= y)
      return seg[id];
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    return _get(x, y, il, l, mid) + _get(x, y, ir, mid, r);
  }
  int get(int x, int y) {
    return _get(x, y, 1, 0, n);
  }
};



struct SumSeg {
  int n;
  vector<int> seg;
  SumSeg(int _n) : n(_n), seg(_n * 4, 0) {};
  void _upd(int x, int y, int v, int id, int l, int r) {
    if (x >= r || l >= y) return;
    if (x <= l && r <= y) {
      seg[id] += v;
      return;
    }
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    _upd(x, y, v, il, l, mid);
    _upd(x, y, v, ir, mid, r);
  }
  void update(int x, int y, int v) {
    _upd(x, y, v, 1, 0, n);
  }
  int _get(int x, int id, int l, int r) {
    if (r-l < 2)
      return seg[id];
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    return seg[id] + (x < mid ? _get(x, il, l, mid) : _get(x, ir, mid, r));
  }
  int get(int x) {
    return _get(x, 1, 0, n);
  }
};

vector<int> live;

/**
 *  HLD + In-Order Tree
 *
 *  Usage:
 *    HldTree tree(number of vertices)
 *    tree.addEdge(u, v)
 *    tree.build(u, v) = build HLD
 *    tree.lca(u, v) = get Lowest common ancestor
 *    tree.isAncestor(parent, child)
 *
 *    ## tree.process(parent, child) ## = template to process HLD
 */

struct HldTree {
public:
  const int n;
  vector<vector<int>> graph;
  vector<int> depth, size, parent;
  vector<int> in, out, pos, nodes;

  HldTree(int _n = 0) : n(_n) {
    graph.resize(n);
    for (int i = 0; i < n; ++i)
      graph[i].clear();
    depth.assign(n, -1);
    size.assign(n, 0);
    parent.assign(n, -1);
    in.assign(n, -1);
    out.assign(n, -1);
    pos.assign(n, -1);
  }

  void addEdge(int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  void build(int v) {
    nodes.clear();
    calcSize(v);
    dfs(v);
  }

  int lca(int u, int v) {
    while (u != v) {
      if (in[u] > in[v])
        swap(u, v);
      int step = min(pos[v], in[v] - in[u]);
      v = nodes[in[v] - step];
      if (v != u)
        v = parent[v];
    }
    return u;
  }

  void process(SumSeg & sum, CntSeg & cnt, int v) {
    live[v] ^= 1;
    if (v == 0) return;
    int add = sum.get(in[v]);
    if (live[v])
      cnt.update(in[v], +1);
    else {
      cnt.update(in[v], -1);
      add = -add;
    }
    v = parent[v];
    while (1) {
      if (cnt.get(in[v] - pos[v], in[v]+1) == pos[v]+1) {
        sum.update(in[v]-pos[v], in[v]+1, add);
      }
      else {
        int lo = in[v] - pos[v] + 1, ri = in[v]+1;
        while (lo < ri) {
          int mid = (lo + ri) >> 1;
          if (cnt.get(mid, in[v]+1) >= in[v]+1 - mid)
            ri = mid;
          else
            lo = mid+1;
        }
        --lo;
        sum.update(lo, in[v]+1, add);
        break;
      }
      v = nodes[in[v] - pos[v]];
      if (v == parent[v])
        break;
      v = parent[v];
    }
  }

  bool isAncestor(int par, int child) {
    return in[par] <= in[child] && out[child] <= out[par];
  }

private:
  void calcSize(int v, int par = -1) {
    size[v] = 1;
    for (int u : graph[v]) {
      if (u == par) continue;
      calcSize(u, v);
      size[v] += size[u];
    }
    for (int & u : graph[v]) {
      if (u == par) continue;
      if (size[u] > size[graph[v][0]])
        swap(u, graph[v][0]);
    }
  }

  void dfs(int v, int par = -1) {
    if (par == -1) par = v;
    depth[v] = (par == v ? 0 : depth[par] + 1);
    parent[v] = par;
    in[v] = nodes.size();
    nodes.push_back(v);
    pos[v] = in[v] == in[par]+1 ? pos[par] + 1 : 0;
    for (auto u : graph[v]) {
      if (u == par) continue;
      dfs(u, v);
    }
    out[v] = nodes.size();
  }
};

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  HldTree tree(n);
  for (int i = 0; i < n-1; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    tree.addEdge(u, v);
  }
  tree.build(0);
  CntSeg cnt(n);
  SumSeg sum(n);
  live.assign(n, 1);
  for (int i = 0; i < n; ++i) {
    sum.update(tree.in[i], tree.in[i]+1, tree.size[i]);
  }
  for (int i = 0; i < q; ++i) {
    int t, v;
    scanf("%d %d", &t, &v);
    --v;
    if (t == 2) {
      if (!live[v]) {
        puts("0");
        continue;
      }
      printf("%d\n", sum.get(tree.in[v]));
    }
    else {
      tree.process(sum, cnt, v);
    }
  }
  return 0;
}
