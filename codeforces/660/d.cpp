#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector<int> g[N];
long long a[N];
int b[N];
vector<int> to[N];

void dfs(int v, int par = -1) {
  for (int u : g[v]) {
    if (u == par) continue;
    dfs(u, v);
    if (a[u] <= 0) {
      to[v].push_back(u);
    } else {
      to[u].push_back(v);
      a[v] += a[u];
    }
  }
}

void solve() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    g[i].clear();
    scanf("%lld", a+i);
  }
  vector<int> roots;
  for (int i = 0; i < n; ++i) {
    scanf("%d", b+i);
    --b[i];
    if (b[i] >= 0) {
      int u = i, v = b[i];
      g[u].emplace_back(v);
      g[v].emplace_back(u);
    } else {
      roots.push_back(i);
    }
  }
  for (int root : roots)
    dfs(root);
  vector<int> topo, deg(n);
  for (int i = 0; i < n; ++i)
    for (int u : to[i])
      ++deg[u];
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += a[i];
    if (deg[i]) continue;
    topo.push_back(i);
  }
  for (int i = 0; i < (int)topo.size(); ++i) {
    int v = topo[i];
    for (int u : to[v]) {
      --deg[u];
      if (deg[u] == 0) {
        topo.push_back(u);
      }
    }
  }
  printf("%lld\n", ans);
  for (int i = 0; i < n; ++i) {
    printf("%d%c", topo[i]+1, i+1 == n ? '\n' : ' ');
  }
}

int main() {
  int tc = 1;
  // scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
