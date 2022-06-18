#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<int> vis, used, x, y;

vector<int> nodes;
void dfs(int v) {
  vis[v] = 1;
  nodes.push_back(v);
  for (int e : g[v]) {
    if (used[e]) continue;
    int u = x[e] ^ y[e] ^ v;
    used[e] = 1;
    if (!vis[u]) {
      dfs(u);
    } else {
      nodes.push_back(u);
    }
    nodes.push_back(v);
  }
}

void solve() {
  int n;
  cin >> n;
  g.resize(n * 2);
  x.resize(n);
  y.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
    --x[i], --y[i];
    g[x[i]].push_back(i);
    g[y[i]].push_back(i);
  }
  used.assign(n, 0);
  vis.assign(n * 2, 0);
  vector<vector<int>> val(2, vector<int>(n, -1));
  vector<string> a(2, string(n, 'x'));
  auto b = a;
  int len = 0;
  for (int i = 0; i < 2 * n; ++i) {
    if (vis[i] || g[i].empty()) continue;
    dfs(i);
    nodes.pop_back();
    if (nodes.size() <= 2) {
      cout << "-1\n";
      return;
    }
    int sz = nodes.size(), half = sz/2;
    for (int j = 0; j < half; ++j) {
      val[0][len + j] = nodes[j];
      val[1][len + j] = nodes[sz-1-j];
    }
    for (int j = 0; j < half; j += 2) {
      a[0][len+j] = 'L';
      a[1][len+j] = 'L';
      b[0][len+j] = 'R';
      b[1][len+j] = 'R';
      if (j + 1 < half) {
        a[0][len+j+1] = 'R';
        a[1][len+j+1] = 'R';
        b[0][len+j+1] = 'L';
        b[1][len+j+1] = 'L';
      }
    }
    b[0][len] = 'U';
    b[1][len] = 'D';
    if (half & 1) {
      a[0][len + half - 1] = 'U';
      a[1][len + half - 1] = 'D';
    } else {
      b[0][len + half - 1] = 'U';
      b[1][len + half - 1] = 'D';
    }
    nodes.clear();
    len += half;
  }
  cout << "2 " << n << "\n";
  cout << "\n";
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << val[i][j]+1 << (j + 1 == n ? "\n" : " ");
    }
  }
  cout << "\n";
  for (int i = 0; i < 2; ++i) {
    cout << a[i] << "\n";
  }
  cout << "\n";
  for (int i = 0; i < 2; ++i) {
    cout << b[i] << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc = 1;
  // cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
