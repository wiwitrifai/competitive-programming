#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

int p[N], par[N], to[N];

vector<tuple<int, int, int> > edge;
vector<pair<int, int> > g[N];

int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}

bool merge(int u, int v) {
  if ((u = find(u)) == (v = find(v)))
    return false;
  if (-p[u] < -p[v])
    swap(u, v);
  p[u] += p[v];
  p[v] = u;
  return true;
}
int lv[N];

void dfs(int v) {
  for (auto it : g[v]) {
    int u = it.first;
    if (u == par[v]) continue;
    // cerr << v << " " << u << endl;
    par[u] = v;
    lv[u] = lv[v] + 1;
    if (it.second)
      to[u] = to[v];
    else
      to[u] = u;
    dfs(u);
  }
}

int go(int x) {
  return (to[x] == x) ? x : to[x] = go(to[x]);
}

void gabung(int x, int y) {
  x = go(x);
  y = go(y);
  if (x == y) return;
  to[x] = y;
}

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &k, &m);
  fill(p, p+n, -1);
  fill(par, par+n, -1);
  for (int i = 0; i < k; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].emplace_back(v, 0);
    g[v].emplace_back(u, 0);
    merge(u, v);
  }
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    --u, --v;
    edge.emplace_back(w, u, v);
  }
  sort(edge.begin(), edge.end());
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    tie(w, u, v) = edge[i];
    if (merge(u, v)) {
      g[u].emplace_back(v, 1);
      g[v].emplace_back(u, 1);
    }
  }
  // cerr << "done " << endl;
  par[0] = 0;
  to[0] = 0;
  lv[0] = 0;
  dfs(0);
  long long ans = 0;
  // for (int i = 0; i < n; ++i)
  //   cerr << i << " done " << go(i) << endl;
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    tie(w, u, v) = edge[i];
    // cerr << u << " " << v << endl;
    u = go(u);
    v = go(v);
    vector<int> upd;
    while (u != v) {
      // cerr << u << " " << v << endl;
      if (lv[u] < lv[v])
        swap(u, v);
      ans += w;
      gabung(u, par[u]);
      u = go(u);
    }
  }
  for (int i = 0; i < n; ++i) {
    if (go(i) != 0) {
      puts("-1");
      return 0;
    }
  }
  cout << ans << endl;
  return 0;
}