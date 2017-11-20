#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int x[N][N], mr[N], mc[N], match[N], matched[N];

bool vis[N];
vector< int > g[N];

bool dfs(int v) {
  if (vis[v]) return 0;
  vis[v] = 1;
  for (int u : g[v])
    if (match[u] == -1 || dfs(match[u]))
      return match[u] = v, matched[v] = u, 1;
  return 0;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      scanf("%d", x[i]+j), mr[i] = max(x[i][j], mr[i]), mc[j] = max(x[i][j], mc[j]);
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (x[i][j] == 0) continue;
      if (mc[j] == mr[i])
        g[i].push_back(j);
      ans += x[i][j]-1;
    }
  }
  memset(match, -1, sizeof match);
  memset(matched, -1, sizeof matched);
  while (1) { 
    memset(vis, 0, sizeof vis);
    int fnd = 0;
    for (int i = 0; i < n; i++) if (matched[i] == -1) {
      fnd |= dfs(i);
    }
    if (!fnd) break;
  }
  for (int i = 0; i < n; i++) if (matched[i] == -1)
    ans -= max(0, mr[i]-1);
  for (int i = 0; i < m; i++)
    ans -= max(0, mc[i]-1);
  printf("%lld\n", ans);
  return 0;
}