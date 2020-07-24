#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, inf = 1e9 + 7;

int p[N];
int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}

void merge(int u, int v) {
  if ((u = find(u)) == (v = find(v)))
    return;
  if (-p[u] < -p[v])
    swap(u, v);
  p[v] += p[u];
  p[u] = v;
}

vector<int> g[N];
vector<int> nodes;
vector<int> elem[N];

int dfs(int v, int par) {
  int ret = 0;
  nodes.push_back(v);
  for (int u : g[v]) {
    if (u == par) continue;
    ret += dfs(u, v);
    if (-p[find(u)] <= 1) {
      merge(u, v);
      ret += 2;
    }
  }
  return ret;
}

int main() {
  memset(p, -1, sizeof p);
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int ans = dfs(0, 0);
  if (-p[find(0)] <= 1) {
    ans += 2;
    merge(0, g[0][0]);
  }
  vector<int> moved(n);
  for (int v : nodes) {
    elem[find(v)].push_back(v);
  }
  for (int i = 0; i < n; ++i) {
    if (elem[i].empty()) continue;
    elem[i].push_back(elem[i][0]);
    for (int j = 0; j + 1 < (int)elem[i].size(); ++j) {
      moved[elem[i][j]] = elem[i][j+1];
    }
  }
  printf("%d\n", ans);
  for (int i = 0; i < n; ++i) {
    printf("%d%c", moved[i]+1, i+1 == n ? '\n' : ' ');
  }
  return 0;
}
