#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, inf = 1e9 + 7;

vector<int> g[N];
int sz[N], n;

long long dfs(int v, int par) {
  long long ret = 0;
  sz[v] = 1;
  for (int u : g[v]) {
    if (u == par) continue;
    ret += dfs(u, v);
    sz[v] += sz[u];
    ret += min(sz[u], n - sz[u]) * 2;
  }
  return ret;
}

void subtree(int v, int par, vector<int>& elem) {
  elem.push_back(v);
  for (int u : g[v]) {
    if (u == par) continue;
    subtree(u, v, elem);
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  long long ans = dfs(0, 0);
  int root = 0;
  for (int i = 0; i < n; ++i) {
    if (sz[i] * 2 >= n) {
      if (sz[i] < sz[root])
        root = i;
    }
  }
  vector<vector<int>> elems(g[root].size());
  set<pair<int, int>> st;
  for (int i = 0; i < (int)g[root].size(); ++i) {
    subtree(g[root][i], root, elems[i]);
    st.insert({-(int)elems[i].size(), i});
  }
  vector<int> moved(n);
  iota(moved.begin(), moved.end(), 0);
  while (st.size() >= 2) {
    auto it = st.begin();
    auto it2 = it++;
    int x = it->second, y = it2->second;
    st.erase(it);
    st.erase(it2);
    int u = elems[x].back(), v = elems[y].back();
    elems[x].pop_back();
    elems[y].pop_back();
    swap(moved[u], moved[v]);
    if (!elems[x].empty())
      st.insert({-(int)elems[x].size(), x});
    if (!elems[y].empty())
      st.insert({-(int)elems[y].size(), y});
  }
  int other = 0;
  for (int i = 0; i < n; ++i) {
    if (i == root) continue;
    if (other == root || moved[i] == i)
      other = i;
  }
  swap(moved[root], moved[other]);
  printf("%lld\n", ans);
  for (int i = 0; i < n; ++i) {
    printf("%d%c", moved[i]+1, i+1 == n ? '\n' : ' ');
  }
  return 0;
}
