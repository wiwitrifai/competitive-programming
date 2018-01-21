#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, LG = 21;

vector<int> g[N];

int n, q;
int st[N], en[N], cntr = 0, node[N];
int par[LG][N], lv[N], aw[N];

void dfs(int v) {
  node[cntr] = v;
  st[v] = cntr++;
  for (int i = 0; i + 1 < LG; ++i)
    par[i+1][v] = par[i][par[i][v]];
  for (int u : g[v]) if (u != par[0][v]) {
    par[0][u] = v;
    lv[u] = lv[v] + 1;
    dfs(u);
  }
  en[v] = cntr;
}

int lca(int u, int v) {
  if (lv[u] > lv[v]) swap(u, v);
  int diff = lv[v] - lv[u];
  for (int i = 0; i < LG; ++i) if (diff & (1 << i))
    v = par[i][v];
  if (u == v) return v;
  for (int i = LG-1; i >= 0; --i)
    if (par[i][u] != par[i][v])
      u = par[i][u], v = par[i][v];
  return par[0][v];
}

int ancestor(int u, int pos) {
  int diff = lv[u] - pos;
  for (int i = 0; i < LG; ++i) if (diff & (1 << i))
    u = par[i][u];
  return u;
}

long long sum[N << 2], add[N << 2];
void build(int id = 1, int l = 0, int r = n) {
  add[id] = 0;
  if (r-l < 2) {
    sum[id] = aw[node[l]];
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
  sum[id] = sum[il] + sum[ir];
}

void upd(int id, int l, int r, long long v) {
  sum[id] += 1LL * (r-l) * v;
  add[id] += v;
}
void push(int id, int l, int r) {
  if (add[id] == 0) return;
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  upd(il, l, mid, add[id]);
  upd(ir, mid, r, add[id]);
  add[id] = 0;
}
void update(int x, int y, int v, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    upd(id, l, r, v);
    return;
  }
  push(id, l, r);
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  update(x, y, v, il, l, mid);
  update(x, y, v, ir, mid, r);
  sum[id] = sum[il] + sum[ir];
}
long long get(int x, int y, int id =1 , int l = 0, int r = n) {
  if (x >= r || l >= y) return 0;
  if (x <= l && r <= y) {
    return sum[id];
  }
  push(id, l, r);
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  return get(x, y, il, l, mid) + get(x, y, ir, mid, r);
}

int main() {
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; ++i) {
    scanf("%d", aw+i);
  }
  for (int i = 0; i < n-1; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  cntr = 0;
  par[0][0] = 0;
  lv[0] = 0;
  dfs(0);
  build();
  int root = 0;
  while (q--) {
    int t, u, v, x;
    scanf("%d %d", &t, &u);
    --u;
    if (t == 1)
      root = u;
    else if (t == 2) {
      scanf("%d %d", &v, &x);
      --v;
      int a = lca(u, v), b = lca(u, root), c = lca(v, root);
      if (lv[a] < lv[b]) swap(a, b);
      if (lv[a] < lv[c]) swap(a, c);
      if (a == root) {
        update(0, n, x);
      }
      else if (lca(a, root) == a) {
        update(0, n, x);
        a = ancestor(root, lv[a]+1);
        update(st[a], en[a], -x);
      }
      else
        update(st[a], en[a], x);
    }
    else {
      long long ans = 0;
      if (u == root)
        ans = sum[1];
      else if (lca(u, root) == u) {
        u = ancestor(root, lv[u]+1);
        ans = sum[1] - get(st[u], en[u]);
      }
      else
        ans = get(st[u], en[u]);
      printf("%I64d\n", ans);
    }
  }
  return 0;
}