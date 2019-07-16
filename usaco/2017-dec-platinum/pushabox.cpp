#include <bits/stdc++.h>

using namespace std;


struct Tree
{
  int n, LN;
  vector<vector< int > > adj;
  vector<int> lv;
  vector<vector<int> >  par;
  Tree(int n = 0) : n(n) {
    lv.assign(n, -1);
    LN = 0;
    while ((1LL << LN) <= n) ++LN;
    ++LN;
    par.resize(LN);
    for (int i = 0; i < LN; ++i)
      par[i].assign(n, -1);
    adj.resize(n);
    for (int i = 0; i < n; ++i)
      adj[i].clear();
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

  void build() {
    for (int i = 0; i < n; ++i) {
      sort(adj[i].begin(), adj[i].end());
      adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
    }
    for (int i = 0; i < n; ++i) if (lv[i] == -1) {
      dfs(i);
    }
  }

  bool pathACwoB(int a, int b, int c) {
    if (par[LN-1][a] != par[LN-1][c]) return false;
    if (par[LN-1][a] != par[LN-1][b]) return true;
    int ac = lca(a, c);
    if (lv[b] < lv[ac]) return true;
    return (ancestor(a, lv[b]) != b) && (ancestor(c, lv[b]) != b);
  }
} tree;

struct Graph
{
  int n;
  vector<vector< int > > adj;
  vector< pair< int, int > > bridge, edge;
  vector< vector< pair< int, int > > > block;
  vector< int > node2Tree; 
  vector<int> low, num, artp, vis;
  int counter, root, childroot, nblock;
  int ntree;
  Graph(int n = 0) : n(n) {
    low.assign(n, -1);
    num.assign(n, -1);
    artp.assign(n, 0);
    node2Tree.assign(n, -1);
    adj.resize(n);
    for (int i = 0; i < n; i++)
      adj[i].clear();
    counter = 0;
    nblock = 0;
    block.push_back(vector< pair<int, int> > ());
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
          block.push_back(vector< pair<int, int> > ());
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
          block.push_back(vector< pair<int, int> > ());
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
  void build() {
    for (int i = 0; i < n; ++i) {
      sort(adj[i].begin(), adj[i].end());
      adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
    }
    nblock = 0;
    for (int i = 0; i < n; i++) if (num[i] == -1) {
      root = i;
      childroot = 0;
      edge.clear();
      dfs(i);
      artp[i] = childroot > 1;
      if (edge.size() > 0) {
        while (edge.size() > 0) {
          auto it = edge.back(); edge.pop_back();
          block[nblock].push_back(it);
        }
        block.push_back(vector< pair<int, int> > ());
        nblock++;
      }
    }
    for (int i = 0; i < n; ++i)
      node2Tree[i] = -1;
    for (int i = 0; i < nblock; i++) {
      int last = -1;
      for (auto e : block[i]) {
        if (!artp[e.first])
          node2Tree[e.first] = i;
        if (!artp[e.second])
          node2Tree[e.second] = i;
      }
    }
    ntree = nblock;
    for (int i = 0; i < n; ++i) if (node2Tree[i] == -1)
      node2Tree[i] = ntree++;
  }
  int getTreeNode(int node) {
    return node2Tree[node];
  }
} gr;

const int N = 1505;

int n, m;
char s[N][N];
bool ans[N][N];
bool vis[N][N][4];
int dx[] = {-1, 0, 0, 1};
int dy[] = { 0,-1, 1, 0};

void buildBlockCutTree() {
  // construct graph
  gr = Graph(n * m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == '#') continue;
      for (int k = 0; k < 4; ++k) {
        int x = i + dx[k], y = j + dy[k];
        if (x < 0 || x >= n || y < 0 || y >= m) continue;
        if (s[x][y] == '#') continue;
        gr.add(i * m + j, x * m + y);
      }
    }
  }

  // build block cut tree
  gr.build();
  tree = Tree(gr.ntree);
  for (int i = 0; i < gr.nblock; ++i) {
    for (auto e : gr.block[i]) {
      if (gr.artp[e.first])
        tree.add(i, gr.node2Tree[e.first]);
      if (gr.artp[e.second])
        tree.add(i, gr.node2Tree[e.first]);
    }
  }
  tree.build();
}

bool can(int x, int y, int bx, int by, int d) {
  int xx = bx + dx[d], yy = by + dy[d];
  if (xx < 0 || xx >= n || yy < 0 || yy >= m) return false;
  if (s[xx][yy] == '#' || s[x][y] == '#' || s[bx][by] == '#') return false;
  int a = x * m + y, b = bx * m + by, c = xx * m + yy;
  a = gr.getTreeNode(a);
  c = gr.getTreeNode(c);
  if (tree.par[tree.LN-1][a] != tree.par[tree.LN-1][c]) return false;
  if (!gr.artp[b]) return true;
  b = gr.getTreeNode(b);
  return tree.pathACwoB(a, b, c);
}

int main() {
#ifndef LOCAL
  freopen("pushabox.in", "r", stdin);
  freopen("pushabox.out", "w", stdout);
#endif
  int q;
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 0; i < n; ++i)
    scanf("%s", s[i]);
  queue<pair<pair<int, int>, int> > que;
  pair<int, int> a, b;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == 'A')
        a = {i, j};
      else if (s[i][j] == 'B')
        b = {i, j};
    }
  }
  buildBlockCutTree();
  ans[b.first][b.second] = 1;
  for (int i = 0; i < 4; ++i) {
    if (!can(a.first, a.second, b.first, b.second, i)) continue;
    que.push(make_pair(b, i));
    vis[b.first][b.second][i] = 1;
  }
  while (!que.empty()) {
    pair<pair<int, int> , int> fron = que.front(); que.pop();
    b = fron.first;
    a = {b.first + dx[fron.second], b.second + dy[fron.second]};
    for (int i = 0; i < 4; ++i) {
      if (i == fron.second) continue;
      if (vis[b.first][b.second][i]) continue;
      if (!can(a.first, a.second, b.first, b.second, i)) continue;
      que.push(make_pair(b, i));
      vis[b.first][b.second][i] = 1;
    }
    a = b;
    b.first += dx[3^fron.second];
    b.second += dy[3^fron.second];
    if (b.first < 0 || b.first >= n || b.second < 0 || b.second >= m) continue; 
    if (vis[b.first][b.second][fron.second]) continue;
    if (s[b.first][b.second] == '#') continue;
    que.push(make_pair(b, fron.second));
    vis[b.first][b.second][fron.second] = 1;   
  }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      for (int k = 0; k < 4; ++k)
        ans[i][j] |= vis[i][j][k];
  while (q--) {
    int x, y;
    scanf("%d %d", &x, &y);
    --x, --y;
    puts(ans[x][y] ? "YES" : "NO");
  }
  return 0;
}