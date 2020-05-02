#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long inf = 1e18;
long long an[N << 2], sn[N << 2], b[N << 2];
int lv[N], a[N], node[N], lazy[N << 2], n;

vector< int > adj[N];


void build(int id = 1, int l = 0, int r = n) {
  lazy[id] = 0;
  if (r-l < 2) {
    int v = node[l];
    b[id] = a[v];
    an[id] = 1LL * a[v] * lv[v];
    sn[id] = 1LL * a[v] * (lv[v] + 1) * lv[v] / 2;
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
  b[id] = b[il] + b[ir];
  an[id] = an[il] + an[ir];
  sn[id] = sn[il] + sn[ir];
}

void upd(int id, int v) {
  if (v == 0)
    return;
  if (v < 0) {
    long long ann = an[id] + 1LL * b[id] * (v + 1);
    sn[id] += 1LL * v * (an[id] + ann) / 2;
    an[id] += 1LL * v * b[id];
  }
  else {
    long long ann = an[id] + b[id];
    an[id] += 1LL * v * b[id];
    sn[id] += 1LL * v * (an[id] + ann) / 2;
  }
  lazy[id] += v;
}

void shift(int id) {
  if (lazy[id]) {
    int il = id << 1, ir = il | 1;
    upd(il, lazy[id]);
    upd(ir, lazy[id]);
    lazy[id] = 0;
  }
}

void update(int x, int y, int v, int id = 1, int l = 0, int r = n) {
  if (x >= r || y <= l) return;
  if (x <= l && r <= y) {
    upd(id, v);
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  shift(id);
  update(x, y, v, il, l, mid);
  update(x, y, v, ir, mid, r);
  an[id] = an[il] + an[ir];
  sn[id] = sn[il] + sn[ir];
}
int cntr = 0, le[N], ri[N];
void pre(int v, int p = -1) {
  le[v] = cntr;
  node[cntr++] = v;
  for (int u : adj[v]) if (u != p) {
    lv[u] = lv[v] + 1;
    pre(u, v);
  }
  ri[v] = cntr;
}
long long ans = inf;
int vv = 0;

void dfs(int v, int p = -1) {
  if (ans > sn[1]) {
    ans = sn[1];
    vv = v;
  }
  update(0, n, +1);
  for (int u : adj[v]) if (u != p) {
    update(le[u], ri[u], -2);
    dfs(u, v);
    update(le[u], ri[u], +2); 
  }
  update(0, n, -1);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  cntr = 0;
  lv[0] = 1;
  pre(0);
  build();
  ans = sn[1];
  vv = 0;
  dfs(0);
  printf("%d %lld\n", vv+1, ans);
  return 0;
}