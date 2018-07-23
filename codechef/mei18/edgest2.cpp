#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int bit[N + N];
int n;
int st[N], en[N], cntr, p[N];
vector<pair<int, int> > g1[N];
vector<int> g2[N];
const int LG = 21;
int sp[LG][N+N], lv[N];
int sz[N], bg[N], no[N], ans[N];
bool used[N];

void upd(int x, int v) {
  for (++x; x <= cntr+1; x += x&-x)
    bit[x] += v;
}
int get(int x) {
  int r = 0;
  for (++x; x; x -= x&-x)
    r += bit[x];
  return r;
}
void dfs1(int v = 0, int par = -1) {
  lv[v] = par == -1 ? 0 : lv[par] + 1;
  p[v] = par;
  sp[0][cntr] = v;
  st[v] = cntr++;
  for (int u : g2[v]) if (u != par) {
    dfs1(u, v);
    sp[0][cntr++] = v;
  }
  en[v] = cntr;
}
int get_sp(int l, int r) {
  int len = r-l;
  int lg = 31 - __builtin_clz(len);
  int le = sp[lg][l], ri = sp[lg][r-(1<<lg)];
  return lv[le] < lv[ri] ? le : ri;
}

int lca(int u, int v) {
  if (st[u] > st[v]) swap(u, v);
  return get_sp(st[u], st[v]+1);
}
void flip(int v) {
  used[v] ^= 1;
  if (p[v] != -1) {
    int val = 1;
    if (used[v] == used[p[v]]) val = -1;
    upd(st[v], val);
    upd(en[v], -val);
  }
  for (int u : g2[v]) if (u != p[v]) {
    int val = 1;
    if (used[v] == used[u]) val = -1;
    upd(st[u], val);
    upd(en[u], -val);
  }
}
void dfs2(int v = 0, int par = -1) {
  sz[v] = 1;
  bg[v] = -1;
  for (auto it : g1[v]) {
    int u = it.first;
    if (u == par) continue;
    no[u] = it.second;
    dfs2(u, v);
    sz[v] += sz[u];
    if (bg[v] == -1 || sz[bg[v]] < sz[u])
      bg[v] = u;
  }
}

void flip_tree(int v, int par) {
  flip(v);
  for (auto it : g1[v]) {
    if (it.first == par) continue;
    flip_tree(it.first, v);
  }
}

void dfs3(int v = 0, int par = -1) {
  for (auto it : g1[v]) {
    if (it.first == par || it.first == bg[v]) continue;
    dfs3(it.first, v);
    flip_tree(it.first, v);
  }
  if (bg[v] != -1) {
    dfs3(bg[v], v);
  }
  if (no[v] == -1) return;
  for (auto it : g1[v]) {
    if (it.first == par || it.first == bg[v]) continue;
    flip_tree(it.first, v);
  }
  flip(v);
  int w = lca(par, v);
  ans[no[v]] = get(st[v]) + get(st[par]) - 2 * get(st[w]);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
      g1[i].clear(), g2[i].clear();
    for (int i = 0; i < n-1; ++i) {
      int u, v;
      scanf("%d %d", &u, &v); --u, --v;
      g1[u].emplace_back(v, i);
      g1[v].emplace_back(u, i);
    }
    for (int i = 0; i < n-1; ++i) {
      int u, v;
      scanf("%d %d", &u, &v); --u, --v;
      g2[u].emplace_back(v);
      g2[v].emplace_back(u);
    }
    cntr = 0;
    dfs1();
    assert(cntr < N + N);
    for (int i = 0; i < LG; ++i) {
      for (int j = 0; j + (1 << (i+1)) <= cntr; ++j) {
        int le = sp[i][j], ri = sp[i][j+(1<<i)];
        sp[i+1][j] = lv[le] < lv[ri] ? le : ri;
      }
    }
    fill(bit, bit+cntr+2, 0);
    fill(used, used+n, 0);
    fill(no, no+n, -1);
    dfs2();
    dfs3();
    for (int i = 0; i < n-1; ++i)
      printf("%d%c", ans[i], i == n-2 ? '\n' : ' ');
  }
  return 0;
}