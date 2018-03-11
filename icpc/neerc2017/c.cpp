// by wiwit
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> edge[N], rev[N];
set<pair<int, int>> imp;
bool vis[N];

void dfs(int v) {
  vis[v] = 1;
  for (int u : edge[v]) {
    if (vis[u]) continue;
    dfs(u);
    imp.insert(make_pair(v, u));
  }
}
void dfs_rev(int v) {
  vis[v] = 1;
  for (int u : rev[v]) {
    if (vis[u]) continue;
    dfs_rev(u);
    imp.insert(make_pair(u, v));
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      edge[u].push_back(v);
      rev[v].push_back(u);
    }
    fill(vis, vis+n+1, 0);
    dfs(1);
    fill(vis, vis+n+1, 0);
    dfs_rev(1);

    int out = m - 2 * n;
    for (int i = 1; i <= n; i++) {
      for (auto it : edge[i]) {
        if (!imp.count(make_pair(i, it)) && out > 0) {
          out--;
          printf("%d %d\n", i, it);
        }
      }
    }

    for (int i = 1; i <= n; i++) {
      edge[i].clear();
      rev[i].clear();
      vis[i] = 0;
    }
    imp.clear();
  }
  return 0;
}