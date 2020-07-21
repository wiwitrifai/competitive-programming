#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> g[N];

vector<int> nodes;

bool dfs0(int v, int x, int par) {
  nodes.push_back(v);
  if (v == x)
    return true;
  for (int u : g[v]) {
    if (u == par) continue;
    if (dfs0(u, x, v))
      return true;
  }
  nodes.pop_back();
  return false;
}

vector<int> cnt;

int dfs1(int v, int par, int len) {
  ++len;
  if (len >= (int)nodes.size()) {
    ++cnt[v];
  }
  int ret = 1;
  for (int u : g[v]) {
    if (u == par) continue;
    int res = dfs1(u, v, max(len, ret)) + 1;
    if (res >= (int)nodes.size()) {
      ++cnt[v];
    }
    ret = max(ret, res);
  }
  if (cnt[v] < 3)
    cnt[v] = 0;
  return ret;
}

int dfs(int v, int par, vector<int> & can, vector<int> & far) {
  can[v] = cnt[v] >= 3;
  int ret = 1;
  for (int u : g[v]) {
    if (u == par) continue;
    int res = dfs(u, v, can, far);
    can[v] |= can[u];
    ++res;
    ret = max(ret, res);
  }
  far[v] = ret;
  return ret;
}

void solve() {
  int n, a, b;
  scanf("%d %d %d", &n, &a, &b);
  --a, --b;
  for (int i = 0; i < n; ++i)
    g[i].clear();
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  nodes.clear();
  dfs0(a, b, -1);
  cnt.assign(n, 0);
  dfs1(0, 0, 0);
  for (int i = 0; i < n; ++i)
    reverse(g[i].begin(), g[i].end());
  dfs1(0, 0, 0);
  vector<int> ca(n, 0), cb(n, 0);
  vector<int> fa(n, 0), fb(n, 0);
  dfs(a, -1, ca, fa);
  dfs(b, -1, cb, fb);
  int l = 0, r = (int)nodes.size()-1;
  bool ans = false;
  int le = -1, ri = r + 1;
  while (!ans && (le < l || ri > r)) {
    if (le < l) {
      ++le;
      int v = nodes[le];
      ans |= cb[v] > 0;
      r = min(r, max(le, le - fb[v] + (int)nodes.size()));
    } else {
      --ri;
      int v = nodes[ri];
      ans |= ca[v] > 0;
      l = max(l, min(ri, ri + fa[v] - (int)nodes.size()));
    }
  }
  puts(ans ? "YES" : "NO");
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
