#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int deg[N];
set<int> g[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    g[a].insert(b);
    g[b].insert(a);
    ++deg[a];
    ++deg[b];
  }
  bool ok = 1;
  int dual = 0, triple = 0;
  for (int i = 1; i <= n; ++i) {
    ok &= ((deg[i] & 1) == 0);
    if (deg[i] == 4)
      ++dual;
    else if (deg[i] >= 6)
      ++triple;
  }
  if (!ok || (triple == 0 && dual < 2)) {
    puts("No");
    return 0;
  }
  if (triple || dual > 2) {
    puts("Yes");
    return 0;
  }
  for (int i = 1; i <= n; ++i) {
    if (g[i].size() == 2) {
      auto it = g[i].begin();
      int u = *it; g[i].erase(it);
      it = g[i].begin();
      int v = *it; g[i].erase(it);
      g[u].erase(i);
      g[v].erase(i);
      g[u].insert(v);
      g[v].insert(u);
    }
  }
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    if (g[i].size() > 0)
      ++cnt;
    // cerr << i << " " << g[i].size() << endl;
  }
  puts(cnt <= 2 ? "No" : "Yes");
  return 0;
}