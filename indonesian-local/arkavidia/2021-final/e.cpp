#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<long long> a(n, -1);
  vector<vector<long long>> g(n, vector<long long>(n, -1));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j)
      scanf("%lld", &g[i][j]);
  }
  auto bfs = [&](int v) {
    queue<int> que;
    a[v] = 0;
    que.push(v);
    while (!que.empty()) {
      v = que.front();
      que.pop();
      for (int u = 0; u < n; ++u) {
        if (a[u] != -1 || max(g[v][u], g[u][v]) == -1) continue;
        a[u] = a[v] ^ max(g[v][u], g[u][v]);
        que.push(u);
      }
    }
  };
  for (int i = 0; i < n; ++i) {
    if (a[i] != -1) continue;
    bfs(i);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (g[i][j] != -1 && g[i][j] != (a[i]^a[j])) {
        puts("NO");
        return 0;
      }
    }
  }
  puts("YES");
  for (int i = 0; i < n; ++i)
    printf("%lld%c", a[i], i+1 == n ? '\n' : ' ');
  return 0;
}
