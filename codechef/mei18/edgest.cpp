#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

const int N = 2e5 + 5;

typedef tree<long long, null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

ordered_set st[N << 2];

int n;
void build(int id = 1, int l = 0, int r = n) {
  st[id].clear();
  if (r-l < 2) {
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
}

void insert(int x, long long y, int id = 1, int l = 0, int r = n) {
  st[id].insert((y << 32) | x);
  if (r-l < 2) {
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  if (x < mid)
    insert(x, y, il, l, mid);
  else
    insert(x, y, ir, mid, r);
}

void erase(int x, long long y, int id = 1, int l = 0, int r = n) {
  st[id].erase((y << 32) | x);
  if (r-l < 2) {
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  if (x < mid)
    erase(x, y, il, l, mid);
  else
    erase(x, y, ir, mid, r);
}

int get(int x, int y, long long lo, long long hi, int id = 1, int l = 0, int r = n) {
  if (l >= y || x >= r) return 0;
  if (x <= l && r <= y) {
    return st[id].order_of_key(hi << 32) - st[id].order_of_key(lo << 32);
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  return get(x, y, lo, hi, il, l, mid) + get(x, y, lo, hi, ir, mid, r);
}

vector<pair<int, int> > g1[N];
vector<int> g2[N];
const int LG = 21;
int ans[N], p[LG][N], lv[N];

int lca(int u, int v) {
  if (lv[u] > lv[v]) swap(u, v);
  int diff = lv[v] - lv[u];
  for (int i = 0; i < LG; ++i)
    if (diff & (1 << i))
      v = p[i][v];
  if (u == v) return v;
  for (int i = LG-1; i >= 0; --i) {
    if (p[i][u] != p[i][v])
      u = p[i][u], v = p[i][v];
  }
  return p[0][u];
}

void dfs1(int v = 0, int par = 0) {
  lv[v] = v == par ? 0 : lv[par] + 1;
  p[0][v] = par;
  for (int i = 0; i+1 < LG; ++i) {
    p[i+1][v] = p[i][p[i][v]];
  }
  for (int u : g2[v]) if (u != par) {
    dfs1(u, v);
  }
}

int num[N], en[N], cntr = 0;
vector<tuple<int, int, int, int> > que[N];

void dfs2(int v = 0, int par = 0) {
  num[v] = cntr++;
  for (auto it : g1[v]) {
    int u = it.first;
    if (u == par) continue;
    dfs2(u, v);
    int id = it.second;
    int w = lca(u, v);
    que[u].emplace_back(id, 1, num[u], en[u]);
    que[v].emplace_back(id, 1, num[u], en[u]);
    que[w].emplace_back(id, -2, num[u], en[u]);
  }
  en[v] = cntr;
}

void dfs3(int v = 0, int par = 0) {
  for (auto it : que[v]) {
    int id, w, l, r;
    tie(id, w, l, r) = it;
    ans[id] += w * (get(0, l, l, r) + get(l, r, r, n));
  }
  for (int u : g2[v]) if (u != par) {
    int a = num[v], b = num[u];
    if (a > b) swap(a, b);
    insert(a, b);
    dfs3(u, v);
    erase(a, b);
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
      g1[i].clear(), g2[i].clear(), que[i].clear();
    for (int i = 0; i < n-1; ++i) {
      int u, v;
      scanf("%d %d", &u, &v); --u, --v;
      g1[u].emplace_back(v, i);
      g1[v].emplace_back(u, i);
    }
    for (int i = 0; i < n-1; ++i) {
      int u, v;
      scanf("%d %d", &u, &v); --u, --v;
      g2[u].push_back(v);
      g2[v].push_back(u);
    }
    fill(ans, ans+n, 0);
    cntr = 0;
    build();
    dfs1();
    dfs2();
    dfs3();
    for (int i = 0; i < n-1; ++i) {
      printf("%d%c", ans[i], i == n-2 ? '\n' : ' ');
    }
  }
  return 0;
}