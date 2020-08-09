#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

vector<int> g[N];
vector<int> nodes[N];
bool vis[N];
int n;

vector<int> path;
bool dfs(int v, int depth) {
  if (vis[v])
    return false;
  vis[v] = true;
  path.push_back(v);
  nodes[depth].push_back(v);
  ++depth;
  if (depth * 2 >= n)
    return true;
  for (int u : g[v]) {
    bool res = dfs(u, depth);
    if (res)
      return true;
  }
  path.pop_back();
  return false;
}

void solve() {
  int m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    g[i].clear();
    nodes[i].clear();
  }
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  fill(vis, vis+n, false);
  path.clear();
  bool res = dfs(0, 0);
  if (res) {
    puts("PATH");
    printf("%d\n", (int)path.size());
    for (int i = 0; i < (int)path.size(); ++i) {
      printf("%d%c", path[i]+1, i+1 == (int)path.size() ? '\n' : ' ');
    }
  } else {
    vector<pair<int, int>> pairing;
    for (int i = 0; i < N && !nodes[i].empty(); ++i) {
      for (int j = 0; j + 1 < (int)nodes[i].size(); j += 2) {
        pairing.emplace_back(nodes[i][j], nodes[i][j+1]);
      }
    }
    puts("PAIRING");
    printf("%d\n", (int)pairing.size());
    for (auto it : pairing) {
      printf("%d %d\n", it.first+1, it.second+1);
    }
  }
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
