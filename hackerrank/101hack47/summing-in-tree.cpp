#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int cnt[N], lv[N], cur, sz[N];
int a[N];
vector< int > g[N];
void add(int l, int val = 1) {
  if (cnt[l] < a[l] && cnt[l] + val >= a[l])
    cur++;
  if (cnt[l] >= a[l] && cnt[l] + val < a[l])
    cur--;
  cnt[l] += val;
}
void proc(int v, int val = 1) {
  add(lv[v], val);
  for (int u : g[v]) {
    proc(u, val);
  }
}
void pre(int v) {
  sz[v] = 1;
  for (int u : g[v]) {
    lv[u] = lv[v] + 1;
    pre(u);
    sz[v] += sz[u];
  }
}
long long ans = 0;
int bg[N];
void dfs(int v) {
  bg[v] = -1;
  for (int u : g[v])
  if (bg[v] == -1)
    bg[v] = u;
  else if (sz[u] > sz[bg[v]])
    bg[v] = u;
  for (int u : g[v]) if (u != bg[v]) {
    dfs(u);
    proc(u, -1);
  }
  if (bg[v] != -1)
    dfs(bg[v]);
  for (int u : g[v]) if (u != bg[v]) {
    proc(u, 1);
  }
  add(lv[v], 1);
  ans += cur;
}

int main() {
  int n, h;
  scanf("%d %d", &n, &h);
  for (int i = 1; i < n; i++) {
    int p;
    scanf("%d", &p);
    g[p].push_back(i);
  }
  cur = 0;
  for (int i = 0; i <= h; i++)
    scanf("%d", a+i), cur += a[i] == 0;
  lv[0] = 0;
  ans = 0;
  pre(0);
  dfs(0);
  cout << ans << endl;
  return 0;
}