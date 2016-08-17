#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 5;

long long c[N<<2];
int lazy[N<<2];
int cc[N], n, ccol[N];

void build(int id = 1, int l = 0, int r = n) {
  lazy[id] = -1;
  if (r-l < 2) {
    c[id] = 1LL<<cc[l];
    return;
  }
  int mid = (l+r) >> 1, il = id<<1, ir = il|1;
  build(il, l, mid);
  build(ir, mid, r);
  c[id] = c[il] | c[ir];
}

void shift(int id) {
  if (lazy[id] >= 0) {
    int il = id << 1, ir = il|1;
    c[il] = c[ir] = 1LL << lazy[id];
    lazy[il] = lazy[ir] = lazy[id];
    lazy[id] = -1;
  }
}

long long get(int x, int y, int id = 1, int l = 0, int r = n) {
  if (x >= r || y <= l) return 0;
  if (x <= l && r <= y) return c[id];
  shift(id);
  int mid = (l+r)>>1, il = id<<1, ir = il|1;
  return get(x, y, il, l, mid) | get(x, y, ir, mid, r);
}

void upd(int x, int y, int col, int id = 1, int l = 0, int r = n) {
  if (x >= r || y <= l) return;
  if (x <= l && r <= y) {
    c[id] = 1LL<<col;
    lazy[id] = col;
    return;
  }
  shift(id);
  int mid = (l+r)>>1, il = id<<1, ir = il|1;
  upd(x, y, col, il, l, mid);
  upd(x, y, col, ir, mid, r);
  c[id] = c[il] | c[ir];
}

vector < int > adj[N];
int st[N], fn[N], tmpstmp;

void dfs(int v, int par = -1) {
  cc[tmpstmp] = ccol[v];
  st[v] = tmpstmp++;
  for (int u : adj[v]) if (u != par) {
    dfs(u, v);
  }
  fn[v] = tmpstmp;
}

int main() {
  int m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++)
    scanf("%d", ccol+i), ccol[i]--;
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  tmpstmp = 0;
  dfs(0);
  assert(tmpstmp == n);
  build();  
  while (m--) {
    int t, v;
    scanf("%d %d", &t, &v);
    v--;
    if (t == 1) {
      int col;
      scanf("%d", &col);
      upd(st[v], fn[v], col-1);
    }
    else {
      long long res = get(st[v], fn[v]);
      int ans = __builtin_popcountll(res);
      printf("%d\n", ans);
    }
  }
  return 0;
}