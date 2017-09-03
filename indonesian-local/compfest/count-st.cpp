#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, mod = 1e9 + 7;

vector< int > g[N];
int num[N], n, m;
long long ans = 1;
int dfs(int v, int prev = -1) {
  num[v] = prev == -1 ? 0 : num[prev] + 1;
  for (int u : g[v]) if (u != prev) {
    if (num[u] == -1) {
      dfs(u, v);
    }
    else if (num[v] >= num[u])
      ans = (ans * (num[v] + 1 - num[u])) % mod;
  }
}


int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
      g[i].clear();
    memset(num, -1, sizeof num);
    for (int i = 0; i < m; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      g[u].push_back(v);
      g[v].push_back(u);
    }
    ans = 1;
    dfs(0);
    ans %= mod;
    if (ans < 0) ans += mod;
    printf("%lld\n", ans);
  }
  return 0;
}