#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, LN = 19;

struct rmq {
  int n, v;
  vector< int > val;
  rmq(int n) : n(n) {
    val.assign(n << 2, 0);
  }
  void upd(int x, int vv, int id, int l, int r) {
    if (r-l < 2) {
      val[id] = max(val[id], vv);
      return;
    }
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    if (x < mid)
      upd(x, vv, il, l, mid);
    else
      upd(x, vv, ir, mid, r);
    val[id] = max(val[il], val[ir]);
  }
  int get(int x, int y, int id, int l, int r) {
    if (x >= r || y <= l) return 0;
    if (x <= l && r <= y) return val[id];
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    return max(get(x, y, il, l, mid), get(x, y, ir, mid, r));
  }
  void update(int x, int vv) {
    if (x < 0)
      return;
    upd(x, vv, 1, 0, n);
  } 
  int maxx(int x) {
    if (x < 0)
      return get(0, n, 1, 0, n);
    return max(get(0, x, 1, 0, n), get(x+1, n, 1, 0, n));
  }
};
pair<int, int> que[3 * N];
vector< pair<int, int> > adj[N];
int sz[N], to[N], cntr, die[N];
vector< pair<int, rmq *> > sd[N];
vector< pair<pair<int, int>, pair<int, rmq *> > > vupd;

void getsz(int v, int p = -1) {
  sz[v] = 1;
  to[v] = -1;
  for (auto u : adj[v]) if (u.first != p && !die[u.first]) {
    getsz(u.first, v);
    sz[v] += sz[u.first];
    if (to[v] == -1 || sz[to[v]] < sz[u.first])
      to[v] = u.first;
  }
}

void dfs2(int v, int p, int no, rmq * rm, int noupd) {
  sd[v].emplace_back(no, rm);
  vupd.push_back({{noupd, no}, {v, rm}});
  for (auto u : adj[v]) if (u.first != p && !die[u.first])
    dfs2(u.first, v, no, rm, max(noupd, u.second));
}

void dfs(int v) {
  getsz(v);
  int tot = sz[v];
  int batas = tot / 2;
  while (to[v] != -1 && sz[to[v]] > batas) v = to[v];
  int cnt = 0;
  for (auto u : adj[v]) if (!die[u.first])
    cnt++;
  rmq * rm = new rmq(cnt);
  cnt = 0;
  rm->v = v;
  sd[v].emplace_back(-1, rm);
  for (auto u : adj[v]) if (!die[u.first]) {
    dfs2(u.first, v, cnt++, rm, u.second);
  }
  die[v] = 1;
  for (auto u : adj[v]) if (!die[u.first]) {
    dfs(u.first);
  }
}

int lv[N], sparse[LN][N << 2], node[N << 2], pos[N];

int lca(int a, int b) {
  a = pos[a];
  b = pos[b];
  if (a > b)
    swap(a, b);
  int len = b-a+1;
  int ln = 31 - __builtin_clz(len);
  a = sparse[ln][a];
  b = sparse[ln][b-(1<<ln)+1];
  return lv[a] < lv[b] ? a : b;
}

int dist(int a, int b) {
  int ab = lca(a, b);
  return lv[a] + lv[b] - 2 * lv[ab];
}

void dfs3(int v, int p = -1) {
  pos[v] = cntr;
  node[cntr++] = v;
  lv[v] = p < 0 ? 1 : lv[p] + 1;
  for (auto u : adj[v]) if (u.first != p) {
    dfs3(u.first, v);
    node[cntr++] = v;
  }
}

int p[N];
int find(int v) {
  return p[v] < 0 ? v : p[v] = find(p[v]);
}
bool merge(int u, int v) {
  if ((u = find(u)) == (v = find(v)))
    return false;
  if (p[u] < p[v])
    swap(u, v);
  p[v] += p[u];
  p[u] = v;
  return true;
}


int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < q; i++) {
    int t, x, y;
    scanf("%d %d", &t, &x);
    x--;
    if (t == 1) {
      scanf("%d", &y); y--;
      adj[x].emplace_back(y, i);
      adj[y].emplace_back(x, i);
      que[i] = {x, y};
    }
    else
      que[i] = {-1, x};
  }
  cntr = 0;
  memset(lv, -1, sizeof lv);
  for (int i = 0; i < n; i++) if (lv[i] == -1)
    dfs3(i);
  for (int i = 0; i < cntr; i++) {
    sparse[0][i] = node[i];
  }
  for (int i = 0; i + 1 < LN; i++) {
    for (int j = 0; j + (1<<(i+1)) <= cntr; j++) {
      int a = sparse[i][j], b = sparse[i][j+(1<<i)];
      sparse[i+1][j] = lv[a] < lv[b] ? a : b;
    }
  }
  cntr = 0;
  memset(die, 0, sizeof die);
  for (int i = 0; i < n; i++) if (!die[i])
    dfs(i);
  memset(p, -1, sizeof p);
  sort(vupd.begin(), vupd.end());
  int iupd = 0;
  for (int i = 0; i < q; i++) {
    if (que[i].first < 0) {
      int v = que[i].second;
      int ans = 0;
      for (auto it : sd[v])
        if (find(v) == find(it.second->v))
          ans = max(ans, dist(v, it.second->v) + it.second->maxx(it.first));
      printf("%d\n", ans);
    }
    else {
      while (iupd < vupd.size() && vupd[iupd].first.first == i) {
        int u = vupd[iupd].second.first;
        int no = vupd[iupd].first.second;
        rmq * rm = vupd[iupd].second.second;
        rm->update(no, dist(u, rm->v));\
        iupd++;
      }
      merge(que[i].first, que[i].second);
    }
  }
  return 0; 
}