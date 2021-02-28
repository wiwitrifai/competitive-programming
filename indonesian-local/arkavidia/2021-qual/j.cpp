#include <bits/stdc++.h>

using namespace std;

vector<vector<vector<int>>> dp;
vector<vector<int>> g;

vector<int> par, a;

vector<int> combine(vector<int> & lef, vector<int> & rig) {
  vector<int> ret = lef;
  for (int i = 0; i < 4; ++i) {
    if (lef[i] < 0) continue;
    for (int j = 0; j < 4; ++j) {
      if (rig[j] < 0) continue;
      int k = i + j;
      if (k >= 4)
        k -= 4;
      ret[k] = max(ret[k], lef[i] + rig[j]);
    }
  }
  return ret;
}

void dfs(int v) {
  for (int & u : g[v]) {
    if (u == par[v])
      swap(u, g[v].back());
  }
  if (!g[v].empty() && par[v] == g[v].back())
    g[v].pop_back();
  dp[v].emplace_back(vector<int>(4, -1));
  dp[v].back()[a[v]] = 1;
  for (int u : g[v]) {
    par[u] = v;
    dfs(u);
    vector<int> res = combine(dp[v].back(), dp[u].back());
    dp[v].emplace_back(res);
  }
}

vector<int> ans;
void backtrack(int v, int r) {
  if (dp[v].back()[r] == 0)
    return;
  ans.push_back(v);
  auto & dpcur = dp[v];
  int id = (int)dpcur.size()-1;
  while (id > 0) {
    int u = g[v][id-1];
    bool found = false;
    if (dpcur[id-1][r] == dpcur[id][r]) {
      found = true;
    } else {
      for (int i = 0; i < 4; ++i) {
        int s = r - i;
        if (s < 0)
          s += 4;
        if (dpcur[id-1][i] <= 0 || dp[u].back()[s] <= 0) continue;
        if (dpcur[id-1][i] + dp[u].back()[s] != dpcur[id][r]) continue;
        backtrack(u, s);
        r = i;
        found = true;
        break;
      }
    }
    assert(found);
    --id;
  }
  assert(r == a[v]);
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  g.resize(n);
  a.resize(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    a[i] &= 3;
  }
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  dp.resize(n);
  par.assign(n, -1);
  for (int i = 0; i < n; ++i) {
    if (dp[i].empty()) {
      dfs(i);
    }
    if (dp[i].back()[0] >= 2) {
      backtrack(i, 0);
      break;
    }
  }
  if (ans.empty()) {
    puts("-1");
  } else {
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < (int)ans.size(); ++i) {
      printf("%d%c", ans[i]+1, i+1 == (int)ans.size() ? '\n' : ' ');
    }
  }
  return 0;
}
