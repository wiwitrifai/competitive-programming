#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector<int> g[N];
int a[N];
int sum[N];
vector<pair<int, int>> ans;
vector<int>* leaf[N];
set<pair<int, int>> st[N];

void dfs(int v, int par = 0) {
  for (int i = 0; i + 1 < (int)g[v].size(); ++i)
    if (g[v][i] == par)
      swap(g[v][i], g[v].back());
  if (!g[v].empty() && g[v].back() == par)
    g[v].pop_back();
  if (g[v].empty()) {
    leaf[v] = new vector<int>(a[v], v);
    return;
  }
  for (int u : g[v]) {
    dfs(u, v);
    sum[v] += (int)leaf[u]->size();
    st[v].insert(make_pair(leaf[u]->size(), u));
  }
  while (sum[v] > a[v]) {
    auto it = --st[v].end();
    auto it2 = it;
    --it2;
    int x = it->second, y = it2->second;
    st[v].erase(it);
    st[v].erase(it2);
    ans.emplace_back(leaf[x]->back(), leaf[y]->back());
    leaf[x]->pop_back();
    leaf[y]->pop_back();
    st[v].insert(make_pair(leaf[x]->size(), x));
    st[v].insert(make_pair(leaf[y]->size(), y));
    --sum[v];
  }
  for (auto it = st[v].rbegin(); it != st[v].rend(); ++it) {
    int u = it->second;
    if (leaf[v] == NULL)
      leaf[v] = leaf[u];
    else {
      for (int x : *leaf[u])
        leaf[v]->push_back(x);
    }
  }

  if (leaf[v] == NULL)
    leaf[v] = new vector<int>();
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 1; i <= n; ++i)
    scanf("%d", a+i);
  dfs(1);
  printf("%d\n", (int)ans.size());
  for (auto it : ans) {
    printf("%d %d\n", it.first, it.second);
  }
  return 0;
}
