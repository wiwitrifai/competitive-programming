#include <bits/stdc++.h>

using namespace std;

struct Biconnected
{
  // input variable
  int n;
  vector<vector< int > > adj;

  // temporary variable
  vector<int> low, num, vis;
  int counter, root, childroot;
  vector< pair< int, int > > edge;

  // ouput variable
  int nblock;
  vector< vector< pair< int, int > > > block;
  vector<int> artp;
  vector< pair< int, int > > bridge;

  // variable to convert to block-cut tree
  int ntree;
  vector< int > node2Tree; 

  Biconnected(int n = 0) : n(n) {
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
        cerr << v << " add " << u << endl;
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
      else if (bef != u && num[u] < num[v]) {
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
};

const int N = 1e5 + 5;
map<pair<int, int>, int> mp;
int deg[N]; 

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  Biconnected g(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    if (u > v)
      swap(u, v);
    mp[make_pair(u, v)] = i+1;
    g.add(u, v);
  }
  g.build();
  vector<int> ans;
  for (int i = 0; i <= g.nblock; ++i) {
    set<int> ver;
    cerr << i << endl;
    for (auto it : g.block[i]) {
      int u = it.first, v = it.second;
      cerr << u << " " << v << endl;
      ver.insert(u);
      ver.insert(v);
      ++deg[u];
      ++deg[v];
    }
    bool ok = 1;
    for (int v : ver) {
      ok &= deg[v] == 2;
      deg[v] = 0;
    }
    if (ok) {
      for (auto it : g.block[i]) {
        int u = it.first, v = it.second;
        if (u > v) swap(u, v);
        ans.push_back(mp[make_pair(u, v)]);
      }
    }
  }
  sort(ans.begin(), ans.end());
  ans.erase(unique(ans.begin(), ans.end()), ans.end());
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); ++i) {
    if (i) printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}