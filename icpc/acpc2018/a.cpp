#include <bits/stdc++.h>

using namespace std;

void open_file(string filename) {
#ifndef LOCAL
  freopen(filename.c_str(), "r", stdin);
#endif
}

void close_file() {
#ifndef LOCAL
  fclose(stdin);
#endif
}

const int N = 1e5 + 5;

vector<int> g[N];
int L, R;
int sz[N], to[N], live[N], lv[N];

void get_sz(int v, int par = -1) {
  sz[v] = 1;
  to[v] = -1;
  for (int u : g[v]) {
    if (!live[u]) continue;
    if (u == par) continue;
    get_sz(u, v);
    sz[v] += sz[u];
    if (to[v] == -1 || sz[to[v]] < sz[u])
      to[v] = u;
  }
}

int bit[N];
void upd_bit(int x, int v) {
  for (++x; x < N; x += x&-x)
    bit[x] += v;
}
int get_bit(int x) {
  int ret = 0;
  for (++x; x; x -= x&-x)
    ret += bit[x];
  return ret;
}

long long ans;

void get_ans(int v, int par) {
  lv[v] = lv[par] + 1;
  if (lv[v] <= R)
    ans += get_bit(R-lv[v]);
  if (lv[v] <= L)
    ans -= get_bit(L-lv[v]);
  for (int u : g[v]) {
    if (u == par || !live[u]) continue;
    get_ans(u, v);
  }
}

void dfs_add(int v, int par, int d) {
  upd_bit(lv[v], d);
  for (int u : g[v]) {
    if (u == par || !live[u]) continue;
    dfs_add(u, v, d);
  }
}

void centroid(int v) {
  get_sz(v);
  int tot = sz[v];
  while (to[v] != -1 && 2 * sz[to[v]] > tot) v = to[v];
  lv[v] = 0;
  for (int u : g[v]) {
    if (!live[u]) continue;
    get_ans(u, v);
    dfs_add(u, v, +1);
  }
  for (int u : g[v]) {
    if (!live[u]) continue;
    dfs_add(u, v, -1);
  }
  live[v] = 0;
  for (int u : g[v]) {
    if (!live[u]) continue;
    centroid(u);
  }
}

int main() {
  open_file("awesome.in");
  int t;
  scanf("%d", &t);
  upd_bit(0, 1);
  while (t--) {
    int n;
    scanf("%d %d %d", &n, &L, &R);
    L = n-1 - L;
    R = n-1 - R;
    swap(L, R);
    L = max(L, 1);
    --L;
    R = max(R, 1);
    for (int i = 0; i < n; ++i)
      g[i].clear();
    fill(live, live+n, 1);
    for (int i = 0; i + 1 < n; ++i) {
      int u, v;
      scanf("%d %d", &u, &v);
      --u, --v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    ans = 0;
    centroid(0);
    printf("%lld\n", ans);
  }
  close_file();
  return 0;
}