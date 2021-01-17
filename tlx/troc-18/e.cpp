#include <bits/stdc++.h>

using namespace std;


struct BIT {
  vector<int> sum;

  BIT(int _n) : sum(_n+1, 0) {}

  void upd(int x, int v) {
    for (++x; x < (int)sum.size(); x += x&-x)
      sum[x] ^= v;
  }

  int get(int x) {
    int ret = 0;
    for (++x; x; x -= x&-x)
      ret ^= sum[x];
    return ret;
  }
};

const int N = 2e5 + 5;

vector<int> g[N];

int col[N], in[N], out[N], cntr = 0;

void dfs(int v, int par = -1) {
  in[v] = cntr++;
  for (int u : g[v]) {
    if (u == par) continue;
    col[u] = col[v] ^ 1;
    dfs(u, v);
  }
  out[v] = cntr;
}

void solve() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i< n-1; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  dfs(0);
  int q;
  scanf("%d", &q);
  vector<BIT> bits(2, BIT(n+1));
  while (q--) {
    int t, v, x;
    scanf("%d %d", &t, &v);
    --v;
    if (t == 2) {
      int ans = bits[col[v]].get(in[v]);
      printf("%d\n", ans);
    } else {
      scanf("%d", &x);
      bits[col[v]].upd(in[v], x);
      bits[col[v]].upd(out[v], x);
    }
  }
}

int main() {
  int tc = 1;
  // scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
