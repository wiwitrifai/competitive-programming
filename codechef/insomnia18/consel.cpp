#include <bits/stdc++.h>

using namespace std;

const int N = 5e6 + 6;

vector<int> g[N], adj[N];
int nodes, n, val[N];

long long extended(long long a, long long b, long long & x, long long & y) {
  if(b == 0) { x = 1; y = 0; return a; } 
  long long d = extended(b, a % b, x, y); 
  long long xx, yy;
  xx = y;
  yy = x - (a/b)*y;
  x = xx; y = yy;
  return d;
}

long long inverse(long long a, long long m) {
  long long x, y;
  long long d = extended(a, m, x, y);
  if (d != 1) return -1;
  x %= m;
  if (x < 0) x += m;
  return x;
}

int last[N];
vector<pair<int, int> > upd[N];
vector<int> fac[N];

void dfs(int v, int par = -1) {
  adj[v].push_back(4 * n + v);
  adj[v].push_back(5 * n + v);
  for (int d : fac[val[v]]) {
    int p = last[d];
    if (p != -1) {
      adj[4 * n + p].push_back(n + v);
      adj[5 * n + v].push_back(n + p);
      adj[4 * n + p].push_back(4 * n + v);
      adj[5 * n + v].push_back(5 * n + p);
    }
    upd[v].emplace_back(d, p);
    last[d] = v;
  }
  for (int u : g[v]) if (u != par) {
    dfs(u, v);
  }
  for (auto it : upd[v]) {
    last[it.first] = it.second;
  }
  upd[v].clear();
}
int pr[N];

/****** Tarjan’s SCC *******/
vector< int > num, low, S, vis, cc;
int cntr, numCC;

void tarjan(int v) {
  low[v] = num[v] = ++cntr;
  vis[v] = 1;
  S.push_back(v);
  for(auto u : adj[v]) {
    if(num[u] == -1)
      tarjan(u);
    if(vis[u])
      low[v] = min(low[v], low[u]);
  }
  if(low[v] == num[v]) {
    while(1) {
      int u = S.back(); S.pop_back(); vis[u] = 0;
      cc[u] = numCC;
      if(u == v)
        break;
    }
    ++numCC;
  }
}

vector<int> boomerang[N];

int main() {
  int M = 2e5 + 5;
  for (int i = 2; i < M; ++i) if (pr[i] == 0) {
    for (int j = i; j < M; j += i) {
      pr[j] = i;
      fac[j].push_back(i);
    }
  } 
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < 6 * n; ++i)
      adj[i].clear();
    for (int i = 0; i < n; ++i) {
      scanf("%d", val+i);
      g[i].clear();
      upd[i].clear();
      last[i] = -1;
      boomerang[i].clear();
    }
    for (int i = 1; i < n; ++i) {
      int u, v;
      scanf("%d %d", &u, &v); --u, --v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) {
      adj[i].push_back(2 * n + val[i]);
      adj[n+i].push_back(3 * n + val[i]);
      long long v = inverse(val[i], n);
      if (v == -1) continue;
      if (v == val[i]) {
        boomerang[v].push_back(i);
        continue;
      }
      adj[2 * n + v].push_back(i+n);
      adj[3 * n + v].push_back(i);
    }
    bool ok = 1;
    for (int i = 0; i < n; ++i) {
      if (boomerang[i].size() > 2) {
        ok = 0;
        break;
      }
      else if (boomerang[i].size() == 2) {
        int u = boomerang[i][0], v = boomerang[i][1];
        adj[u].push_back(v+n);
        adj[u+n].push_back(v);
        adj[v].push_back(u+n);
        adj[v+n].push_back(u);
      }
    }
    if (!ok) {
      puts("No");
      continue;
    }
    dfs(0);
    num.assign(6*n, -1);
    low.assign(6*n, -1);
    vis.assign(6*n, 0);
    cc.assign(6*n, 0);
    cntr = numCC = 0;
    for (int i = 0; i < 6 * n; ++i) {
      if (num[i] != -1) continue;
      tarjan(i);
    }
    for (int i = 0; i < n; ++i) {
      ok &= (cc[i] != cc[i+n]);
    }
    puts(ok ? "Yes" : "No");
  }
  return 0;
}