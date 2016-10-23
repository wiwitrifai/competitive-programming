#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int t, n, m, c, k;
int g[N][N+N], match[N+N];
bool vis[N];

bool dfs(int v, int threshold) {
  if (vis[v])
    return false;
  vis[v] = 1;
  for (int i = 0; i < m; i++) if (g[v][i] <= threshold) {
    if (match[i] == -1 || dfs(match[i], threshold))
      return match[i] = v, true;
  } 
  return false;
}

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d %d %d", &n, &m, &k, &c);
    int ma = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        scanf("%d", g[i]+j);
        g[i][j+m] = g[i][j] + c;
        ma = max(g[i][j]+c, ma);
      }
    }
    m <<= 1;
    int l = 0, r = ma;
    while (l < r) {
      int mid = (l + r) >> 1;
      int cnt = 0;
      memset(match, -1, sizeof match);
      for (int i = 0; i < n; i++) {
        memset(vis, 0, sizeof vis);
        cnt += dfs(i, mid);
      }
      if (cnt >= k)
        r = mid;
      else
        l = mid + 1;
    }
    printf("%d\n", l);

  }
  return 0;
}