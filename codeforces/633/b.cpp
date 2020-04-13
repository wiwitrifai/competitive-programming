#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> g[N];

bool col[N];

void dfs(int v, int par = -1) {
  for (int u : g[v]) {
    if (u == par) continue;
    col[u] = !col[v];
    dfs(u, v);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0);
  int mini = 1;
  int leaf = -1;
  for (int i = 0; i < n; ++i) {
    if (g[i].size() != 1) continue;
    if (leaf == -1)
      leaf = i;
    if (col[i] != col[leaf]) {
      mini = 3;
    }
  }
  int maxi = n-1;
  for (int i = 0; i < n; ++i) {
    int cnt = 0;
    for (int u : g[i]) {
      cnt += g[u].size() == 1;
    }
    if (cnt > 1) {
      maxi -= cnt - 1;
    }
  }
  printf("%d %d\n", mini, maxi);
  return 0;
}
