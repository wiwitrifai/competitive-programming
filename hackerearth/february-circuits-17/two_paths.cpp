#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 6, LN = 19;

struct Dsu
{
  int n, p[N];
  Dsu(int n = N) : n(n) {
    memset(p, -1, sizeof p);
  }
  void reset() {
    memset(p, -1, sizeof p);
  }
  int find(int x) {
    return p[x] < 0 ? x : p[x] = find(p[x]);
  }
  bool merge(int u, int v) {
    if ((u = find(u)) == (v = find(v)))
      return false;
    if (p[u] > p[v])
      swap(u, v);
    p[u] += p[v];
    p[v] = u;
    return true;
  }
} dsu;

struct Tree
{
  int n;
  vector< int > adj[N];
  int lv[N], par[LN][N];
  Tree(int n = N) : n(n) {
    memset(lv, -1, sizeof lv);
    memset(par, -1, sizeof par);
  }
  void add(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  void dfs(int u, int p = -1) {
    lv[u] = (p == -1 ? 0 : lv[p] + 1);
    par[0][u] = (p == -1 ? u : p);
    for (int i = 0; i + 1 < LN; i++)
      par[i+1][u] = par[i][par[i][u]];
    for (auto v : adj[u]) if (lv[v] == -1) {
      dfs(v, u);
    }
  }
  int ancestor(int v, int lev) {
    if (lev > lv[v])
      return -1;
    int d = lv[v] - lev;
    for (int i = LN-1; i >= 0; i--)
      if (d & (1<<i))
        v = par[i][v];
    return v;        
  }
  int lca(int u, int v) {
    if (lv[u] > lv[v])
      swap(u, v);
    v = ancestor(v, lv[u]);
    if (u == v)
      return u;
    for (int i = LN-1; i >= 0; i--)
      if (par[i][u] != par[i][v])
        u = par[i][u], v = par[i][v];
    return par[0][v];
  }
} tree;

struct Graph
{
  int n;
  vector< int > adj[N];
  vector< pair< int, int > > bridge, edge, block[N];
  int low[N], num[N], counter, root, childroot, artp[N], vis[N], nblock;
  Graph(int n = N) : n(n) {
    memset(low, -1, sizeof low);
    memset(num, -1, sizeof num);
    memset(artp, 0, sizeof artp);
    for (int i = 0; i < n; i++)
      adj[i].clear();
    counter = 0;
    nblock = 0;
  }
  void add(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  void dfs(int v, int bef = -1) {
    num[v] = low[v] = counter++;
    for (int u : adj[v]) {
      if (num[u] == -1) {
        edge.emplace_back(v, u);
        if (v == root)
          childroot++;
        dfs(u, v);
        if (childroot > 1 && v == root) {
          artp[v] = 1;
          while (edge.size() > 0) {
            auto it = edge.back(); edge.pop_back();
            block[nblock].push_back(it);
            if (it == make_pair(v, u))
              break;
          }
          nblock++;
        }
        if (low[u] >= num[v] && v != root) {
          artp[v] = 1;
          while (edge.size() > 0) {
            auto it = edge.back(); edge.pop_back();
            block[nblock].push_back(it);
            if (it == make_pair(v, u))
              break;
          }
          nblock++;
        }
        if (low[u] > num[v])
          bridge.emplace_back(u, v);
        low[v] = min(low[v], low[u]);
      }
      else if (bef != u && low[v] > num[u]) {
        low[v] = min(low[v], num[u]);
        edge.emplace_back(v, u);
      }
    }
  }
} gr;

vector< pair<int, int> > be, we;  
int white[N], tobl[N];

int main() {
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    u--; v--;
    if (w)
      we.emplace_back(u, v);
    else
      be.emplace_back(u, v);
  }
  /* convert connected component by white edge to one vertex */
  memset(white, -1, sizeof white);
  dsu.n = n;
  for (auto e : we) {
    dsu.merge(e.first, e.second);
  }
  gr.n = 0;
  for (int i = 0; i < n; i++) if (dsu.find(i) == i) {
    white[i] = gr.n++;
  }
  for (int i = 0; i < n; i++) {
    white[i] = white[dsu.find(i)];
    assert(white[i] != -1);
  }

  /* compress black-edge graph to block-cut tree */
  for (auto e : be) {
    if (white[e.first] != white[e.second])
      gr.add(white[e.first], white[e.second]);
  }
  dsu.reset();
  for (int i = 0; i < gr.n; i++) if (gr.num[i] == -1) {
    gr.root = i;
    gr.childroot = 0;
    gr.edge.clear();
    gr.dfs(i);
    gr.artp[i] = gr.childroot > 1;
    if (gr.edge.size() > 0) {
      while (gr.edge.size() > 0) {
        auto it = gr.edge.back(); gr.edge.pop_back();
        gr.block[gr.nblock].push_back(it);
      }
      gr.nblock++;
    }
  }
  tree.n = gr.n + gr.nblock;
  memset(tobl, -1, sizeof tobl);
  for (int i = 0; i < gr.nblock; i++) {
    int last = -1;
    for (auto e : gr.block[i]) {
      if (gr.artp[e.first])
        tree.add(e.first, gr.n+i);
      else if (last == -1)
        last = e.first;
      else
        dsu.merge(e.first, last);
      if (gr.artp[e.second])
        tree.add(e.second, gr.n+i);
      else if (last == -1)
        last = e.second;
      else
        dsu.merge(e.second, last);
    }
    if (last != -1)
      tobl[dsu.find(last)] = gr.n+i;
  }
  for (int i = 0; i < gr.n; i++) {
    if (gr.artp[i])
      tobl[i] = i;
    else {
      tobl[i] = tobl[dsu.find(i)];
      if (tobl[i] == -1)
        tobl[i] = tree.n++;
    }
  }
  for (int i = 0; i< tree.n; i++)
    if (tree.lv[i] == -1)
      tree.dfs(i);
  for (int i = 0; i < tree.n; i++) {
    for (auto it : tree.adj[i])
      assert(it == tree.par[0][i] || tree.par[0][it] == i);
  }
  /* query answering */
  while (q--) {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    a--; b--; c--; d--;
    a = white[a], b = white[b], c = white[c], d = white[d];
    if (c == d)
      puts("No");
    else if (a == b)
      puts("Yes");
    else if ((a == c && b == d) || (a == d && b == c))
      puts("No");
    else {
      int ta = tobl[a], tb = tobl[b], tc = tobl[c], td = tobl[d];
      if (tree.par[LN-1][ta] != tree.par[LN-1][tb])
        puts("No");
      else {
        bool ok = 0;
        /* cek path a-c-b && a-d-b ? */
        for (int i = 0; i < 2; i++) {
          if (ok) break;
          ok = 1;
          if (c == a || c == b)
            ok = 0;
          if (gr.artp[c]) {
            int lca = tree.lca(ta, tb);
            if (tree.lv[lca] <= tree.lv[tc]) {
              int va = tree.ancestor(ta, tree.lv[tc]), vb = tree.ancestor(tb, tree.lv[tc]);
              if (va == tc || vb == tc)
                ok = 0;
            }
          }
          swap(c, d);
          swap(tc, td);
        }
        puts(ok ? "Yes" : "No");
      }
    }
  }
  return 0;
}