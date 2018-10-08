#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, LG = 20;

int a[N], par[LG][N], st[N], en[N], lv[N], cntr = 0;
long long ans[N];
vector<int> node[N], g[N];
vector<pair<int, int> > ev[N];
long long bit[N];

void dfs(int v) {
  st[v] = cntr++;
  for (int i = 0; i+1 < LG; ++i) {
    par[i+1][v] = par[i][par[i][v]];
  }
  for (int u : g[v]) {
    lv[u] = lv[v] + 1;
    dfs(u);
  }
  en[v] = cntr;
}
int lca(int u, int v) {
  if (lv[u] > lv[v])
    swap(u, v);
  int diff = lv[v] - lv[u];
  for (int i = 0; i < LG; ++i)
    if (diff & (1 << i))
      v = par[i][v];
  if (u == v)
    return v;
  for (int i = LG-1; i >= 0; --i) {
    if (par[i][u] != par[i][v])
      u = par[i][u], v = par[i][v];
  }
  return par[0][v];
}

long long get(int x) {
  long long ret = 0;
  for (++x; x; x -= x&-x)
    ret += bit[x];
  return ret; 
}
void upd(int x, int v) {
  for (++x; x < N; x += x&-x)
    bit[x] += v;
}


int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  memset(par[0], -1, sizeof par[0]);
  for (int i = 0; i < n-1; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    par[0][v] = u;
  }
  int root = -1;
  for (int i = 0; i < n; ++i)
    if (par[0][i] == -1)
      root = i;
  par[0][root] = root;
  dfs(root);
  vector<int> va;
  for (int i = 0; i < n; ++i)
    va.push_back(a[i]);
  sort(va.begin(), va.end());
  va.erase(unique(va.begin(), va.end()), va.end());
  for (int i = 0; i < q; ++i) {
    int u, v, l, r;
    scanf("%d %d %d %d", &u, &v, &l, &r);
    --u, --v;
    int w = lca(u, v);
    ans[i] = (l <= a[w] && a[w] <= r)  ? a[w] : 0;
    l = lower_bound(va.begin(), va.end(), l) - va.begin() - 1;
    r = upper_bound(va.begin(), va.end(), r) - va.begin() - 1;
    if (r < 0)
      continue;
    if (u != w) {
      ev[r].emplace_back((i+1), u);
      ev[r].emplace_back(-(i+1), w);
    }
    if (v != w) {
      ev[r].emplace_back((i+1), v);
      ev[r].emplace_back(-(i+1), w);
    }
    if (l >= 0) {
      if (u != w) {
        ev[l].emplace_back(-(i+1), u);
        ev[l].emplace_back((i+1), w);
      }
      if (v != w) {
        ev[l].emplace_back(-(i+1), v);
        ev[l].emplace_back((i+1), w);
      }
    }
  }
  for (int i = 0; i < n; ++i)
    node[lower_bound(va.begin(), va.end(), a[i]) - va.begin()].push_back(i);
  for (int it = 0; it < va.size(); ++it) {
    for (int v : node[it]) {
      upd(st[v], +a[v]);
      upd(en[v], -a[v]);
    }
    for (auto e : ev[it]) {
      int id = e.first, v = e.second;
      ans[abs(id)-1] += get(st[v]) * (id < 0 ? -1 : 1);
    }
  }
  for (int i = 0; i < q; ++i) {
    printf("%lld\n", ans[i]);
  }
  return 0;
}