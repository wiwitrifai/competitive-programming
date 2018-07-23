#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6, mod = 1e9 + 7;

int * cnt[N], * sum[N], * dp[N];
vector<int> g[N];
int sz[N];
int pre(int v, int par = -1) {
  sz[v] = 1;
  for (int u : g[v]) if (u != par) {
    pre(u, v);
    sz[v] += sz[u];
  }
}

int t1[N], t2[N], t3[N];

void add(int & le, int ri) {
  le += ri;
  if (le >= mod) le -= mod;
}

int mul(int le, int ri) {
  return 1LL * le * ri % mod;
}

void init(int v, int s) {
  dp[v] = new int[s];
  sum[v] = new int[s];
  cnt[v] = new int[s];
}

void copy(int v, int u) {
  dp[v] = dp[u];
  sum[v] = sum[u];
  cnt[v] = cnt[u];
}

int n;
void solve(int v, int u, int sv, int su, int to = -1) {
  if (to == -1) to = v;
  int s = sv + su;
  fill(t1, t1+s, 0);
  fill(t2, t2+s, 0);
  fill(t3, t3+s, 0);
  for (int i = 0; i < sv; ++i) {
    for (int j = 0; j < su; ++j) {
      add(t3[i+j], mul(dp[v][i], cnt[u][j]));
      add(t3[i+j], mul(cnt[v][i], dp[u][j]));
      add(t3[i+j], mul(2, mul(sum[v][i], sum[u][j])));
      add(t2[i+j], mul(sum[v][i], cnt[u][j]));
      add(t2[i+j], mul(cnt[v][i], sum[u][j]));
      add(t1[i+j], mul(cnt[v][i], cnt[u][j]));

      add(t3[i+j+1], mul(dp[v][i], cnt[u][j]));
      add(t3[i+j+1], mul(cnt[v][i], dp[u][j]));
      add(t2[i+j+1], mul(sum[v][i], cnt[u][j]));
      add(t1[i+j+1], mul(cnt[v][i], cnt[u][j]));
    }
  }
  for (int i = 0; i < s; ++i) {
    dp[to][i] = t3[i];
    sum[to][i] = t2[i];
    cnt[to][i] = t1[i];
  }
}

int dfs(int v, int par = -1) {
  int bg = -1;
  for (int u : g[v]) if (u != par) {
    if (bg == -1 || sz[bg] < sz[u])
      bg = u;
  }
  int now = 1;
  if (bg != -1) {
    copy(bg, v);
    dfs(bg, v);
    solve(n, v, 1, sz[bg], v), now += sz[bg];
  } else
    dp[v][0] = cnt[v][0] = sum[v][0] = 1;
  for (int u : g[v]) if (u != par && u != bg) {
    init(u, sz[u]);
    dfs(u, v);
    solve(v, u, now, sz[u]);
    now += sz[u];
  }
}

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  pre(0);
  init(0, n);
  init(n, 1);
  dp[n][0] = sum[n][0] = cnt[n][0] = 1;
  dfs(0);
  int cur = 1;
  for (int i = 0; i < n; ++i) {
    printf("%d%c", mul(cur, dp[0][i]), i == n-1 ? '\n' : ' ');
    cur = mul(cur, powmod(n-i-1, mod-2));
    cur = mul(cur, i+1);
  }
  return 0;
}