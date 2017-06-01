#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, mod = 1e9 + 7;

long long dp[N], val[N];
long long sum = 0;
void reset(int x) {
  sum -= val[x];
  if (sum < 0) sum += mod;
  val[x] = 0;
}
void add(int x, long long a) {
  val[x] += a; 
  if (val[x] >= mod) val[x] -= mod;
  sum += a;
  if (sum >= mod) sum -= mod;
}
int c[N];
vector< int > g[N];
void join(int v) {
  long long tmp = val[c[v]]+1;
  for (int u : g[v])
    join(u);
  tmp = tmp * dp[v] % mod;
  add(c[v], tmp); 
}
void rem(int v) {
  reset(c[v]);
  for (int u : g[v])
    rem(u);
}
int sz[N];
void pre(int v) {
  sz[v] = 1;
  for (int u : g[v])
    pre(u), sz[v] += sz[u];
}
void dfs(int v) {
  int bg = -1;
  for (int u : g[v])
    if (bg == -1 || sz[u] > sz[bg])
      bg = u;
  for (int u : g[v]) if (u != bg) {
    dfs(u);
    rem(u);
  }
  if (bg != -1)
    dfs(bg);
  for (int u : g[v]) if (u != bg)
    join(u);
  dp[v] = 1 + sum;
  if (dp[v] >= mod) dp[v] -= mod;
  add(c[v], dp[v]);
}

int main() {
  int n;
  int rt = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int p;
    scanf("%d %d", &p, c+i);
    p--;
    if (p < 0)
      rt = i;
    else
      g[p].push_back(i);
  }
  pre(rt);
  sum = 0;
  memset(val, 0, sizeof val);
  dfs(rt);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans = (ans + dp[i]) % mod;
    // cerr << i << " " << dp[i] << endl;
  }
  if (ans < 0) ans += mod;
  cout << ans << endl;
  return 0;
}