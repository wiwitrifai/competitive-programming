#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

int num[N], low[N], comp[N], ncomp = 0;
int timestmp;
vector<int> g[N];

vector<int> nodes;
vector<pair<int, int> > bridge;
set<int> st[N];
vector<int> elem[N];
bool vis[N];

void dfs(int v, int par = -1) {
  num[v] = low[v] = ++timestmp;
  nodes.push_back(v);
  for (int u : g[v]) {
    if (num[u] == -1) {
      dfs(u, v);
      low[v] = min(low[v], low[u]);
      if (low[u] > num[v]) {
        bridge.emplace_back(u, v);
      }
    }
    else if (u != par)
      low[v] = min(low[v], num[u]);
  }
  if (num[v] == low[v]) {
    while (1) {
      int w = nodes.back();
      nodes.pop_back();
      comp[w] = ncomp;
      elem[ncomp].push_back(w);
      if (w == v)
        break;
    }
    ++ncomp;
  }
}

vector<pair<int, int> > ans;
bool dfs2(int v, int par = -1) {
  assert(!vis[v]);
  vis[v] = 1;
  bool ret = elem[v].size() == 1;
  vector<int> tmp;
  for (int i : st[v]) {
    int a = bridge[i].first, b= bridge[i].second;
    if (comp[a] != v)
      swap(a, b);
    assert(comp[a] == v);
    int u = comp[b];
    if (u == par) continue;
    bool res = dfs2(u, v);
    if (res)
      tmp.push_back(i);
    ret &= res;
  }
  if (!ret) {
    for (int i : tmp) {
      int a = bridge[i].first, b = bridge[i].second;
      if (comp[a] != v)
        swap(a, b);
      assert(comp[a] == v);
      ans.emplace_back(a, b);
    }
  }
  return ret;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  memset(num, -1, sizeof num);
  timestmp = 0;
  for (int i = 0; i < n; ++i) {
    if (num[i] != -1) continue;
    dfs(i);
  }
  for (int i = 0; i < bridge.size(); ++i) {
    auto e = bridge[i];
    int u = comp[e.first], v = comp[e.second];
    st[u].insert(i);
    st[v].insert(i);
  }
  for (int i = 0; i < ncomp; ++i) {
    if (vis[i]) continue;
    if (elem[i].size() <= 1) continue;
    dfs2(i);
  }
  for (int i = 0; i < ncomp; ++i) {
    if (vis[i]) continue;
    assert(elem[i].size() == 1);
    if (st[i].size() != 1) continue;
    int id = *st[i].begin();
    int a = bridge[id].first, b = bridge[id].second;
    if (comp[a] != i)
      swap(a, b);
    assert(comp[a] == i);
    ans.emplace_back(a, b);
  }
  sort(ans.begin(), ans.end());
  printf("%d\n", (int)ans.size());
  for (auto e : ans) {
    printf("%d %d\n", e.first + 1, e.second + 1);
  }
  return 0;
}
