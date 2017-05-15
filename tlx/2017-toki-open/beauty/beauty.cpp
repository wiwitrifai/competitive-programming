#include "beauty.h"

#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
int n, comp[N], num[N], low[N], cntr, nc, xr[N], art[N], to[N], val[N], lv[N];
vector< int > g[N], ad[N], ed;
bool used[N];

void dfs(int v, int par = -1) {
  num[v] = low[v] = cntr++;
  int child = 0;
  for (int i : ad[v]) {
    int u = xr[i] ^ v;
    if (num[u] == -1){
      child++;
      ed.push_back(i), used[i] = 1;
      dfs(u, i);
      low[v] = min(low[v], low[u]);
      if (par == -1 && child > 1) {
        art[v] = 1;
        comp[i] = nc;
        while (!ed.empty()) {
          int j = ed.back();
          ed.pop_back();
          comp[j] = nc;
          if (j == i) break;
        }
        nc++;
      }
      if (par != -1 && low[u] >= num[v]) {
        art[v] = 1;
        comp[i] = nc;
        while (!ed.empty()) {
          int j = ed.back();
          ed.pop_back();
          comp[j] = nc;
          if (j == i) break;
        }
        nc++;
      }
    }
    else {
      if (i != par && num[u] < low[v])
        low[v] = num[u], ed.push_back(i);
    }
  }
}
int sp[19][N], p[19][N];

void dfs2(int v = 0, int par = -1) {
  lv[v] = par == -1 ? 0 : lv[par] + 1;
  p[0][v] = par == -1 ? v : par;
  sp[0][v] = max(val[v], val[p[0][v]]);
  for (int i = 0; i < 18; i++) {
    p[i+1][v] = p[i][p[i][v]];
    sp[i+1][v] = max(sp[i][v], sp[i][p[i][v]]);
  }
  for (int u : g[v]) if (u != par)
    dfs2(u, v);
}

std::vector<int> getMaximumBeauty(int N, int M, int Q, std::vector<int> T,
    std::vector<int> U, std::vector<int> V,
    std::vector<int> A, std::vector<int> B) {
  n = N;
  for (int i = 0; i < n; i++) ad[i].clear();
  for (int i = 0; i < ::N; i++) g[i].clear();
  memset(num, -1, sizeof num);
  for (int i = 0; i < U.size(); i++) {
    U[i]--; V[i]--;
    ad[U[i]].push_back(i);
    ad[V[i]].push_back(i);
    xr[i] = U[i] ^ V[i];
  }
  cntr = nc = 0;
  memset(comp, -1, sizeof comp);
  for (int i = 0; i < n; i++) {
    if (num[i] != -1) continue;
    ed.clear();
    dfs(i, -1);
    if (!ed.empty()) {
      while (!ed.empty()) {
        int j = ed.back();
        ed.pop_back();
        comp[j] = nc;
      }
      nc++;
    }
  }
  memset(to, -1, sizeof to);
  for (int i = 0; i < M; i++) {
    if (comp[i] == -1) continue;
    val[comp[i]] = max(val[comp[i]], max(T[U[i]], T[V[i]]));
    if (!art[U[i]]) {
      to[U[i]] = comp[i];
    }
    if (!art[V[i]]) {
      to[V[i]] = comp[i];
    }
  }
  for (int i = 0; i < n; i++) {
    if (art[i]) {
      to[i] = nc;
      val[nc] = T[i];
      for (int j : ad[i]) {
        if (comp[j] == -1) continue;
        g[nc].push_back(comp[j]);
        g[comp[j]].push_back(nc);
      }
      nc++;
    }
  }
  for (int i = 0; i < nc; i++) {
    sort(g[i].begin(), g[i].end());
    g[i].erase(unique(g[i].begin(), g[i].end()), g[i].end());
  }
  dfs2(0);
  std::vector<int> ans;
  for (int i = 0; i < Q; i++) {
    A[i]--; B[i]--;
    int u = A[i], v = B[i];
    u = to[u], v = to[v];
    int cans = val[u], val[v];
    if (lv[u] > lv[v]) swap(u, v);
    int diff = lv[v] - lv[u];
    for (int j = 0; j < 19; j++) if (diff & (1<<j))
      cans = max(cans, sp[j][v]), v = p[j][v];
    if (u != v) {
      for (int j = 18; j >= 0; j--) if (p[j][u] != p[j][v]) {
        cans = max(cans, max(sp[j][u], sp[j][v]));
        u = p[j][u], v = p[j][v];
      }
      cans = max(cans, max(sp[0][u], sp[0][v]));
    }
    ans.push_back(cans);
  }
  return ans;
}