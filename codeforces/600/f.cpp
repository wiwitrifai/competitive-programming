#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5, LG = 20;
const long long infll = 1e16;

vector<pair<int, int>> g[N];
long long dist[N];
int from[N];
int p[N];

int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}

vector<pair<int, long long>> tree[N];
int lv[N], par[LG][N];
long long val[LG][N];

bool merge(int u, int v) {
  if ((u = find(u)) == (v = find(v)))
    return false;
  if (-p[u] > -p[v])
    swap(u, v);
  p[v] += p[u];
  p[u] = v;
  return true;
}

void dfs(int v) {
  for (int i = 0; i + 1 < LG; ++i) {
    par[i+1][v] = par[i][par[i][v]];
    val[i+1][v] = max(val[i][v], val[i][par[i][v]]);
  }
  for (auto e : tree[v]) {
    if (e.first == par[0][v]) continue;
    par[0][e.first] = v;
    val[0][e.first] = e.second;
    lv[e.first] = lv[v] + 1;
    dfs(e.first);
  }
}

long long solve(int u, int v) {
  if (lv[v] < lv[u]) swap(u, v);
  int diff = lv[v] - lv[u];
  long long ret = 0;
  for (int i = 0; i < LG; ++i) {
    if (diff & (1 << i)) {
      ret = max(ret, val[i][v]);
      v = par[i][v];
    }
  }
  if (u == v) return ret;
  for (int i = LG-1; i >= 0; --i) {
    if (par[i][v] != par[i][u]) {
      ret = max(ret, max(val[i][u], val[i][v]));
      v = par[i][v];
      u = par[i][u];
    }
  }
  ret = max(ret, max(val[0][u], val[0][v]));
  return ret;
}

int main() {
  int n, m, k, q;
  scanf("%d %d %d %d", &n, &m, &k, &q);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    --u, --v;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }
  fill(dist, dist+n, infll);
  priority_queue<pair<long long, int> > pq;
  for (int i = 0; i < k; ++i) {
    from[i] = i;
    dist[i] = 0;
    pq.emplace(0, i);
  }
  while (!pq.empty()) {
    int v = pq.top().second;
    long long w = -pq.top().first;
    pq.pop();
    if (dist[v] != w) continue;
    for (auto e : g[v]) {
      long long cur = w + e.second;
      if (dist[e.first] > cur) {
        from[e.first] = from[v];
        dist[e.first] = cur;
        pq.emplace(-cur, e.first);
      }
    }
  }
  vector<tuple<long long, int, int> > edges;
  for (int v = 0; v < n; ++v) {
    for (auto e : g[v]) {
      if (from[v] == from[e.first]) continue;
      edges.emplace_back(dist[v] + e.second + dist[e.first], from[v], from[e.first]);
    }
  }
  fill(p, p+n, -1);
  sort(edges.begin(), edges.end());
  for (auto e : edges) {
    int u, v;
    long long w;
    tie(w, u, v) = e;
    if (merge(u, v)) {
      tree[u].emplace_back(v, w);
      tree[v].emplace_back(u, w);
    }
  }
  par[0][0] = 0;
  val[0][0] = 0;
  lv[0] = 0;
  dfs(0);
  for (int i = 0; i < q; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    --a, --b;
    printf("%lld\n", solve(a, b));
  }
  return 0;
}
