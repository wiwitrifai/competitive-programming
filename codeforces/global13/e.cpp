#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<int> alive, f, fib;
vector<int> xxor, par, sz;

vector<int> last;
vector<int> visited;
void get_size(int v) {
  visited.push_back(v);
  sz[v] = 1;
  for (auto e : g[v]) {
    if (!alive[e] || par[v] == e) continue;
    int u = xxor[e] ^ v;
    par[u] = e;
    get_size(u);
    sz[v] += sz[u];
  }
}

pair<int, int> dfs(int v) {
  par[v] = -1;
  visited.clear();
  get_size(v);
  if (sz[v] <= 2)
    return {par[last[1]], 0};
  int k = f[sz[v]];
  if (k == -1)
    return {-1, -1};
  int cand = -1;
  for (int u : visited) {
    if (sz[u] == fib[k-1] || sz[u] == fib[k-2]) {
      cand = u;
    }
  }
  if (cand == -1)
    return {-1, -1};
  int e = par[cand];
  int a = cand, b = xxor[e] ^ a;
  alive[e] = 0;
  auto res1 = dfs(a);
  if (res1 == make_pair(-1, -1))
    return res1;
  auto res2 = dfs(b);
  if (res2 == make_pair(-1, -1))
    return res2;
  return {e, -1};
}

int main() {
  int n;
  scanf("%d", &n);

  int a = 1, b = 1;
  f.assign(n+1, -1);
  fib.resize(n+1, 1);
  last.assign(n+1, -1);
  for (int i = 1; b <= n; ++i) {
    f[b] = i;
    fib[i] = b;
    int c = a + b;
    a = b;
    b = c;
  }
  g.resize(n);
  alive.resize(n);
  sz.resize(n);
  xxor.resize(n);
  par.resize(n);
  for (int i = 0; i < n-1; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    xxor[i] = u ^ v;
    alive[i] = true;
    g[u].emplace_back(i);
    g[v].emplace_back(i);
  }
  pair<int, int> res = dfs(0);
  if (res == make_pair(-1, -1)) {
    puts("NO");
    return 0;
  }
  puts("YES");
  return 0;
}
