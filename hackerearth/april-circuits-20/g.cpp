#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

struct Fenwick {
  vector<int> bit;
  Fenwick() {}
  void reset(int n) {
    bit.assign(n+2, 0);
  }
  void update(int x, int v) {
    for (++x; x < (int)bit.size(); x += x&-x) {
      bit[x] += v;
      if (bit[x] >= mod)
        bit[x] -= mod;
    }
  }
  int get(int x) {
    int ret = 0;
    for (++x; x; x -= x&-x) {
      ret += bit[x];
      if (ret >= mod)
        ret -= mod;
    }
    return ret;
  }
};

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
  vector<vector<pair<int, int>>> graph;
  vector<int> depth, size, parent, weight;
  vector<int> in, out, pos, nodes;

  HldTree(int _n = 0) : n(_n) {
    graph.resize(n);
    for (int i = 0; i < n; ++i)
      graph[i].clear();
    depth.assign(n, -1);
    size.assign(n, 0);
    parent.assign(n, -1);
    weight.assign(n, 0);
    in.assign(n, -1);
    out.assign(n, -1);
    pos.assign(n, -1);
  }

  void addEdge(int u, int v, int w) {
    graph[u].emplace_back(v, w);
    graph[v].emplace_back(u, w);
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

  // specific to problem
  Fenwick fen;
  vector<int> mult;

  void init() {
    fen.reset(n);
    mult.assign(n, 1);
    for (int i = 0; i < n; ++i) {
      if (in[parent[i]] + 1 != in[i]) continue;
      fen.update(in[i], weight[i]);
    }
  }

  void multiply2(int v) {
    int cur = in[v];
    if (in[parent[v]] + 1 == cur) {
      fen.update(cur, weight[v]);
    }
    weight[v] = weight[v] * 2 % mod;
    mult[v] = mult[v] * 2 % mod;
    if (cur + 1 < n) {
      int u = nodes[cur + 1];
      if (parent[u] == v) {
        fen.update(cur+1, weight[u]);
        weight[u] = weight[u] * 2 % mod;
      }
    }
  }

  int process(int u, int v) {
    long long ans = 0;
    while (1) {
      if (in[u] > in[v])
        swap(u, v);
      if (in[v] - pos[v] == in[u] - pos[u]) {
        // process [ in[u] .. in[v] ]
        ans = (ans + fen.get(in[v]) - fen.get(in[u])) % mod;
        if (ans < 0)
          ans += mod;
        return ans;
      }
      ans = (ans + fen.get(in[v]) - fen.get(in[v]-pos[v])) % mod;
      // process [ (in[v]-pos[v]) .. in[v] ]
      v = nodes[in[v] - pos[v]];
      ans = (ans + (long long)weight[v] * mult[parent[v]]) % mod;
      v = parent[v];
    }
  }

  bool isAncestor(int par, int child) {
    return in[par] <= in[child] && out[child] <= out[par];
  }

private:
  void calcSize(int v, int par = -1) {
    size[v] = 1;
    for (auto e : graph[v]) {
      int u = e.first;
      if (u == par) continue;
      calcSize(u, v);
      size[v] += size[u];
    }
    for (auto & e : graph[v]) {
      int u = e.first;
      if (u == par) continue;
      if (size[u] > size[graph[v][0].first])
        swap(e, graph[v][0]);
    }
  }

  void dfs(int v, int par = -1) {
    if (par == -1) par = v;
    depth[v] = (par == v ? 0 : depth[par] + 1);
    parent[v] = par;
    in[v] = nodes.size();
    nodes.push_back(v);
    pos[v] = in[v] == in[par]+1 ? pos[par] + 1 : 0;
    for (auto & e : graph[v]) {
      int u = e.first;
      if (u == par) continue;
      weight[u] = e.second;
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
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    if (u > v)
      swap(u, v);
    w %= mod;
    if (w < 0)
      w += mod;
    tree.addEdge(u, v, w);
  }
  tree.build(0);
  tree.init();
  while (q--) {
    int t, u, v;
    scanf("%d %d", &t, &u);
    if (t == 1) {
      scanf("%d", &v);
      printf("%d\n", tree.process(u, v));
    }
    else {
      tree.multiply2(u);
    }
  }
  return 0;
}
