#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5, LG = 20;

vector<int> g[N];

int flat[N], st[N], en[N], lv[N];
int sp[LG][N], nodes = 0;
void dfs(int v, int par = -1) {
  st[v] = nodes;
  flat[nodes++] = v;
  for (int u : g[v]) if (u != par) {
    lv[u] = lv[v] + 1;
    dfs(u, v);
    flat[nodes++] = v;
  }
  en[v] = nodes;
}

int get_sp(int l, int r) {
  int len = (r- l);
  int lg = 31-__builtin_clz(len);
  int u = sp[lg][l], v = sp[lg][r-(1<<lg)];
  return lv[u] < lv[v] ? u : v;
}
int lca(int u, int v) {
  if (st[u] > st[v]) swap(u, v);
  return get_sp(st[u], st[v]+1);
}
bool used[N];
int bit[N];
int get(int x) {
  int r = 0;
  for (; x; x -= x&-x)
    r += bit[x];
  return r;
}
void upd(int x, int v) {
  for (; x < N; x += x&-x)
    bit[x] += v;
}
int main() {
  int n, m;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  lv[0] = 0;
  nodes = 0;
  dfs(0);
  for (int i = 0; i < nodes; ++i) {
    sp[0][i] = flat[i];
  }
  for (int i = 0; i + 1 < LG; ++i) {
    for (int j = 0; j + (1 << (i+1)) <= nodes; ++j) {
      int u = sp[i][j], v= sp[i][j+(1 << i)];
      sp[i+1][j] = lv[u] < lv[v] ? u : v;
    }
  }
  vector<int> ans;
  vector<tuple<int, int, int> > e;
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    int w = lca(u, v);
    e.emplace_back(-lv[w], u, v);
  }
  sort(e.begin(), e.end());
  for (int i = 0; i < m; ++i) {
    int u, v;
    tie(ignore, u, v) = e[i];
    int w = lca(u, v);
    int cnt = get(st[u]+1) + get(st[v]+1) - get(st[w]+1) * 2 + used[w];
    if (cnt > 0) continue;
    used[w] = 1;
    ans.push_back(w);
    upd(st[w]+1, +1);
    upd(en[w]+1, -1);
  }
  sort(ans.begin(), ans.end());
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); ++i) {
    if (i) printf(" ");
    printf("%d", ans[i]+1);
  }
  printf("\n");
  return 0;
}