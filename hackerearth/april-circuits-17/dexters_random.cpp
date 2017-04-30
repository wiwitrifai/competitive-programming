// HLD + Trie - TLE
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector< int > g[N];
int to[400 * N][2], nodes;

void add(int root, int x) {
  for (int i = 30; i >= 0; i--) {
    int b = (x >> i) & 1;
    if (to[root][b] == 0)
      to[root][b] = ++nodes;
    root = to[root][b];
  }
}
int get(int root, int x) {
  int ans = 0;
  for (int i = 30; i >= 0; i--) {
    int b = (x >> i) & 1;
    b = !b;
    if (to[root][b] == 0) b = !b;
    root = to[root][b];
    ans |= b << i;
  }
  return ans^x;
}

struct seg_tree {
  vector < int > root;
  vector< int > val;
  int n;
  void build(int id, int l, int r) {
    root[id] = ++nodes;
    for (int i = l; i < r; ++i) {
      add(root[id], val[i]);
    }
    if (r-l < 2) return;
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    build(il, l, mid);
    build(ir, mid, r);
  }
  int get(int x, int y, int v, int id, int l, int r) {
    if (x >= r || y <= l) return 0;
    if (x <= l && r <= y) return ::get(root[id], v);
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    return max(get(x, y, v, il, l, mid), get(x, y, v, ir, mid, r));
  }
  int query(int x, int y, int v) {
    return get(x, y, v, 1, 0, n);
  }
};
seg_tree st[N];
int com[N], ncom, pos[N], sz[N], up[N], lv[N];
int val[N];

void pre(int v = 0, int par = -1) {
  sz[v] = 1, lv[v] = par == -1 ? 0 : lv[par] + 1;
  for (int u : g[v]) if (u != par)
    pre(u, v), sz[v] += sz[u];
}
int dfs(int v = 0, int par = -1) {
  com[v] = ncom;
  pos[v] = st[ncom].val.size();
  st[ncom].val.push_back(val[v]);
  int bg = -1;
  for (int u : g[v]) if (u != par) {
    if (bg == -1 || sz[bg] < sz[u])
      bg = u;
  }
  if (bg != -1)
    dfs(bg, v);
  for (int u : g[v]) if (u != par && u != bg) {
    ncom++;
    up[ncom] = v;
    dfs(u, v);
  }
}

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; i++) {
    scanf("%d", val+i);
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  pre();
  ncom = 0;
  up[0] = -1;
  dfs();
  for (int i = 0; i <= ncom; i++) {
    st[i].n = st[i].val.size();
    st[i].root.resize(st[i].n << 2);
    st[i].build(1, 0, st[i].n);
  }
  while (q--) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    int val_u = val[u], val_v = val[v];
    int ans = 0;
    while (com[u] != com[v]) {
      int llu = up[com[u]] < 0 ? -1 : lv[up[com[u]]];
      int llv = up[com[v]] < 0 ? -1 : lv[up[com[v]]];
      if (llu > llv) {
        int c = com[u];
        ans = max(st[c].query(0, pos[u]+1, val_u), ans);
        ans = max(st[c].query(0, pos[u]+1, val_v), ans);
        u = up[c];
      }
      else {
        int c = com[v];
        ans = max(st[c].query(0, pos[v]+1, val_u), ans);
        ans = max(st[c].query(0, pos[v]+1, val_v), ans);
        v = up[c];
      }
    }
    if (pos[u] > pos[v])
      swap(u, v);
    int c = com[u];
    ans = max(st[c].query(pos[u], pos[v]+1, val_u), ans);
    ans = max(st[c].query(pos[u], pos[v]+1, val_v), ans);
    printf("%d\n", ans);
  }
  return 0;
}