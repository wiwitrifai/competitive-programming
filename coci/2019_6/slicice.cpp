#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int n, m, k;
int p[N], b[N];
int dp[N][N];

void upd(int & x, int y) {
  if (x < y)
    x = y;
}

int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < n; ++i)
    scanf("%d", p+i);
  for (int i = 0; i <= m; ++i)
    scanf("%d", b+i);
  memset(dp, -1, sizeof dp);
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= k; ++j) {
      if (dp[i][j] == -1) continue;
      int cur = dp[i][j];
      int til = min(k-j, m-p[i]);
      for (int add = 0; add <= til; ++add) {
        upd(dp[i+1][j+add], cur + b[p[i]+add]);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= k; ++i)
    upd(ans, dp[n][i]);
  printf("%d\n", ans);
  return 0;
}