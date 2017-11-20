#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<pair<int, int> > g[N];

int n, sz[N];

void pre(int v, int par = -1) {
  sz[v] = 1;
  for (auto it : g[v]) if (it.first != par) {
    int u = it.first;
    pre(u, v);
    sz[v] += sz[u];
  }
}

vector<int> vs;
void dfs(int v, int par = -1) {
  for (auto it : g[v]) if (it.first != par) {
    int u = it.first;
    if (it.second) {
      vs.push_back(sz[u]);
      continue;
    }
    dfs(u, v);
  }
}

int main() {
  int k;
  scanf("%d %d", &n, &k);
  for (int i = 1; i < n; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    u--; v--;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }
  pre(0);
  dfs(0);
  sort(vs.begin(), vs.end());
  int now = n;
  for (int x : vs)
    now -= x;
  int ans = vs.size();
  for (int x : vs) {
    if (now + x > k)
      break;
    ans--;
    now += x;
  }
  if (now > k)
    puts("-1");
  else
    printf("%d\n", ans);
  return 0;
}