#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int vis[N];

vector<int> g[N];

int main() {
  int n, m, t;
  scanf("%d %d %d", &n, &m, &t);
  vector<int> cand;
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    if (v == t)
      cand.push_back(u);
    else
      g[v].push_back(u);
  }
  queue<int> que;
  memset(vis, -1, sizeof vis);
  for (int u : cand) {
    vis[u] = u;
    que.push(u);
  }
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    for (int u : g[v]) {
      if (vis[u] == vis[v] || vis[u] == n) continue;
      if (vis[u] == -1) {
        vis[u] = vis[v];
        que.push(u);
        continue;
      }
      if (vis[u] != -1 && vis[u] != vis[v]) {
        vis[u] = n;
        que.push(u);
        continue;
      }
    }
  }
  vector<int> ans;
  for (int u : cand)
    if (vis[u] == u)
      ans.push_back(u);
  sort(ans.begin(), ans.end());
  printf("%d\n", (int)ans.size());
  for (int i = 0; i < (int)ans.size(); ++i) {
    printf("%d\n", ans[i]);
  }
  return 0;
}
