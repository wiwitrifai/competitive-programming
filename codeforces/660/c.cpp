#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector<int> g[N];
long long p[N], h[N], tot[N], cnt[N];

bool dfs(int v, int par = -1) {
  tot[v] = p[v];
  cnt[v] = 0;
  for (int u : g[v]) {
    if (u == par) continue;
    bool res = dfs(u, v);
    if (!res)
      return false;
    tot[v] += tot[u];
    cnt[v] += cnt[u];
  }
  long long neg = (tot[v] - h[v]);
  if (neg & 1)
    return false;
  neg /= 2;
  if (cnt[v] + p[v] < neg || neg < 0)
    return false;
  cnt[v] = neg;
  return true;
}


void solve() {
  int n;
  long long m;
  scanf("%d %lld", &n, &m);
  for (int i = 0; i < n; ++i) {
    g[i].clear();
    scanf("%lld", p+i);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%lld", h+i);
  }
  for (int i = 0; i < n-1; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  bool ans = dfs(0);
  puts(ans ? "YES" : "NO");
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
