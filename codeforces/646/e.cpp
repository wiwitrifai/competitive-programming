#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector<int> g[N];

int a[N], b[N], c[N];

long long ans = 0;

int dfs(int v, int par = -1) {
  int cur = 0;
  if (b[v] != c[v]) {
    cur += b[v] ? 1 : -1;
  }
  for (int u : g[v]) {
    if (u == par) continue;
    a[u] = min(a[u], a[v]);
    int res = dfs(u, v);
    int tot = abs(cur) + abs(res);
    cur += res;
    int d = (abs(tot) - abs(cur));
    ans += 1LL * a[v] * d;
  }
  return cur;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d %d", a+i, b+i, c+i);
  }
  for (int i = 0; i < n-1; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  ans = 0;
  int res = dfs(0);
  if (res != 0) {
    ans = -1;
  }
  printf("%lld\n", ans);
  return 0;
}
