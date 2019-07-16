#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

int p[N], n, k;
bool on_cycle[N];
int used[N];
vector<int> child[N];
vector<int> add;
int ans[N];

void dfs(int v, int lv, int low) {
  --add[max(lv - k - 1, low)];
  ++add[lv];
  for (int u : child[v]) {
    dfs(u, lv+1, low);
  }
  ans[v] += add[lv];
  add[lv-1] += add[lv];
  add[lv] = 0;
}

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", p+i);
    --p[i];
  }
  vector<int> roots;
  for (int v = 0; v < n; ++v) {
    if (used[v]) continue;
    int root = v;
    while (used[root] == 0) {
      used[root] = 1;
      root = p[root];
    }
    bool ok = used[root] != 2;
    root = v;
    while (used[root] == 1) {
      used[root] = 2;
      root = p[root];
    }
    if (!ok) continue;
    while (!on_cycle[root]) {
      on_cycle[root] = 1;
      root = p[root];
    }
    roots.push_back(root);
  }
  for (int i = 0; i < n; ++i)
    if (!on_cycle[i])
      child[p[i]].push_back(i);
  add.assign(n+n, 0);
  for (int root : roots) {
    assert(on_cycle[root]);
    vector<int> cycle;
    while (on_cycle[root]) {
      on_cycle[root] = 0;
      cycle.push_back(root);
      root = p[root];
    }
    reverse(cycle.begin(), cycle.end());
    for (int i = 0; i < cycle.size(); ++i) {
      dfs(cycle[i], i+(int)cycle.size(), i);
    }
    int sz = cycle.size();
    for (int i = 0; i < sz; ++i)
      cycle.push_back(cycle[i]);
    for (int i = (int)cycle.size() - 1; i >= 0; --i) {
      ans[cycle[i]] += add[i];
      if (i)
        add[i-1] += add[i];
      add[i] = 0;
    }
  }
  for (int i = 0; i < n; ++i) {
    printf("%d\n", ans[i]);
  }
  return 0;
}
