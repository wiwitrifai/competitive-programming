#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, mod = 1e9 + 7;

vector<pair<int, int>> g[N];
int a[N], sz[N], big[N], die[N];

void get_sz(int v, int par = -1) {
  sz[v] = 1;
  big[v] = -1;
  for (auto & e : g[v]) {
    int u = e.first;
    if (u == par || die[u]) continue;
    get_sz(u, v);
    if (big[v] == -1 || sz[u] > sz[big[v]])
      big[v] = u;
    sz[v] += sz[u];
  }
}

void add(long long & var, long long val) {
  var += val;
  if (var >= mod)
    var -= mod;
  else if (var < 0)
    var += mod;
}

long long ans = 0;
struct Fenwick {
  long long sum[N];
  Fenwick() {
    memset(sum, 0, sizeof sum);
  }
  long long get(int x) {
    long long ret = 0;
    for (++x; x; x -= x&-x)
      add(ret, sum[x]);
    return ret;
  }
  void update(int x, int v) {
    for (++x; x < N; x += x&-x)
      add(sum[x], v);
  }
};

Fenwick sum[2];
Fenwick cnt[2];

int mul = 1;

void dfs(int v, int par, long long cost, int change, int col) {
  int last = col ^ (change & 1);
  add(cost, a[v]);

  sum[col].update(change, mul * cost);
  cnt[col].update(change, mul);

  for (auto & e : g[v]) {
    int u = e.first;
    if (u == par || die[u]) continue;
    dfs(u, v, cost, change + (last != e.second), col);
  }
}

int n, k;

void dfs2(int v, int par, long long cost, int change, int col) {
  if (change > k) return;
  int last = col ^ (change & 1);
  add(cost, a[v]);

  ans = (ans + 1LL * cnt[col].get(k - change) * cost + 1LL * sum[col].get(k - change));
  if (change + 1 <= k)
    ans = (ans + 1LL * cnt[col^1].get(k - change - 1) * cost + 1LL * sum[col^1].get(k - change - 1));

  for (auto & e : g[v]) {
    int u = e.first;
    if (u == par || die[u]) continue;
    dfs2(u, v, cost, change + (last != e.second), col);
  }
}

void centroid(int v) {
  get_sz(v);
  int tot = sz[v];
  while (big[v] != -1 && sz[big[v]] * 2 >= tot)
    v = big[v];

  for (auto & e : g[v]) {
    int u = e.first;
    if (die[u]) continue;

    dfs2(u, v, 0, 0, e.second);

    mul = 1;
    dfs(u, v, a[v], 0, e.second);
  }

  ans = (ans + a[v]) % mod;
  for (int i = 0; i < 2; ++i) {
    ans = (ans + 1LL * sum[i].get(k)) % mod; 
  }

  for (auto & e : g[v]) {
    int u = e.first;
    if (die[u]) continue;
    mul = -1;
    dfs(u, v, a[v], 0, e.second);
  }

  die[v] = 1;

  for (auto & e : g[v]) {
    int u = e.first;
    if (die[u]) continue;
    centroid(u);
  }
}

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  for (int i = 0; i < n-1; ++i) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    --u, --v;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }
  centroid(0);
  ans %= mod;
  if (ans < 0)
    ans += mod;
  printf("%lld\n", ans);
  return 0;
}
