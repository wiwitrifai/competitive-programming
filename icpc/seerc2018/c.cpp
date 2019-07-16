#include <bits/stdc++.h>

using namespace std;

const int N = 102;

vector<int> g[N];
int c[N];

int dfs(int v, int k, int par = -1) {
  int ret = c[v];
  if (k == 0)
    return ret;
  --k;
  for (int u : g[v]) if (u != par) {
    ret += dfs(u, k, v);
  }
  return ret;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i)
    scanf("%d", c+i);
  vector<pair<int, int> > edge;
  for (int i = 0; i + 1 < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
    edge.emplace_back(u, v);
  }
  int ans = 0;
  while (1) {
    bool ok = 0;
    if (ans & 1) {
      for (auto it : edge) {
        int res = dfs(it.first, ans/2, it.second) + dfs(it.second, ans/2, it.first);
        if (res >= m) {
          ok = 1;
          break;
        }
      }
    }
    else {
      for (int i = 0; i < n; ++i) {
        int res = dfs(i, ans/2);
        if (res >= m) {
          ok = 1;
          break;
        }
      }
    }
    if (ok) break;
    ++ans;
  }
  printf("%d\n", ans);
  return 0;
}