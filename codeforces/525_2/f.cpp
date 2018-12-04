#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5, LG = 21;

int a[N], par[LG][N];
vector<int> g[N];

void dfs(int v) {
  for (int i = 0; i + 1 < LG; ++i)
    par[i+1][v] = par[i][par[i][v]];
  for (int u : g[v]) {
    if (u == par[0][v]) continue;
    par[0][u] = v;
    dfs(u);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int root = 0;
  for (int i = 0; i < n; ++i)
    if (a[i] < a[root])
      root = i;
  par[0][root] = root;
  dfs(root);
  long long ans = 0;
  for (int v = 0; v < n; ++v) {
    if (v == root) continue;
    ans += a[v];
    long long best = a[par[0][v]];
    for (int i = 0; i < LG; ++i) {
      best = min(best, 1LL * a[par[i][v]] * (i+1));
    }
    ans += best;
  }
  printf("%lld\n", ans);
  return 0;
}