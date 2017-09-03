#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector< int > g[N];
int c[N], fr[N], to[N], par[19][N], cur, n, q, lv[N], node[N];
bool on[N];
set<int> st[N];

void dfs(int v = 0) {
  node[cur] = v;
  fr[v] = cur++;
  for (int i = 0; i < 18; i++)
    par[i+1][v] = par[i][par[i][v]];
  for (int u : g[v]) {
    lv[u] = lv[v] + 1;
    dfs(u);
  }
  to[v] = cur;
}

long long bit[N];
long long get(int x) {
  long long ret = 0;
  for (; x; x -= x&-x)
    ret += bit[x];
  return ret; 
}
void upd(int x, long long val) {
  for (; x <= n; x += x&-x)
    bit[x] += val;
}
int lca(int u, int v) {
  if (lv[u] > lv[v])
    swap(u, v);
  int diff = lv[v] - lv[u];
  for (int i = 0; i < 19; i++)
    if (diff & (1 << i))
      v = par[i][v];
  if (u == v)
    return u;
  for (int i = 18; i >= 0; i--)
    if (par[i][u] != par[i][v])
      u = par[i][u], v = par[i][v];
  return par[0][u];
}


int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &q);
    vector< int > vx;
    for (int i = 0; i < n; i++)
      scanf("%d", c+i), vx.push_back(c[i]);
    sort(vx.begin(), vx.end());
    vx.erase(unique(vx.begin(), vx.end()), vx.end());
    for (int i = 0; i < n; i++)
      c[i] = lower_bound(vx.begin(), vx.end(), c[i]) - vx.begin();
    for (int i = 0; i < n; i++) {
      g[i].clear();
      st[i].clear();
    }
    memset(par, -1, sizeof par);
    for (int i = 1; i < n; i++) {
      scanf("%d", par[0]+i);
      par[0][i]--;
      g[par[0][i]].push_back(i);
    }
    cur = 0;
    lv[0] = 0;
    par[0][0] = 0;
    dfs(0);
    memset(on, 0, sizeof on);
    for (int i = 0; i <= n; i++) bit[i] = 0;
    while (q--) {
      int u, v;
      scanf("%d %d", &u, &v);
      v--;
      if (u == 1) {
        int w = -1;
        if (on[v]) {
          st[c[v]].erase(fr[v]);
          upd(fr[v]+1, -vx[c[v]]);
          int z = -1;
          auto it = st[c[v]].lower_bound(fr[v]);
          if (it != st[c[v]].end()) {
            z = lca(v, node[*it]);
          }
          if (it != st[c[v]].begin()) {
            it--;
            int w = lca(v, node[*it]);
            if (z == -1 || lv[z] < lv[w])
              z = w;
          }
          if (z != -1)
            upd(fr[z]+1, vx[c[v]]);
        }
        else {
          upd(fr[v]+1, vx[c[v]]);
          int z = -1;
          auto it = st[c[v]].lower_bound(fr[v]);
          if (it != st[c[v]].end()) {
            z = lca(v, node[*it]);
          }
          if (it != st[c[v]].begin()) {
            it--;
            int w = lca(v, node[*it]);
            if (z == -1 || lv[z] < lv[w])
              z = w;
          }
          if (z != -1)
            upd(fr[z]+1, -vx[c[v]]);
          st[c[v]].insert(fr[v]);
        }
        on[v] ^= 1;
      }
      else {
        printf("%lld\n", get(to[v]) - get(fr[v]));
      }
    }
  }
  return 0;
}