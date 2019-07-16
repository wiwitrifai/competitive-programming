#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 6;

long long sum[N][2];
int col[N], cnt[N][2];
vector<int> g[N];

long long ans = 0;
void dfs(int v, int par = -1) {
  ++cnt[v][col[v]];
  for (int u : g[v]) {
    if (u == par) continue;
    col[u] = col[v] ^ 1;
    dfs(u, v);
    for (int j = 0; j < 2; ++j) {
      sum[v][j] += sum[u][j] + cnt[u][j];
      cnt[v][j] += cnt[u][j];
    }
  }
}

void dfs2(int v, int par = -1) {
  for (int u : g[v]) {
    if (u == par) continue;
    for (int j = 0; j < 2; ++j) {
      sum[u][j] = sum[v][j] - cnt[u][j] + (cnt[0][j] - cnt[u][j]);
    }
    dfs2(u, v);
  }
  ans += sum[v][col[v]]/2 + (sum[v][col[v]^1] + cnt[0][col[v]^1]) / 2;
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
  ans = 0;
  dfs(0);
  dfs2(0);
  // assert((ans & 1) == 0);
  ans /= 2;
  printf("%lld\n", ans);
  return 0;
}