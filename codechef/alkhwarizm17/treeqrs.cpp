#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector< int > g[N];
int par[19][N], lv[N];

void dfs(int v = 0) {
  for (int i = 0; i + 1 < 19; i++) {
    par[i+1][v] = par[i][par[i][v]];
  }
  for (int u : g[v]) if (u != par[0][v]) {
    par[0][u] = v;
    lv[u] = lv[v] + 1;
    dfs(u);
  }
}
int lca(int u, int v) {
  if (lv[u] > lv[v])
    swap(u, v);
  int diff = lv[v] - lv[u];
  for (int i = 0; i < 19; i++)
    if (diff & (1<<i))
      v = par[i][v];
  if (u == v) return u;
  for (int i = 18; i >= 0; i--) {
    if (par[i][v] != par[i][u])
      v = par[i][v], u = par[i][u];
  }
  return par[0][v];
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0);
  int q;
  scanf("%d", &q);
  while (q--) {
    int r, x, y;
    long long a, b;
    scanf("%d %lld %lld %d %d", &r, &a, &b, &x, &y);
    x--; y--; r--;
    int xy = lca(x, y), xr = lca(x, r), yr = lca(y, r);
    int nlca = xy;
    if (lv[xr] > lv[nlca]) nlca = xr;
    if (lv[yr] > lv[nlca]) nlca = yr;
    int dist = lv[x] + lv[y] - 2 * lv[xy];
    long long le = lv[x] + lv[nlca] - 2 * lv[lca(x, nlca)], ri = dist - le;
    // cerr << r << " " << x << " " << y << " " << nlca << endl;
    // cerr << le << " " << ri << endl;
    long long ans = a * (ri * (ri + 1)/2 + le * (le + 1)/2);
    long long cur = (a * ri - b * le + a)/(a+b);
    // cerr << cur << endl;
    // cur++;
    for (int i = -2; i < 2; i++) {
      cur += i;
      if (cur > 0 && cur <= ri) {
        long long r = ri - cur;
        long long tmp = a * le * (le+1)/2 + a * r * (r+1)/2 + b * le * cur + b * cur * (cur + 1)/2;
        // cerr << " res " << r << " " << " " << cur << " " <<  tmp << endl;
        ans = min(ans, tmp);
      }
      cur -= i;
    }
    swap(le, ri);
    cur = (a * ri - b * le + a)/(a+b);
    for (int i = -2; i < 2; i++) {
      cur += i;
      if (cur > 0 && cur <= ri) {
        long long r = ri - cur;
        long long tmp = a * le * (le+1)/2 + a * r * (r+1)/2 + b * le * cur + b * cur * (cur + 1)/2;
        // cerr << " res " << r << " " << " " << cur << " " <<  tmp << endl;
        ans = min(ans, tmp);
      }
      cur -= i;
    }
    printf("%lld\n", ans);
  }
  return 0;
}