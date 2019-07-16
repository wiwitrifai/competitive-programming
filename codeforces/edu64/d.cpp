#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector<pair<int, int> > g[N];

int cnt[N][2];

void dfs(int v, int par = -1) {
  memset(cnt[v], 0, sizeof cnt[v]);
  for (auto e : g[v]) {
    int u = e.first;
    if (u == par) continue;
    dfs(u, v);
    int c = e.second;
    cnt[v][c] += cnt[u][c] + 1;
  }
}

void dfs2(int v, int par = -1) {
  for (auto e : g[v]) {
    int u = e.first, w = e.second;
    if (u == par) continue;
    cnt[u][w] = cnt[v][w];
    dfs2(u, v);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n-1; ++i) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    --u, --v;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }
  dfs(0);
  dfs2(0);
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += 1LL * (cnt[i][0] + 1) * (cnt[i][1] + 1) - 1;
  }
  printf("%lld\n", ans);
  return 0;
}
