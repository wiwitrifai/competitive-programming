#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

vector<int> g[N];
int a[N], b[N], w[N];
long long c[N];
int cnt[N], bridge[N];
vector<int> num, low, par;
int cntr;

void dfs(int v) {
  low[v]= num[v] = ++cntr;
  for(auto i : g[v]) {
    int u = v ^ a[i];
    if(num[u] == -1) {
      par[u] = v;

      dfs(u);

      if(low[u] > num[v]) {
        bridge[i] = 1;
      }

      low[v] = min(low[v], low[u]);
    }
    else if(u != par[v])
      low[v] = min(low[v], num[u]);
  }
}

struct Dsu {
  vector<int> p;

  Dsu(int _n) {
    p.assign(_n, -1);
  }

  int find(int x) {
    return p[x] < 0 ? x : p[x] = find(p[x]);
  }

  void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (-p[u] > -p[v])
      swap(u, v);
    p[v] += p[u];
    p[u] = v;
    cnt[v] += cnt[u];
    c[v] += c[u];
  }
};

vector<pair<int, int>> tree[N];
long long dp[N], ans[N];

int k;

void dfs2(int v, int p) {
  dp[v] = c[v];
  for (auto e : tree[v]) {
    int u = e.first;
    if (u == p) continue;
    dfs2(u, v);
    cnt[v] += cnt[u];
    long long cur = dp[u];
    if (cnt[u] > 0 && cnt[u] < k)
      cur = dp[u] - e.second;
    dp[v] += max(0LL, cur);
  }
}


void dfs3(int v, int p) {
  ans[v] = dp[v];
  for (auto e : tree[v]) {
    int u = e.first;
    if (u == p) continue;
    long long cost = dp[u];
    if (cnt[u] > 0 && cnt[u] < k)
      cost = dp[u] - e.second;
    long long cur = dp[v] - max(0LL, cost);
    if (cnt[u] > 0 && cnt[u] < k)
      cur -= e.second;
    dp[u] += max(0LL, cur);
    dfs3(u, v);
  }
}

void solve() {
  int n, m;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < k; ++i) {
    int v;
    scanf("%d", &v);
    --v;
    cnt[v] = 1;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%lld", c+i);
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d", w+i);
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d %d", a+i, b+i);
    --a[i], --b[i];
    g[a[i]].push_back(i);
    g[b[i]].push_back(i);
    a[i] ^= b[i];
  }
  cntr = 0;
  num.assign(n, -1);
  low.assign(n, 0);
  par.assign(n, -1);
  dfs(0);
  Dsu dsu(n);
  for (int i = 0; i < m; ++i) {
    if (bridge[i]) continue;
    dsu.merge(a[i]^b[i], b[i]);
  }
  for (int i = 0; i < m; ++i) {
    if (!bridge[i]) continue;
    int u = a[i]^b[i], v = b[i];
    u = dsu.find(u);
    v = dsu.find(v);
    tree[u].emplace_back(v, w[i]);
    tree[v].emplace_back(u, w[i]);
  }
  int root = dsu.find(0);
  dfs2(root, root);
  dfs3(root, root);
  for (int i = 0; i < n; ++i)
    printf("%lld%c", ans[dsu.find(i)], i+1 == n ? '\n' : ' ');
}

int main() {
  int tc = 1;
  // scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
