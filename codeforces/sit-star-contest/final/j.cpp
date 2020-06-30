#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<int> pos;

vector<int> ans;

void dfs(int v) {
  while (pos[v] < (int)g[v].size()) {
    int u = g[v][pos[v]++];
    dfs(u);
  }
  ans.push_back(v);
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  g.resize(n);
  pos.resize(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  dfs(0);
  printf("%d\n", (int)ans.size()-1);
  for (int i = 0; i < (int)ans.size(); ++i) {
    printf("%d%c", ans[i]+1, i+1 == (int)ans.size() ? '\n' : ' ');
  }
  return 0;
}
