#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int vis[N], match[N], matched[N], n;
vector<int> g[N];
int ma[N << 2], mi[N << 2], lz[N << 2];

void build(int id = 1, int l = 0, int r = n) {
  ma[id] = mi[id] = lz[id] = 0;
  if (r-l < 2) {
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
}

inline void upd(int id, int val) {
  ma[id] += val; 
  mi[id] += val;
  lz[id] += val;
}
inline void push(int id, int il, int ir) {
  if (lz[id] == 0) return;
  upd(il, lz[id]);
  upd(ir, lz[id]);
  lz[id] = 0;
}

inline void update(int x, int y, int z, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    upd(id, z);
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  push(id, il, ir);
  update(x, y, z, il, l, mid);
  update(x, y, z, ir, mid, r);
  mi[id] = min(mi[il], mi[ir]);
  ma[id] = max(ma[il], ma[ir]);
}

inline void get(vector<int> & ve, int id = 1, int l = 0, int r = n) {
  if (ma[id] == 0) return;
  if (mi[id] > 0) {
    for (int i = l; i < r; ++i)
      ve.push_back(i);
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  push(id, il, ir);
  get(ve, il, l, mid);
  get(ve, ir, mid, r);
}

vector<int> visited;

int dfs(int u) {
  if (vis[u]) return false;
  vis[u] = 1;
  visited.push_back(u);
  for (int v : g[u]) if (match[v] == -1 || dfs(match[v]))
    return match[v] = u, matched[u] = v, true;
  return false;
}

void konig(int u) {
  if (vis[u]) return;
  vis[u] = 1;
  for (int v : g[u]) if (match[v] != -1)
    konig(match[v]);
}

vector<pair<int, int> > rem[N], add[N];

int main() {
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    ++c, ++d;
    add[a].emplace_back(b, d);
    rem[c].emplace_back(b, d);
  }
  n = 3e5;
  vector<int> vu;
  for (int i = 0; i < n; ++i) {
    for (auto it : add[i])
      update(it.first, it.second, +1);
    for (auto it : rem[i])
      update(it.first, it.second, -1);
    g[i].clear();
    get(g[i]);
    if (g[i].size())
      vu.push_back(i);
  }
  memset(match, -1, sizeof match);
  memset(matched, -1, sizeof matched);
  vector<int> all = vu;
  while(true) {
    bool fnd = false;
    for(int u : vu) if(matched[u] == -1 && !vis[u])
      fnd |= dfs(u);
    for (int u : visited)
      vis[u] = 0;
    visited.clear();
    vector<int> vv;
    for (int u : vu) if (matched[u] == -1)
      vv.push_back(u);
    vu.swap(vv);
    if(!fnd)
      break;
  }
  for (int u : vu)
    konig(u);
  vector<int> colomn, row;
  for (int u : all) {
    if (matched[u] == -1) continue;
    if (vis[u])
      row.push_back(matched[u]);
    else
      colomn.push_back(u);
  }
  printf("%d\n", row.size() + colomn.size());
  printf("%d\n", colomn.size());
  for (int i = 0; i < colomn.size(); ++i) {
    if (i)
      printf(" ");
    printf("%d", colomn[i]);
  }
  printf("\n");
  printf("%d\n", row.size());
  for (int i = 0; i < row.size(); ++i) {
    if (i)
      printf(" ");
    printf("%d", row[i]);
  }
  printf("\n");
  return 0;
}