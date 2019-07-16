#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, LG = 17;

template<class T>
struct BIT {
  T bit[N];
  BIT() {
    memset(bit, 0, sizeof bit);
  }
  T get(int x) {
    T ret = 0;
    for (++x; x; x -= x&-x)
      ret += bit[x];
    return ret;
  }
  void upd(int x, int v) {
    for (++x; x < N; x += x&-x)
      bit[x] += v;
  }
};

BIT<int> plazy;
BIT<int> plive, up;
int par[LG][N], lv[N], st[N], en[N], cntr = 0, col[N];
int live[N];
vector<int> g[N];
int lazy[N];

void dfs(int v) {
  st[v] = cntr++;
  for (int i = 0; i + 1 < LG; ++i) {
    par[i+1][v] = par[i][par[i][v]];
  }
  for (int u : g[v]) {
    if (par[0][v] == u) continue;
    par[0][u] = v;
    lv[u] = lv[v] + 1;
    col[u] = col[v] ^ 1;
    dfs(u);
  }
  en[v] = cntr;
}

int find(int v) {
  int cur = up.get(st[par[0][v]]);
  int r = v;
  for (int i = LG-1; i >= 0; --i) {
    int u = par[i][r];
    if (cur - up.get(st[par[0][u]]) == lv[v] - lv[u])
      r = u;
  }
  return r;
}
int deg[N], res[N];

void dfs2(int v, int sum = 0) {
  if (live[v] <= 0)
    sum = 0;
  sum = (sum + lazy[v]) % 360;
  if (live[v] == 1)
    res[v] = (deg[v] + sum) % 360;
  else
    res[v] = deg[v];
  for (int u : g[v]) {
    if (u == par[0][v]) continue;
    dfs2(u, sum);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  g[0].push_back(1);
  g[1].push_back(0);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0);
  for (int i = 1; i <= n; ++i) {
    live[i] = 1;
    plive.upd(st[i], 1);
    up.upd(st[i], 1);
    up.upd(en[i], -1);
  }
  plive.upd(st[0], -n);
  live[0] = -n;
  int q;
  scanf("%d", &q);
  while (q--) {
    int t, x;
    scanf("%d %d", &t, &x);
    if (t == 1) {
      assert(live[x] == 1);
      int tot = plive.get(en[x]-1) - (st[x] ? plive.get(st[x]-1) : 0);
      int z = par[0][find(x)];
      live[z] += tot;
      plive.upd(st[z], tot);
      live[x] -= tot;
      plive.upd(st[x], -tot);
      up.upd(st[x], -1);
      up.upd(en[x], 1);

      int add = plazy.get(st[x]) - (z ? plazy.get(st[par[0][z]]) : 0);
      add %= 360;
      if (add < 0) add += 360;
      deg[x] = (deg[x] + add) % 360;
      plazy.upd(st[x], add-lazy[x]);
      plazy.upd(en[x], lazy[x]-add);
      lazy[x] = add;
    }
    else if (t == 2) {
      assert(live[x] <= 0);
      int tot = -live[x] + 1;
      int z = par[0][find(x)];
      live[z] -= tot;
      plive.upd(st[z], -tot);
      live[x] += tot;
      plive.upd(st[x], tot);
      up.upd(st[x], 1);
      up.upd(en[x], -1);

      int add = plazy.get(st[x]) - (z ? plazy.get(st[par[0][z]]) : 0);
      int pre = lazy[x];
      add = (2 * lazy[x] - add);
      add %= 360;
      if (add < 0) add += 360;
      deg[x] = (deg[x] - lazy[x]) % 360;
      if (deg[x] < 0) deg[x] += 360;
      plazy.upd(st[x], add-lazy[x]);
      plazy.upd(en[x], lazy[x]-add);
      lazy[x] = add;
    }
    else {
      int a;
      scanf("%d", &a);
      int z = find(x);
      int tot = plive.get(en[z]-1) - (st[z] ? plive.get(st[z]-1) : 0);
      printf("%d\n", tot * a);
      if (col[x])
        a = 360-a;
      lazy[z] = (lazy[z] + a) % 360;
      plazy.upd(st[z], a);
      plazy.upd(en[z], -a);
    }
  }
  dfs2(0);
  int sum = 0;
  for (int i = 1; i <=n; ++i) {
    int now = res[i];
    if (col[i])
      now = 360 - now;
    now %= 360;
    if (now < 0) now += 360;
    sum += now;
  }
  printf("%d\n", sum);
  return 0;
}