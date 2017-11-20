#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6, mod = 1e9 + 7;

vector<int> g[N];
long long sum, s[N], a[N], dua[N], b[N], ss[N];
long long cs[N], ca[N], cb[N], css[N];
long long ts[N], ta[N], tb[N], tss[N];

void dfs(int v, int par = -1) {
  b[v] = ss[v] = 0;
  int c = g[v].size();
  if (par != -1) c--;
  for (int u : g[v]) if (u != par) {
    dfs(u, v);
    b[v] += s[u];
    ss[v] = (ss[v] + s[u] * s[u]) % mod;
    if (b[v] >= mod) s[v] -= mod;
  }
  s[v] = b[v] * dua[c-1] + dua[c] - 1;
  if (c) s[v]--;
  s[v] %= mod;
  if (s[v] < 0) s[v] += mod;
  a[v] = (b[v] * b[v] - ss[v]) % mod;
  a[v] = (a[v] * dua[c-1] + s[v]) % mod;
  if (a[v] < 0) a[v] += mod;
}

void add(long long & le, long long ri) {
  le += ri;
  if (le >= mod) le -= mod;
}

long long ans[N];

void dfs2(int v, int par = -1) {
  int c = g[v].size();
  if (par != -1) c--;
  if (par != -1) {
    int c = (int)g[par].size()-1;
    ts[par] = cs[par];
    ta[par] = ca[par];
    tb[par] = cb[par];
    tss[par] = css[par];

    add(tb[par], mod-s[v]);
    add(tss[par], s[v] * s[v] % mod);
    ts[par] = (b[par] * dua[c-1] + dua[c] - 1 - (c != 0)) % mod;
    if (ts[par] < 0) ts[par] += mod;
    add(sum, mod - ta[par]);
    ta[par] = (tb[par] * tb[par] - css[par]) % mod;
    if (ta[v] < 0) ta[v] += mod;
    add(sum, ta[v]);    
  }
  cs[v] = s[v];
  ca[v] = a[v];
  cb[v] = b[v];
  css[v] = ss[v];
  if (par != -1) {
    int c = g[v].size();
    add(cb[v], ts[par]);
    add(css[v], ts[par] * ts[par] % mod);
    cs[v] = (cb[v] * dua[c-1] + dua[c] - 1 - (c != 0)) % mod;
    if (cs[v] < 0) cs[v] += mod;
    add(sum, mod - ca[v]);
    ca[v] = (cb[v] * cb[v] - css[v]) % mod;
    if (ca[v] < 0) ca[v] += mod;
    add(sum, ca[v]);
  }
  ans[v] = sum;
  for (int u : g[v]) if (u != par) {
    sum = ans[v];
    dfs2(u, v);
  }
}

int main() {
  dua[0] = 1;
  for (int i = 1; i < N; i++)
    dua[i] = dua[i-1] * 2 % mod;
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      g[i].clear();
    for (int i = 1; i < n; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      u--; v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    dfs(0);
    sum = 0;
    for (int i = 0; i < n; i++) {
      sum += a[i];
      if (sum >= mod) sum -= mod;
    }
    dfs2(0);
    for (int i = 0; i < n; i++) {
      ans[i] %= mod;
      if (ans[i] < 0) ans[i] += mod;
      cerr << s[i] << " " << a[i] << endl;
      printf("%lld\n", ans[i]);
    }
  }

  return 0;
}