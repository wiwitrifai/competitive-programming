#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
vector< int > adj[N];
int w[N], par[N], st[N], en[N], cntr, node[N];
int n, q;

void dfs(int v) {
  node[cntr] = v;
  st[v] = cntr++;
  for (int u : adj[v]) if (u != par[v]) {
    par[u] = v;
    dfs(u);
  }
  en[v] = cntr;
}

long long sum[N << 2], laz[N << 2];
void build(int id = 1, int l = 0, int r = n) {
  laz[id] = 0;
  if (r-l < 2) {
    sum[id] = w[node[l]];
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
  sum[id] = sum[il] + sum[ir];
}
void upd(int id, int l, int r, long long val) {
  laz[id] += val;
  sum[id] += val * (r-l);
}
void shift(int id, int l, int r) {
  if (!laz[id])
    return;
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  upd(il, l, mid, laz[id]);
  upd(ir, mid, r, laz[id]);
  laz[id] = 0;
}
void update(int x, int y, long long val, int id = 1, int l = 0, int r = n) {
  if (x >= r || y <= l) return;
  if (x <= l && r <= y) {
    upd(id, l, r, val);
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  shift(id, l, r);
  update(x, y, val, il, l, mid);
  update(x, y, val, ir, mid, r);
  sum[id] = sum[il] + sum[ir];
}
long long get(int x, int y, int id = 1, int l = 0, int r = n) {
  if (x >= r || y <= l) return 0;
  if (x <= l && r <= y) {
    return sum[id];
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  shift(id, l, r); 
  return get(x, y, il, l, mid) + get(x, y, ir, mid, r);
}

// Subtask #1
const int NS = 2017;
set< int > child[NS];
long long ww[NS];
void add(int v, long long val) {
  ww[v] += val;
  for (int u : child[v]) {
    add(u, val);
  }
}
long long get(int v) {
  long long ret = ww[v];
  for (int u : child[v]) {
    ret += get(u);
  }
  return ret;
}
void solve1() {
  for (int i = 0; i < n; i++) {
    for (int u : adj[i]) if (u != par[i]) {
      child[i].insert(u);
    }
    ww[i] = w[i];
  }
  while (q--) {
    int t, u, v;
    scanf("%d %d", &t, &u);
    u--;
    if (t == 1) {
      printf("%lld\n", get(u));
      continue;
    }
    scanf("%d", &v);
    if (t == 2) {
      add(u, v);
    }
    else {
      v--;
      bool ok = true;
      int now = v;
      while (now != u && now) {
        now = par[now];
      }
      if (now == u)
        ok = false;
      now = u;
      while (now != v && now) {
        now = par[now];
      }
      if (now == v)
        ok = false;
      if (ok) {
        child[par[u]].erase(u);
        child[par[v]].erase(v);
        swap(par[u], par[v]);
        child[par[u]].insert(u);
        child[par[v]].insert(v);
      }
      else
        puts("-1");
    }
  }
}

int main() {
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; i++) {
    scanf("%d", w+i);
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  cntr = 0;
  dfs(0);
  if (n <= 1000) {
    solve1();
    return 0;
  }
  build();
  while (q--) {
    int t, u, v;
    scanf("%d %d", &t, &u);
    u--;
    if (t == 1) {
      printf("%lld\n", get(st[u], en[u]));
      continue;
    }
    scanf("%d", &v);
    update(st[u], en[u], v);
  }
  return 0;
}