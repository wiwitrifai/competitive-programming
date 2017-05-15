#include "radius.h"

#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5, inf = 1e9 + 7;
int seg[N << 2], n;
void build(int id = 1, int l = 0, int r = n) {
  seg[id] = -inf;
  if (r-l < 2) return;
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
}
void upd(int x, int v, int id = 1, int l = 0, int r = n) {
  if (r-l < 2) {
    seg[id] = v;
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  if (x < mid)
    upd(x, v, il, l, mid);
  else
    upd(x, v, ir, mid, r);
  seg[id] = max(seg[il], seg[ir]);
}
int get(int x, int y, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return -inf;
  if (x <= l && r <= y) return seg[id];
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  return max(get(x, y, il, l, mid), get(x, y, ir, mid, r));
}
vector< int > g[N];
int ans[N];
vector< int > cur;
int lv[N], mlv[N], sib[N];
void pre(int v, int par = -1) {
  lv[v] = par == -1 ? 0 : lv[par] + 1;
  mlv[v] = lv[v];
  for (int u : g[v]) if (u != par)
    pre(u, v), mlv[v] = max(mlv[v], mlv[u]);
  sib[v] = 0;
  int now = lv[v];
  for (int u : g[v]) if (u != par) {
    sib[u] = max(now, sib[u]);
    now = max(now, mlv[u]);
  }
  now = lv[v];
  for (int i = (int)g[v].size()-1; i >= 0; i--) {
    int u = g[v][i];
    if (u == par) continue;
    sib[u] = max(now, sib[u]);
    now = max(now, mlv[u]);
  }
  ans[v] = mlv[v]-lv[v] + (v != 0);
}

void dfs(int v, int par = -1, int val = 0, int id = 0) {
  while (id <= lv[v]/2 && id < cur.size()) val = max(val, cur[id]+2 * id), id++;
  ans[v] = max(ans[v], max(val, 1 + lv[v] + get(lv[v]/2 + 1, lv[v])));
  for (int u : g[v]) if (u != par) {
    int nval = val;
    cur.push_back(sib[u]-2*lv[v]);
    upd(lv[v], cur.back());
    dfs(u, v, nval, id);
    upd(lv[v], -inf);
    cur.pop_back();
  }
}


std::vector<int> getRadius(int N, int Q,
    std::vector<int> U, std::vector<int> V, std::vector<int> A) {
  n = N;
  for (int i = 0; i < n; i++) g[i].clear();
  for (int i = 0; i < N-1; i++) {
    U[i]--; V[i]--;
    g[U[i]].push_back(V[i]);
    g[V[i]].push_back(U[i]);
  }
  build();
  pre(0);
  cur.clear();
  dfs(0);
  std::vector<int> ans;
  for (int i = 0; i < Q; i++)
    ans.push_back(::ans[A[i]-1]);
  return ans;
}
