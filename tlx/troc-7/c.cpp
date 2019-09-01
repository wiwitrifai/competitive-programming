#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> g[N];

int dua[N], satu[N], atas1[N], atas2[N];
int ans = 0;
void dfs(int v, int par = -1) {
  satu[v] = dua[v] = 1;
  for (int u : g[v]) {
    if (u == par) continue;
    dfs(u, v);
    dua[v] = max(dua[v], dua[u]);
    dua[v] = max(dua[v], satu[v] + satu[u]);
    satu[v] = max(satu[v], satu[u]+1);
  }
}

void dfs2(int v, int par = -1) {
  for (int i = 0; i+1 < (int)g[v].size(); ++i)
    if (g[v][i] == par) {
      swap(g[v][i], g[v].back());
    }
  if (par != -1) {
    ans = min(ans, max(atas2[v], dua[v]));
    g[v].pop_back();
  }
  int one = 1, two = 1;
  vector<pair<int, int>> left(g[v].size());
  for (int i = 0; i < g[v].size(); ++i) {
    int u = g[v][i];
    assert(u != par);
    left[i] = {one, two};
    atas2[u] = max(atas2[u], two);
    atas1[u] = max(atas1[u], one);
    two = max(two, one + satu[u]);
    two = max(two, dua[u]);
    one = max(one, satu[u]+1);
  }

  one = atas1[v] + 1, two = max(one, atas2[v]);
  for (int i = 0; i < g[v].size(); ++i) {
    int u = g[v][i];
    assert(u != par);
    atas2[u] = max(atas2[u], two);
    atas1[u] = max(atas1[u], one);
    two = max(two, one + satu[u]);
    two = max(two, dua[u]);
    one = max(one, satu[u]+1);
  }
  reverse(g[v].begin(), g[v].end());
  reverse(left.begin(), left.end());
  one = atas1[v] + 1, two = max(one, atas2[v]);
  for (int i = 0; i < g[v].size(); ++i) {
    int u = g[v][i];
    assert(u != par);
    atas2[u] = max(atas2[u], two);
    atas1[u] = max(atas1[u], one);
    atas2[u] = max(atas2[u], one + left[i].first-1);
    two = max(two, one + satu[u]);
    two = max(two, dua[u]);
    one = max(one, satu[u]+1);
  }
  for (int u : g[v]) {
    dfs2(u, v);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n-1; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0);
  ans = dua[0];
  dfs2(0);
  --ans;
  printf("%d\n", ans);
  return 0;
}
