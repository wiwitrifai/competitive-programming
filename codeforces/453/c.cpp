#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 6, LG = 20;

vector<int> g[N];
int par[LG][N], ma[LG][N], mi[LG][N], lv[N];
bool vis[N];

void dfs(int u) {
  vis[u] = 1;
  for (int i = 0; i + 1 < LG; ++i) {
    int p = par[i][u];
    par[i+1][u] = par[i][p];
    ma[i+1][u] = max(ma[i][u], ma[i][p]);
    mi[i+1][u] = min(mi[i][u], mi[i][p]);
  }
  for (int v : g[u]) if (v != par[0][u] && !vis[v]) {
    par[0][v] = u;
    ma[0][v] = mi[0][v] = v;
    lv[v] = lv[u] + 1;
    dfs(v);
  }
}

int ri[N], le[N];

long long sum[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<pair<int, int> > edges;
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
    edges.emplace_back(u, v);
  }
  memset(vis, 0, sizeof vis);
  for (int i = 0; i < n; ++i) if (!vis[i]) {
    par[0][i] = i;
    ma[0][i] = i;
    mi[0][i] = i;
    lv[i] = 0;
    dfs(i);
  }
  vector<pair<int, int> > constrain;
  for (auto it : edges) {
    int u = it.first, v = it.second;
    if (par[0][u] == v || par[0][v] == u) continue;
    // cerr << u << " " << v << endl;
    // cerr << par[0][u] << " / " << par[0][v] << endl;
    if (lv[u] > lv[v]) swap(u, v);
    int diff = lv[v] - lv[u];
    int vma = max(u, v), vmi = min(u, v);
    for (int i = 0; i < LG; ++i) {
      if (diff & (1 << i)) {
        vma = max(vma, ma[i][v]);
        vmi = min(vmi, mi[i][v]);
        v = par[i][v];
      }
    }
    if (u != v) {
      for (int i = LG-1; i >= 0; i--) {
        if (par[i][u] != par[i][v]) {
          vma = max(vma, max(ma[i][v], ma[i][u]));
          vmi = min(vmi, min(mi[i][v], mi[i][u]));
        }
      }
      vma = max(vma, max(v, u));
      vmi = min(vmi, min(v, u));
      v = par[0][v];
    }
    vma = max(vma, max(v, u));
    vmi = min(vmi, min(v, u));
    constrain.emplace_back(vmi, vma);
  }
  for (int i = 0; i < n; ++i)
    le[i] = -1, ri[i] = n;
  for (auto it : constrain) {
    // cerr << it.first << " ? " << it.second << endl;
    le[it.second] = max(it.first, le[it.second]);
    ri[it.first] = min(it.second, ri[it.first]);
  }
  for (int i = 0; i+1 < n; ++i)
    le[i+1] = max(le[i+1], le[i]);
  for (int i = n-2; i >= 0; --i)
    ri[i] = min(ri[i], ri[i+1]);
  sum[0] = 0;
  for (int i = 0; i < n; ++i)
    sum[i+1] = sum[i] + ri[i] - i;
  int q;
  scanf("%d", &q);
  while (q--) {
    int l, r;
    scanf("%d %d", &l, &r);
    l--; r--;
    long long ans = 0;
    if (le[r] < l) {
      int len = r-l+1;
      ans = 1LL * len * (len+1) / 2;
    }
    else {
      int len = r - le[r];
      ans = 1LL * len * (len + 1) / 2 + sum[le[r]+1] - sum[l];
    }
    printf("%I64d\n", ans);
  }
  return 0;
}