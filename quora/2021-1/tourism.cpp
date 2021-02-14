#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector<pair<int, int>> g[N];
int add[N];

int a[N], b[N];

int dead[N], group[N], big[N], sz[N];

long long ans[N];
long long fwd_cost[N];

void get_sz(int v, int par = -1) {
  sz[v] = 1;
  big[v] = -1;
  for (auto & e : g[v]) {
    int u = e.first;
    if (dead[u] || u == par) continue;
    get_sz(u, v);
    sz[v] += sz[u];
    if (big[v] == -1 || sz[u] > sz[big[v]])
      big[v] = u;
  }
}

void fwd_dfs(int v, int par, long long cost, long long cur, int col) {
  group[v] = col;
  fwd_cost[v] = cost;
  cur += add[v];
  for (auto& e : g[v]) {
    int u = e.first;
    if (dead[u] || u == par) continue;
    long long nxt = cur - e.second, ncost = cost;
    if (nxt < 0) {
      ncost -= nxt;
      nxt = 0;
    }
    fwd_dfs(u, v, ncost, nxt, col);
  }
}

vector<int> que[N];

void bck_dfs(int v, int par, long long cur, long long til) {
  for (int id : que[v]) {
    ans[id] = cur + max(fwd_cost[b[id]] - til, 0LL);
  }
  que[v].clear();
  for (auto& e : g[v]) {
    int u = e.first;
    if (dead[u] || u == par) continue;
    long long pre = cur + e.second - add[u], ntil = til;
    if (pre < 0) {
      ntil -= pre;
      pre = 0;
    }
    bck_dfs(u, v, pre, ntil);
  }
}

void centroid(int v, vector<int>& queries) {
  if (queries.empty()) return;
  get_sz(v);
  int tot = sz[v];
  while (big[v] != -1 && sz[big[v]] * 2 >= tot) v = big[v];
  fwd_cost[v] = 0;
  int cnt = 0;
  group[v] = -1;
  for (auto &e : g[v]) {
    int u = e.first;
    if (dead[u]) continue;
    fwd_dfs(u, v, e.second, 0, cnt);
    ++cnt;
  }
  vector<vector<int>> nxt_queries(cnt, vector<int>());
  for (int id : queries) {
    int x = a[id], y = b[id];
    if (group[x] == group[y]) {
      nxt_queries[group[x]].push_back(id);
    } else {
      que[x].push_back(id);
    }
  }
  bck_dfs(v, -1, 0, add[v]);
  cnt = 0;
  dead[v] = true;
  for (auto &e : g[v]) {
    int u = e.first;
    if (dead[u]) continue;
    centroid(u, nxt_queries[cnt++]);
  }
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i)
    scanf("%d", add+i);
  for (int i = 0; i < n-1; ++i) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    --u, --v;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }
  vector<int> queries(m);
  iota(queries.begin(), queries.end(), 0);
  for (int i = 0; i < m; ++i) {
    scanf("%d %d", a+i, b+i);
    --a[i], --b[i];
  }
  centroid(0, queries);
  for (int i = 0; i < m; ++i) {
    printf("%lld\n", ans[i]);
  }
  return 0;
}
