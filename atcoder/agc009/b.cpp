#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6;

vector< int > child[N];
vector< int > depth[N];

int dfs(int v) {
  int ret = 0;
  for (int u : child[v]) {
    depth[v].push_back(dfs(u));
  }
  sort(depth[v].begin(), depth[v].end());
  for (int i = 0; i < depth[v].size(); i++) {
    ret = max(ret, depth[v][i]) + 1;
  }
  return ret;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int p;
    scanf("%d", &p);
    p--;
    child[p].push_back(i);
  }
  printf("%d\n", dfs(0));

  return 0;
}