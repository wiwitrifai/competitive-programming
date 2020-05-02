#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, LN= 18;


vector< int > adj[N];
int par[LN][N], lv[N], le[N], ri[N], counter, node[N];

void dfs(int v) {
  node[counter] = v;
  le[v] = counter++;
  if (par[0][v] != v)
    lv[v] = lv[par[0][v]] + 1;
  for (int i = 0; i+1 < LN; i++)
    par[i+1][v] = par[i][par[i][v]];
  for (int u : adj[v]) if (u != par[0][v]) {
    par[0][u] = v;
    dfs(u);
  }
  ri[v] = counter;
}
int ancestor(int v, int lev) {
  if (lev > lv[v])
    return -1;
  int d = lv[v] - lev;
  for (int i = 0; i < LN; i++)
    if (d & (1<<i))
      v = par[i][v];
  return v;
}
int lca(int u, int v) {
  if (lv[u] > lv[v])
    swap(u, v);
  v = ancestor(v, lv[u]);
  if (v == u)
    return u;
  for (int i = LN-1; i >= 0; i--)
    if (par[i][v] != par[i][u])
      u = par[i][u], v = par[i][v];
  return par[0][v];
}
int dist(int u, int v) {
  return lv[u] + lv[v] - 2 * lv[lca(u, v)];
}
bool isanc(int u, int v) {
  return le[v] <= le[u] && ri[u] <= ri[v];
}
pair< int, int > center(int u, int v) {
  int d = dist(u, v);
  pair< int, int > ret;
  int mid = (d-1)/2;
  if (lv[u] > lv[v]) {
    ret.first = ancestor(u, lv[u]-mid);
    ret.second = par[0][ret.first];
  }
  else {
    ret.second = ancestor(v, lv[v]-mid);
    ret.first = par[0][ret.second];
  }
  return ret;
}

int a[N << 2], lz[N << 2], mark[N << 2], n;
void build(int id = 1, int l = 0, int r = n) {
  lz[id] = 0;
  mark[id] = 1;
  if (r-l < 2) {
    a[id] = lv[node[l]];
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
  a[id] = max(a[il], a[ir]);
}
void shift(int id) {
  int il = id << 1, ir = il | 1;
  if (lz[id]) {
    a[il] += lz[id];
    lz[il] += lz[id];
    a[ir] += lz[id];
    lz[ir] += lz[id];
    lz[id] = 0;
  }
  if (mark[id]) {
    mark[il] = mark[id];
    mark[ir] = mark[id];
  }
}
void update1(int x, int y, int val, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    a[id] += val;
    lz[id] += val;
    return;
  }
  shift(id);
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  update1(x, y, val, il, l, mid);
  update1(x, y, val, ir, mid, r);
  a[id] = 0;
  if (mark[id] == 0) {
    if (mark[il] != -1)
      a[id] = max(a[id], a[il]);
    if (mark[ir] != -1)
      a[id] = max(a[id], a[ir]);
  }
  else
    a[id] = max(a[il], a[ir]);
}
void update2(int x, int y, int mrk, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y && mark[id] != 0) {
    mark[id] = mrk;
    return;
  }
  shift(id);
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  update2(x, y, mrk, il, l, mid);
  update2(x, y, mrk, ir, mid, r);
  if (mark[il] == 1 && mark[ir] == 1)
    mark[id] = 1;
  else if (mark[il] == -1 && mark[ir] == -1)
    mark[id] = -1;
  else
    mark[id] = 0;
  if (mark[id] == 0) {
    a[id] = 0;
    if (mark[il] != -1)
      a[id] = max(a[id], a[il]);
    if (mark[ir] != -1)
      a[id] = max(a[id], a[ir]);
  }
  else
    a[id] = max(a[il], a[ir]);
}
int get(int x, int y, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return 0;
  if (x <= l && r <= y)
    return mark[id] == -1 ? 0 : a[id];
  shift(id);
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  return max(get(x, y, il, l, mid), get(x, y, ir, mid, r));
}
int ans[N];
struct query {
  int id, n;
  pair< int, int > a[5];
  query(int n = 0) : n(n) {
  } 
  void add(pair<int, int> v) {
    this->a[this->n++] = v;
  }
};
query tque[5];
int tv[5];
vector< query > que[N];
void dfs2(int v) { 
  for (query qe : que[v]) {
    update2(0, n, 1);
    pair< int, int > up(-1, -1);
    for (int i = 0; i < qe.n; i++) {
      if (isanc(v, qe.a[i].second)) {
        if (up.second == -1 || isanc(qe.a[i].second, up.second))
          up = qe.a[i];
      }
    }
    if (up.second != -1) {
      update2(0, n, -1);
      update2(le[up.first], ri[up.first], +1);
    }
    else
      update2(0, n, +1);
    for (int i = 0; i < qe.n; i++) {
      if (!isanc(v, qe.a[i].second)) {
        update2(le[qe.a[i].second], ri[qe.a[i].second], -1);
      }
    }
    ans[qe.id] = max(ans[qe.id], get(0, n));
  }
  for (int u : adj[v]) if (u != par[0][v]) {
    update1(0, n, +1);
    update1(le[u], ri[u], -2);
    dfs2(u);
    update1(le[u], ri[u], +2);
    update1(0, n, -1);
  }
}

int main() {
  int q;
  scanf("%d %d", &n, &q);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  par[0][0] = 0;
  dfs(0);
  for (int i = 0; i < q; i++) {
    ans[i] = 0;
    int k;
    scanf("%d", &k);
    for (int j = 0; j < k; j++) {
      scanf("%d", tv+j);
      tv[j]--;
      tque[j].id = i;
      tque[j].n = 0;
    }
    sort(tv, tv+k);
    k = unique(tv, tv+k) - tv;
    for (int j = 0; j < k; j++) {
      for (int z = j+1; z < k; z++) {
        pair< int, int > res = center(tv[j], tv[z]);
        tque[j].add(res);
        swap(res.first, res.second);
        tque[z].add(res);
      }
      que[tv[j]].push_back(tque[j]);
    }
  }
  build();
  update2(0, n, -1);
  update2(0, n, +1);
  dfs2(0);
  for (int i = 0; i < q; i++)
    printf("%d\n", ans[i]);
  return 0;
}