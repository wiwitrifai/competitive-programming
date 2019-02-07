#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 4;
const long long inf = 1e18;

long long mins[N << 2], lazy[N << 2];
long long val[N];
int len;

void build(int id = 1, int l = 0, int r = len) {
  mins[id] = lazy[id] = 0;
  if (r-l < 2) {
    mins[id] = val[l];
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
  mins[id] = min(mins[il], mins[ir]);
}

inline void upd(int id, long long x) {
  mins[id] += x;
  lazy[id] += x;
}

inline void push(int id, int il, int ir) {
  if (lazy[id] == 0) return;
  upd(il, lazy[id]);
  upd(ir, lazy[id]);
  lazy[id] = 0;
}

void update(int x, int y, long long z, int id = 1, int l = 0, int r = len) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    upd(id, z);
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  push(id, il, ir);
  update(x, y, z, il, l, mid);
  update(x, y, z, ir, mid, r);
  mins[id] = min(mins[il], mins[ir]);
}

long long get(int x, int y, int id =1, int l = 0, int r= len) {
  if (x >= r || l >= y) return inf;
  if (x <= l && r <= y) {
    return mins[id];
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  push(id, il, ir);
  return min(get(x, y, il, l, mid), get(x, y, ir, mid, r));
}

vector<int> leaves;
int st[N], en[N];
int cntr = 0;
long long lv[N];

vector<pair<int, int> > g[N];

void dfs(int v) {
  st[v] = leaves.size();
  if (g[v].empty()) {
    val[leaves.size()] = lv[v];
    leaves.push_back(cntr);
  }
  ++cntr;
  for (auto it : g[v]) {
    int u = it.first, w = it.second;
    lv[u] = lv[v] + w;
    dfs(u);
  }
  en[v] = leaves.size();
}
vector<int> que[N];
int le[N], ri[N];
long long ans[N];

void dfs2(int v) {
  for (int id : que[v]) {
    ans[id] = get(le[id], ri[id]);
  }
  for (auto it : g[v]) {
    int u = it.first, w = it.second;
    update(0, len, w);
    update(st[u], en[u], -2 * w);
    dfs2(u);
    update(0, len, -w);
    update(st[u], en[u], +2 * w);
  }
}

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 1; i < n; ++i) {
    int u, w;
    scanf("%d %d", &u, &w);
    --u;
    g[u].emplace_back(i, w);
  }
  dfs(0);
  for (int i = 0; i < q; ++i) {
    int v;
    scanf("%d %d %d", &v, le+i, ri+i);
    --v;
    --le[i];
    le[i] = lower_bound(leaves.begin(), leaves.end(), le[i]) - leaves.begin();
    ri[i] = lower_bound(leaves.begin(), leaves.end(), ri[i]) - leaves.begin();
    assert(ri[i] > le[i]);
    que[v].push_back(i);
  }
  len = leaves.size();
  build();
  dfs2(0);
  for (int i = 0; i < q; ++i)
    printf("%lld\n", ans[i]);
  return 0;
}