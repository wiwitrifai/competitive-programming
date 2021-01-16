#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<pair<int, int>> g[N];
int sz[N], big[N], alive[N];
int n, k;

void get_size(int v, int par = -1) {
  sz[v] = 1;
  big[v] = -1;
  for (auto & e : g[v]) {
    int u = e.first;
    if (!alive[u] || u == par) continue;
    get_size(u, v);
    sz[v] += sz[u];
    if (big[v] == -1 || sz[u] > sz[big[v]])
      big[v] = u;
  }
}

vector<pair<int, int>> semipaths;

void dfs(int v, int depth, int maxi, int par = -1) {
  semipaths.emplace_back(maxi, depth);
  for (auto & e : g[v]) {
    int u, w;
    tie(u, w) = e;
    if (!alive[u] || u == par) continue;
    dfs(u, depth + 1, max(maxi, w), v);
  }
}

struct BIT {
  vector<int> sum;

  BIT(int _n) : sum(_n+1, 0) {}

  void upd(int x, int v) {
    for (++x; x < (int)sum.size(); x += x&-x)
      sum[x] += v;
  }

  int get(int x) {
    int ret = 0;
    for (++x; x; x -= x&-x)
      ret += sum[x];
    return ret;
  }
} bit(N);

long long process() {
  long long ret = 0;
  sort(semipaths.begin(), semipaths.end());
  for (auto & sp : semipaths) {
    int rest = sp.first - sp.second - k;
    if (rest >= 0)
      ret += bit.get(rest);
    bit.upd(sp.second, +1);
  }

  for (auto & sp : semipaths) {
    bit.upd(sp.second, -1);
  }
  return ret;
}

long long centroid(int v) {
  get_size(v);
  int tot = sz[v];
  while (big[v] != -1 && sz[big[v]] * 2 >= tot)
    v = big[v];

  semipaths.clear();
  dfs(v, 0, 0);
  long long ret = process();
  alive[v] = false;
  for (auto & e : g[v]) {
    if (!alive[e.first]) continue;
    int u = e.first, w = e.second;
    semipaths.clear();
    dfs(u, 1, w);
    ret -= process();
  }

  for (auto & e : g[v]) {
    if (!alive[e.first]) continue;
    ret += centroid(e.first);
  }

  return ret;
}

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n-1; ++i) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    --u, --v;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }
  fill(alive, alive+n, true);
  long long ans = centroid(0) * 2LL;
  printf("%lld\n", ans);
  return 0;
}
