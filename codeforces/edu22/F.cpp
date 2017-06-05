#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, LG = 19;

int ch[LG][N];
vector< int > ve[LG];
set< int > st[N];
int p[N], lv = 0, col[N];
bool adde(int u, int v) {
  if (p[u] == p[v]) {
    return (col[u] != col[v]);
  }
  bool alt = col[u] == col[v];
  u = p[u], v = p[v];
  if (st[u].size() < st[v].size()) swap(u, v);
  for (int x : st[v]) {
    st[u].insert(x);
    if (ch[lv][x] < 0) {
      ve[lv].push_back(x);
      ch[lv][x] = p[x];
    }
    p[x] = u;
    if (alt)
      col[x] ^= 1;
  }
  st[v].clear();
  return true;
}
void next() {
  lv++;
}
void prev() {
  for (auto x : ve[lv]) {
    st[p[x]].erase(x);
    p[x] = ch[lv][x];
    st[p[x]].insert(x);
    ch[lv][x] = -1;
  }
  ve[lv].clear();
  lv--;
}

vector< pair< int, int > > ed[N << 2];
int n, q;
void add(int x, int y, pair< int, int > e, int id = 1, int l = 0, int r = q) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    ed[id].push_back(e);
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  add(x, y, e, il, l, mid);
  add(x, y, e, ir, mid, r);
}
bool ans[N];
void solve(int id = 1, int l = 0, int r = q) {
  next();
  bool cek = 1;
  for (auto it : ed[id]) {
    if (!adde(it.first, it.second)) {
      cek = 0;
      break;
    }
  }
  if (!cek) {
    for (int i = l; i < r; i++)
      ans[i] = 0;
    prev();
    return;
  }
  if (r-l < 2) {
    ans[l] = 1;
    prev();
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  solve(il, l, mid);
  solve(ir, mid, r);
  prev();
}

int main() {
  scanf("%d %d", &n, &q);
  map< pair< int, int >, int > mp;
  for (int i = 0; i < q; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    if (u > v) swap(u, v);
    pair< int, int > e(u, v);
    if (mp.count(e)) {
      add(mp[e], i, e);
      mp.erase(e);
    }
    else
      mp[e] = i;
  }
  for (auto it : mp) {
    add(it.second, q, it.first);
  }
  lv = 0;
  memset(ch, -1, sizeof ch);
  for (int i = 0; i < n; i++) {
    p[i] = i;
    col[i] = 0;
    st[i].insert(i);
  }
  solve(1, 0, q);
  for (int i = 0; i < q; i++)
    puts(ans[i] ? "YES" : "NO");
  return 0;
}