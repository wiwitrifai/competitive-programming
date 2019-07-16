#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, LG = 21;
int lv[N], par[LG][N], ma[LG][N];
vector<pair<int, int> > g[N];
int p[N];
int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}
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
  for (int i = 0; i+1 < LG; ++i) {
    int u = par[i][v];
    par[i+1][v] = par[i][u];
    ma[i+1][v] = max(ma[i][v], ma[i][u]);
  }
  for (auto it : g[v]) {
    if (it.first == par[0][v]) continue;
    par[0][it.first] = v;
    ma[0][it.first] = it.second;
    lv[it.first] = lv[v] + 1;
    dfs(it.first);
  }
}

int main() {
  int n, r;
  scanf("%d %d", &n, &r);
  vector<tuple<int, int, int> > edge;
  while (r--) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    if (u > v) swap(u, v);
    --u, --v;
    edge.emplace_back(w, u, v);
  }
  sort(edge.begin(), edge.end());
  long long mst = 0;
  memset(p, -1, sizeof p);
  for (auto & it : edge) {
    int u, v, w;
    tie(w, u, v) = it;
    if (merge(u, v)) {
      mst += w;
      g[u].emplace_back(v, w);
      g[v].emplace_back(u, w);
    }
    it = make_tuple(u, v, w);
  }
  sort(edge.begin(), edge.end());
  int q;
  scanf("%d", &q);
  dfs(0);
  while (q--) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    if (u > v) swap(u, v);
    auto it = lower_bound(edge.begin(), edge.end(), make_tuple(u, v, -1));
    assert(get<0>(*it) == u && get<1>(*it) == v);
    long long cur = mst + get<2>(*it);
    if (lv[u] > lv[v])
      swap(u, v);
    int diff = lv[v] - lv[u];
    int hig = 0;
    for (int i = 0; i < LG; ++i)
      if (diff & (1 << i)) {
        hig = max(hig, ma[i][v]);
        v = par[i][v];
      }
    if (u != v) {
      for (int i = LG-1; i >= 0; --i) {
        if (par[i][u] != par[i][v]) {
          hig = max(hig, max(ma[i][u], ma[i][v]));
          u = par[i][u];
          v = par[i][v];
        }
      }
      hig = max(hig, max(ma[0][u], ma[0][v]));
    }
    cur -= hig;
    printf("%lld\n", cur);
  }
  return 0;
}