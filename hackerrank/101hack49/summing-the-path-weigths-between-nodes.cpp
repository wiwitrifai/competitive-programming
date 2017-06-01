#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int c[N], r[N], b[N], nr, nb;
vector< pair< int, int > > g[N];
long long ans;

void dfs(int v = 0, int par = -1) {
  r[v] = !c[v], b[v] = c[v];
  for (auto it : g[v]) {
    int u = it.first;
    if (u == par) continue;
    dfs(u, v);
    ans += 1LL * it.second * (1LL * r[u] * (nb-b[u]) + 1LL * b[u] * (nr-r[u]));
    b[v] += b[u];
    r[v] += r[u];
  }
}



int main() {
  int n;
  scanf("%d", &n);
  nr = nb = 0;
  for (int i = 0; i < n; i++)
    scanf("%d", c+i), nb += c[i];
  nr = n - nb;
  for (int i = 1; i < n; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    u--; v--;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }
  ans = 0;
  dfs();
  cout << ans << endl;
  return 0;
} 