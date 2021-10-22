#include <bits/stdc++.h>


using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> b(n, 0);
  vector<pair<int, int>> edges;
  vector<vector<int>> g(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    if (u > v)
      swap(u, v);
    edges.emplace_back(u, v);
  }
  sort(edges.begin(), edges.end());
  edges.erase(unique(edges.begin(), edges.end()), edges.end());
  for (auto & [u, v] : edges) {
    ++b[u];
    ++b[v];
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> ids;
  set<pair<int, int>> st;
  for (int i = 0; i < n; ++i) {
    st.insert(make_pair(b[i], i));
  }
  int biggest = 0;
  while (!st.empty()) {
    auto it = st.begin();
    int v = it->second;
    st.erase(it);
    biggest = max(biggest, b[v]);
    ids.push_back(v);
    b[v] = -1;
    for (int u : g[v]) {
      if (b[u] < 0) continue;
      st.erase(make_pair(b[u], u));
      --b[u];
      st.insert(make_pair(b[u], u));
    }
  }
  reverse(ids.begin(), ids.end());
  vector<int> ans(n);
  for (int i = 0; i < n; ++i) {
    ans[ids[i]] = i+1;
  }
  cout << biggest << '\n';
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << (i+1 == n ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
