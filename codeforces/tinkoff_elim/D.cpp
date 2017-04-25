#include <bits/stdc++.h>

using namespace std;

const int N = 88, inf = 1e8;

int dp[2][N][N][N];
int to[N][N];

int solve(int dir, int v, int sz, int k) {
  if (k == 0) return 0;
  if (sz == 0) return inf;
  int & ret = dp[dir][v][sz][k];
  if (ret != -1)
    return ret;
  ret = inf;
  if (dir) {
    for (int i = 1; i <= sz; i++) {
      int u = v + i;
      if (to[v][u] >= inf) continue;
      ret = min(ret, to[v][u] + min(solve(0, u, i-1, k-1), solve(1, u, sz-i, k-1)));
    }
  }
  else {
    for (int i = 1; i <= sz; i++) {
      int u = v - i;
      if (to[v][u] >= inf) continue;
      ret = min(ret, to[v][u] + min(solve(0, u, sz-i, k-1), solve(1, u, i-1, k-1)));
    }
  }
  return ret;
}

int main() {
  int n, k, m;
  scanf("%d %d", &n, &k);
  scanf("%d", &m);
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++)
      to[i][j] = inf;
  for (int i = 0; i < m; i++) {
    int u, v, c;
    scanf("%d %d %d", &u, &v, &c);
    u--; v--;
    if (to[u][v] > c)
      to[u][v] = c;
  }
  memset(dp, -1, sizeof dp);
  int ans = inf;
  for (int i = 0; i < n; i++) {
    ans = min(ans, solve(0, i, i, k-1));
    ans = min(ans, solve(1, i, n-1-i, k-1));
  }
  if (ans >= inf)
    ans = -1;
  cout << ans << endl;
  return 0;
}