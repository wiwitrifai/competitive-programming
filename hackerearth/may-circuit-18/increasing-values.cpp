#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e5 + 5, LG = 20;
 
long long bit[N];
int par[LG][N], st[N], en[N], lv[N], cntr = 0;
int n;
vector<int> g[N];
 
long long get(int x) {
  long long r = 0;
  for (; x; x -= x&-x)
    r += bit[x];
  return r;
}
 
void upd(int x, int v) {
  for (; x <= n; x += x&-x)
    bit[x] += v;
}
 
void dfs(int v, int pp = -1) {
  par[0][v] = pp == -1 ? v : pp;
  lv[v] = pp == -1 ? 0 : lv[pp] + 1;
  for (int i = 0; i+1 < LG; ++i)
    par[i+1][v] = par[i][par[i][v]];
  st[v] = cntr++;
  for (int u : g[v]) if (u != pp) {
    dfs(u, v);
  }
  en[v] = cntr;
}
 
int get_lv(int u, long long low) {
  for (int i = LG-1; i >= 0; --i) {
    int p = par[i][u];
    long long cur = get(en[p]) - get(st[p]);
    if (cur <= low)
      u = p;
  }
  int down = lv[u];
  if (get(en[u]) - get(st[u]) <= low)
    --down;
  return down;
}
 
int main() {
  int q, x;
  scanf("%d %d %d", &n, &q, &x);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v); --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0);
  for (int i = 0; i < n; ++i) {
    int f;
    scanf("%d", &f);
    upd(st[i]+1, f);
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    long long cur = get(en[i]) - get(st[i]);
    ans += cur > x;
  }
  while (q--) {
    int d, a;
    scanf("%d %d", &d, &a);--d;
    int down = get_lv(d, x-a), up = get_lv(d, x);
    upd(st[d]+1, a);
    ans += down - up;
    printf("%d\n", ans);
  }
  return 0;
}