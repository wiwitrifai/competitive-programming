#include <bits/stdc++.h>

using namespace std;


const int N = 1e5 + 5, mod = 1e9 + 7;

long long C[22][22];

struct poly {
  int n;
  int x[22];
  poly(int n = 0) : n(n) {
    memset(x, 0, sizeof x);
  }
  void reset(int n = 0) {
    this->n = n;
    memset(x, 0, sizeof x);
  }
  long long get(long long p) {
    long long ret = 0, now = 1;
    for (int i = 0; i <= n; i++) {
      ret = (ret + 1LL * x[i] * now) % mod;
      now = now * p % mod;
    }
    return ret;
  }
  void add(poly & other) {
    for (int i = 0; i <= n; i++) {
      x[i] += other.x[i];
      if (x[i] >= mod) x[i] -= mod;
    }
  }
};

poly val[N], up[N];
long long ans[N];
int n, lv[N], k;
vector< int > g[N];

void dfs(int v, int par = -1) {
  if (par != -1)
    val[v].add(val[par]);
  for (int u : g[v]) {
    lv[u] = lv[v] + 1;
    dfs(u, v);
    up[v].add(up[u]);
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int r = -1;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) g[i].clear();
    for (int i = 0; i < n; i++) {
      int p;
      scanf("%d", &p); p--;
      if (p < 0)
        r = i;
      else
        g[p].push_back(i);
      val[i].reset(k);
      up[i].reset(k);
    }
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
      int y, z, x;
      scanf("%d %d", &y, &z);
      z--;
      if (y == 2) {
        for (int j = 0; j <= k; j++) {
          scanf("%d", &x);
          up[z].x[j] += x;
          if (up[z].x[j] >= mod)
            up[z].x[j] -= mod;
        }
      }
      else {
        for (int j = 0; j <= k; j++) {
          scanf("%d", &x);
          val[z].x[j] += x;
          if (val[z].x[j] >= mod)
            val[z].x[j] -= mod;
        }
      }
    }
    lv[r] = 1;
    dfs(r);
    for (int i = 0; i < n; i++)
      ans[i] = (up[i].get(lv[i]) + val[i].get(lv[i])) % mod;
    for (int i = 0; i < n; i++) printf("%d ", ans[i]);
    printf("\n");
  }
  return 0;
}