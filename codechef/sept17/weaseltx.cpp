#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, M = 1 << 18;

int n, m;
vector<int> g[N];
long long a[N], x[N];
long long ans[M];
vector<long long> dp[M];

void dfs(int v, int par = -1, int lv = 0) {
  m = max(m, lv+1);
  a[lv] ^= x[v];
  for (int u : g[v]) if (u != par) {
    dfs(u, v, lv+1);
  }
}

int main() {
  int q;
  scanf("%d %d", &n, &q);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 0; i < n; i++)
    scanf("%lld", x+i);
  m = 0;
  dfs(0, 0);
  for (int i = 0; i < m; i++)
    dp[0].push_back(a[i]);
  ans[0] = dp[0][0]; 
  for (int i = 1; i < M; i++) {
    int bg = 1 << (31-__builtin_clz(i));
    int bawah = i ^ bg;
    int blangkah = bg / (1 << (31-__builtin_clz(max(bawah, 1))));
    long long now = 0;
    dp[i].resize(m/bg + 1);
    for (int j = m/bg; j >= 0; j--) {
      now ^= dp[bawah][j * blangkah];
      dp[i][j] = now;
    }
    ans[i] = dp[i][0];
  }
  for (int i = 0; i < q; i++) {
    long long d;
    scanf("%lld", &d);
    d &= M-1;
    printf("%lld\n", ans[d]);
  }
  return 0;
}