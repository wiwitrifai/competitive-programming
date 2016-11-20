#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5, LOG = 20;

vector< int > adj[N];
int beg[N], en[N], flat[N], p[LOG][N], cntr, sz[N], sec[N];
bool ancestor(int v, int u) {
  return beg[v] <= beg[u] && en[u] <= en[v];
}
void dfs(int u, int par, int sector) {
  sec[u] = sector;
  beg[u] = cntr;
  flat[cntr++] = u;
  for (int i = 0; i + 1 < LOG; i++) {
    p[i+1][u] = p[i][p[i][u]];
  }
  sz[u] = !adj[u].size();
  for (int v : adj[u]) {
    p[0][v] = u;
    dfs(v, u, sector);
    sz[u] += sz[v];
  }
  en[u] = cntr;
  flat[cntr++] = ~u;
}

int lca(int u, int v) {
  for (int i = LOG-1; i >= 0; i--) if (!ancestor(p[i][u], v)) {
    u = p[i][u];
  }
  if (ancestor(u, v))
    return u;
  return p[0][u];
}

int cnt[N], bs[N];
set < int > st[N];

int main() {
  freopen("gangsters.in", "r", stdin);
  freopen("gangsters.out", "w", stdout);

  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 1; i < n; i++) {
    int par;
    scanf("%d", &par);
    par--;
    adj[par].push_back(i);
  }
  cntr = 0;
  sz[0] = 1;
  beg[0] = cntr;
  flat[cntr++] = 0;
  for (int u : adj[0]) {
    dfs(u, 0, u);
    sz[0] += sz[u];
  }
  en[0] = cntr;
  flat[cntr++] = 0;
  int ans = 0, ans1 = 0;
  memset(cnt, 0, sizeof cnt);
  while (q--) {
    char s[10];
    int v;
    scanf("%s %d", s, &v);
    v--;
    int u = sec[v];
    ans -= cnt[u];
    // cerr << cnt[u] << " ";
    if (s[0] == '+') {
      if (st[u].empty())
        ans1++;
      st[u].insert(beg[v]);
      auto it = st[u].begin(), it2 = --st[u].end();
      int aa = lca(flat[*it], flat[*it2]);
      // cerr << "lca " << flat[*it] << " " << flat[*it2] << " " << aa << endl;
      cnt[u] = sz[aa] - (int)st[u].size();
    }
    else {
      st[u].erase(beg[v]);
      if (st[u].empty())
        ans1--;
      if (!st[u].empty()) {
        auto it = st[u].begin(), it2 = --st[u].end();
        int aa = lca(flat[*it], flat[*it2]);
        cnt[u] = sz[aa] - (int)st[u].size();
      }
      else
        cnt[u] = 0;
    }
    // cerr << cnt[u] << endl;
    ans += cnt[u];
    printf("%d %d\n", ans1, ans);
  }
  return 0;
}