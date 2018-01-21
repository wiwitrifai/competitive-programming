#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector<int> g[N];
int val[N], live[N], sz[N], to[N];
char col[N];
void getSz(int v, int par = -1) {
  sz[v] = 1;
  to[v] = -1;
  for (int u : g[v]) if (live[u] && u != par) {
    getSz(u, v);
    sz[v] += sz[u];
    if (to[v] == -1 || sz[to[v]] < sz[u])
      to[v] = u;
  }
}

long long cnt[1 << 21];
long long ans[N];
void add(int v, int par, int mask) {
  mask ^= val[v];
  ++cnt[mask];
  for (int u : g[v]) if (live[u] && u != par) {
    add(u, v, mask);
  }
}

void rem(int v, int par, int mask) {
  mask ^= val[v];
  --cnt[mask];
  for (int u : g[v]) if (live[u] && u != par) {
    rem(u, v, mask);
  }
}

long long get(int v, int par, int mask) {
  mask ^= val[v];
  long long ret = cnt[mask];
  for (int i = 0; i < 20; ++i)
    ret += cnt[mask^(1 << i)];
  for (int u : g[v]) if (live[u] && u != par) {
    ret += get(u, v, mask);
  }
  ans[v] += ret;
  return ret;
}

void centroid(int v) {
  getSz(v);
  int tot = sz[v];
  while (to[v] != -1 && 2 * sz[to[v]] >= tot) v = to[v];
  cnt[0] = 1;
  for (int u : g[v]) if (live[u]) {
    ans[v] += get(u, v, val[v]);
    add(u, v, 0);
  }
  for (int u : g[v]) if (live[u])
    rem(u, v, 0);
  cnt[0] = 0;
  for (int i = (int)g[v].size() - 1; i >= 0; --i) {
    int u = g[v][i];
    if (!live[u]) continue;
    get(u, v, val[v]);
    add(u, v, 0);
  }
  for (int u : g[v]) if (live[u])
    rem(u, v, 0);
  live[v] = 0;
  for (int u : g[v]) if (live[u])
    centroid(u);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  scanf("%s", col);
  for (int i = 0; i < n; ++i)
    val[i] = 1 << (col[i] - 'a');
  fill(live, live + n, 1);
  fill(ans, ans + n, 1);
  centroid(0);
  for (int i = 0; i < n; ++i) {
    printf("%I64d%c", ans[i], i == n-1 ? '\n' : ' ');
  }
  return 0;
}