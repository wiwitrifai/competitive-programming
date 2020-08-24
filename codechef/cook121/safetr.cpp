// verdict: TLE

#include <bits/stdc++.h>

using namespace std;


const int N = 8e5 + 5;

vector<int> g[N];

int sz[N], biggest[N], live[N], rad[N];
long long ans[N];
int add[N];

void get_size(int v, int par) {
  sz[v] = 1;
  biggest[v] = -1;
  for (int u : g[v]) {
    if (u == par || !live[u]) continue;
    get_size(u, v);
    sz[v] += sz[u];
    if (biggest[v] == -1 || sz[u] > sz[biggest[v]])
      biggest[v] = u;
  }
}

long long cur = 0;

void get_rad(int v, int par, int depth, int mul) {
  if (rad[v] > depth) {
    int sisa = rad[v] - depth;
    cur += mul * (rad[v] - depth);
    add[0] += -mul;
    add[sisa] += mul;
  }
  for (int u : g[v]) {
    if (u == par || !live[u]) continue;
    get_rad(u, v, depth+1, mul);
  }
}

void upd_ans(int v, int par, int depth, long long now, long long b) {
  now += b;
  b += add[depth];
  ans[v] += now;
  for (int u : g[v]) {
    if (u == par || !live[u]) continue;
    upd_ans(u, v, depth+1, now, b);
  }
}

void centroid(int v) {
  get_size(v, v);
  int tot = sz[v];
  while (biggest[v] != -1 && sz[biggest[v]] * 2 >= tot)
    v = biggest[v];


  cur = 0;
  get_rad(v, v, 0, +1);

  ans[v] += cur;

  for (int u : g[v]) {
    if (!live[u]) continue;

    get_rad(u, v, 1, -1);

    upd_ans(u, v, 1, cur, add[0]);

    get_rad(u, v, 1, 1);
  }
  get_rad(v, v, 0, -1);

  live[v] = false;

  for (int u : g[v]) {
    if (!live[u]) continue;
    centroid(u);
  }
}

void solve() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i)
    g[i].clear();
  for (int i = 0; i < n-1; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  fill(rad, rad+n, 0);
  for (int i = 0; i < k; ++i) {
    int v, r;
    scanf("%d %d", &v, &r);
    --v;
    rad[v] = r;
  }
  fill(live, live+n, true);
  fill(ans, ans+n, 0);

  centroid(0);

  for (int i = 0; i < n; ++i)
    printf("%lld%c", ans[i], i+1 == n ? '\n' : ' ');
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
