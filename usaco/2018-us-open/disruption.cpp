#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, inf = 1e9 + 7;

int com[N], up[N], pos[N];
int ans[N], id[N], lv[N], sz[N], ncom = 0;
vector<int> elem[N];
vector<pair<int, int> > g[N];

void get_sz(int v, int par = -1) {
  sz[v] = 1;
  for (auto it : g[v]) {
    int u = it.first;
    if (u == par) continue;
    id[it.second] = u;
    lv[u] = lv[v] + 1;
    get_sz(u, v);
    sz[v] += sz[u];
  }
}

void hld(int v, int par = -1) {
  int bg = -1;
  for (auto it : g[v]) {
    int u = it.first;
    if (u == par) continue;
    if (bg == -1 || sz[bg] < sz[u])
      bg = u;
  }
  if (bg != -1) {
    pos[bg] = elem[ncom].size();
    com[bg] = ncom;
    elem[ncom].push_back(bg);
    hld(bg, v);
  }
  for (auto it : g[v]) {
    int u = it.first;
    if (u == par || u == bg) continue;
    ++ncom;
    up[ncom] = v;
    elem[ncom].clear();
    pos[u] = elem[ncom].size();
    com[u] = ncom;
    elem[ncom].push_back(u);
    hld(u, v);
  }
}

struct rmq {
  vector<int> s;
  int n;
  rmq(int n) : n(n), s(n << 2, inf) {
  }
  void upd(int x, int y, int v, int id, int l, int r) {
    if (x >= r || l >= y) return;
    if (x <= l && r <= y) {
      s[id] = min(s[id], v);
      return;
    }
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    upd(x, y, v, il, l, mid);
    upd(x, y, v, ir, mid, r);
  }
  int query(int x, int id, int l, int r) {
    if (r-l < 2)
      return s[id];
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    return min(s[id], x < mid ? query(x, il, l, mid) : query(x, ir, mid, r));
  }
  void update(int x, int y, int v) {
    upd(x, y, v, 1, 0, n);
  }
  int get(int x) {
    return query(x, 1, 0, n);
  }
};

rmq * seg[N];

void open(string s) {
#ifndef LOCAL
  freopen((s + ".in").c_str(), "r", stdin); 
  freopen((s + ".out").c_str(), "w", stdout);
#endif
}
void close() {
#ifndef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
}
int main() {
  open("disrupt");
  int n, m;
  scanf("%d %d", &n, &m);
  fill(ans, ans+n+1, inf);
  for (int i = 0; i+1 < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].emplace_back(v, i);
    g[v].emplace_back(u, i);
  }
  lv[0] = 0;
  get_sz(0, -1);
  pos[0] = com[0] = ncom = 0;
  elem[ncom].push_back(0);
  hld(0, -1); ++ncom;
  for (int i = 0; i < ncom; ++i) {
    seg[i] = new rmq(elem[i].size());
  }
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    --u, --v;
    while (u != v) {
      if (com[u] == com[v]) {
        if (lv[u] > lv[v]) swap(u, v);
        seg[com[v]]->update(pos[u]+1, pos[v]+1, w);
        v = u;
      }
      else {
        if (lv[elem[com[u]][0]] > lv[elem[com[v]][0]]) swap(u, v); 
        seg[com[v]]->update(0, pos[v]+1, w);
        v = up[com[v]];
      }
    }
  }
  for (int i = 0; i+1 < n; ++i) {
    int u = id[i];
    int res = seg[com[u]]->get(pos[u]);
    if (res >= inf) res = -1;
    printf("%d\n", res);
  }
  close();
  return 0;
}