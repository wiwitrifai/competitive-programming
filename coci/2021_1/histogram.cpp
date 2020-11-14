// Unfinished

#include <bits/stdc++.h>

using namespace std;

vector<tuple<int, int, int>> find_ranges(vector<int> &a) {
  int n = a.size();
  stack<int> st;
  vector<tuple<int, int, int>> ret;
  for (int i = 0; i < n; ++i) {
    while (!st.empty() && a[st.top()] > a[i]) {
      int cur = st.top();
      st.pop();
      int lef = 0;
      if (!st.empty())
        lef = st.top() + 1;
      ret.emplace_back(lef, i, a[cur]);
    }
    while (!st.empty() && a[st.top()] == a[i])
      st.pop();
    st.push(i);
  }
  while (!st.empty()) {
    int cur = st.top();
    st.pop();
    int lef = 0;
    if (!st.empty())
      lef = st.top() + 1;
    ret.emplace_back(lef, n, a[cur]);
  }
  return ret;
}

const long long inf = 1e18;

struct Line {
  long long m, b; // y = mx + b
  Line(long long _m, long long _b) : m(_m), b(_b) {}
  long long get(long long x) {
    return m * x + b;
  }
};

bool bad(const Line & lef, const Line & mid, const Line & rig) {
  return (long long)(lef.b - mid.b) * (rig.m - mid.m) >=
         (long long)(mid.b - rig.b) * (mid.m - lef.m);
}


struct ConvexHull {
  vector<Line> hull;
  int p = 0;
  ConvexHull() {}
  void add(Line line) {
    int size;
    while ((size = hull.size()) >= 2 && bad(hull[size-2], hull[size-1], line)) {
      hull.pop_back()
      lef.pop_back();
    }
    p = min((int)hull.size()-1, p);
    if (p < 0)
      p = 0;
    hull.push_back(line);
  }

  long long calc(long long x) {
    while (p + 1 < (int)hull.size()) {
      if (hull[p+1].get(x) > hull[p].get(x))
        ++p;
    }
    return p >= (int)hull.size() ? -inf : hull[p].get(x);
  }
};


struct SegmentTree {
  int n;
  vector<ConvexHull> hulls;
  void init(int _n) {
    n = _n;
    build(1, 0, n);
  }

  void build(int id, int l, int r) {
    if ((int)hulls.size() <= id)
      hulls.resize(id+1);
    if (r-l < 2) {
      return;
    }
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    build(il, l, mid);
    build(ir, mid, r);
  }

  void add(int pos, const Line & line, int id, int l, int r) {
    hulls[id].add(line);
    if (r-l < 2) {
      return;
    }
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    if (pos < mid)
      add(pos, line, il, l, mid);
    else
      add(pos, line, ir, mid, r);
  }

  void add(int pos, long long m, long long b) {
    Line line(m, b);
    add(pos, line, 1, 0, n);
  }

  long long query(int lef, int rig, long long x, int id, int l, int r) {
    if (lef >= r || l >= rig) return -inf;
    if (lef <= l && r <= rig) {
      return hulls[id].get(x);
    }
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    return max(query(lef, rig, x, il, l, mid),
               query(lef, rig, x, ir, mid, r));
  }

  long long query(int lef, int rig, long long x) {
    return query(lef, rig, x, 1, 0, n);
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
  vector<vector<int>> graph;
  vector<int> depth, size, parent;
  vector<int> in, out, pos, nodes;
  vector<SegmentTree> hulls;

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
    hulls.resize(n);
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

  long long process(int u, int v, long long x) {
    long long ret = -inf;
    while (1) {
      if (in[u] > in[v])
        swap(u, v);
      int id = in[v] - pos[v];
      if (in[v] - pos[v] == in[u] - pos[u]) {
        // process [ in[u] .. in[v] ]
        ret = max(ret, hulls[id].query(pos[u], pos[v] + 1, x));
        return ret;
      }
      // process [ (in[v]-pos[v]) .. in[v] ]
      ret = max(ret, hulls[id].query(0, pos[v]+1, x));
      v = nodes[in[v] - pos[v]];
      v = parent[v];
    }
    return ret;
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

struct Fenwick {
  vector<long long> bit;
  Fenwick(int _n) {
    bit.assign(_n+1, -inf);
  }
  void upd(int x, long long v) {
    for (++x; x; x -= x&-x)
      bit[x] = max(bit[x], v);
  }
  long long get(int x) {
    long long ret = -inf;
    for (++x; x < (int)bit.size(); x += x&-x)
      ret = max(ret, bit[x]);
    return ret;
  }
}

long long calc(int n, vector<tuple<int, int, int>> & a, vector<tuple<int, int, int>> & b) {
  sort(a.begin(), a.end(), [&](tuple<int, int, int>& lef, tuple<int, int, int> & rig) {
    if (get<1>(lef) != get<1>(rig))
      return get<1>(lef) < get<1>(rig);
    return get<0>(lef) < get<0>(rig);
  });
  sort(b.begin(), b.end());
  int p = 0;
  Fenwick bit(n+2);
  long long ans = -inf;
  for (auto & it : b) {
    int l, r, h;
    tie(l, r, h) = it;
    while (p < (int)a.size() && get<1>(a[p]) <= r) {
      int ll, rr, hh;
      tie(ll, rr, hh) = a[p++];
      bit.upd(ll, (long long)(rr-ll) * hh);
    }
    ans = max(ans, bit.get(ll) * h);
  }

  // sort(a.begin(), a.end(), [&](tuple<int, int, int>& lef, tuple<int, int, int> & rig) {
  //   if (get<0>(lef) != get<0>(rig))
  //     return get<0>(lef) < get<0>(rig);
  //   return get<1>(lef) > get<1>(rig);
  // });

  vector<pair<int, int>> que;
  for (int i = 0; i < (int)b.size(); ++i) {
    int l, r, h;
    tie(l, r, h) = b[i];
    que.emplace_back(l, i);
  }
  vector<pair<int, int>> path(que.size(), make_pair(-1, -1));
  sort(que.begin(), que.end());
  vector<int> anc;
  HldTree hld(a.size());
  for (int i = 0, j = 0; i < (int)a.size(); ++i) {
    while (!anc.empty() && get<1>(a[anc.back()]) <= get<0>(a[i]))
      anc.pop_back();
    hld.addEdge(anc.back(), i);
    anc.push_back(i);
    while (j < (int)que.size() && que[j].first < get<1>(a[i])) {
      int id = que[j].second;
      int qr = get<1>(b[id]);
      int low = 0, hig = (int)anc.size();
      while (low < hig) {
        int mid = (low + hig) >> 1;
        if (get<1>(a[anc[mid]]) <= qr)
          hig = mid;
        else
          low = mid + 1;
      }
      if (low < (int)anc.size())
        path[id] = make_pair(i, anc[low]);
      ++j;
    }
  }
  hld.build(0);
}

int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &a[i], &b[i]);
  }
  auto ra = find_ranges(a);
  auto rb = find_ranges(b);
  long long ans = min(calc(n, a, b), calc(n, b, a));
  return 0;
}
