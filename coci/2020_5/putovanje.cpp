#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int cnt[N];

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

  void process(int v, int par) {
    for (int u : graph[v]) {
      if (u == par) continue;
      process(u, v);
      cnt[v] += cnt[u];
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


int a[N], b[N], c[N], d[N];

int main() {
  int n;
  scanf("%d", &n);
  HldTree tree(n);
  for (int i = 0; i < n-1; ++i) {
    scanf("%d %d %d %d", a+i, b+i, c+i, d+i);
    --a[i], --b[i];
    tree.addEdge(a[i], b[i]);
  }
  tree.build(0);
  for (int i = 0; i < n-1; ++i) {
    int u = i, v = i+1;
    ++cnt[u];
    ++cnt[v];
    int w = tree.lca(u, v);
    cnt[w] -= 2;
  }
  tree.process(0, 0);
  long long ans = 0;
  for (int i = 0; i < n-1; ++i) {
    int u = a[i], v = b[i];
    if (tree.parent[u] != v)
      swap(u, v);
    int cur = cnt[u];
    ans += min(1LL * cur * c[i], (long long)d[i]);
  }
  printf("%lld\n", ans);
  return 0;
}
