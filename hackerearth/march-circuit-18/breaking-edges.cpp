#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, LG = 21;

int a[N], st[N], en[N], cntr = 0;
vector<int> g[N];

int sp[LG][N];
void dfs(int v, int par = -1) {
  sp[0][cntr] = a[v];
  st[v] = cntr++;
  for (int u : g[v]) if (u != par) {
    dfs(u, v);
  }
  en[v] = cntr;
}

int get(int l, int r) {
  int len = r-l;
  if (len == 0) return 0;
  int lg = 31 - __builtin_clz(len);
  return sp[lg][l] | sp[lg][r-(1<<lg)];
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0);
  for (int i = 0; i+1 < LG; ++i) {
    for (int j = 0; j + (1 << (i+1)) <= n; ++j) {
      sp[i+1][j] = sp[i][j] | sp[i][j+(1<<i)];
    }
  }
  int ans = 0;
  for (int i = 1; i < n; ++i) {
    ans += (get(0, st[i]) | get(en[i], n)) == get(st[i], en[i]);
  }
  printf("%d\n", ans);
  return 0;
}