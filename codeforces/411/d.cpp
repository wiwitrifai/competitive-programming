#include <bits/stdc++.h>

using namespace std;


const int N = 1e5 + 5, MAGIC = 300, SZ = (N/MAGIC + 20);

vector< int > g[N];
int n, m, q, p[N], id[N], d[N], up[N];
bool vis[N];
vector< int > vd[N];
vector< long long > vs[N];
long long sum[N];

int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}
bool merge(int u, int v) {
  if ((u = find(u)) == (v = find(v))) return 0;
  if (-p[u] > -p[v])
    swap(u, v);
  p[v] += p[u];
  p[u] = v;
  return 1;
}
void pre(int v, int par) {
  assert(!vis[v]);
  vis[v] = 1;
  d[v] = 1;
  for (int u : g[v]) if (u != par)
    pre(u, v), d[v] = max(d[v], d[u]+1);
}
int dfs(int v, int par) {
  int now = 1;
  for (int u : g[v]) if (u != par) {
    up[u] = max(up[u], now);
    now = max(now, d[u]+1);
  }
  now = up[v] + 1;
  for (int i = (int)g[v].size() - 1; i >= 0; i--) {
    int u = g[v][i];
    if (u == par) continue;
    up[u] = max(up[u], now);
    now = max(now, d[u]+1);
  }
  d[v] = max(d[v], up[v]+1);
  vd[find(v)].push_back(d[v]);
  for (int u : g[v]) if (u != par) {
    dfs(u, v);
  }
}
double dp[SZ][SZ];

double solve(int u, int v) {
  if (-p[u] > -p[v]) swap(u, v);
  int mi = 0;
  double ans = (double)sum[u] * -p[v] + (double)sum[v] * -p[u];
  int dim = max(vd[u].back(), vd[v].back()), last = 0;
  for (int i = 0; i < -p[u]; i++) {
    int x = lower_bound(vd[v].begin(), vd[v].end(), dim-vd[u][i]) - vd[v].begin();
    ans += (double)dim * x;
    ans -= (double)vd[u][i] * x + (double)vs[v][x];
  }
  return ans/-p[u]/-p[v] - 1;
}

int main() {
  scanf("%d %d %d", &n, &m, &q);
  memset(p, -1, sizeof p);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
    merge(u, v);
  }
  cerr << " done " << endl;
  for (int i = 0; i < n; i++) {
    if (d[i] == 0)
      pre(i, -1), dfs(i, -1);
  }
  vector< int > big;
  memset(id, -1, sizeof id);
  cerr << " why " << endl;
  for (int i = 0; i < n; i++) {
    if (p[i] >= 0) continue;
    if (-p[i] >= MAGIC) {
      id[i] = big.size();
      big.push_back(i);
    }
    sort(vd[i].begin(), vd[i].end());
    sum[i] = 0;
    vs[i].push_back(0);
    for (int x : vd[i])
      sum[i] += x, vs[i].push_back(sum[i]);
  }
  cerr << big.size() << endl;
  for (int i = 0; i < big.size(); i++) {
    for (int j = i+1; j < big.size(); j++) {
      dp[i][j] = solve(big[i], big[j]);
    }
  }
  while (q--) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    u = find(u), v = find(v);
    if (u == v) {
      printf("-1\n");
      continue;
    }
    if (id[u] >= 0 && id[v] >= 0) {
      if (id[u] > id[v]) swap(u, v);
      printf("%.15lf\n", dp[id[u]][id[v]]);
      continue;
    }
    printf("%.15lf\n", solve(u, v));
  }
  cerr << big.size() << endl;
  return 0;
}