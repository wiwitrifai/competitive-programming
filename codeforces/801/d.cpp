#include <bits/stdc++.h>

using namespace std;

constexpr int N = 2e5 + 5, inf = 1e9 + 7;

vector<vector<int>> g;

int dp[N];

int dfs(int v, int par = -1) {
  int ret = 0;
  if (g[v].size() == 1) {
    dp[v] = 1;
    return ret;
  }
  int child = -1;
  int cnt = 0;
  for (int u : g[v]) {
    if (u == par) continue;
    ret += dfs(u, v);
    child = u;
    cnt += dp[u];
  }
  ret += max(0, cnt-1);
  if (g[v].size() == 2) {
    dp[v] = dp[child];
  } else {
    dp[v] = 0;
  }
  return ret;
}

void solve() {
  int n;
  cin >> n;
  g.resize(n);
  for (int i = 0; i < n; ++i) {
    g[i].clear();
  }
  for (int i = 0; i < n-1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  if (n <= 2) {
    cout << n-1 << "\n";
    return;
  }
  int root = -1;
  for (int i = 0; i < n; ++i) {
    if (g[i].size() > 2) {
      root = i;
      break;
    }
  }
  if (root == -1) {
    cout << 1 << "\n";
  } else {
    cout << dfs(root) << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
