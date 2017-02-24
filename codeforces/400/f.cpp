#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], b[N], ans[N], sz[N], to[N], id[N];
vector< int > edge[N], used[N];
vector< int > vtx[N], adj[N];
bool alive[N];
void getsz(int v, int par = -1) {
  if (!alive[v]) return;
  sz[v] = 1;
  to[v] = -1;
  for (int u : adj[v]) if (par != u && alive[u]) {
    getsz(u, v);
    sz[v] += sz[u];
    if (to[v] == -1 || sz[to[v]] < sz[u])
      to[v] = u;
  }
}
void solve(int v, int col) {
  if (!alive[v]) return;
  getsz(v);
  int mid = v;
  int szall = sz[v];
  while (to[mid] != -1 && 2 * sz[to[mid]] >= szall)
    mid = to[mid];
  alive[mid] = 0;
  ans[mid] = col;
  for (int u : adj[mid])
    solve(u, col+1);
}

bool cmp(int l, int r) {
  return vtx[l] < vtx[r];
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", a+i, b+i);
    a[i]--; b[i]--;
    edge[a[i]].push_back(b[i]);
    edge[b[i]].push_back(a[i]);
  }
  for (int i = 0; i < n; i++) {
    int u = i, v = (i + 1) % n;
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  for (int i = 0; i < n; i++) {
    sort(edge[i].begin(), edge[i].end());
    used[i].assign(edge[i].size(), 0);
  }
  int reg = -1;
  map< pair< int, int >, int > mp;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < edge[i].size(); j++) {
      if (used[i][j]) continue;
      int v = i, to = j;
      vector< int > ver;
      while (!used[v][to]) {
        ver.push_back(v);
        used[v][to] = 1;
        int tv = edge[v][to], tto = lower_bound(edge[tv].begin(), edge[tv].end(), v) - edge[tv].begin();
        tto = (tto + 1) % edge[tv].size();
        v = tv;
        to = tto;
      }
      if (reg == -1) {
        reg++;
        continue;
      }
      for (int z = 0; z < ver.size(); z++) {
        int u = ver[z], v = ver[(z+1) % ver.size()];
        if (u > v)
          swap(u, v);
        pair< int, int > now(u, v);
        if (mp.count(now)) {
          int nod = mp[now];
          adj[nod].push_back(reg);
          adj[reg].push_back(nod);
        }
        else
          mp[now] = reg;
      }
      sort(ver.rbegin(), ver.rend());
      vtx[reg] = ver;
      reg++;
    }
  }
  memset(alive, 1, sizeof alive);
  solve(0, 1);
  for (int i = 0; i < reg; i++)
    id[i] = i;
  sort(id, id+reg, cmp);
  for (int i = 0; i < reg; i++)
    printf("%d ", ans[id[i]]);
  printf("\n");
  return 0;
}