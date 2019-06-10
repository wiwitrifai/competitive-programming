#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int sz[N], bg[N];
int pos[N], comp[N];

int nxt[N], ncomp = 0;
vector<int> g[N], elem[N];
set<pair<int, int>> seg[N];

void get_sz(int v, int par = -1) {
  sz[v] = 1;
  bg[v] = -1;
  for (int u: g[v]) {
    if (u == par) continue;
    get_sz(u, v);
    sz[v] += sz[u];
    if (bg[v] == -1 || sz[bg[v]] < sz[u])
      bg[v] = u;
  }
}

void hld(int v, int par = -1) {
  comp[v] = ncomp;
  pos[v] = elem[ncomp].size();
  elem[ncomp].push_back(v);
  if (bg[v] != -1)
    hld(bg[v], v);
  for (int u : g[v]) {
    if (u == par || u == bg[v]) continue;
    ++ncomp;
    nxt[ncomp] = v;
    hld(u, v);
  }
}
int cnt[N];
int num[N];

void add(int col, int v) {
  if (v == 0 || col == 0) return;
  --num[cnt[col]];
  cnt[col] += v;
  ++num[cnt[col]];
}


int main() {
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  get_sz(0);
  nxt[0] = -1;
  hld(0);
  ++ncomp;
  for (int i = 0; i < ncomp; ++i) {
    seg[i].insert(make_pair(0, 0));
    seg[i].insert(make_pair((int)elem[i].size()+1, 0));
  }
  num[0] = m;
  while (q--) {
    int u, c, x;
    scanf("%d %d %d", &u, &c, &x);
    --u;
    while (u >= 0) {
      int p = pos[u];
      int h = comp[u];
      int last = seg[h].begin()->second, from = 0;
      while (!seg[h].empty()) {
        auto it = seg[h].begin();
        if (it->first <= p+1) {
          add(last, from - it->first);
          from = it->first;
          last = it->second;
          seg[h].erase(it);
        }
        else {
          add(last, from - (p+1));
          if (p+1 < it->first) {
            seg[h].insert(make_pair(p+1, last));
          }
          break;
        }
      }
      seg[h].insert(make_pair(0, c));
      add(c, p+1);
      u = nxt[h];
    }
    add(c, -1);
    printf("%d\n", num[x]);
    add(c, 1);
  }
  return 0;
}
