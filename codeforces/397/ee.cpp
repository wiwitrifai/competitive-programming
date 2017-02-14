#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

set< int > g[N], s[N];
bool vis[N];

int main() {
  memset(vis, 0, sizeof vis);
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    g[u].insert(v);
    g[v].insert(u);
  }
  queue< int > que;
  for (int i = 0; i < n; i++) {
    if (g[i].size() <= 1) {
      que.push(i);
      vis[i] = 1;
    }
  }
  int ans = -1;
  while (!que.empty()) {
    int v = que.front(); que.pop();
    if (g[v].empty()) {
      ans = 0;
      for (int d : s[v])
        ans += d;
      break;
    }
    if (s[v].size() > 1)
      continue;
    int now = 0;
    for (int d : s[v])
      now = max(now, d);
    now++;
    for (int u : g[v]) {
      s[u].insert(now);
      g[u].erase(v);
      if (g[u].size() <= 1 && (g[u].size() + s[u].size()) <= 2 && !vis[u])
        que.push(u), vis[u] = 1;
    }
  }
  while (ans > 0 && ((ans & 1) == 0)) ans >>= 1; 
  printf("%d\n", ans);
  return 0;
}