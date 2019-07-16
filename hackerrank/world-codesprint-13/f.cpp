#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 5, LG = 21;

int st[N], en[N];
int hidup[N];
int sp[LG][N], lv[N], par[N], nodes = 0;

vector<int> g[N];

void dfs(int v) {
  st[v] = nodes;
  sp[0][nodes++] = v;
  for (int u : g[v]) {
    if (u == par[v]) continue;
    par[u] = v;
    lv[u] = lv[v] + 1;
    dfs(u);
    sp[0][nodes++] = v;
  }
  en[v] = nodes;
}

int get(int l, int r) {
  int len = r-l+1;
  int lg = 31-__builtin_clz(len);
  int le = sp[lg][l], ri = sp[lg][r-(1<<lg)+1];
  return lv[le] < lv[ri] ? le : ri;
}

int lca(int u, int v) {
  if (st[u] > st[v]) swap(u, v);
  return get(st[u], st[v]);
}

int bit[N];
int get_bit(int x) {
  int r = 0;
  for (; x; x -= x&-x)
    r += bit[x];
  return r;
}
void upd_bit(int x, int v) {
  for (; x < N; x += x&-x)
    bit[x] += v;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  par[0] = 0;
  lv[0] = 0;
  nodes = 1;
  dfs(0);
  for (int i = 0; i+1 < LG; ++i) {
    for (int j = 0; j + (1 << (i+1)) <= nodes; ++j) {
      int le = sp[i][j], ri = sp[i][j+(1<<i)];
      sp[i+1][j] = lv[le] < lv[ri] ? le : ri;
    }
  }
  int q;
  scanf("%d", &q);
  for (int i = 0; i < n; ++i) {
    upd_bit(st[i], 1);
    upd_bit(en[i], -1);
    hidup[i] = 1;
  }
  // cerr << " why " << endl;
  while (q--) {
    char t;
    int x, y;
    scanf(" %c %d %d", &t, &x, &y); --x; --y;
    // cerr << t << " " << x << " " << y << endl;
    if (par[x] != y) swap(x, y);
    if (t == 'q') {
      int z = lca(x, y);
      // cerr << z << endl;
      int dist = lv[x] + lv[y] - 2 * lv[z];
      int dist2 = get_bit(st[x]) + get_bit(st[y]) - 2 * get_bit(st[z]);
      if (dist != dist2)
        puts("Impossible");
      else
        printf("%d\n", dist);
    }
    else {
      if (par[x] != y) continue;
      if (t == 'd') {
        if (hidup[x]) {
          hidup[x] = 0;
          upd_bit(st[x], -1);
          upd_bit(en[x], +1);
        }
      }
      else {
        if (!hidup[x]) {
          hidup[x] = 1;
          upd_bit(st[x], +1);
          upd_bit(en[x], -1);
        }
      }
    }
  }

  return 0;
}