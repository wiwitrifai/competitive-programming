#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int a[N];
vector<int> g[N];
long long best = 0;
int cnt;

long long dfs(int v, int par = -1) {
  long long ret = a[v];
  for (int u : g[v]) {
    if (u == par) continue;
    ret += dfs(u, v);
  }
  best = max(best, ret);
  return max(ret, 0LL);
}

long long dfs2(int v, int par = -1) {
  long long ret = a[v];
  for (int u : g[v]) {
    if (u == par) continue;
    ret += dfs2(u, v);
  }
  if (ret == best) {
    ++cnt;
    ret = 0;
  }
  return max(ret, 0LL);
}

int main() {
  int n;
  scanf("%d", &n);
  int ma = -1e9;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    ma = max(ma, a[i]);
  }
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  cnt = 0;
  if (ma <= 0) {
    for (int i = 0; i < n; ++i) {
      if (a[i] == ma)
        ++cnt;
    }
    printf("%lld %d\n", 1LL * ma * cnt, cnt);
    return 0;
  }
  best = ma;
  dfs(0);
  dfs2(0);
  printf("%lld %d\n", 1LL * best * cnt, cnt);
  return 0;
}