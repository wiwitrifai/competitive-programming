#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector<int> g[N];
int a[N], par[N];
long long raw[N], dp[N];

vector<int> ver[N];

int dfs(int v, int depth = 0) {
  int res = depth;
  ver[depth].push_back(v);
  for (int u : g[v]) {
    res = max(res, dfs(u, depth+1));
  }
  return res;
}

void solve() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i <= n; ++i) {
    g[i].clear();
    ver[i].clear();
  }
  for (int i = 1; i < n; ++i) {
    scanf("%d", par+i);
    --par[i];
    g[par[i]].push_back(i);
  }
  for (int i = 1; i < n; ++i)
    scanf("%d", a+i);
  int depth = dfs(0);
  for (int i = 0; i <= depth; ++i) {
    sort(ver[i].begin(), ver[i].end(), [&](int le, int ri) {
      return a[le] < a[ri];
    });
  }
  fill(raw, raw+n, 0);
  fill(dp, dp+n, 0);
  for (int d = depth; d > 0; --d) {
    long long low = a[ver[d][0]], hig = a[ver[d].back()];
    long long maxi = 0, last = low;
    for (int v : ver[d]) {
      dp[v] = max(dp[v], raw[v] + max(a[v] - low, hig - a[v]));
      if (last < a[v]) {
        maxi += a[v] - last;
        last = a[v];
      }
      maxi = max(maxi, raw[v]);
      dp[v] = max(dp[v], maxi);
    }
    maxi = 0;
    last = hig;
    for (int i = (int)ver[d].size()-1; i >= 0; --i) {
      int v = ver[d][i];
      if (last > a[v]) {
        maxi += last - a[v];
        last = a[v];
      }
      maxi = max(maxi, raw[v]);
      dp[v] = max(dp[v], maxi);
    }
    for (int v : ver[d]) {
      raw[par[v]] = max(raw[par[v]], dp[v]);
    }
  }
  printf("%lld\n", raw[0]);
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
