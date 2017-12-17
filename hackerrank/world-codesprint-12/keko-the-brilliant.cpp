#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, inf = 1e9 + 7;

struct seg_tree {
  vector<int> mi, lz, lmi;
  vector<int> val;
  int n;
  seg_tree(vector<int> val) : val(val) {
    n = val.size();
    for (int i = 0; i+1 < val.size(); ++i)
      assert(val[i] < val[i+1]);
    mi.resize(n << 2);
    lz.resize(n << 2);
    lmi.resize(n << 2);
    build(1, 0, n);
  }
  int idx(int x) {
    return lower_bound(val.begin(), val.end(), x) - val.begin();
  }
  inline void build(int id, int l, int r) {
    mi[id] = 0;
    lz[id] = 0;
    lmi[id] = inf;
    if (r-l < 2)
      return;
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    build(il, l, mid);
    build(ir, mid, r);
  }

  inline void push(int id) {
    int il = id << 1, ir = il | 1;
    if (lz[id] != 0) {
      mi[il] += lz[id];
      mi[ir] += lz[id];
      lz[il] += lz[id];
      lz[ir] += lz[id];
      lmi[il] += lz[id];
      lmi[ir] += lz[id];
      lz[id] = 0;
    }
    if (lmi[id] < inf) {
      mi[il] = min(lmi[id], mi[il]);
      mi[ir] = min(lmi[id], mi[ir]);
      lmi[il] = min(lmi[id], lmi[il]);
      lmi[ir] = min(lmi[id], lmi[ir]);
      lmi[id] = inf;
    }
  }
  inline void update(int x, int y, int v, int id, int l, int r) {
    if (x >= r || l >= y) return;
    if (x <= l && r <= y) {
      lmi[id] += v;
      mi[id] += v;
      lz[id] += v;
      return;
    }
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    push(id);
    update(x, y, v, il, l, mid);
    update(x, y, v, ir, mid, r);
    mi[id] = min(mi[il], mi[ir]);
  }
  inline void update2(int x, int y, int v, int id, int l, int r) {
    if (x >= r || l >= y) return;
    if (x <= l && r <= y) {
      mi[id] = min(v, mi[id]);
      lmi[id] = min(v, lmi[id]);
      return;
    }
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    push(id);
    update2(x, y, v, il, l, mid);
    update2(x, y, v, ir, mid, r);
    mi[id] = min(mi[il], mi[ir]);
  }
  int get(int x, int id, int l, int r) {
    if (r-l < 2)
      return mi[id];
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    push(id);
    if (x < mid)
      return get(x, il, l, mid);
    else
      return get(x, ir, mid, r);
  }
  int geti(int x) {
    return get(x, 1, 0, n);
  }
  inline void add(int x, int y, int v) {
    update(x, y, v, 1, 0, n);
  }
  inline void cmp(int x, int y, int v) {
    update2(x, y, v, 1, 0, n);
  }
};

vector<int> g[N];
seg_tree * seg[N];
int n, a[N], sz[N];

inline void getSize(int v, int par = -1) {
  sz[v] = 1;
  for (int u : g[v]) if (u != par) {
    getSize(u, v);
    sz[v] += sz[u];
  }
}

vector<int> val;
inline void getVal(int v, int par = -1) {
  val.push_back(a[v]);
  for (int u : g[v]) if (u != par) {
    getVal(u, v);
  }
}

int bg[N];
inline void dfs(int v, int par = -1) {
  bg[v] = -1;
  for (int u : g[v]) if (u != par) {
    if (bg[v] == -1 || sz[u] > sz[bg[v]])
      bg[v] = u;
  }

  if (bg[v] == -1) {
    seg[v]->add(seg[v]->idx(a[v]) + 1, seg[v]->n, 1);
    return;
  }

  for (int u : g[v]) {
    if (u == par || u == bg[v]) continue;
    val.clear();
    getVal(u, v);
    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end());
    seg[u] = new seg_tree(val);
    dfs(u, v);
  }

  seg[bg[v]] = seg[v];
  dfs(bg[v], v);
  for (int u : g[v]) {
    if (u == par || u == bg[v]) continue;
    int now = 0, last = 0;
    for (int i = 0; i < seg[u]->n; ++i) {
      int cur = seg[u]->geti(i);
      int id = seg[v]->idx(seg[u]->val[i]);
      seg[v]->add(now, id+1, cur);
      now = id + 1;
      last = cur;
    }
    seg[v]->add(now, seg[v]->n, sz[u]);
  }
  int id = seg[v]->idx(a[v]);
  seg[v]->add(0, id, 1);
  seg[v]->add(id+1, seg[v]->n, 1);
  int vcur = seg[v]->geti(id);
  seg[v]->cmp(0, id+1, vcur);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  for (int i = 0; i < n-1; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  getSize(0);
  cerr << sz[0] << endl;
  val.clear();
  getVal(0);
  sort(val.begin(), val.end());
  val.erase(unique(val.begin(), val.end()), val.end());
  seg[0] = new seg_tree(val);
  dfs(0);
  assert(sz[0] == n);
  int ans = sz[0] - 1;
  int last = 0;
  for (int i = 0; i < seg[0]->n; ++i) {
    int cur = seg[0]->geti(i);
    ans = min(ans, cur);
    last = cur;
  }
  printf("%d\n", ans);
  return 0;
}